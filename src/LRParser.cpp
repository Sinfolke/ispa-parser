#include <LRParser.h>
auto LRParser::begin() -> Parser::Tree::iterator {
    return tree->getRawTree().begin();
}
auto LRParser::end() -> Parser::Tree::iterator {
    return tree->getRawTree().end();
}
void LRParser::addAugmentedRule() {
    tree->getRawTree().push_back(Tokens::make_rule(Parser::Rules::Rule, obj_t {
        {"name", Tokens::make_rule(Parser::Rules::id, std::string("S'"))},
        {"rule", std::vector<Parser::Rule>{Tokens::make_rule(Parser::Rules::Rule_other, rule_other {std::string("main"), {std::string("main")}})}},
        {"nestedRules", std::vector<Parser::Rule> {}}
    }));
}
void LRParser::get_item_set(const Parser::Rule &rule, std::vector<rule_other> &item_set) {
    Parser::Rule arule;
    if (rule.name == Parser::Rules::Rule_rule) {
        arule = Tokens::getValueFromRule_rule(rule);
    } else {
        arule = rule;
    }
    auto arule_data = std::any_cast<rule_other>(arule.data);
    item_set.push_back(arule_data);
    if (corelib::text::isLower(arule_data.name)) {
        auto rule = Tokens::find_token_in_tree(tree->getRawTree(), arule_data.fullname);
        if (rule == nullptr) {
            throw Error("Not found requested rule");
        }
        auto data = std::any_cast<obj_t>(rule->data);
        auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
        get_item_set(rules[0], item_set);
    }
}
// since map cannot store std::vector<std::string> as key use std::vector<std::pair>
void LRParser::construct_initial_item_set(Parser::Tree &tree, InitialItemSet &initial_item_set, std::vector<std::string> &fullname) {
    for (auto &member : tree) {
        if (member.name != Parser::Rules::Rule)
            continue;
        auto data = std::any_cast<obj_t>(member.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
        auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        // do not include tokens
        if (corelib::text::isUpper(name_str) && name_str != "S'")
            continue;
        fullname.push_back(name_str);
        std::vector<std::vector<rule_other>> item_sets;
        std::vector<rule_other> item_set;
        for (auto rule : rules) {
            get_item_set(rule, item_set);
            item_sets.push_back(item_set);
            item_set.clear();
        }
        initial_item_set.push_back({fullname, item_sets});
        construct_initial_item_set(nested_rules, initial_item_set, fullname);
        fullname.pop_back();
    }
}
LRParser::InitialItemSet LRParser::construct_initial_item_set() {
    std::vector<std::string> fullname;
    InitialItemSet initial_item_set;
    construct_initial_item_set(tree->getRawTree(), initial_item_set, fullname);
    return initial_item_set;
}
std::vector<std::vector<std::string>> LRParser::constructFirstSet(const std::vector<Parser::Rule>& rules, size_t pos) {

    if (rules.empty())
        return {{"ε"}};
    Parser::Rule first_rule_rule;
    if (rules[pos].name == Parser::Rules::Rule_rule) {
        first_rule_rule = Tokens::getValueFromRule_rule(rules[pos]);
    } else first_rule_rule = rules[0];
    auto first_ro = std::any_cast<rule_other>(first_rule_rule.data);
    if (corelib::text::isUpper(first_ro.name)) {
        // terminal
        return {first_ro.fullname};
    } else {
        auto rule_data = Tokens::find_token_in_tree(tree->getRawTree(), first_ro.fullname);
        if (rule_data == nullptr)
            throw Error("Failed construct FirstSet: non-terminal not found\n");
        auto data = std::any_cast<obj_t>(rule_data->data);
        auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
        return constructFirstSet(rules);
    }
}

void LRParser::constructFirstSet(Parser::Tree &tree, std::vector<std::string> &fullname) {
    for (auto &member : tree) {
        if (member.name != Parser::Rules::Rule)
            continue;
        auto data = std::any_cast<obj_t>(member.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
        auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        // do not include tokens
        if (corelib::text::isUpper(name_str) && name_str != "S'")
            continue;
        fullname.push_back(name_str);
        auto f = constructFirstSet(rules);
        first[corelib::text::join(fullname, "_")] = f;
        fullname.pop_back();
    }
}
void LRParser::constructFirstSet() {
    std::vector<std::string> fullname;
    constructFirstSet(tree->getRawTree(), fullname);
}
void LRParser::constructFollowSet(std::vector<std::string> &name, const std::vector<Parser::Rule>& rules) {
    if (rules.empty())
        return;
    follow[corelib::text::join(name, "_")] = constructFirstSet(rules, 1)[0];
}

void LRParser::constructFollowSet(Parser::Tree &tree, std::vector<std::string> &fullname, std::vector<std::string> &nonterminals) {
    follow["S'"].push_back("$");  // Add $ to FOLLOW(S')
    for (auto nonterminal : nonterminals) {
        follow[nonterminal] = {"ε"};
    }
    for (auto &member : tree) {
        if (member.name != Parser::Rules::Rule)
            continue;
        
        auto data = std::any_cast<obj_t>(member.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
        auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));

        // Do not include tokens
        if (corelib::text::isUpper(name_str) && name_str != "S'")
            continue;
        
        fullname.push_back(name_str);
        
        // Construct FOLLOW set for current rule set
        constructFollowSet(fullname, rules);
        
        fullname.pop_back();
    }
}

void LRParser::constructFollowSet(std::vector<std::string> &nonterminals) {
    std::vector<std::string> fullname;
    constructFollowSet(tree->getRawTree(), fullname, nonterminals);
}


void LRParser::create_item_collection(CanonicalItem &closure, const ItemSet &item) {
    CanonicalEl new_item{item.first, {}, 0, rule_index++};
    if (std::find_if(closure.begin(), closure.end(), [&item](const CanonicalEl &i) {return item.first == i.lhs;}) != closure.end())
        return;
    std::for_each(item.second.begin(), item.second.end(), [&new_item](auto &rhs) {
        new_item.rhs.push_back(rhs[0]);
    });
    closure.push_back(new_item);
    for (const auto &rhs : item.second) {
        // If the dot is before a non-terminal, expand rules related to that non-terminal
        if (!rhs.empty() && corelib::text::isLower(rhs[0].name)) {
            // Find the matching rule for this non-terminal (rhs[0])
            auto rule = std::find_if(initial_item_set.begin(), initial_item_set.end(), [&](const ItemSet &set) {
                return set.first == std::vector<std::string>{rhs[0].fullname}; // match only non-terminal
            });
            if (rule != initial_item_set.end()) {
                // Recursively create items for this non-terminal
                create_item_collection(closure, *rule);
            }
        }
    }
}

LRParser::CanonicalItemSet LRParser::construct_cannonical_collections_of_items() {
    CanonicalItemSet cci;

    // Find the augmented start rule "S'"
    auto begin_rule = std::find_if(initial_item_set.begin(), initial_item_set.end(), [](const ItemSet &set) {
        return set.first == std::vector<std::string>{"S'"}; // Find the augmented start rule
    });
    if (begin_rule == initial_item_set.end()) {
        throw Error("No augmented rule\n");
    }

    // Start with the initial item set (I0)
    CanonicalItem I0;
    create_item_collection(I0, *begin_rule);
    cci.push_back(I0);
    std::queue<CanonicalItem> worklist;
    worklist.push(I0);
    
    while (!worklist.empty()) {
        CanonicalItem current = worklist.front();
        worklist.pop();
    
        // Group items by symbol after the dot
        std::map<std::string, CanonicalItem> transitions;
    
        for (const auto& item : current) {
            if (item.dot_pos < item.rhs.size()) {
                const std::string& sym = item.rhs[item.dot_pos].name;
                CanonicalEl advanced = item;
                advanced.dot_pos++;
                transitions[sym].push_back(advanced);
            }
        }
    
        for (auto& [sym, items] : transitions) {
            CanonicalItem closure = items;
            // Expand non-terminals after dot if any
            for (const auto& el : items) {
                if (el.dot_pos < el.rhs.size() && corelib::text::isLower(el.rhs[el.dot_pos].name)) {
                    auto rule = std::find_if(initial_item_set.begin(), initial_item_set.end(), [&](const ItemSet& set) {
                        return set.first == std::vector<std::string>{el.rhs[el.dot_pos].fullname};
                    });
                    if (rule != initial_item_set.end()) {
                        create_item_collection(closure, *rule);
                    }
                }
            }
    
            if (std::find(cci.begin(), cci.end(), closure) == cci.end()) {
                cci.push_back(closure);
                worklist.push(closure);
            }
        }
    }
    
    return cci; // Return the complete set of canonical collections
}



size_t LRParser::find_goto_state(const CanonicalItem &item_set, const rule_other &symbol) {
    CanonicalItem next_state;

    // Step 1: Shift dot over symbol where possible
    for (const auto &item : item_set) {
        if (item.dot_pos < item.rhs.size() && item.rhs[item.dot_pos] == symbol) {
            CanonicalEl shifted = item;
            shifted.dot_pos++;
            next_state.push_back(shifted);
        }
    }

    // Step 2: Compute closure of this new state
    CanonicalItem closure;
    for (const auto &item : next_state) {
        closure.push_back(item);
    }
    for (const auto &item : next_state) {
        if (item.dot_pos < item.rhs.size()) {
            const auto &next_sym = item.rhs[item.dot_pos];
            if (corelib::text::isLower(next_sym.name)) {
                // Non-terminal → expand it
                auto rule = std::find_if(initial_item_set.begin(), initial_item_set.end(), [&](const ItemSet &set) {
                    return set.first == std::vector<std::string>{next_sym.fullname};
                });
                if (rule != initial_item_set.end()) {
                    create_item_collection(closure, *rule);
                }
            }
        }
    }

    // Step 3: Check if this closure already exists in canonical set
    for (size_t i = 0; i < canonical_item_set.size(); ++i) {
        if (canonical_item_set[i] == closure) {
            return i;
        }
    }

    // Step 4: If not, add it (only do this if building dynamically — otherwise error)
    throw std::runtime_error("GOTO leads to non-existent state. Should be precomputed.");
}

void LRParser::build() {
    addAugmentedRule();
    initial_item_set = construct_initial_item_set();
    canonical_item_set = construct_cannonical_collections_of_items();
    rule_index = 0;
    auto [tokens, rules] = tree->getTokenAndRuleNames();
    constructFirstSet();
    constructFollowSet(rules);
    size_t I = 0;
    for (const auto &item_set : canonical_item_set) {
        for (const auto &rule : item_set) {
            // Dot is at the end: Reduce or Accept
            if (rule.dot_pos >= rule.rhs.size()) {
                if (rule.lhs == std::vector<std::string>{"S'"} && rule.rhs.size() == 1) {
                    action_table[I]["$"] = Action{Action_type::ACCEPT, 0};
                } else {
                    std::string lhs_key = corelib::text::join(rule.lhs, "_");
                    cpuf::printf("follow[%s], size(): %$\n", lhs_key, follow[lhs_key].size());
                    for (const auto& follow_token : follow[lhs_key]) {
                        action_table[I][follow_token] = Action{Action_type::REDUCE, rule.rule_index};
                    }
                }
            }
            // Dot is before a symbol
            else {
                const auto &next = rule.rhs[rule.dot_pos];
                size_t next_state = find_goto_state(item_set, next); // this computes goto(I, X)

                if (corelib::text::isLower(next.name)) {
                    // Non-terminal → GOTO
                    goto_table[I][corelib::text::join(next.fullname, "_")] = next_state;
                } else {
                    // Terminal → SHIFT
                    action_table[I][corelib::text::join(next.fullname, "_")] = Action{Action_type::SHIFT, next_state};
                }
            }
        }
        I++;
    }
}
void LRParser::formatCanonicalItemSet(std::ostringstream &oss) {
    size_t count = 0;
    for (const auto &item_set : canonical_item_set) {
        oss << "I" << count++ << ":\n";
        for (const auto &item : item_set) {
            // Print the LHS
            for (const auto &lhs_part : item.lhs) {
                oss << '\t' << lhs_part << " ";
            }
            oss << "→ ";

            // Print RHS with dot position
            for (size_t i = 0; i <= item.rhs.size(); ++i) {
                if (i == item.dot_pos) {
                    oss << "• ";
                }
                if (i < item.rhs.size()) {
                    oss << "{ ";
                    for (const auto &part : item.rhs[i].fullname) {
                        oss << part << " ";
                    }
                    oss << "} ";
                }
            }

            oss << "\n";
        }
        oss << "\n";
    }
}


void LRParser::printCanonicalCollection(const std::string &fileName) {
    // Step 1: Print to std::ostringstream
    std::ostringstream oss;
    formatCanonicalItemSet(oss);

    // Step 2: Output the stringstream content to a file
    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << oss.str();
        outFile.close();
    } else {
        std::cerr << "Failed to open the file for writing: " << fileName << "\n";
    }
}

// Helper function to format the Action Table into a string
#include <iomanip> // For std::setw

std::string LRParser::formatActionTable() const {
    std::ostringstream oss;
    const int stateWidth = 6;
    const int tokenWidth = 15;
    const int actionWidth = 10;
    const int nextStateWidth = 10;

    oss << "Action Table:\n";
    oss << std::left
        << std::setw(stateWidth) << "State"
        << std::setw(tokenWidth) << "Token"
        << std::setw(actionWidth) << "Action"
        << std::setw(nextStateWidth) << "Next State"
        << "\n";

    for (const auto& state_entry : action_table) {
        size_t state = state_entry.first;
        for (const auto& token_entry : state_entry.second) {
            const std::string& token = token_entry.first;
            const Action& action = token_entry.second;

            std::string action_str;
            switch (action.type) {
                case Action_type::SHIFT:
                    action_str = "SHIFT";
                    break;
                case Action_type::REDUCE:
                    action_str = "REDUCE";
                    break;
                case Action_type::ACCEPT:
                    action_str = "ACCEPT";
                    break;
                case Action_type::ERROR:
                    action_str = "ERROR";
                    break;
            }

            oss << std::left
                << std::setw(stateWidth) << state
                << std::setw(tokenWidth) << token
                << std::setw(actionWidth) << action_str
                << std::setw(nextStateWidth) << action.state
                << "\n";
        }
    }
    return oss.str();
}

std::string LRParser::formatGotoTable() const {
    std::ostringstream oss;
    const int stateWidth = 6;
    const int nonTerminalWidth = 20;
    const int nextStateWidth = 12;

    oss << "Goto Table:\n";
    oss << std::left
        << std::setw(stateWidth) << "State"
        << std::setw(nonTerminalWidth) << "Non-Terminal"
        << std::setw(nextStateWidth) << "Next State"
        << "\n";

    for (const auto& state_entry : goto_table) {
        size_t state = state_entry.first;
        for (const auto& non_terminal_entry : state_entry.second) {
            const std::string& non_terminal = non_terminal_entry.first;
            size_t next_state = non_terminal_entry.second;

            oss << std::left
                << std::setw(stateWidth) << state
                << std::setw(nonTerminalWidth) << non_terminal
                << std::setw(nextStateWidth) << next_state
                << "\n";
        }
    }
    return oss.str();
}

// Method to print both Action and Goto tables into a single file
void LRParser::printTables(const std::string& filename) {
    std::ofstream out_file(filename);

    if (!out_file.is_open()) {
        std::cerr << "Error opening file for writing tables.\n";
        return;
    }

    // Format the Action Table and Goto Table
    std::string action_table_str = formatActionTable();
    std::string goto_table_str = formatGotoTable();

    // Write both tables to the file
    out_file << action_table_str << "\n" << goto_table_str;

    out_file.close();
}