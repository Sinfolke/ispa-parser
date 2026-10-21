module LRParser;
import std;

namespace {
// Lengths and dot positions are numbers; production/state references are always
// structural strings. Nothing here persists an address or a table index.
auto checksum(std::string_view bytes) -> std::uint64_t {
    std::uint64_t value = 14695981039346656037ULL;
    for (unsigned char byte : bytes) { value ^= byte; value *= 1099511628211ULL; }
    return value;
}
struct Writer {
    std::string data;
    void number(std::uint64_t value) {
        for (unsigned i = 0; i < 8; ++i) data.push_back(static_cast<char>((value >> (8 * i)) & 255));
    }
    void text(std::string_view value) { number(value.size()); data.append(value); }
    void name(const LRBase::Name& value) {
        number(value.size());
        for (const auto& part : value) text(part);
    }
    void window(const LRBase::Lookahead& value) {
        number(value.size());
        for (const auto& token : value) name(token);
    }
    void windows(const LRBase::Lookaheads& value) {
        number(value.size());
        for (const auto& window : value) this->window(window);
    }
    void records(const std::map<std::string, std::string>& values) {
        number(values.size());
        for (const auto& [key, value] : values) { text(key); text(value); }
    }
};
struct Reader {
    std::string_view data;
    auto number() -> std::uint64_t {
        if (data.size() < 8) throw std::invalid_argument("Truncated LR cache");
        std::uint64_t value = 0;
        for (unsigned i = 0; i < 8; ++i) value |= std::uint64_t(static_cast<unsigned char>(data[i])) << (8 * i);
        data.remove_prefix(8);
        return value;
    }
    auto count() -> std::size_t {
        const auto value = number();
        if (value > 1000000 || value > data.size()) throw std::invalid_argument("Invalid LR cache count");
        return static_cast<std::size_t>(value);
    }
    auto text() -> std::string {
        const auto size = number();
        if (size > data.size()) throw std::invalid_argument("Invalid LR cache string");
        std::string value(data.substr(0, size));
        data.remove_prefix(size);
        return value;
    }
    auto name() -> LRBase::Name {
        LRBase::Name value;
        for (auto left = count(); left; --left) value.push_back(text());
        return value;
    }
    auto window() -> LRBase::Lookahead {
        LRBase::Lookahead value;
        for (auto left = count(); left; --left) value.push_back(name());
        return value;
    }
    auto windows() -> LRBase::Lookaheads {
        LRBase::Lookaheads value;
        for (auto left = count(); left; --left) value.insert(window());
        return value;
    }
    auto records() -> std::map<std::string, std::string> {
        std::map<std::string, std::string> values;
        for (auto left = count(); left; --left) {
            auto key = text();
            auto value = text();
            if (!values.emplace(std::move(key), std::move(value)).second)
                throw std::invalid_argument("Duplicate LR cache entry");
        }
        return values;
    }
    void finish() const {
        if (!data.empty()) throw std::invalid_argument("Trailing LR cache data");
    }
};
}

void LRParser::prepareCacheKeys() {
    production_keys.clear();
    production_ids.clear();
    std::map<std::string, std::size_t> occurrences;
    for (const auto& production : productions) {
        Writer key;
        key.name(production.lhs);
        key.number(production.rhs.size());
        for (const auto& symbol : production.rhs) key.name(symbol);
        key.number(production.whitespace_gaps.size());
        for (bool gap : production.whitespace_gaps) key.number(gap);
        const auto occurrence = occurrences[key.data]++;
        key.number(occurrence);
        production_ids.emplace(key.data, production_keys.size());
        production_keys.push_back(std::move(key.data));
    }
}

auto LRParser::encodeItems(const CanonicalItem& items) const -> std::string {
    std::vector<std::string> ordered;
    for (const auto& [item, lookaheads] : items) {
        Writer record;
        record.text(production_keys.at(item.production));
        record.number(item.dot_pos);
        record.windows(lookaheads);
        ordered.push_back(std::move(record.data));
    }
    std::sort(ordered.begin(), ordered.end());
    Writer out;
    out.number(ordered.size());
    for (const auto& record : ordered) out.text(record);
    return out.data;
}

auto LRParser::itemKey(const CanonicalItem& items) const -> std::string { return encodeItems(items); }

auto LRParser::decodeItems(std::string_view bytes) const -> CanonicalItem {
    Reader in{bytes};
    CanonicalItem items;
    for (auto left = in.count(); left; --left) {
        const auto bytes = in.text();
        Reader record{bytes};
        const auto production = production_ids.at(record.text());
        const auto dot = record.number();
        if (dot > productions.at(production).rhs.size()) throw std::invalid_argument("Invalid cached LR item");
        auto lookaheads = record.windows();
        if (lookaheads.empty()) throw std::invalid_argument("Empty cached LR lookaheads");
        for (const auto& window : lookaheads)
            if (window.size() > k) throw std::invalid_argument("Invalid cached LR lookahead");
        if (!items.emplace(LR0Core{production, static_cast<std::size_t>(dot)}, std::move(lookaheads)).second)
            throw std::invalid_argument("Duplicate cached LR item");
        record.finish();
    }
    in.finish();
    if (items.empty()) throw std::invalid_argument("Empty cached LR state");
    return items;
}

auto LRParser::dependencyStamp(const CanonicalItem& items) const -> std::string {
    // Closure reads the alternatives of the symbol after the dot and FIRST of
    // its suffix. Track those reads, including recursively expanded dot-0 items.
    // FIRST is recomputed globally, so its actual value captures nullable and
    // transitive dependencies without persisting a second dependency graph.
    std::set<LR0Core> pending;
    for (const auto& [item, ignored] : items) pending.insert(item);
    const auto core = pending;
    if (const auto found = dependency_stamps.find(core); found != dependency_stamps.end()) return found->second;
    std::set<LR0Core> visited;
    std::set<Name> expanded, first;
    while (!pending.empty()) {
        const auto item = *pending.begin();
        pending.erase(pending.begin());
        if (!visited.insert(item).second) continue;
        const auto& p = productions.at(item.production);
        if (item.dot_pos >= p.rhs.size()) continue;
        for (auto i = item.dot_pos + 1; i < p.rhs.size(); ++i)
            if (isNonterminal(p.rhs[i])) first.insert(p.rhs[i]);
        const auto& symbol = p.rhs[item.dot_pos];
        if (isNonterminal(symbol) && expanded.insert(symbol).second)
            for (const auto id : productions_by_lhs.at(symbol)) pending.insert(LR0Core{id, 0});
    }
    Writer out;
    out.number(expanded.size());
    for (const auto& name : expanded) {
        out.name(name);
        std::vector<std::string> alternatives;
        for (auto id : productions_by_lhs.at(name)) alternatives.push_back(production_keys.at(id));
        std::sort(alternatives.begin(), alternatives.end());
        out.number(alternatives.size());
        for (const auto& key : alternatives) out.text(key);
    }
    out.number(first.size());
    for (const auto& name : first) { out.name(name); out.windows(first_k.at(name)); }
    dependency_stamps.emplace(core, out.data);
    return out.data;
}

auto LRParser::closure(CanonicalItem items) const -> CanonicalItem {
    Writer key;
    key.text(itemKey(items));
    key.text(dependencyStamp(items));
    // Repeated kernels in the same traversal have identical closures too.
    if (const auto local = current_closures.find(key.data); local != current_closures.end())
        return decodeItems(local->second);
    if (const auto found = cached_closures.find(key.data); found != cached_closures.end()) {
        try {
            auto result = decodeItems(found->second);
            current_closures.emplace(key.data, found->second);
            ++cache_stats.closures_reused;
            return result;
        } catch (const std::exception&) { /* Invalid entries rebuild independently. */ }
    }
    ++cache_stats.closures_built;
    auto result = closureUncached(std::move(items));
    current_closures[key.data] = encodeItems(result);
    return result;
}

auto LRParser::proposalsForState(std::size_t state) -> std::vector<Proposal> {
    Writer key;
    key.text(state_keys.at(state));
    key.text(dependencyStamp(canonical_item_set.at(state)));
    for (const auto& [symbol, target] : transitions.at(state)) {
        key.name(symbol);
        key.text(state_keys.at(target));
    }
    if (const auto found = cached_rows.find(key.data); found != cached_rows.end()) {
        try {
            Reader in{found->second};
            std::vector<Proposal> result;
            for (auto left = in.count(); left; --left) {
                Proposal p;
                p.window = in.window();
                const auto type = in.number();
                if (type > static_cast<unsigned>(Action_type::ERR)) throw std::invalid_argument("Invalid cached LR action");
                p.action.type = static_cast<Action_type>(type);
                const auto target = in.text();
                if (p.action.type == Action_type::SHIFT) p.action.state = state_ids.at(target);
                else if (p.action.type == Action_type::REDUCE) {
                    const auto id = production_ids.at(target);
                    if (!id) throw std::invalid_argument("Invalid cached LR reduction");
                    p.action.state = id - 1;
                } else if (p.action.type != Action_type::ACCEPT || !target.empty())
                    throw std::invalid_argument("Invalid cached LR proposal");
                p.item.production = production_ids.at(in.text());
                p.item.dot_pos = in.number();
                if (!canonical_item_set.at(state).contains(p.item)) throw std::invalid_argument("Invalid cached LR origin");
                result.push_back(std::move(p));
            }
            in.finish();
            std::sort(result.begin(), result.end(), [](const auto& a, const auto& b) {
                return std::tie(a.item, a.window, a.action.type, a.action.state) <
                       std::tie(b.item, b.window, b.action.type, b.action.state);
            });
            current_rows.emplace(key.data, found->second);
            ++cache_stats.rows_reused;
            return result;
        } catch (const std::exception&) { /* Remapping failure invalidates this row. */ }
    }
    ++cache_stats.rows_built;
    std::vector<Proposal> result;
    for (const auto& [core, lookaheads] : canonical_item_set.at(state)) {
        const auto& p = productions.at(core.production);
        if (core.dot_pos < p.rhs.size()) {
            const auto& next = p.rhs[core.dot_pos];
            if (!isNonterminal(next)) {
                const auto target = transitions.at(state).at(next);
                for (const auto& lookahead : lookaheads)
                    for (const auto& window : firstOfSuffix(p, core.dot_pos + 1, lookahead, &next))
                        result.push_back({window, Action{Action_type::SHIFT, target}, core});
            }
        } else {
            for (const auto& window : lookaheads) {
                if (core.production == 0) {
                    if (window == Lookahead(k, eof)) result.push_back({window, Action{Action_type::ACCEPT, 0}, core});
                } else result.push_back({window, Action{Action_type::REDUCE, core.production - 1}, core});
            }
        }
    }
    std::sort(result.begin(), result.end(), [](const auto& a, const auto& b) {
        return std::tie(a.item, a.window, a.action.type, a.action.state) <
               std::tie(b.item, b.window, b.action.type, b.action.state);
    });
    Writer out;
    out.number(result.size());
    for (const auto& p : result) {
        out.window(p.window);
        out.number(static_cast<unsigned>(p.action.type));
        out.text(p.action.type == Action_type::SHIFT ? state_keys.at(p.action.state) :
            p.action.type == Action_type::REDUCE ? production_keys.at(p.action.state + 1) : std::string{});
        out.text(production_keys.at(p.item.production));
        out.number(p.item.dot_pos);
    }
    current_rows[key.data] = std::move(out.data);
    return result;
}

void LRParser::loadCache(std::string_view bytes) {
    cached_closures.clear(); cached_rows.clear(); cached_resolutions.clear();
    if (bytes.empty()) return;
    try {
        Reader envelope{bytes};
        const auto payload = envelope.text();
        if (envelope.number() != checksum(payload)) return;
        envelope.finish();
        Reader in{payload};
        if (in.text() != "ISPA-LR-cache-1" || in.text() != cacheKind() || in.number() != k) return;
        auto closures = in.records();
        auto rows = in.records();
        auto decisions = in.text();
        in.finish();
        cached_closures = std::move(closures);
        cached_rows = std::move(rows);
        cached_resolutions = std::move(decisions);
    } catch (const std::exception&) { /* A corrupt snapshot is a cold cache. */ }
}

auto LRParser::saveCache() const -> std::string {
    Writer out;
    out.text("ISPA-LR-cache-1"); out.text(cacheKind()); out.number(k);
    out.records(current_closures); out.records(current_rows); out.text(cached_resolutions);
    Writer envelope;
    envelope.text(out.data); envelope.number(checksum(out.data));
    return envelope.data;
}

auto LRParser::resolutionKey(std::size_t max_lookahead) const -> std::string {
    Writer key;
    key.text(cacheKind()); key.number(k); key.number(max_lookahead);
    key.number(skip_automatic_whitespace);
    for (const auto& production : production_keys) key.text(production);
    return key.data;
}

auto LRParser::restoreResolutions(std::size_t max_lookahead) -> bool {
    if (cached_resolutions.empty()) return false;
    try {
        Reader in{cached_resolutions};
        if (in.text() != resolutionKey(max_lookahead)) return false;
        const auto decision_depth = in.number();
        if (decision_depth < k || decision_depth > std::max(k, max_lookahead)) return false;
        std::map<std::string, std::size_t> conflict_ids;
        for (std::size_t i = 0; i < conflicts.size(); ++i) {
            Writer id;
            id.text(state_keys.at(conflicts[i].state)); id.window(conflicts[i].lookahead_sequence);
            conflict_ids.emplace(std::move(id.data), i);
        }
        std::vector<Resolution> restored;
        std::set<std::size_t> seen;
        for (auto left = in.count(); left; --left) {
            Resolution r;
            r.conflict = conflict_ids.at(in.text());
            if (!seen.insert(r.conflict).second) return false;
            r.lookahead = in.number();
            if (r.lookahead && (r.lookahead <= k || r.lookahead > decision_depth)) return false;
            for (auto count = in.count(); count; --count) {
                Decision d;
                d.state = state_ids.at(in.text()); d.window = in.window();
                const auto type = in.number();
                const auto target = in.text();
                if (type == static_cast<unsigned>(Action_type::SHIFT)) d.action = {Action_type::SHIFT, state_ids.at(target)};
                else if (type == static_cast<unsigned>(Action_type::REDUCE)) {
                    const auto id = production_ids.at(target);
                    if (!id) return false;
                    d.action = {Action_type::REDUCE, id - 1};
                } else if (type == static_cast<unsigned>(Action_type::ACCEPT) && target.empty()) d.action = {Action_type::ACCEPT, 0};
                else return false;
                const auto& conflict = conflicts.at(r.conflict);
                if (d.state != conflict.state || d.window.size() != r.lookahead ||
                    std::find(conflict.actions.begin(), conflict.actions.end(), d.action) == conflict.actions.end()) return false;
                r.decisions.push_back(std::move(d));
            }
            if ((r.lookahead == 0) != r.decisions.empty()) return false;
            restored.push_back(std::move(r));
        }
        in.finish();
        if (restored.size() != conflicts.size()) return false;
        std::sort(restored.begin(), restored.end(), [](const auto& a, const auto& b) { return a.conflict < b.conflict; });
        resolutions = std::move(restored);
        decision_k = decision_depth; auto_conflicts = true; cache_stats.resolutions_reused = true;
        return true;
    } catch (const std::exception&) { return false; }
}

void LRParser::cacheResolutions(std::size_t max_lookahead) {
    Writer out;
    out.text(resolutionKey(max_lookahead)); out.number(decision_k); out.number(resolutions.size());
    for (const auto& r : resolutions) {
        const auto& conflict = conflicts.at(r.conflict);
        Writer id;
        id.text(state_keys.at(conflict.state)); id.window(conflict.lookahead_sequence);
        out.text(id.data); out.number(r.lookahead); out.number(r.decisions.size());
        for (const auto& d : r.decisions) {
            out.text(state_keys.at(d.state)); out.window(d.window); out.number(static_cast<unsigned>(d.action.type));
            out.text(d.action.type == Action_type::SHIFT ? state_keys.at(d.action.state) :
                d.action.type == Action_type::REDUCE ? production_keys.at(d.action.state + 1) : std::string{});
        }
    }
    cached_resolutions = std::move(out.data);
}
