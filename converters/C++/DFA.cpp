module Converter.DFA;
import DFA;
import corelib;
import dstd;
import std;
import std.compat;

void DFAConverter::createDFATable(const DFA &dfa, size_t count) {
    auto number_or_null = [](size_t index) {
        return index == std::numeric_limits<size_t>::max() ? std::string("DFA_NULL") : std::to_string(index);
    };
    bool token_type = true;
    std::ostringstream table_out;
    for (const auto &state : dfa.getStates()) {
        table_out << "{ " << number_or_null(state.else_goto) << ", " << number_or_null(state.else_goto_accept) << ", {\n";
        for (auto it = state.transitions.begin(); it != state.transitions.end(); it++) {
            const auto &transition = *it;
            table_out << "{";
            if (std::holds_alternative<stdu::vector<std::string>>(transition.first)) {
                token_type = true;
                const auto &symbol = std::get<stdu::vector<std::string>>(transition.first);
                table_out << '"' << corelib::text::join(symbol, "_") << '"' << ", " << transition.second.next << ", " << transition.second.accept_index;
            } else {
                token_type = false;
                const auto &symbol = std::get<char>(transition.first);
                table_out << "'" << corelib::text::getCharFromEscaped(symbol) << "'" << ", " << transition.second.next << ", " << transition.second.accept_index;
            }
            table_out << "}";
            if (std::next(it) != state.transitions.end()) {
                table_out << ", ";
            }
        }
        table_out << "} }\n";
    }
    out << (token_type ? "const DFATokenTable" : "DFACharTable") << " table_" << count << " = " << "{" << table_out.str() << "};\n";
}


void DFAConverter::create() {
    size_t count = 0;
    for (const auto &d : dfas) {
        createDFATable(d, count++);
    }
}
auto DFAConverter::get() -> std::ostringstream & {
    return out;
}

