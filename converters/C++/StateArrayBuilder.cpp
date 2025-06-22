module TransitionArrayBuilder;
import corelib;
import dstd;
import std;

void StateArrayBuilder::output() {
    auto number_or_null = [this](std::size_t index) {
        return index == std::numeric_limits<std::size_t>::max()
            ? "::" + namespace_name + "::DFA::null_state"
            : std::to_string(index);
    };
    std::size_t count = 0;
    const auto &dfa_compatible_table = lexer_data.getDfaCompatibleTable();
    for (const auto &t : data.first) {
        out << "\tDFA::" << DFA::getStateTypeStr(t, isToken) << '<' << t.size() << "> dfa_state_" << count++ << "{ ";
        cached_h_out << "\tDFA::" << DFA::getStateTypeStr(t, isToken) << '<' << t.size() << "> dfa_state_" << count++ << ";";
        std::size_t transition_index = 0;
        for (const auto &transition : t) {
            out << "\tDFA::" << dfa.getTransitionType(isToken) << " { ";

            if (std::holds_alternative<stdu::vector<std::string>>(transition.first)) {
                const auto &symbol = std::get<stdu::vector<std::string>>(transition.first);

                if (dfa_compatible_table.contains(symbol)) {
                    std::size_t dfa_index = dfa_compatible_table.at(symbol);
                    const std::string dfa_table_name = "dfa_span_" + std::to_string(dfa_index);
                    out << dfa_table_name << ", ";
                } else {
                    out << (isToken ? "&" : "Tokens::") << corelib::text::join(symbol, "_") << ", ";
                }
            } else {
                const auto &ch = std::get<char>(transition.first);
                out << "'" << corelib::text::getEscapedAsStr(ch, false) << "', ";
            }

            out << transition.second.next << ", "
                      << number_or_null(transition.second.accept_index) << " }";

            if (++transition_index != t.size())
                out << ",\n";
            else
                out << "\n";
        }

        out << "    } },\n";
    }
}

void StateArrayBuilder::outputHeader() const {
    h_out << cached_h_out.str();
}
