module DFASpans;

import DFATypes;
import DFA.API;
import std;


void DFASpans::output(bool isToken, const std::string &name) const {
    std::size_t count = 0;
    for (const auto &dfa : dfas.get()) {
        const auto span_type = dfa.getType(isToken, dct);
        const std::string span_type_str = DFATypes::getSpanTypeStr(span_type, namespace_name);

        const std::string table_name = "dfa_table_" + std::to_string(count);

        out << "const ::ISPA_STD::DFAAPI::" << span_type_str << " "
            << namespace_name << "::" << name << "::dfa_span_" << count << " = {\n";
        if (span_type == DFA::DfaType::Multi)
            out << "\t{ ";
        out << "\t" << table_name << ".data(), " << table_name << ".size()";
        if (span_type == DFA::DfaType::Multi)
            out << " }\n";
        else
            out << "\n";
        out << "};\n";

        ++count;
    }
}
void DFASpans::outputH(bool isToken) const {
    std::size_t count = 0;
    for (const auto &dfa : dfas.get()) {
        const std::string span_type = DFATypes::getSpanTypeStr(dfa.getType(isToken, dct), namespace_name);

        const std::string table_name = "dfa_table_" + std::to_string(count);

        out << "\t\tstatic const ::ISPA_STD::DFAAPI::" << span_type << " dfa_span_" << count << ";\n";

        ++count;
    }
}