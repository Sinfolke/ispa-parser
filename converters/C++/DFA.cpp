module Converter.DFA;
import DFA;
import corelib;
import logging;
import cpuf.printf;
import dstd;
import std;
import std.compat;

void DFAConverter::createDFATable(const DFA &dfa, std::size_t count) {
    auto number_or_null = [this](std::size_t index) {
        return index == std::numeric_limits<std::size_t>::max()
            ? "::" + namespace_name + "::DFA::null_state"
            : std::to_string(index);
    };

    std::ostringstream table_out;

    const auto &states = dfa.getStates();
    std::size_t state_count = 0;

    for (const auto &state : states) {
        table_out << "\tDFA::Span" << DFA::getStateTypeStr(state.transitions, isToken) << "{ "
                  << number_or_null(state.else_goto) << ", "
                  << number_or_null(state.else_goto_accept) << ", "
                  << (state.transitions.empty() ? "{}" : "&dfa_state_" + std::to_string(location_map.at({count, state_count})));
        table_out << "\t},\n";
        state_count++;
    }

    out << "const ::" << namespace_name << "::DFA::" << dfa.getTypeStr(isToken) << " "
        << namespace_name << "::" << prefix << "::" << name << '_' << count
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

