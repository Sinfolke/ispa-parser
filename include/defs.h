#include <parser.h>
#include <string>
#include <internal_types.h>
#include <corelib.h>

struct variable_place {
    int rule_number;
    bool is_multiple_assing;
    size_t place;
    size_t assign_place;
};

extern bool processingToken;
extern char qualifier;
extern std::vector<variable_place> vars;
extern variable_place current_place;
void on_Rule(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void on_Rule_group(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void on_Rule_csequence(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void on_accessor(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void on_Rule_hex(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void on_Rule_bin(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void on_Rule_other(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void on_Rule_escaped(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void on_Rule_any(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void on_Rule_op(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void on_cll(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void on_string(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);
void on_number(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member);