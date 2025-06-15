export module LexerBuilder;
import AST.API;
import AST.Tree;
import DFA;
import LLIR.API;
import fcdt;
import dstd;
import std;
export class LexerBuilder {
    AST::Tree &ast;
    stdu::vector<DFA> dfas;
    stdu::vector<DFA> function_dfas;
    std::vector<LLIR::Data> functions;
    FCDT fcdt;
    bool isDfaCompatible(const stdu::vector<AST::RuleMember> &member);
public:
    LexerBuilder(AST::Tree &ast) : ast(ast), fcdt(ast) {};
    void build();

};