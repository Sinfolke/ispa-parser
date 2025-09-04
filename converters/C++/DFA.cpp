module Converter.DFA;
import DFA.API;
import DFA.Base;
import DFA.MachineDFA;
import corelib;
import logging;
import cpuf.printf;
import DFATypes;
import dstd;
import std;

void DFAConverter::createDFATable(const DFA::MachineDFA &dfa, std::size_t count) {
    auto number_or_null = [this](std::size_t index) {
        return index == std::numeric_limits<std::size_t>::max()
            ? "::ISPA_STD::DFAAPI::null_state"
            : std::to_string(index);
    };

    std::ostringstream table_out;

    const auto &states = dfa.get();
    auto type = dfa.getType(isToken, dfa_compatible_table);
    std::size_t state_count = 0;

    for (const auto &state : states) {
        auto find = state_set.location_in_set.find(std::make_pair(count, state_count++));
        if (find == state_set.location_in_set.end())
            continue;
        std::string state_name = "dfa_state_" + std::to_string(find->second);
        auto state_type = DFA::Base::getStateType(state.transitions, dfa_compatible_table, isToken);
        auto state_type_str = DFATypes(dfa).getSpanStateTypeStr(state.transitions, dfa_compatible_table, namespace_name, isToken);

        if (state_type == DFA::DfaType::NONE && type != DFA::DfaType::Token) {
            table_out << '\t' << state_name << ",\n";
        } else {
            if (state_type == DFA::DfaType::NONE) {
                // empty state - initialize with empty type or with SpanEmptyState
                if (type != DFA::DfaType::Multi) {
                    state_type_str = DFATypes(dfa).getSpanStateTypeStr(type, type, namespace_name);
                    state_type = type;
                }
            }
            table_out << "\tISPA_STD::DFAAPI::Span" << state_type_str;
            if (state_type != DFA::DfaType::NONE) {
                table_out << "{ "
                          << state.else_goto << ", "
                          << number_or_null(state.else_goto_accept)
                          << ", ";
                table_out << (state.transitions.empty() ? "{nullptr, 0}" : "{" + state_name + ".data(), " + state_name + ".size()}");
                table_out << "},\n";
            }
        }
    }

    out << "const ::ISPA_STD::DFAAPI::" << DFATypes::getTypeStr(type, namespace_name, states.size())
        << ' ' << namespace_name << "::" << prefix << "::" << name << '_' << count
        << " = {\n" << table_out.str() << "};\n";
}


void DFAConverter::create() {
    std::size_t count = 0;
    for (const auto &d : dfas) {
        createDFATable(d, count++);
    }
}
auto DFAConverter::get() -> std::ostringstream & {
    return out;
}

