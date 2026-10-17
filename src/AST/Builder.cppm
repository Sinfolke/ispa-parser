module;
#include <output/Parser.h>
export module AST.Builder;
import AST.types;
import AST.API;
import AST.Tree;
import dstd;
import hash;

export namespace AST {
class Builder {
    TreeMap tree_map;
    SpacemodeStates spacemode = SpacemodeStates::MIXED;
    std::string name;
    Use use;
    const Parser::Types::main* root = nullptr;
    stdu::vector<std::string> fullname;
    bool allowDeferredReferences = false;
    using Members = stdu::vector<std::shared_ptr<AST::RuleMember>>;
    using Value = Parser::FlatTypes::rule_value;
    using Pattern = Parser::FlatTypes::rule_value_pattern;
    using Grammar = Parser::FlatTypes::grammar;
    using Rule = Parser::FlatTypes::rule;

    AST::RuleMember convertPattern(const Pattern& pattern);
    AST::RuleMember convertValue(const Value& value);
    AST::DataBlock convertData(const ::ISPA_STD::Node<Parser::Rules, Parser::FlatTypes::rule_ast>& data);
    // "rule.value" / "rule::value" / {"rule","value"} -> {"rule","value"}
    static Name normalizeReference(const Name& reference);

    static std::string printable(const Name& parts);

    // Lexical lookup: innermost scope -> enclosing scopes -> global.
    std::optional<Name> tryResolve(const Name& ref) const;

    Name resolveName(const Name& rawReference) const;

    // First pass: recursively declare every ordinary rule before converting any
    // pattern. This makes forward references and references to later siblings work.
    void predeclareGrammar(const Grammar& grammar);
    void convertGrammar(const Grammar& grammar);
    void convertRule(const Rule& rule);
    void convertMain(const Parser::Types::main& main);

public:
    explicit Builder(const Parser::Types::main& mod) : root(&mod) {}
    explicit Builder(const ::ISPA_STD::Node<Parser::Rules, Parser::Types::main>& mod)
        : root(&mod.data()) {}
    void build();
    auto get() -> Tree { return {std::move(name), std::move(spacemode), std::move(use), std::move(tree_map)}; }
};
}
