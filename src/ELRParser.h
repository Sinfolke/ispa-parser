/**
 * The Extended LR parser. ELR.h and ELR.cpp files reponse for generating LR(*) parser. 
 */
#pragma once
#include <LRParser.h>
#include <optional>
class ELRParser : public LRParser {
    public:
        struct NFA_state {
            std::unordered_map<std::vector<std::string>, std::vector<size_t>> transitions;
            std::optional<Action> reduce_action;
            bool is_starting_state = false;
            Action* place = nullptr;
        };
        struct DFA_state {
            std::set<size_t> nfa_states; // the NFA states this DFA state represents
            std::unordered_map<std::vector<std::string>, size_t> transitions;
            std::optional<Action> action; // optional
            std::vector<Action*> places;
        };
        
        void printNfa(const std::string filename);
        void printDfa(const std::string filename);
        bool isELR() const override;
        const std::vector<ELRParser::DFA_state>& getDFA() const;
    protected:
        std::vector<NFA_state> nfa_states;
        std::vector<DFA_state> dfa_states;
        void build() override;
        std::set<size_t> epsilon_closure(const std::set<size_t>& states);
        public:
        ELRParser(Tree *tree) : LRParser(tree, false) {
            build();
        }
        ELRParser(Tree &tree) : LRParser(&tree, false) {
            build();
        }
};