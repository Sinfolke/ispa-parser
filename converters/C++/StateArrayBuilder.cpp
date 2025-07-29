module StateArrayBuilder;
import corelib;
import DFATypes;
import NFA;
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
        auto dfa_table_type = dfas.getDFAS().at(data.state_in_dfa_location_map.at(count)).getType(isToken, dfa_compatible_table);
        auto type_str = DFATypes::getStateTypeStr(dfa_table_type, type, namespace_name, t.transitions.size());
        std::ostringstream out_content;
        std::size_t transition_index = 0;
        if (type != DFA::DfaType::NONE) {
            for (const auto &transition : t.transitions) {
                std::string transition_type;
                if (std::holds_alternative<stdu::vector<std::string>>(transition.first)) {
                    const auto &symbol = std::get<stdu::vector<std::string>>(transition.first);
                    if (dfa_compatible_table && dfa_compatible_table->contains(symbol) && dfa_compatible_table->at(symbol) != LexerBuilder::DFA_NOT_COMPATIBLE) {
                        std::size_t dfa_index = dfa_compatible_table->at(symbol);
                        out_content << "\tISPA_STD::DFAAPI::" << DFATypes(dfas.getDFAS()[dfa_index]).getTransitionsTypeStr(isToken, dfa_compatible_table, namespace_name) << " { ";
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
                            << std::boolalpha << transition.second.close_cst_node << ", "
                            << std::boolalpha << number_or_null(transition.second.new_group) << ", "
                            << std::boolalpha << number_or_null(transition.second.group_close) << ", "
                            << number_or_null(transition.second.accept_index)
                            << " }";

                if (++transition_index != t.transitions.size())
                    out_content << ",\n";
                else
                    out_content << "\n";
            }
        } else if (!t.rule_name.empty()) {
            out_content << "::" << namespace_name << "::Tokens::" << corelib::text::join(t.rule_name, "_") << ", [](const ::ISPA_STD::DFAAPI::MemberBegin &mb, const ::ISPA_STD::DFAAPI::GroupBegin &gb, const ::ISPA_STD::DFAAPI::" << DFATypes::getDataVectorType(dfa_table_type, namespace_name) << " &dv)\n\t{\n";
            if (std::holds_alternative<std::monostate>(t.dtb)) {
                out_content << "\t\treturn std::any {};\n";
            } else {
                out_content << "\t\tTypes::" << corelib::text::join(t.rule_name, "_") << " data;\n";
                if (std::holds_alternative<NFA::TemplatedDataBlock>(t.dtb)) {
                    for (const auto &data : std::get<NFA::TemplatedDataBlock>(t.dtb)) {
                        out_content << "\t\t::ISPA_STD::DFAAPI::";
                        if (data.second.first == NFA::StoreCstNode::CST_GROUP) {
                            out_content << "cst_group_store<Tokens>(data." << data.first << ", " << data.second.second << ", gb, dv);";
                        } else {
                            out_content << "cst_store<Tokens>(data." << data.first << ", " << data.second.second << ", mb, dv);";
                        }
                        out_content << '\n';
                    }
                } else if (std::holds_alternative<NFA::SingleValueDataBlock>(t.dtb)) {
                    const auto &data = std::get<NFA::SingleValueDataBlock>(t.dtb);
                    out_content << "\t\t::ISPA_STD::DFAAPI::";
                    if (data == NFA::StoreCstNode::CST_GROUP) {
                        out_content << "cst_group_store<Tokens>(data, 0, gb, dv);";
                    } else {
                        out_content << "cst_store<Tokens>(data, 0, mb, dv);";
                    }
                    out_content << "\n";
                }
                out_content << "\t\treturn std::make_any<Types::" << corelib::text::join(t.rule_name, "_") << ">(data);\n";
            }
            out_content << "\t}\n";
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
