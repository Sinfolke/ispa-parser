module StateArrayBuilder;
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
        auto type = DFA::getStateType(t, &dfa_compatible_table, isToken);
        auto type_str = DFA::getStateTypeStr(t, &dfa_compatible_table, isToken);
        std::ostringstream out_content;
        std::size_t transition_index = 0;
        if (type != DFA::DfaType::NONE) {
            for (const auto &transition : t) {
                std::string transition_type;
                if (std::holds_alternative<stdu::vector<std::string>>(transition.first)) {
                    const auto &symbol = std::get<stdu::vector<std::string>>(transition.first);
                    if (dfa_compatible_table.contains(symbol)) {
                        std::size_t dfa_index = dfa_compatible_table.at(symbol);
                        out_content << "\tDFA::" << lexer_data.getDFAS().getDFAS()[dfa_index].getTypeStr(isToken) << "Transition { ";
                        const std::string dfa_table_name = "dfa_span_" + std::to_string(dfa_index);
                        out_content << dfa_table_name;
                    } else {
                        if (isToken) {
                            out_content << "\tDFA::CallableTokenTransition { ";
                        } else {
                            out_content << "\tDFA::TokenTransition { ";
                        }
                        out_content << (isToken ? "&" : "Tokens::") << corelib::text::join(symbol, "_");
                    }
                } else {
                    out_content << "\tDFA::CharTransition { ";
                    const auto &ch = std::get<char>(transition.first);
                    out_content << "'" << corelib::text::getEscapedAsStr(ch, false) << "'";
                }
                out_content << ", ";
                out_content << transition.second.next << ", "
                          << number_or_null(transition.second.accept_index) << " }";

                if (++transition_index != t.size())
                    out_content << ",\n";
                else
                    out_content << "\n";
            }
        }

        out << "const ::" << namespace_name << "::DFA::" << type_str << (type != DFA::DfaType::NONE ? std::string("<") + std::to_string(t.size()) + ">" :  "")
            << ' ' << namespace_name << "::" << prefix << "::dfa_state_" << count++ << " = {\n" << out_content.str() << "};\n";
    }
}

void StateArrayBuilder::outputHeader() {
    std::size_t count = 0;
    const auto dfa_compatible_table = lexer_data.getDfaCompatibleTable();
    for (const auto &t : data.first) {
        out << "\t\tstatic const DFA::" << DFA::getStateTypeStr(t, &dfa_compatible_table, isToken) << (DFA::getStateType(t, &dfa_compatible_table, isToken) != DFA::DfaType::NONE ? std::string("<") + std::to_string(t.size()) + ">" : "")
            << " dfa_state_" << count++ << ";\n";
    }
}
