export module Algorithm.CBinding;
import AST.Tree;
import LRBase;
import std;
export using AlgorithmCreateFn = auto(AST::Tree*, std::size_t) -> LRBase*;
export using AlgorithmFinishFn = auto(LRBase*) -> void;
