#include <parser.h>
#include <string>
#include <internal_types.h>
#include <corelib.h>
#if defined(_WIN32)
    #define EXPORT  extern "C" __declspec(dllexport)
#else
    #define EXPORT  extern "C" __attribute__((visibility("default")))
#endif

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
EXPORT void on_Rule(use_prop_t &use_prop, std::string &buf, Parser::Rule member);
EXPORT void on_Rule_group(use_prop_t &use_prop, std::string &buf, Parser::Rule member);
EXPORT void on_Rule_csequence(use_prop_t &use_prop, std::string &buf, Parser::Rule member);
EXPORT void on_accessor(use_prop_t &use_prop, std::string &buf, Parser::Rule member);
EXPORT void on_Rule_hex(use_prop_t &use_prop, std::string &buf, Parser::Rule member);
EXPORT void on_Rule_bin(use_prop_t &use_prop, std::string &buf, Parser::Rule member);
EXPORT void on_Rule_other(use_prop_t &use_prop, std::string &buf, Parser::Rule member);
EXPORT void on_Rule_escaped(use_prop_t &use_prop, std::string &buf, Parser::Rule member);
EXPORT void on_Rule_any(use_prop_t &use_prop, std::string &buf, Parser::Rule member);
EXPORT void on_Rule_op(use_prop_t &use_prop, std::string &buf, Parser::Rule member);
EXPORT void on_cll(use_prop_t &use_prop, std::string &buf, Parser::Rule member);
EXPORT void on_string(use_prop_t &use_prop, std::string &buf, Parser::Rule member);
EXPORT void on_number(use_prop_t &use_prop, std::string &buf, Parser::Rule member);