
export module AST.types;
import hash;
import dstd;
import AST.API;
import LangAPI;
import std;
export namespace AST {
    enum class SpacemodeStates {
        MIXED, MANUAL, SKIPPED
    };
    using Name = stdu::vector<std::string>;
    using TreeMap = utype::unordered_map<stdu::vector<std::string>, AST::Rule>;
    using UsePlaceTable = utype::unordered_map<stdu::vector<std::string>, stdu::vector<stdu::vector<std::string>>>;
    using First = utype::unordered_map<stdu::vector<std::string>, std::set<stdu::vector<std::string>>>;
    using Follow = First;
    using InitialItemSet = utype::unordered_map<stdu::vector<std::string>, stdu::vector<AST::Rule>>;
    using NullableMap = utype::unordered_set<stdu::vector<std::string>>;
    using NameToIndexMap = utype::unordered_map<stdu::vector<std::string>, std::size_t>;
};
