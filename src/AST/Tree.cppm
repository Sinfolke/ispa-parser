export module AST.Tree;
import AST.types;
import AST.API;
import corelib;
import Parser;
import hash;
import dstd;
import std;
import std.compat;
export namespace AST {
    /*
     * Tree class that holds features could be done on it. Contains tree_map map
     */
    class Tree {
    private:
        TreeMap tree_map;
        SpacemodeStates spacemode = SpacemodeStates::MIXED;
        Use use;
        std::string name;
        InitialItemSet initial_item_set;
        UsePlaceTable use_places;
        utype::unordered_set<stdu::vector<std::string>> nullable;
        First first;
        Follow follow;

        static auto compute_group_length(const stdu::vector<AST::RuleMember> &group) -> size_t;
        void getUsePlacesTable(const stdu::vector<AST::RuleMember> &members, const stdu::vector<std::string> &name);
        void transform_helper(
            stdu::vector<AST::RuleMember> &members,
            const stdu::vector<std::string> &fullname,
            const stdu::vector<std::string> &original_fullname,
            utype::unordered_map<stdu::vector<std::string>, std::pair<char, stdu::vector<std::string>>> &replacements
        );
        void transform();
        void createInitialItemSet();
        auto createUsePlacesTable() -> UsePlaceTable&;
        void computeNullableSet();
        void constructFirstSet(const stdu::vector<AST::Rule>& options, const stdu::vector<std::string> &nonterminal, bool &changed);
        void constructFirstSet();
        void constructFollowSet();
        void formatFirstOrFollowSet(std::ostringstream &oss, AST::First &set);
    public:
        auto getTreeMap() const -> const TreeMap& { return tree_map; };
        auto getUse() const -> const Use& { return use; };
        auto getSpacemode() const -> const SpacemodeStates& { return spacemode; };
        auto getName() const -> const std::string& { return name; }
        auto getTreeMap() ->  TreeMap& { return tree_map; };
        auto getUse() ->  Use& { return use; };
        auto getSpacemode() -> SpacemodeStates& { return spacemode; };
        auto getName() -> std::string& { return name; }
        auto begin() const { return tree_map.begin(); };
        auto end() const { return tree_map.end(); };
        Tree(std::string&& name, SpacemodeStates&& spacemode, Use&& use, TreeMap&& map)
            : name(std::move(name)),
              spacemode(std::move(spacemode)),
              use(std::move(use)),
              tree_map(std::move(map)) {}
        Tree(std::string& name, SpacemodeStates& spacemode, Use& use, TreeMap& map)
            : name(name),
              spacemode(spacemode),
              use(use),
              tree_map(map) {}
        ~Tree() = default;
        auto getUsePlacesTable() -> UsePlaceTable& {
            if (use_places.empty())
                createUsePlacesTable();
            return use_places;
        };
        auto getFirstSet()-> First& {
            if (first.empty())
                constructFirstSet();
            return first;
        };
        auto getFollowSet() -> Follow& {
            if (follow.empty())
                constructFollowSet();
            return follow;
        };
        auto getRawFirstSet()-> First& { return first; };
        auto getRawFollowSet() -> Follow& { return follow; };
        auto getCodeForLexer() -> lexer_code;
        auto getInitialItemSet() -> InitialItemSet&;
        auto getTerminals() -> stdu::vector<stdu::vector<std::string>>;
        auto getNonTerminals() -> stdu::vector<stdu::vector<std::string>>;

        void printFirstSet(const std::string &fileName);
        void printFollowSet(const std::string &fileName);

        auto operator[](const stdu::vector<std::string> &name) const -> const Rule& {
            return tree_map.at(name);
        }
    };
};