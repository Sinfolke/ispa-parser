module;
#include <cstdio>
#include <cstdlib>
#if defined(_WIN32)
#include <io.h>
#else
#include <unistd.h>
#endif

export module ISPA.Diagnostics;
import std;

export namespace ISPA::Diagnostics {
    enum class Severity { Error, Warning, Info };
    enum class ColorPolicy { Auto, Always, Never };

    struct Location {
        std::string file;
        std::size_t offset = std::string::npos;
        std::size_t length = 0;
        std::size_t line = 0;     // 1 based
        std::size_t column = 0;   // 1 based, byte columns
    };

    struct Diagnostic {
        Severity severity = Severity::Error;
        std::string code;
        std::string message;
        Location location;
        std::vector<std::string> notes;
        std::string help;
    };

    // Central, reusable compiler diagnostic service. Locations point into the original source.
    class Reporter {
    public:
        void source(std::string file, std::string content);
        const std::string* sourceText(const std::string& file) const;
        void emit(Diagnostic diagnostic);
        void error(std::string code, std::string message, Location location = {});
        void warning(std::string code, std::string message, Location location = {});
        void info(std::string code, std::string message, Location location = {});
        const std::vector<Diagnostic>& diagnostics() const noexcept { return entries_; }
        std::size_t count(Severity severity) const;
        bool hasErrors() const { return count(Severity::Error) != 0; }
        void clear() { entries_.clear(); }
        void print(std::ostream& out, ColorPolicy policy = ColorPolicy::Auto) const;
        void printSummary(std::ostream& out, ColorPolicy policy = ColorPolicy::Auto) const;
    private:
        std::map<std::string, std::string> sources_;
        std::vector<Diagnostic> entries_;
    };
}

namespace {
    bool enabled(ISPA::Diagnostics::ColorPolicy policy) {
        if (policy == ISPA::Diagnostics::ColorPolicy::Never) return false;
        if (policy == ISPA::Diagnostics::ColorPolicy::Always) return true;
        if (std::getenv("NO_COLOR")) return false;
#if defined(_WIN32)
        return _isatty(_fileno(stderr)) != 0;
#else
        return isatty(fileno(stderr)) != 0;
#endif
    }
    std::string_view label(ISPA::Diagnostics::Severity s) {
        using S = ISPA::Diagnostics::Severity;
        switch (s) { case S::Error: return "error"; case S::Warning: return "warning"; case S::Info: return "info"; }
        return "diagnostic";
    }
    std::string_view tint(ISPA::Diagnostics::Severity s) {
        using S = ISPA::Diagnostics::Severity;
        switch (s) { case S::Error: return "\033[1;31m"; case S::Warning: return "\033[1;33m"; case S::Info: return "\033[1;36m"; }
        return "";
    }
    constexpr std::string_view reset = "\033[0m";
    constexpr std::string_view dim = "\033[2m";

    // Prefer byte offsets. Some frontends only retain a line and column.
    ISPA::Diagnostics::Location fixLocation(ISPA::Diagnostics::Location p,
                                            const std::string* source) {
        if (!source) return p;
        if (p.offset == std::string::npos || p.offset > source->size()) {
            if (!p.line) return p;
            std::size_t begin = 0;
            for (std::size_t line = 1; line < p.line; ++line) {
                const auto newline = source->find('\n', begin);
                if (newline == std::string::npos) return p;
                begin = newline + 1;
            }
            const auto end = source->find('\n', begin);
            const auto limit = end == std::string::npos ? source->size() : end;
            p.offset = std::min(begin + (p.column ? p.column - 1 : 0), limit);
        }
        p.line = p.column = 1;
        for (std::size_t i = 0; i < p.offset; ++i) {
            if ((*source)[i] == '\n') { ++p.line; p.column = 1; }
            else ++p.column;
        }
        return p;
    }
    std::string expandTabs(std::string_view s, std::size_t column = 0) {
        std::string result;
        for (char c : s) {
            if (c == '\t') result.append(4 - ((column + result.size()) % 4), ' ');
            else if (c != '\r') result += c;
        }
        return result;
    }
}

namespace ISPA::Diagnostics {
    void Reporter::source(std::string file, std::string content) {
        sources_.insert_or_assign(std::move(file), std::move(content));
    }
    const std::string* Reporter::sourceText(const std::string& file) const {
        const auto it = sources_.find(file);
        return it == sources_.end() ? nullptr : &it->second;
    }
    void Reporter::emit(Diagnostic d) { entries_.push_back(std::move(d)); }
    void Reporter::error(std::string c, std::string m, Location p) {
        emit({Severity::Error, std::move(c), std::move(m), std::move(p), {}, {}});
    }
    void Reporter::warning(std::string c, std::string m, Location p) {
        emit({Severity::Warning, std::move(c), std::move(m), std::move(p), {}, {}});
    }
    void Reporter::info(std::string c, std::string m, Location p) {
        emit({Severity::Info, std::move(c), std::move(m), std::move(p), {}, {}});
    }
    std::size_t Reporter::count(Severity s) const {
        return static_cast<std::size_t>(std::count_if(entries_.begin(), entries_.end(),
            [s](const auto& d) { return d.severity == s; }));
    }
    void Reporter::print(std::ostream& out, ColorPolicy policy) const {
        const bool color = enabled(policy);
        for (const Diagnostic& d : entries_) {
            const auto* src = sourceText(d.location.file);
            const Location p = fixLocation(d.location, src);
            const std::string_view accent = color ? tint(d.severity) : std::string_view{};
            const std::string_view normal = color ? reset : std::string_view{};
            const std::string_view faint = color ? dim : std::string_view{};
            out << accent << label(d.severity) << normal;
            if (!d.code.empty()) out << "[" << d.code << "]";
            out << ": " << d.message << '\n';
            if (!p.file.empty()) {
                out << faint << "  --> " << normal << p.file;
                if (p.line) out << ':' << p.line << ':' << (p.column ? p.column : 1);
                out << '\n';
            }
            if (src && p.offset != std::string::npos && p.offset <= src->size()) {
                const auto start = p.offset == 0 ? std::string::npos : src->rfind('\n', p.offset - 1);
                const auto begin = start == std::string::npos ? 0 : start + 1;
                auto end = src->find('\n', p.offset);
                if (end == std::string::npos) end = src->size();
                const auto contextStart = begin < 2 ? std::string::npos : src->rfind('\n', begin - 2);
                const auto previousBegin = contextStart == std::string::npos ? 0 : contextStart + 1;
                const auto nextBegin = end < src->size() ? end + 1 : src->size();
                std::string_view raw(src->data() + begin, end - begin);
                const auto local = std::min(p.offset - begin, raw.size());
                const auto n = std::min(std::max<std::size_t>(p.length, 1), raw.size() - local);
                const std::string before = expandTabs(raw.substr(0, local));
                const std::string marked = expandTabs(raw.substr(local, n), before.size());
                const std::string after = expandTabs(raw.substr(local + n), before.size() + marked.size());
                const std::string gutter = std::to_string(p.line ? p.line : 1);
                if (begin != 0) {
                    const auto previous = expandTabs(std::string_view(src->data() + previousBegin,
                        begin - previousBegin - 1));
                    out << faint << ' ' << (p.line - 1) << " | " << normal << previous << '\n';
                }
                out << faint << ' ' << gutter << " | " << normal << before
                    << accent << marked << normal << after << '\n';
                out << faint << std::string(gutter.size() + 2, ' ') << "| " << normal
                    << std::string(before.size(), ' ') << accent
                    << std::string(std::max<std::size_t>(1, marked.size()), '^') << normal << '\n';
                if (nextBegin < src->size()) {
                    auto nextEnd = src->find('\n', nextBegin);
                    if (nextEnd == std::string::npos) nextEnd = src->size();
                    const auto next = expandTabs(std::string_view(src->data() + nextBegin,
                        nextEnd - nextBegin));
                    out << faint << ' ' << (p.line + 1) << " | " << normal << next << '\n';
                }
            }
            for (const auto& note : d.notes) out << "  = note: " << note << '\n';
            if (!d.help.empty()) out << "  = help: " << d.help << '\n';
        }
    }
    void Reporter::printSummary(std::ostream& out, ColorPolicy policy) const {
        (void)policy;
        out << count(Severity::Error) << " error(s), " << count(Severity::Warning)
            << " warning(s), " << count(Severity::Info) << " info message(s)\n";
    }
}
