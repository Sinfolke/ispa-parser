module Converter.DFA;
import DFA;
import corelib;
import dstd;
import std;
import std.compat;

void DFAConverter::createDFATable(const DFA &dfa, size_t count) {
    auto number_or_null = [this](size_t index) {
        return index == std::numeric_limits<size_t>::max() ? std::string("::" + namespace_name + "::DFA::null_state") : std::to_string(index);
    };
    bool token_type = true;
    std::ostringstream table_out;
    size_t max_states_count = dfa.getStates().size();
    size_t max_transition_count = 0;
    for (const auto &state : dfa.getStates()) {
        table_out << "{ " << number_or_null(state.else_goto) << ", " << number_or_null(state.else_goto_accept) << ", {\n";
        if (max_transition_count < state.transitions.size())
            max_transition_count = state.transitions.size();

        for (auto it = state.transitions.begin(); it != state.transitions.end(); it++) {
            const auto &transition = *it;
            table_out << "{";
            if (std::holds_alternative<stdu::vector<std::string>>(transition.first)) {
                token_type = true;
                const auto &symbol = std::get<stdu::vector<std::string>>(transition.first);
                table_out << "Tokens::" << corelib::text::join(symbol, "_") << ", " << transition.second.next << ", " << number_or_null(transition.second.accept_index);
            } else {
                token_type = false;
                const auto &symbol = std::get<char>(transition.first);
                table_out << "'" << corelib::text::getEscapedAsStr(symbol, false) << "'" << ", " << transition.second.next << ", " << number_or_null(transition.second.accept_index);
            }
            table_out << "}";
            if (std::next(it) != state.transitions.end()) {
                table_out << ", ";
            }
        }
        table_out << "} },\n";
    }
    out << "const " << namespace_name << "::" << (token_type ? "DFA::TokenTable" : "DFA::CharTable") << '<' << max_states_count << ", " << max_transition_count << "> "
    << namespace_name << "::" << prefix << "::" << name << '_' << count << " = " << "{" << table_out.str() << "};\n";
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

