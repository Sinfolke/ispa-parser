module Converter.DFA;
import DFA;
import corelib;
import logging;
import cpuf.printf;
import dstd;
import std;
import std.compat;

void DFAConverter::createDFATable(const DFA &dfa, size_t count) {
    auto number_or_null = [this](size_t index) {
        return index == std::numeric_limits<size_t>::max()
            ? "::" + namespace_name + "::DFA::null_state"
            : std::to_string(index);
    };

    std::ostringstream table_out;

    const auto &states = dfa.getStates();
    size_t max_states_count = states.size();
    size_t max_transition_count = dfa.getMaxTransitionCount();

    for (const auto &state : states) {

        table_out << "\tDFA::" << dfa.getStateType(isToken) << '<' << max_transition_count << '>' << "{ "
                  << number_or_null(state.else_goto) << ", "
                  << number_or_null(state.else_goto_accept) << ", {\n";

        size_t transition_index = 0;
        for (const auto &transition : state.transitions) {
            table_out << "\tDFA::" << dfa.getTransitionType(isToken) << " { ";

            if (std::holds_alternative<stdu::vector<std::string>>(transition.first)) {
                const auto &symbol = std::get<stdu::vector<std::string>>(transition.first);

                if (dfa_compatible_table && dfa_compatible_table->contains(symbol)) {
                    size_t dfa_index = dfa_compatible_table->at(symbol);
                    const std::string dfa_table_name = "dfa_table_" + std::to_string(dfa_index);
                    table_out << "DFA::Span" << dfas[dfa_index].getTypeStr(isToken)
                              << "(" << dfa_table_name << "), ";
                } else {
                    cpuf::printf("symbol {} not contained", symbol);
                    table_out << (isToken ? "&" : "Tokens::") << corelib::text::join(symbol, "_") << ", ";
                }
            } else {
                const auto &ch = std::get<char>(transition.first);
                table_out << "'" << corelib::text::getEscapedAsStr(ch, false) << "', ";
            }

            table_out << transition.second.next << ", "
                      << number_or_null(transition.second.accept_index) << " }";

            if (++transition_index != state.transitions.size())
                table_out << ",\n";
            else
                table_out << "\n";
        }

        table_out << "    } },\n";
    }

    out << "const ::" << namespace_name << "::DFA::" << dfa.getTypeStr(isToken)
        << "<" << max_states_count << ", " << max_transition_count << "> "
        << namespace_name << "::" << prefix << "::" << name << '_' << count
        << " = {\n" << table_out.str() << "};\n";
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

