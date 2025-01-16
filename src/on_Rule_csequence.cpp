#include <defs.h>
#include <debug/logging.h>
bool csequence_not;
int rule_number = 0;
EXPORT void on_Rule_csequence(use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    if (!processingToken)
        throw Error("processing Rule_csequence in non-token rule");
    auto data = std::any_cast<obj_t>(member.data);
    csequence_not = std::any_cast<bool>(corelib::map::get(data, "not"));
    current_place = { rule_number++, qualifier == '+' || qualifier == '*', buf.size(), 0 };
    if (qualifier == '+' || qualifier == '*') {
        buf += "\twhile";
        if (!csequence_not)
            buf += "!(";
        buf += "true";
    } else {
        buf += "if";
        if (!csequence_not)
            buf += "!(";
        buf += "true";
    }
}
EXPORT void on_Rule_csequence_close(use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    buf += ')';
    if (!csequence_not)
        buf += ") {";
    current_place.assign_place = buf.size();
    buf += "\n\t\treturn {};\n";
    buf += "\t}";
    vars.push_back(current_place);
    current_place = {};
}
EXPORT void on_Rule_csequence_diapason(use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<arr_t<Parser::Rule>>(member.data);
    auto first = std::any_cast<char>(data[0].data);
    auto second = std::any_cast<char>(data[1].data);
    std::stringstream str;
    str << " && (" <<  "*pos >= '" << first << "' && *pos <= '" << second << "')";
    buf += str.str();
}
EXPORT void on_Rule_csequence_escape(use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<char>(member.data);
    std::stringstream str;
    std::string c = data == '\'' ? "\\'" : c;
    if (data == 's') // space
        str << "&& isspace(*pos) ";
    else 
        str << "&& *pos == '" << c << "'";
    
    buf += str.str();
}
EXPORT void on_Rule_csequence_symbol(use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<char>(member.data);
    std::stringstream str;
    std::string c = data == '\'' ? "\\'" : c;
    str << "&& (*pos == " << data << ")";
    buf += str.str();
}