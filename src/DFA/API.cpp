module DFA.API;
import AST.API;
import AST.Pass;
import logging;
import std;


auto DFA::Comparator::compareNameWithCharacter(const stdu::vector<std::string> &name, const char c) const -> bool {
    AST::RuleMember ast_name_as_member {.value = AST::RuleMemberName {name} };
    AST::RuleMember ast_char_as_member {.value = AST::String {std::string(1, c)} };
    return AST::TreePass::prioritySort(tree, ast_name_as_member, ast_char_as_member);
}
auto DFA::Comparator::compareNameWithName(const stdu::vector<std::string> &first_name, const stdu::vector<std::string> &second_name) const -> bool {
    AST::RuleMemberName ast_first_name_as_member(AST::RuleMemberName {first_name});
    AST::RuleMemberName ast_second_name_as_member(AST::RuleMemberName {second_name});
    return AST::TreePass::prioritySort(tree, ast_first_name_as_member, ast_second_name_as_member);
}
auto DFA::Comparator::operator()(const NFA::TransitionKey &a, const NFA::TransitionKey &b) const -> bool {
    if (std::holds_alternative<char>(a) && std::holds_alternative<char>(b))
        return 0;
    if (std::holds_alternative<stdu::vector<std::string>>(a) && std::holds_alternative<char>(b)) {
        return compareNameWithCharacter(std::get<stdu::vector<std::string>>(a), std::get<char>(b));
    }
    if (std::holds_alternative<char>(a) && std::holds_alternative<stdu::vector<std::string>>(b)) {
        return compareNameWithCharacter(std::get<stdu::vector<std::string>>(b), std::get<char>(a));
    }
    if (std::holds_alternative<stdu::vector<std::string>>(a) && std::holds_alternative<stdu::vector<std::string>>(b)) {
        return compareNameWithName(std::get<stdu::vector<std::string>>(a), std::get<stdu::vector<std::string>>(b));
    }
    throw Error("Undefined transition Key sort condition");
}
auto DFA::Comparator::operator()(const std::pair<NFA::TransitionKey, TransitionValue> &a, const std::pair<NFA::TransitionKey, TransitionValue> &b) const -> bool {
    return operator()(a.first, b.first);
}