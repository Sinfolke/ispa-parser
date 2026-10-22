#include <gtest/gtest.h>
#include <ispa/parser.h>
import AST.Builder;
import AST.Pass;
import AST.Tree;
import LRParser;
import LALRParser;
import LR_STARParser;
import std;

// Call each out-of-line constructor from outside its DLL. The plugin factories
// call constructors inside the DLL and cannot catch missing Windows exports.
TEST(ParserLinkage, LRFamilyConstructorsAreAvailableToModuleImporters) {
    IspaParser parser;
    AST::Builder builder(parser.parse("A:'a'; main:A;"), "linkage.isc");
    builder.build();
    auto tree = builder.get();
    AST::TreePass pass(tree);
    pass.work();

    LRParser lr_pointer(&tree);
    LRParser lr_reference(tree);
    LRParser lr_cached(&tree, 1, lr_pointer.saveCache());
    EXPECT_FALSE(lr_pointer.getProductions().empty());
    EXPECT_EQ(lr_reference.getGotoTable(), lr_pointer.getGotoTable());
    EXPECT_EQ(lr_cached.getGotoTable(), lr_pointer.getGotoTable());

    LALRParser lalr_pointer(&tree);
    LALRParser lalr_reference(tree);
    LALRParser lalr_cached(&tree, 1, lalr_pointer.saveCache());
    EXPECT_FALSE(lalr_pointer.getProductions().empty());
    EXPECT_EQ(lalr_reference.getGotoTable(), lalr_pointer.getGotoTable());
    EXPECT_EQ(lalr_cached.getGotoTable(), lalr_pointer.getGotoTable());

    LR_STARParser star_pointer(&tree);
    LR_STARParser star_reference(tree);
    EXPECT_FALSE(star_pointer.isSupported());
    EXPECT_FALSE(star_reference.isSupported());
}
