module LRParser;
import AST.API;
import logging;
import hash;
import cpuf.printf;
import std;
auto LRParser::getActionTable() const -> const ActionTable& {
    return action_table;
}
auto LRParser::getGotoTable() const -> const GotoTable& {
    return goto_table;
}
auto LRParser::getRulesTable() const -> const Rules& {
    return rules;
}
auto LRParser::getMaxStatesCount() const -> std::size_t {
    std::size_t max_state = 0;
    for (const auto& [state, _] : action_table) {
        max_state = std::max(max_state, state);
    }
    return max_state;
}
auto LRParser::ActionTypeToString(const Action_type &type) -> std::string {
    switch (type) {
        case Action_type::SHIFT:
            return "SHIFT";
        case Action_type::REDUCE:
            return "REDUCE";
        case Action_type::ACCEPT:
            return "ACCEPT";
        case Action_type::DFA_RESOLVE:
            return "DFA_RESOLVE";
        case Action_type::ERR:
            return "ERROR";

    }
    throw Error("Undefined action type: %$", (int) type);
}
auto LRParser::getActionTableAsRow() const -> stdu::vector<utype::unordered_map<stdu::vector<std::string>, LRParser::Action>> {
    stdu::vector<utype::unordered_map<stdu::vector<std::string>, LRParser::Action>> row_table;
    for (auto [state, value] : action_table) {
        while(row_table.size() <= state) {
            row_table.push_back({});
        }
        row_table[state] = value;
    }
    return row_table;
}
auto LRParser::getGotoTableAsRow() const -> stdu::vector<utype::unordered_map<stdu::vector<std::string>, std::size_t>> {
    stdu::vector<utype::unordered_map<stdu::vector<std::string>, std::size_t>> row_table;
    for (auto [state, value] : goto_table) {
        while(row_table.size() <= state) {
            row_table.push_back({});
        }
        row_table[state] = value;
    }
    return row_table;
}
bool LRParser::isELR() const {
    return false;
}

// void LRParser::getPriorityTree(const stdu::vector<TreeAPI::Rule> *rule, utype::unordered_set<stdu::vector<std::string>> &visited, std::size_t depth) {
//     for (const auto &r : *rule) {
//         // Avoid re-expansion of already visited rules
//         if (!corelib::text::isLower(r.members.name) || visited.count(r.fullname))
//             continue;

//         // Assign priority if not yet assigned
//         if (priority.find(r.fullname) == priority.end()) {
//             priority[r.fullname] = depth;
//         }

//         visited.insert(r.fullname);

//         // Recurse into rule alternatives
//         auto it = tree->getInitialItemSet().find(r.fullname);
//         if (it != tree->getInitialItemSet().end()) {
//             for (const auto &subrule : it->second) {
//                 getPriorityTree(&subrule, visited, depth + 1);
//             }
//         }
//     }
// }

// void LRParser::getPriorityTree() {
//     utype::unordered_set<stdu::vector<std::string>> visited;

//     auto it = tree->getInitialItemSet().find({"main"});
//     if (it != tree->getInitialItemSet().end()) {
//         for (const auto &r : it->second) {
//             getPriorityTree(&r, visited, 0);
//         }
//     } else {
//         throw Error("No main rule found");
//     }
// }

void LRParser::addAugmentedRule() {
    tree->getInitialItemSet()[{"__start"}] = {AST::Rule { { AST::RuleMember {.value = AST::RuleMemberName {.name = {"main"}}}}}};
}
void LRParser::compute_cci_lookahead(const AST::Rule &rhs_group, const stdu::vector<std::string> &lhs_name, LR1Core &new_item) {
    std::size_t next_pos = new_item.dot_pos + 1;
    // cpuf::printf("computing lookahead for %$ -> ", lhs_name);
    if (rhs_group.rule_members.empty() || next_pos >= rhs_group.rule_members.size()) {
        // end of rule, compute lookahead of follow(current)
        auto &lookahead = tree->getFollowSet()[lhs_name];
        new_item.lookahead.insert(lookahead.begin(), lookahead.end());
        return;
    }
    // check whether next symbol is terminal or non-terminal
    bool epsilon_in_all = true;
    for (std::size_t i = next_pos; i < rhs_group.rule_members.size(); i++) {
        auto &symbol = rhs_group.rule_members[i];
        if (!symbol.isName())
            throw Error("Symbol is not name");
        const auto &name = symbol.getName();
        if (corelib::text::isUpper(name.name.back())) {
            // terminal
            // cpuf::printf("[terminal] %$", symbol.fullname);
            new_item.lookahead.insert(name.name);
            epsilon_in_all = false;
            break;
        } else {
            // non-terminal, insert FIRST of next symbol
            auto &first_set = tree->getFirstSet()[name.name];
            bool has_espsilon = false;
            // cpuf::printf("[non-terminal %$] ", symbol.fullname);
            for (const auto& el : first_set) {
                if (el == stdu::vector<std::string>{"ε"}) {
                    has_espsilon = true;
                    continue;
                }
                // cpuf::printf("%$, ", el);
                new_item.lookahead.insert(el);
            }
        }
    }
    // If all symbols after dot can derive ε, add FOLLOW(lhs)
    if (epsilon_in_all) {
        const auto& follow_set = tree->getFollowSet()[lhs_name];
        new_item.lookahead.insert(follow_set.begin(), follow_set.end());
    }
    // for (auto el : new_item.lookahead) {
    //     cpuf::printf("%$, ", el);
    // }
    // cpuf::printf("\n");
}
void LRParser::create_item_collection(CanonicalItem &closure, const ItemSet &item, const stdu::vector<std::string> &lhs_name) {
    for (const auto& rhs_group : item) {
        LR1Core new_item;
        // Create LHS rule_other

        new_item.lhs = lhs_name;
        new_item.rhs = rhs_group;
        new_item.dot_pos = 0;
        if (closure.find(new_item) != closure.end())
            continue;
        compute_cci_lookahead(rhs_group, lhs_name, new_item);
        // Avoid duplicate

        closure.insert(new_item);

        // If rule is epsilon, no need to recurse further
        if (rhs_group.rule_members.empty()) {
            continue;
        }

        // Expand first symbol if it's non-terminal
        const auto& sym = rhs_group.rule_members[0];
        const auto& name = sym.getName();
        if (corelib::text::isLower(name.name.back())) {
            auto rule = tree->getInitialItemSet().find(name.name);
            if (rule != tree->getInitialItemSet().end()) {
                create_item_collection(closure, rule->second, name.name);
            }
        }
    }
}


LRParser::CanonicalItemSet LRParser::construct_cannonical_collections_of_items() {
    CanonicalItemSet cci;

    auto begin_rule = tree->getInitialItemSet().find({"__start"});
    if (begin_rule == tree->getInitialItemSet().end()) {
        throw Error("No augmented rule\n");
    }

    CanonicalItem I0;
    create_item_collection(I0, begin_rule->second, begin_rule->first);
    cci.push_back(I0);

    std::queue<CanonicalItem> worklist;
    worklist.push(I0);

    while (!worklist.empty()) {
        CanonicalItem current = worklist.front();
        worklist.pop();

        // You likely need to aggregate per symbol with a merged lookahead set
        utype::unordered_map<stdu::vector<std::string>, CanonicalItem> transitions;

        for (const auto& item : current) {
            if (item.dot_pos < item.rhs.rule_members.size()) {
                const auto& sym = item.rhs.rule_members[item.dot_pos].getName().name;

                LR1Core advanced = item;
                advanced.dot_pos++;
                compute_cci_lookahead(advanced.rhs, advanced.lhs, advanced);

                // Merge item into the transition set for this symbol
                auto& itemset = transitions[sym];

                // If an identical core+dot_pos exists but with different lookahead, merge
                bool found = false;
                for (auto& e : itemset) {
                    if (e.lhs == advanced.lhs && e.rhs == advanced.rhs && e.dot_pos == advanced.dot_pos) {
                        e.lookahead.insert(advanced.lookahead.begin(), advanced.lookahead.end());
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    itemset.insert(advanced);
                }
            }
        }


        for (auto& [sym, items] : transitions) {
            CanonicalItem closure = items;

            for (const auto& el : items) {
                if (el.dot_pos < el.rhs.rule_members.size()) {
                    const auto& sym_rhs = el.rhs.rule_members[el.dot_pos];
                    const auto &sym_rhs_name = sym_rhs.getName();
                    if (corelib::text::isLower(sym_rhs_name.name.back())) {
                        auto rule = tree->getInitialItemSet().find(sym_rhs_name.name);
                        if (rule != tree->getInitialItemSet().end()) {
                            create_item_collection(closure, rule->second, sym_rhs_name.name);
                        }
                    }
                }
            }

            if (std::find(cci.begin(), cci.end(), closure) == cci.end()) {
                cci.push_back(closure);
                worklist.push(closure);
            }
        }
    }

    return cci;
}


std::size_t LRParser::find_goto_state(const CanonicalItem &item_set, const stdu::vector<std::string> &symbol) {
    CanonicalItem next_state;

    // Step 1: Shift dot over symbol where possible
    for (const auto &item : item_set) {
        if (item.dot_pos < item.rhs.rule_members.size() && item.rhs.rule_members[item.dot_pos].getName().name == symbol) {
            LR1Core shifted = item;
            shifted.dot_pos++;
            next_state.insert(shifted);
        }
    }
    CanonicalItem closure = next_state;
    // Step 2: Compute closure of this new state
    for (const auto &item : next_state) {
        if (item.dot_pos < item.rhs.rule_members.size()) {
            const auto &next_sym = item.rhs.rule_members[item.dot_pos];
            const auto &next_sym_name = next_sym.getName();
            if (corelib::text::isLower(next_sym_name.name.back())) {
                // Non-terminal → expand it
                auto rule = tree->getInitialItemSet().find(next_sym_name.name);
                if (rule != tree->getInitialItemSet().end()) {
                    create_item_collection(closure, rule->second, rule->first);
                }
            }
        }
    }


    // Step 3: Check if this closure already exists in canonical set
    auto it = std::find(canonical_item_set.begin(), canonical_item_set.end(), closure);
    if (it != canonical_item_set.end()) {
        return std::distance(canonical_item_set.begin(), it);
    }

    // Step 4: If not, add it (only do this if building dynamically — otherwise error)
    throw Error("GOTO leads to non-existent state. Should be precomputed.");
}
std::size_t LRParser::find_rules_index(const LR1Core &rule) {
    std::size_t reduce_index;
    auto found_rhs = std::find_if(rules.begin(), rules.end(), [&rule](const Rules_part &el) {
        if (rule.lhs != el.first)
            return false;
        auto &rhs = el.second.second;
        if (rhs.size() != rule.rhs.rule_members.size())
            return false;
        for (std::size_t i = 0; i < rhs.size(); i++) {
            if (rhs[i].getName().name != rule.rhs.rule_members[i].getName().name) 
                return false;
        }
        return true;
    });
    if (found_rhs != rules.end()) {
        reduce_index = found_rhs - rules.begin();
    } else {
        rules.push_back(Rules_part {rule.lhs, {rule.rhs.rule_members.size(), rule.rhs.rule_members}});
        reduce_index = rules.size() - 1;
    }
    return reduce_index;
}
bool isInUsePlace(const AST::UsePlaceTable &use_places, const stdu::vector<std::string> &first, const stdu::vector<std::string> &second, utype::unordered_set<stdu::vector<std::string>> &checked) {
    checked.insert(first);
    auto find_it = use_places.find(first);
    if (find_it == use_places.end())
        return false;
    const auto &[name, used_nonterminals] = *find_it;
    for (auto nonterminal : used_nonterminals) {
        if (nonterminal == second) {
            return true;
        } else if (checked.count(nonterminal) == 0 && isInUsePlace(use_places, nonterminal, second, checked)) {
            return true;
        }
    }
    return false;
}
void LRParser::resolveCertainConflict(const Conflict &conflict) {
    auto &[item, place, conflicts, state] = conflict;
    const Action* shift_place = nullptr;
    bool reduce_conflict = false;
    for (const auto &conflict : conflicts) {
        if (conflict.type == Action_type::SHIFT)
            shift_place = &conflict;
        else if (conflict.type == Action_type::REDUCE) 
            reduce_conflict = true;
    }
    if (shift_place != nullptr && reduce_conflict) {
        // SHIFT/REDUCE conflict, prefer shift
        *place = *shift_place;
        return;
    }
    // resolve reduce/reduce conflict statically
    // build small nested table
    if (conflict.conflicts.size() > 2)
        throw Error("Parser is unable to resolve 3 or more reduce/reduce conflicts\n");
    const auto &first = item[0];
    const auto &second = item[1];
    if (!first.rhs.rule_members.empty() && second.rhs.rule_members.empty()) {
        *place = conflicts[0];
    } else if (first.rhs.rule_members.empty() && !second.rhs.rule_members.empty()) {
        *place = conflicts[1];
    } else if (first.rhs.rule_members.empty() && second.rhs.rule_members.empty()) {
        throw Error("REDUCE/REDUCE conflict for two epsilon rules");
    }
    utype::unordered_set<stdu::vector<std::string>> checked;
    // check whether second rule is nested in first
    if (isInUsePlace(use_places, first.lhs, second.lhs, checked)) {
        *place = conflicts[0];
    } else {
        checked.clear();
        if (isInUsePlace(use_places, second.lhs, first.lhs, checked)) {
            *place = conflicts[1];
        } else {
            throw Error("Insoluble reduce/reduce conflict");
            // both rules are not relative, use deepth
            if (priority[first.lhs] > priority[second.lhs]) {
                *place = conflicts[0];
            } else {
                *place = conflicts[1];
            }
        }
    }
}
void LRParser::resolveConflictsStatically() {
    for (const auto &conflict : conflicts) {
        resolveCertainConflict(conflict);
    }
}
void LRParser::buildTable() {
    std::size_t I = 0;
    for (const auto& item_set : canonical_item_set) {
        const LR1Core* prev_rule = nullptr;
        Action* prev_action = nullptr;
        for (const auto& rule : item_set) {
            // cpuf::printf("I%$: %$ → ", I, rule.lhs.fullname);
            // for (std::size_t j = 0; j < rule.rhs.size(); ++j) {
            //     if (j == rule.dot_pos) {
            //         cpuf::printf("• ");
            //     }
            //     cpuf::printf("%$, ", rule.rhs[j].fullname);
            // }
            // if (rule.dot_pos == rule.rhs.size()) {
            //     cpuf::printf("• ");
            // }
            // cpuf::printf("  lookahead: ");
            // for (const auto& lookahead : rule.lookahead) {
            //     cpuf::printf("%$, ", lookahead);
            // }
            // cpuf::printf("\n");

            if (rule.rhs.rule_members.size() == 1 && rule.lhs == rule.rhs.rule_members[0].getName().name) {
                // cpuf::printf("skipping %$ -> %$\n", rule.lhs.fullname, rule.rhs[0].fullname);
                continue;
            }
            // Dot is at the end → Reduce or Accept
            if (rule.dot_pos >= rule.rhs.rule_members.size()) {
                // Accept condition: augmented rule with start symbol
                if (rule.lhs == stdu::vector<std::string> {"__start"} && rule.rhs.rule_members.size() == 1) {
                    action_table[I][{"$"}] = Action{Action_type::ACCEPT, 0};
                    continue;
                }

                // Reduce: only insert reduce if no conflicting shift action exists
                // Use the lookahead token for LR(1)
                // cpuf::printf("Got lookahead for %$ -> ", rule.lhs.fullname);
                for (auto lookahead : rule.lookahead) {
                    if (action_table[I].count(lookahead) == 0) {
                        // No existing shift, safe to reduce
                        action_table[I][lookahead] = Action{Action_type::REDUCE, find_rules_index(rule)};
                    } else {
                        const auto& existing = action_table[I][lookahead];
                        auto rules_index = find_rules_index(rule);
                        if (existing.type != Action_type::REDUCE || existing.state != rules_index) {
                            // Always include the current action and the one already in the action table
                            Conflict new_conflict;
                            if (prev_rule) {
                                new_conflict.item.push_back(*prev_rule);
                            }
                            new_conflict.item.push_back(rule);
                            new_conflict.place = &action_table[I][lookahead];

                            // Add the existing action in the action table as a conflict
                            const auto& existing = action_table[I][lookahead];
                            new_conflict.conflicts.push_back(existing);

                            // Add the current action
                            new_conflict.conflicts.push_back(Action{Action_type::REDUCE, rules_index});
                            new_conflict.state = I;

                            // Check if this conflict already exists
                            auto find_it = std::find_if(conflicts.begin(), conflicts.end(), [&I, &lookahead, this](const Conflict &c) {
                                return c.state == I && c.place == &action_table[I].at(lookahead);
                            });

                            if (find_it != conflicts.end()) {
                                // Add the current rule to the existing conflict
                                find_it->item.push_back(rule);
                                find_it->conflicts.push_back(Action{Action_type::REDUCE, find_rules_index(rule)});
                            } else {
                                // Add a new conflict
                                conflicts.push_back(new_conflict);
                            }
                        }
                        
                    }
                }
                // cpuf::printf("\n");
            } else { // Dot is before a symbol
                const auto& next = rule.rhs.rule_members[rule.dot_pos].getName();
                std::size_t next_state = find_goto_state(item_set, next.name); // goto(I, X)
                if (corelib::text::isUpper(next.name.back())) {
                    // Terminal → SHIFT (unconditionally)
                    if (action_table[I].count(next.name) == 0) {
                        action_table[I][next.name] = Action{Action_type::SHIFT, next_state};
                    } else {
                        const auto& existing = action_table[I][next.name];
                        if (existing.type != Action_type::SHIFT || existing.state != next_state) {
                            // Avoid duplicate SHIFT actions
                            Conflict new_conflict;
                            if (prev_rule) {
                                new_conflict.item.push_back(*prev_rule);
                            }
                            new_conflict.item.push_back(rule);
                            new_conflict.place = &action_table[I][next.name];

                            // Add the existing action in the action table as a conflict
                            new_conflict.conflicts.push_back(existing);

                            // Add the current action
                            new_conflict.conflicts.push_back(Action{Action_type::SHIFT, next_state});
                            new_conflict.state = I;

                            // Check if this conflict already exists
                            auto find_it = std::find_if(conflicts.begin(), conflicts.end(), [&I, &next, this](const Conflict &c) {
                                return c.state == I && c.place == &action_table[I].at(next.name);
                            });

                            if (find_it != conflicts.end()) {
                                // Add the current rule to the existing conflict
                                find_it->item.push_back(rule);
                                find_it->conflicts.push_back(Action{Action_type::SHIFT, next_state});
                            } else {
                                // Add a new conflict
                                conflicts.push_back(new_conflict);
                            }
                        }

                        
                    }
                    prev_action = &action_table[I][next.name];
                } else {// Non-terminal → GOTO
                    goto_table[I][next.name] = next_state;
                }
            }
            prev_rule = &rule;
        }
        I++;
    }

    for (auto &conflict : conflicts) {
        cpuf::printf("Conflict in state %$:", conflict.state);
        for (auto conf : conflict.conflicts) {
            cpuf::printf("[%$ %$]", LRParser::ActionTypeToString(conf.type), conf.state, conflict.item.size());
        }
        cpuf::printf("\n");
    }
}

void LRParser::prepare() {
    addAugmentedRule();
    tree->getFirstSet()[{"__start"}] = tree->getFirstSet()[{"main"}];
    tree->getRawFollowSet()[{"__start"}] = {{"$"}};
    use_places = tree->getUsePlacesTable();
    canonical_item_set = construct_cannonical_collections_of_items();
}
void LRParser::build() {
    prepare();
    buildTable();
    resolveConflictsStatically();
}



void LRParser::formatRulesTable(std::ostringstream& oss) {
    oss << "Rules:\n";
    for (const auto& rule : rules) {
        const auto& rule_name_parts = rule.first;
        const auto& lhs = corelib::text::join(rule_name_parts, "_");

        const std::size_t rule_index = rule.second.first;
        const auto& body = rule.second.second;

        oss << '\t' << rule_index << ": " << lhs << " → ";

        for (const auto& token : body) {
            oss << corelib::text::join(token.getName().name, "_") << " ";
        }
        oss << '\n';
    }
}
void LRParser::formatCanonicalItemSet(std::ostringstream &oss) {
    std::size_t count = 0;
    for (const auto &item_set : canonical_item_set) {
        oss << "I" << count++ << ":\n";
        for (const auto &item : item_set) {
            // Print the LHS
            oss << '\t'
                << corelib::text::join(item.lhs, "_")
                << " → ";

            // Print RHS with dot position
            for (std::size_t i = 0; i <= item.rhs.rule_members.size(); ++i) {
                if (i == item.dot_pos) {
                    oss << "• ";
                }
                if (i < item.rhs.rule_members.size()) {
                    oss << corelib::text::join(item.rhs.rule_members[i].getName().name, "_") << ' ';
                }
            }
            oss << "; lookahead: {";
            for (auto el : item.lookahead) {
                oss << corelib::text::join(el, "_") << ", ";
            }
            oss << "}\n";
        }
        oss << "\n";
    }
}

void LRParser::printCanonicalCollection(const std::string &fileName) {
    // Step 1: Print to std::ostringstream
    std::ostringstream oss;
    formatCanonicalItemSet(oss);

    // Step 2: Output the stringstream content to a file
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << oss.str();
        outFile.close();
    } else {
        std::cerr << "Failed to open the file for writing: " << fileName << "\n";
    }
}

// Helper function to format the Action Table into a string
std::string LRParser::formatActionTable() const {
    std::ostringstream oss;
    const int stateWidth = 6;
    const int tokenWidth = 15;
    const int actionWidth = 10;
    const int nextStateWidth = 10;

    oss << "Action Table:\n";
    oss << std::left
        << std::setw(stateWidth) << "State"
        << std::setw(tokenWidth) << "Token"
        << std::setw(actionWidth) << "Action"
        << std::setw(nextStateWidth) << "Next State"
        << "\n";

    for (const auto& state_entry : action_table) {
        std::size_t state = state_entry.first;
        for (const auto& token_entry : state_entry.second) {
            const std::string& token = corelib::text::join(token_entry.first, "_");
            const Action& action = token_entry.second;

            std::string action_str = ActionTypeToString(action.type);

            oss << std::left
                << std::setw(stateWidth) << state
                << std::setw(tokenWidth) << token
                << std::setw(actionWidth) << action_str
                << std::setw(nextStateWidth) << action.state
                << "\n";
        }
    }
    return oss.str();
}

std::string LRParser::formatGotoTable() const {
    std::ostringstream oss;
    const int stateWidth = 6;
    const int nonTerminalWidth = 20;
    const int nextStateWidth = 12;

    oss << "Goto Table:\n";
    oss << std::left
        << std::setw(stateWidth) << "State"
        << std::setw(nonTerminalWidth) << "Non-Terminal"
        << std::setw(nextStateWidth) << "Next State"
        << "\n";

    for (const auto& state_entry : goto_table) {
        std::size_t state = state_entry.first;
        for (const auto& non_terminal_entry : state_entry.second) {
            const std::string& non_terminal = corelib::text::join(non_terminal_entry.first, "_");
            std::size_t next_state = non_terminal_entry.second;

            oss << std::left
                << std::setw(stateWidth) << state
                << std::setw(nonTerminalWidth) << non_terminal
                << std::setw(nextStateWidth) << next_state
                << "\n";
        }
    }
    return oss.str();
}

// Method to print both Action and Goto tables into a single file
void LRParser::printTables(const std::string& filename) {
    std::ofstream out_file(filename);

    if (!out_file.is_open()) {
        std::cerr << "Error opening file for writing tables.\n";
        return;
    }

    // Format the Action Table and Goto Table
    std::string action_table_str = formatActionTable();
    std::string goto_table_str = formatGotoTable();
    std::ostringstream out;
    formatRulesTable(out);

    // Write both tables to the file
    out_file << action_table_str << "\n" << goto_table_str << "\n" << out.str();

    out_file.close();
}