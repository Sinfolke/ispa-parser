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
    stdu::vector<FailBlock> fail_blocks;
    stdu::vector<FrontendFeature> rule_features;
    SpacemodeStates spacemode = SpacemodeStates::MIXED;
    std::string name;
    UAST::main input;
    std::string file;
    std::vector<std::string> source_files;
    stdu::vector<std::string> fullname;
    using Members = stdu::vector<std::shared_ptr<AST::RuleMember>>;
    using Value = UAST::rule_value;
    using Pattern = UAST::rule_value_pattern;
    using Grammar = UAST::grammar;
    using Rule = UAST::rule;

    AST::RuleMember convertPattern(const Pattern& pattern);
    AST::RuleMember convertValue(const Value& value);
    AST::RuleMember convertCapture(const UAST::rule_value_one_capture& value);
    AST::DataBlock convertData(const UAST::Node<UAST::rule_ast>& data);
    void convertGrammar(const Grammar& grammar);
    void convertRule(const Rule& rule);
    void convertMain(const UAST::main& main);

public:
    // UAST::main is the generated Parser::Types::main. `file` only labels positions.
    explicit Builder(const UAST::main& mod, std::string file = {}) : input(mod), file(std::move(file)) {}
    explicit Builder(const ::ISPA_STD::Node<Parser::Types::main>& mod, std::string file = {})
        : input(mod.data()), file(std::move(file)) {}
    // One source label per top-level input entry, for multi-file CLI inputs.
    void setSourceFiles(std::vector<std::string> files) {
        if (files.size() != input.value.size()) throw std::invalid_argument("AST source file count does not match input entries");
        source_files = std::move(files);
    }
    void build();
    auto get() -> Tree {
        Tree tree{std::move(name), std::move(spacemode), std::move(tree_map)};
        tree.getFailBlocks() = std::move(fail_blocks);
        return tree;
    }
};
}
