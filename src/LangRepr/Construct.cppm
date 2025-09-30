export module LangRepr.Construct;

import LangRepr.Holder;

import LexerBuilder;
import LangAPI;
import LLIR.API;
import LLIR.IR;
import hash;

import boost;
import cpuf.printf;

import dstd;
import std;
export namespace LangRepr {
    class Construct {
        Holder holder;
        LexerBuilder lexer_builder;
        LLIR::IR ir;
        LangAPI::Language lang;
        const std::string &namespace_name;
        auto constructTokensAndRulesEnum() -> void;
        auto constructTokensAndRulesEnumToString() -> void;
        auto constructTypesNamespace() -> void;
        using Name = stdu::vector<std::string>;
                class Node {
        public:
            using ChildT = std::unordered_map<std::string, std::unique_ptr<Node>>;
        private:
            template<typename Func>
            auto visit(Func func, Name &fullname) const -> void {
                for (const auto &[name, child] : children) {
                    fullname.push_back(name);
                    if (func(fullname, *child)) return;
                    child->visit(func, fullname);
                    fullname.pop_back();
                }
            }
            template<typename Func>
            auto visit(Func func, Name &fullname) -> void {
                for (auto &[name, child] : children) {
                    fullname.push_back(name);
                    if (func(fullname, *child)) return;
                    child->visit(func, fullname);
                    fullname.pop_back();
                }
            }
        public:
            ChildT children;
            LLIR::DataBlock data;
            auto find(const Name &name) const -> const Node* {
                const Node* current = this;
                for (const auto& part : name) {
                    if (!current->children.contains(part)) return nullptr;
                    auto& child = current->children.at(part);
                    current = child.get();
                }
                return current;
            }
            auto find_or_emplace(const Name &name) -> Node* {
                Node* current = this;
                for (const auto& part : name) {
                    auto& child = current->children[part];
                    if (!child) child = std::make_unique<Node>();
                    current = child.get();
                }
                return current;
            }
            template<typename Func>
            auto visit(Func func) const -> void {
                Name fullname;
                for (const auto &[name, child] : children) {
                    fullname.push_back(name);
                    if (func(fullname, *child)) return;
                    child->visit(func, fullname);
                    fullname.pop_back();
                }
            }
            template<typename Func>
            auto visit(Func func) -> void {
                Name fullname;
                for (auto &[name, child] : children) {
                    fullname.push_back(name);
                    if (func(fullname, *child)) return;
                    child->visit(func, fullname);
                    fullname.pop_back();
                }
            }
        };
        class SortedNode {
        public:
            using ChildT = boost::container::flat_map<std::string, std::unique_ptr<SortedNode>>;
        private:
            template<typename Func>
            auto visit(Func func, Name &fullname) const -> void {
                for (const auto &[name, child] : children) {
                    fullname.push_back(name);
                    if (func(fullname, *child)) return;
                    child->visit(func, fullname);
                    fullname.pop_back();
                }
            }
            template<typename Func>
            auto visit(Func func, Name &fullname) -> void {
                for (auto &[name, child] : children) {
                    fullname.push_back(name);
                    if (func(fullname, *child)) return;
                    child->visit(func, fullname);
                    fullname.pop_back();
                }
            }
        public:
            ChildT children;
            LLIR::DataBlock data;
        };
        auto collectReferencedNames(const LangAPI::Type &type) -> std::pair<utype::unordered_map<Name, std::size_t>, utype::unordered_set<Name>> {
            utype::unordered_map<Name, std::size_t> out;
            utype::unordered_set<Name> to_forward_declare;
            std::function<void(const LangAPI::Type&, bool)> walk = [&](const LangAPI::Type &t, bool inside_array = false) {
                if (t.isSymbol()) {
                    const auto &sym = t.getSymbol();
                    Name n;
                    n.reserve(sym.path.size());
                    for (const auto &part : sym.path) {
                        if (!std::holds_alternative<std::string>(part)) return; // skip function-based paths
                        n.push_back(std::get<std::string>(part));
                    }
                    if (!n.empty()) ++out[n];
                } else if (t.isValueType() && t.getValueType() == LangAPI::ValueType::Array) {
                    for (const auto &param : t.template_parameters) {
                        if (std::holds_alternative<LangAPI::Type>(param)) {
                            walk(std::get<LangAPI::Type>(param), true);
                        }
                    }
                } else {
                    for (const auto &param : t.template_parameters) {
                        if (std::holds_alternative<LangAPI::Type>(param)) {
                            walk(std::get<LangAPI::Type>(param), false);
                        }
                    }
                }
            };
            walk(type, false);
            return std::make_pair(out, to_forward_declare);
        }
    public:
        Construct(LexerBuilder &&lexer_builder, LLIR::IR &&ir, LangAPI::Language lang, const std::string &namespace_name)
        : lexer_builder(std::move(lexer_builder)), ir(std::move(ir)), lang(lang), namespace_name(namespace_name) {}

        auto construct() -> Holder&;
        static auto construct(LexerBuilder &&lexer_builder, LLIR::IR &&ir, LangAPI::Language lang, const std::string &namespace_name) -> Holder;
    };

}
