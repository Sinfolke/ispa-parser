#include <defs.h>
#include <debug/logging.h>
void on_Rule_csequence(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    if (!processingToken)
        throw Error("processing Rule_csequence in non-token rule");
    if (qualifier == '+' || qualifier == '*') {
        buf += "while (!(true";
    } else {
        buf += "if (!(true";
    }
}
void on_Rule_csequence_close(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    buf += R"())
    {
        return {};
    }
    )";
}
void on_Rule_csequence_diapason(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<arr_t<Parser::Rule>>(member.data);
    auto first = std::any_cast<char>(data[0].data);
    auto second = std::any_cast<char>(data[1].data);
    std::stringstream str;
    str << " && (" <<  "*pos >= '" << first << "' && *pos <= '" << second << "')";
    buf += str.str();
}
void on_Rule_csequence_escape(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<char>(member.data);
    std::stringstream str;
    std::string c = data == '\'' ? "\\'" : c;
    if (data == 's') // space
        str << "&& isspace(*pos) ";
    else 
        str << "&& *pos == '" << c << "'";
    
    buf += str.str();
}
void on_Rule_csequence_symbol(Parser::Tree &tree, int &i, use_prop_t &use_prop, std::string &buf, Parser::Rule member) {
    auto data = std::any_cast<char>(member.data);
    std::stringstream str;
    std::string c = data == '\'' ? "\\'" : c;
    str << "&& (*pos == " << data << ")";
    buf += str.str();
}