module StateArrayBuilder;
import corelib;
import DFATypes;
import cpuf.printf;
import dstd;
import std;

void StateArrayBuilder::output() {
    auto number_or_null = [this](std::size_t index) {
        return index == std::numeric_limits<std::size_t>::max()
            ? "::ISPA_STD::DFAAPI::null_state"
            : std::to_string(index);
    };
    std::size_t count = 0;
    for (const auto &t : data.state_set) {
        auto type = DFA::getStateType(t.transitions, dfa_compatible_table, isToken);
        cpuf::printf("count {}: {}", count, (int) dfas.getDFAS().at(data.state_in_dfa_location_map.at(count)).getType(isToken));
        auto type_str = DFATypes::getStateTypeStr(dfas.getDFAS().at(data.state_in_dfa_location_map.at(count)).getType(isToken), type, namespace_name, t.transitions.size());
        std::ostringstream out_content;
        std::size_t transition_index = 0;
        if (type != DFA::DfaType::NONE) {
            for (const auto &transition : t.transitions) {
                std::string transition_type;
                if (std::holds_alternative<stdu::vector<std::string>>(transition.first)) {
                    const auto &symbol = std::get<stdu::vector<std::string>>(transition.first);
                    if (dfa_compatible_table && dfa_compatible_table->contains(symbol)) {
                        std::size_t dfa_index = dfa_compatible_table->at(symbol);
                        out_content << "\tISPA_STD::DFAAPI::" << DFATypes(dfas.getDFAS()[dfa_index]).getTransitionsTypeStr(isToken, namespace_name) << " { ";
                        const std::string dfa_table_name = "dfa_span_" + std::to_string(dfa_index);
                        out_content << dfa_table_name;
                    } else {
                        if (isToken) {
                            out_content << "\tISPA_STD::DFAAPI::" << DFATypes::getTransitionKeyTypeStr(DFA::DfaType::CallableToken, namespace_name);
                        } else {
                            out_content << "\tISPA_STD::DFAAPI::" << DFATypes::getTransitionKeyTypeStr(DFA::DfaType::Token, namespace_name);
                        }
                        out_content << " { " << (isToken ? "&" : "Tokens::") << corelib::text::join(symbol, "_");
                    }
                } else {
                    out_content << "\tISPA_STD::DFAAPI::CharTransition { ";
                    const auto &ch = std::get<char>(transition.first);
                    out_content << "'" << corelib::text::getEscapedAsStr(ch, false) << "'";
                }
                out_content << ", ";
                out_content << transition.second.next << ", "
                            << std::boolalpha << transition.second.new_cst_node << ", "
                            << std::boolalpha << transition.second.new_member << ", "
                            << number_or_null(transition.second.accept_index)
                            << " }";

                if (++transition_index != t.transitions.size())
                    out_content << ",\n";
                else
                    out_content << "\n";
            }
        }
        out << "const ::ISPA_STD::DFAAPI::" << type_str
            << ' ' << namespace_name << "::" << prefix << "::dfa_state_" << count++ << " = {\n" << out_content.str() << "};\n";
    }
}

void StateArrayBuilder::outputHeader() {
    std::size_t count = 0;
    for (const auto &t : data.state_set) {
        auto str = DFATypes(dfas.getDFAS().at(data.state_in_dfa_location_map.at(count))).getStateTypeStr(t.transitions, dfa_compatible_table, isToken, namespace_name, t.transitions.size());
        if (str == "")
            continue;
        out << "\t\tstatic const ISPA_STD::DFAAPI::" << str << " dfa_state_" << count++ << ";\n";
    }
}
