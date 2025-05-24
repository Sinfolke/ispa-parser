/**
 * The Extended LR parser. ELR.cppm and ELR.cpp files reponse for generating LR(*) parser.
 */
export module ELRParser;
import LRParser;
import AST;
import hash;
import types;
import std;
import std.compat;
export class ELRParser : public LRParser {
    public:
        struct NFA_state {
            utype::unordered_map<vector<std::string>, size_t> transitions;
            std::optional<Action> reduce_action;
            bool is_starting_state = false;
            Action* place = nullptr;
            size_t epsilon_transition = 0;
        };
        struct DFA_state {
            std::set<size_t> nfa_states; // the NFA states this DFA state represents
            utype::unordered_map<vector<std::string>, size_t> transitions;
            std::optional<Action> action; // optional
            vector<Action*> places;
            size_t epsilon_transition = 0;
        };
        struct LookaheadOption {
            vector<std::variant<vector<std::string>, size_t>> token_sequence; // one possible sequence
            vector<vector<LookaheadOption>> nested;      // options after that
        };
        using Lookahead_set = vector<LookaheadOption>;
        void printNfa(const std::string filename);
        void printDfa(const std::string filename);
        bool isELR() const override;
        const vector<ELRParser::DFA_state>& getDFA() const;
    protected:
        vector<NFA_state> nfa_states;
        vector<DFA_state> dfa_states;
        void build() override;
        std::set<size_t> epsilon_closure(const std::set<size_t>& states);
        ELRParser::Lookahead_set getLookeaheadSet(const vector<std::string> &fullname, utype::unordered_set<vector<std::string>> &visited);
        void processLookaheadSet(const Lookahead_set &lookahead_set, size_t nfa_initial_index, const Action& action);
        public:
        ELRParser(AST *tree) : LRParser(tree, false) {
            build();
        }
        ELRParser(AST &tree) : LRParser(&tree, false) {
            build();
        }
};