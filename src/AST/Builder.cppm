module;
#include <output/Parser.h>
export module AST.Builder;
import AST.types;
import AST.API;
import AST.Tree;
import dstd;
import hash;
import UAST;
import UAST.Parser;

export namespace AST {
class Builder {
    TreeMap tree_map;
    SpacemodeStates spacemode = SpacemodeStates::MIXED;
    std::string name;
    Use use;
    UAST::main input;
    const UAST::main* root = &input;
    stdu::vector<std::string> fullname;
    bool allowDeferredReferences = false;
    using Members = stdu::vector<std::shared_ptr<AST::RuleMember>>;
    using Value = UAST::rule_value;
    using Pattern = UAST::rule_value_pattern;
    using Grammar = UAST::grammar;
    using Rule = UAST::rule;

    AST::RuleMember convertPattern(const Pattern& pattern);
    AST::RuleMember convertValue(const Value& value);
    AST::RuleMember convertCapture(const UAST::rule_value_one_capture& value);
    AST::DataBlock convertData(const UAST::Node<UAST::rule_ast>& data);
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
    void convertMain(const UAST::main& main);

public:
    explicit Builder(const UAST::main& mod) : input(mod) {}
    explicit Builder(const Parser::Types::main& mod) : input(UAST::fromParser(mod)) {}
    explicit Builder(const ::ISPA_STD::Node<Parser::Types::main>& mod)
        : input(UAST::fromParser(mod.data())) {}
    void build();
    auto get() -> Tree { return {std::move(name), std::move(spacemode), std::move(use), std::move(tree_map)}; }
};
}
