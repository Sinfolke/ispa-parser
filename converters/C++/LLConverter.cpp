module;
#include <sstream>
#include <any>
module LLConverter;
import LLIR;
import logging;
void LLConverter::writeRules(std::ostringstream &out, bool startName) {
    for (auto &[data_block, name, members] : data) {
        isToken = corelib::text::isUpper(name.back());
        if (isToken == startName) continue;
        rule_prev_name = name;
        rule_prev_name_str = corelib::text::join(name, "_");
        if (isToken) {
            out << std::string(indentLevel, '\t') << namespace_name << "::Token_res " << namespace_name << "::Lexer::" << rule_prev_name_str << "(const char* pos) {\n";
            indentLevel++;
            out << std::string(indentLevel, '\t') << "auto in = pos;\n";
            isToken = true;
        } else {
            out << std::string(indentLevel, '\t') << "template <class IT>\n";
            out << std::string(indentLevel, '\t') << "::" << namespace_name << "::Rule_res " << rule_prev_name_str << "(IT pos) {\n";
            indentLevel++;
            out << std::string(indentLevel, '\t') << "auto in = pos;\n" << std::string(indentLevel, '\t') << "skip_spaces(" << current_pos_counter.top() << ");\n" ;
            isToken = false;
        }
        convertMembers(members, out);
        if (!data_block.empty()) {
            out << std::string(indentLevel, '\t') << convertDataBlock(data_block) << '\n';
        }
        if (isToken) {
            out << std::string(indentLevel, '\t') << "return {true, ::" << namespace_name << "::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::" << namespace_name << "::Tokens::" << rule_prev_name_str;
            if (!data_block.empty())
                out << ", data";
            out << ")};\n";
        } else {
            out << std::string(indentLevel, '\t') << "return {true, ::" << namespace_name << "::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::" << namespace_name << "::Rules::" << rule_prev_name_str;
            if (!data_block.empty())
                out << ", data";
            out << ")};\n";
        }
        indentLevel--;
        out << std::string(indentLevel, '\t') << "}\n";
    }
}
void LLConverter::outputHeader(std::ostringstream &out, const std::string &filename) {
    cpp_file = false;
    namespace_name = filename;
    createLibrary(out, namespace_name);
    createIncludes(out);
    createDefaultTypes(out);
    createNamespace(out, namespace_name);
    createTypes(out, namespace_name);
    createTokensEnum(out, tokens);
    createRulesEnum(out, rules);
    getTypesFromStdlib(out);
    createToStringFunction(tokens, rules, out);
    createTypesNamespace(out, data_block_tokens, data_block_rules);
    create_get_namespace(out, namespace_name, data_block_tokens, data_block_rules);
    create_lexer_header(out, tokens);
    create_parser_header(out);
    indentLevel = 2;
    writeRules(out, true);
    indentLevel = 1;
    close_parser_header(out);
    close_library(out, namespace_name);
}
void LLConverter::convertVariable(LLIR::variable var, std::ostringstream &out) {
    out << convert_var_type(var.type.type, var.type.templ) << " " << var.name;
    if (var.value.kind != LLIR::var_assign_values::NONE)
        out << " = " << convertAssign(var.value);
    out << ';';
}

void LLConverter::convertBlock(std::vector<LLIR::member> block, std::ostringstream &out) {
    out << std::string(indentLevel, '\t') << "{\n";
    indentLevel++;
    convertMembers(block, out);
    indentLevel--;
    out << std::string(indentLevel, '\t') << "}";
}
void LLConverter::convertCondition(LLIR::condition cond, std::ostringstream &out) {
    out << convertExpression(cond.expression, true);
    convertBlock(cond.block, out);
    if (!cond.else_block.empty()) {
        out << "\n" << std::string(indentLevel, '\t') << "else \n";
        convertBlock(cond.else_block, out);
    }
}


void LLConverter::convertAssignVariable(LLIR::variable_assign var, std::ostringstream &out) {
    out << var.name << " " << convert_var_assing_types(var.assign_type) << " " << convertAssign(var.value);
}
void LLConverter::convertMember(const LLIR::member& mem, std::ostringstream &out) {
    if (cpp_file && (!isToken || mem.type == LLIR::types::RULE) && mem.type != LLIR::types::TOKEN) {
        isToken = false;
        return;
    }
    if (mem.type == LLIR::types::EMPTY)
        return;
    if (mem.type != LLIR::types::RULE_END)
        out << std::string(indentLevel, '\t');
    switch (mem.type)
    {

    case LLIR::types::VARIABLE:
        convertVariable(std::any_cast<LLIR::variable>(mem.value), out);
        break;
    case LLIR::types::METHOD_CALL:
        out << convertMethodCall(std::any_cast<LLIR::method_call>(mem.value));
        break;
    case LLIR::types::IF:
        out << "if ";
        convertCondition(std::any_cast<LLIR::condition>(mem.value), out);
        break;
    case LLIR::types::WHILE:
        out << "while ";
        convertCondition(std::any_cast<LLIR::condition>(mem.value), out);
        break;
    case LLIR::types::DOWHILE:
    {
        out << "do\n";
        convertBlock(std::any_cast<LLIR::condition>(mem.value).block, out);
        out << '\n' << std::string(indentLevel, '\t') << "while";
        auto expr = convertExpression(std::any_cast<LLIR::condition>(mem.value).expression, true);
        expr.back() = ';';
        out << expr;
        break;
    }
    case LLIR::types::INCREASE_POS_COUNTER:
        out << current_pos_counter.top() << " += " + std::to_string(pos_counter_stack.top() + 1);
        pos_counter_stack.pop();
        break;
    case LLIR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH: {
        auto var = std::any_cast<std::string>(mem.value);
        out << current_pos_counter.top() << " += " + var + ".node.length()";
        break;
    }
    case LLIR::types::RESET_POS_COUNTER:
        pos_counter_stack.pop();
        break;
    case LLIR::types::ACCESSOR:
        throw Error("Accessor cannot be here\n");
    case LLIR::types::ASSIGN_VARIABLE:
        convertAssignVariable(std::any_cast<LLIR::variable_assign>(mem.value), out);
        break;
    case LLIR::types::BREAK_LOOP:
        out << "break";
        break;
    case LLIR::types::CONTINUE_LOOP:
        out << "continue";
        break;
    case LLIR::types::EXIT:
        out << "return {};";
        break;
    case LLIR::types::ERR:
        out << "reportError(pos, \"";
        for (auto &c : std::any_cast<std::string>(mem.value)) {
            out << corelib::text::getCharFromEscapedAsStr(c, true);
        }
        out << "\");";
        break;
    case LLIR::types::SKIP_SPACES:
        out << "skip_spaces(" << current_pos_counter.top() << ")";
        break;
    case LLIR::types::PUSH_POS_COUNTER: {
        out << "auto " << std::any_cast<std::string>(mem.value) << " = " << current_pos_counter.top();
        current_pos_counter.push(std::any_cast<std::string>(mem.value));
        break;
    }
    case LLIR::types::POP_POS_COUNTER: {
        auto el = current_pos_counter.top();
        current_pos_counter.pop();
        out << current_pos_counter.top() << " = " << el;
        break;
    }
    default:
        throw Error("Undefined IR member\n");
    }
    auto back = out.str().back();
    if (back != '{' && back != '}' && back != ';' && add_semicolon)
        out << ";";
    out << "\n";
    add_semicolon = true;
}

void LLConverter::convertMembers(const std::vector<LLIR::member> &members, std::ostringstream &out) {
    for (auto mem : members)
        convertMember(mem, out);
}
void LLConverter::convertLexerCode(const std::vector<LLIR::member> &members, std::ostringstream &out) {
    isToken = true;
    if (!members.empty()) {
        for (auto it = members.begin() + 1; it != members.end() - 1; it++) {
            auto mem = *it;
            convertMember(mem, out);
        }
    }
    isToken = false;
}
void LLConverter::convertData(std::ostringstream &out) {
    for (const auto &dt : data) {
        convertMembers(dt.members, out);

    }
}
void LLConverter::printIR(std::ostringstream &out, const std::string &filename) {
    namespace_name = filename;
    addHeader(out);
    addStandardFunctionsLexer(out);
    addStandardFunctionsParser(out);
    addGetFunctions(out, data_block_tokens, data_block_rules);
    addLexerCode_Header(out);
    convertLexerCode(lexer_code.getData()[0].members, out);
    addLexerCode_Bottom(out,  lexer_code_access_var);
    writeRules(out, false);
}
void LLConverter::addHeader(std::ostringstream &out) {
    out << "#include \"" << namespace_name << ".h\"\n";
}

void LLConverter::addStandardFunctionsLexer(std::ostringstream &out) {
    out << "void " + namespace_name + R"(::Lexer::printTokens(std::ostream& os) {
    for (const auto& token : tokens)
        printToken(os, token);
})";
    out << '\n' << "void " + namespace_name + R"(::Lexer::printToken(std::ostream& os, const Token& token) {
    os << TokensToString(token.name()) << ": ";

    if (token.data().type() == typeid(str_t)) {
        os << '"' << std::any_cast<str_t>(token.data()) << '"';
    } else if (token.data().type() == typeid(num_t)) {
        os << std::any_cast<num_t>(token.data());
    } else if (token.data().type() == typeid(bool_t)) {
        os << std::boolalpha << std::any_cast<bool_t>(token.data());
    } else if (token.data().type() == typeid(Token)) {
        os << "{ ";
        printToken(os, std::any_cast<Token>(token.data())); // Recursive call
        os << " }";
    } else if (token.data().type() == typeid(arr_t<Token>)) { // Handle array of tokens
        os << "[ ";
        auto arr = std::any_cast<arr_t<Token>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            printToken(os, *it);
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(arr_t<str_t>)) {
        os << "[ ";
        auto arr = std::any_cast<arr_t<str_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << '"' << *it << '"';
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(arr_t<num_t>)) {
        os << "[ ";
        auto arr = std::any_cast<arr_t<num_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << *it;
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    } else if (token.data().type() == typeid(arr_t<bool_t>)) {
        os << "[ ";
        auto arr = std::any_cast<arr_t<bool_t>>(token.data());
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::boolalpha << *it;
            if (std::next(it) != arr.end()) os << ", ";
        }
        os << " ]";
    }
    os << " # " << token.startpos();
    os << '\n';
})";
    out << "\n";
    out << "void ::" << namespace_name << "::Parser::printAST(std::ostream &os) {\n";
    out << "\tsize_t indentLevel = 0;\n";
    out << "\tprintRule(os, tree, indentLevel, false);\n";
    out << "}\n";
    out << "void ::" << namespace_name << "::Parser::printRule(std::ostream &os, const ::" << namespace_name << "::Token &token, size_t &indentLevel, bool addSpaceOnBegin) {\n";
    out << "\tLexer::printToken(os, token);\n";
    out << "}\n";
    out << "void ::" << namespace_name << "::Parser::printRule(std::ostream &os, const ::" << namespace_name << "::Rule &rule, size_t &indentLevel, bool addSpaceOnBegin) {\n";
    out << "\tprintRule(os, rule.data(), indentLevel, addSpaceOnBegin);\n";
    out << "}\n";
    out << "void ::" << namespace_name << "::Parser::printRule(std::ostream &os, const std::any &data, size_t &indentLevel, bool addSpaceOnBegin) {\n";
    out << "\tusing Token = ::" << namespace_name << "::Token;\n";
    out << "\tusing Rule = ::" << namespace_name << "::Rule;\n\n";
    
    out << "\tif (addSpaceOnBegin) os << std::string(indentLevel, '\\t');\n\n";
    
    out << R"(if (data.type() == typeid(str_t)) {
        os << '"' << std::any_cast<str_t>(data) << '"';
    } else if (data.type() == typeid(num_t)) {
        os << std::any_cast<num_t>(data);
    } else if (data.type() == typeid(bool_t)) {
        os << std::boolalpha << std::any_cast<bool_t>(data);
    } else if (data.type() == typeid(Token)) {
        os << std::string(indentLevel, '\t');
        Lexer::printToken(os, std::any_cast<Token>(data));
    } else if (data.type() == typeid(arr_t<Token>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<Token>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::string(indentLevel, '\t');
            Lexer::printToken(os, *it);
        }
        os << std::string(--indentLevel, '\t') << "]";
    } else if (data.type() == typeid(Rule)) {
        os << "{\n";
        indentLevel++;
        printRule(os, std::any_cast<Rule>(data), indentLevel, true);
        os << std::string(--indentLevel, '\t') << "}";
    } else if (data.type() == typeid(arr_t<Rule>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<Rule>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            printRule(os, *it, indentLevel, true);
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    } else if (data.type() == typeid(arr_t<str_t>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<str_t>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::string(indentLevel, '\t') << '"' << *it << '"';
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    } else if (data.type() == typeid(arr_t<num_t>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<num_t>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::string(indentLevel, '\t') << *it;
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    } else if (data.type() == typeid(arr_t<bool_t>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<arr_t<bool_t>>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            os << std::string(indentLevel, '\t') << std::boolalpha << *it;
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    } else if (data.type() == typeid(std::any)) {
        printRule(os, std::any_cast<const std::any&>(data), indentLevel, addSpaceOnBegin);
    } else if (data.type() == typeid(arr_t<std::any>)) {
        os << "[\n";
        indentLevel++;
        auto arr = std::any_cast<const arr_t<std::any>&>(data);
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            printRule(os, *it, indentLevel, true);
            if (std::next(it) != arr.end()) os << ",";
            os << "\n";
        }
        indentLevel--;
        os << std::string(indentLevel, '\t') << "]";
    })";
    for (const auto &[name, value] : data_block_rules) {
        if (!value.is_inclosed_map())
            continue;
        out << "\telse if (data.type() == typeid(Types::" << corelib::text::join(name, "_") << ")) {\n";
        out << "\t\tos << \"{\\n\";\n";
        out << "\t\tauto dt = std::any_cast<Types::" << corelib::text::join(name, "_") << ">(data);\n";
        out << "indentLevel++;";
        for (const auto &[name, key_data] : value.getInclosedMap()) {
            out << "\t\tos << std::string(indentLevel, '\\t') << \"" << name << "\"<< \": \";\n";
            out << "\t\tprintRule(os, dt." << name << ", indentLevel, false);\n";
            out << "\t\tos << \"\\n\";\n";
        }
        out << "\t\tos << std::string(--indentLevel, '\\t') << \"}\\n\";\n";
        out << "\t}\n";
    }
    out <<  "else os << \"<UNDEF TYPE>\";\n";
    out << "}";
}
void LLConverter::addGetRuleFunction(std::ostringstream &out) {
    out << namespace_name <<  "::Rule_res " << namespace_name << R"(::Parser::getRule(Lexer::lazy_iterator &pos) {
        return main(pos);
    })" << '\n';
        out << namespace_name <<  "::Rule_res " << namespace_name << R"(::Parser::getRule(Lexer::iterator &pos) {
        return main(pos);
    })" << '\n';
}
void LLConverter::addparseFromFunctions(std::ostringstream &out) {
    out << "void ::" << namespace_name << R"(::Parser::parseFromTokens() {
        auto pos = Lexer::iterator(lexer);
        parseFromPos(pos);
    })" << '\n';
        out << "void ::" << namespace_name << R"(::Parser::lazyParse() {
        auto pos = Lexer::lazy_iterator(lexer, text);
        parseFromPos(pos);
    })" << '\n';
}

void LLConverter::addStandardFunctionsParser(std::ostringstream &out) {
    addGetRuleFunction(out);
    addparseFromFunctions(out);
}
void LLConverter::addGetFunctions(std::ostringstream &out, const LLIR::DataBlockList &datablocks_tokens, const LLIR::DataBlockList &datablocks_rules) {
    for (const auto &[fullname, dtb] : datablocks_tokens) {
        if (dtb.empty())
            continue;
        const auto name = corelib::text::join(fullname, "_");
        // const overload
        out << "const ::" << namespace_name << "::Types::" << name << "& " << namespace_name << "::get::" << name << "(const ::" << namespace_name << "::Token &token) {\n";
        out << "\tif (token.name() != ::" << namespace_name << "::Tokens::" << name << ") throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::" << name << ", \"" << namespace_name << "\");\n";
        out << "\treturn std::any_cast<const Types::" << name << "&>(token.data());";
        out << "\n}\n";
        // non const overload
        out << "::" << namespace_name << "::Types::" << name << "& " << namespace_name << "::get::" << name << "(::" << namespace_name << "::Token &token) {\n";
        out << "\tif (token.name() != ::" << namespace_name << "::Tokens::" << name << ") throw ISPA_STD::bad_get<Tokens, TokensToString>(token.name(), Tokens::" << name << ", \"" << namespace_name << "\");\n";
        out << "\treturn std::any_cast<Types::" << name << "&>(token.data());";
        out << "\n}\n";
    }
    for (const auto &[fullname, dtb] : datablocks_rules) {
        if (dtb.empty())
            continue;
        const auto name = corelib::text::join(fullname, "_");
        // const overload
        out << "const ::" << namespace_name << "::Types::" << name << "& " << namespace_name << "::get::" << name << "(const ::" << namespace_name << "::Rule &rule) {\n";
        out << "\tif (rule.name() != ::" << namespace_name << "::Rules::" << name << ") throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::" << name << ", \"" << namespace_name << "\");\n";
        out << "\treturn std::any_cast<const Types::" << name << "&>(rule.data());";
        out << "\n}\n";
        // non-const overload
        out << "::" << namespace_name << "::Types::" << name << "& " << namespace_name << "::get::" << name << "(::" << namespace_name << "::Rule &rule) {\n";
        out << "\tif (rule.name() != ::" << namespace_name << "::Rules::" << name << ") throw ISPA_STD::bad_get<Rules, RulesToString>(rule.name(), Rules::" << name << ", \"" << namespace_name << "\");\n";
        out << "\treturn std::any_cast<Types::" << name << "&>(rule.data());";
        out << "\n}\n";
    }
}

void LLConverter::addLexerCode_Header(std::ostringstream &out) {
    out << "\n" << namespace_name << "::Token " << namespace_name << "::Lexer::makeToken(const char*& pos) {\n";
    indentLevel++;
}
void LLConverter::addLexerCode_Bottom(std::ostringstream &out, LLIR::variable var) {
    out << "\treturn " << var.name << ";\n";
    out << "}\n";
    indentLevel--;
}
void LLConverter::outputIR(std::filesystem::path name) {
    std::ofstream cpp(name.string() + ".cpp");
    std::ofstream h(name.string() + ".h");
    if (!cpp) {
        throw std::runtime_error("Unable to open file for writing: " + name.filename().string() + ".cpp");
    }
    if (!h) {
        throw std::runtime_error("Unable to open file for writing: " + name.filename().string() + ".h");
    }
    std::ostringstream cpp_ss, h_ss;
    printIR(cpp_ss, name.filename().string());
    outputHeader(h_ss, name.filename().string());
    cpp << cpp_ss.str();
    h << h_ss.str();
}
extern "C" LLConverter_base* getLLConverter(LLIR_old& ir, ASTPass& tree) {
    return new LLConverter(ir, tree);
}

// IR &ir, IR &lexer_code, IR::node_ret_t& tokenizator_access_var, std::list<std::string> tokens, std::list<std::string> rules, data_block_t datablocks_tokens, data_block_t datablocks_rules, const use_prop_t &use