/**
 * The Extended LR parser. ELR.h and ELR.cpp files reponse for generating LR(*) parser. 
 */
#pragma once
#include <LRParser.h>
#include <optional>
#include <variant>
class ELRParser : public LRParser {
    public:
        struct NFA_state {
            std::unordered_map<std::vector<std::string>, size_t> transitions;
            std::optional<Action> reduce_action;
            bool is_starting_state = false;
            Action* place = nullptr;
            size_t epsilon_transition = 0;
        };
        struct DFA_state {
            std::set<size_t> nfa_states; // the NFA states this DFA state represents
            std::unordered_map<std::vector<std::string>, size_t> transitions;
            std::optional<Action> action; // optional
            std::vector<Action*> places;
        };
        struct LookaheadOption {
            std::vector<std::variant<std::vector<std::string>, std::vector<LookaheadOption>*>> token_sequence; // one possible sequence
            std::vector<std::vector<LookaheadOption>> nested;      // options after that
        };
        using Lookahead_set = std::vector<LookaheadOption>;
        void printNfa(const std::string filename);
        void printDfa(const std::string filename);
        bool isELR() const override;
        const std::vector<ELRParser::DFA_state>& getDFA() const;
    protected:
        std::vector<NFA_state> nfa_states;
        std::vector<DFA_state> dfa_states;
        void build() override;
        std::set<size_t> epsilon_closure(const std::set<size_t>& states);
        ELRParser::Lookahead_set getLookeaheadSet(const std::vector<std::string> &fullname, std::unordered_set<std::vector<std::string>> &visited);
        void processLookaheadSet(const Lookahead_set &lookahead_set, size_t nfa_initial_index, const Action& action);
        public:
        ELRParser(Tree *tree) : LRParser(tree, false) {
            build();
        }
        ELRParser(Tree &tree) : LRParser(&tree, false) {
            build();
        }
};