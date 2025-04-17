#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <any>
#include <typeinfo>
#include <unordered_map>
#include <iomanip>
#include <stack>
#include <IR/IR.h>
#include <logging.h>
#include <LLConverter.h>
#include <logging.h>
static size_t count_strlen(const char* str) {
    size_t count = 0;
    for (const char* pos = str; *pos; pos++) {
        if (*pos == '\\' && *(pos - 1) != '\\') {
            continue;
        }
        count++;
    }
    return count;
}
static std::string format_str(std::string str) {
    std::string res;
    for (auto &c : str) {
        if (c == '"') {
            res += "\\\"";
            continue;
        }
        res += c;
    }
    return res;
}

void LLConverter::writeRules(std::ostringstream &out) {
    bool isRule = false;
    indentLevel = 2;
    for (auto &member : data) {
        if (member.type == LLIR::types::RULE) {
            isRule = true;
        } else if (member.type == LLIR::types::TOKEN) {
            isRule = false;
        } 
        if (isRule) {
            convertMember(member, out);
        }
    }
}
void LLConverter::outputHeader(std::ostringstream &out) {
    cpp_file = false;
    createLibrary(out, namespace_name);
    createNamespace(out, namespace_name);
    createTypes(out, namespace_name);
    createTokensEnum(out, tokens);
    createRulesEnum(out, rules);
    getTypesFromStdlib(out);
    createToStringFunction(out);
    createTypesNamespace(out, data_block_tokens, data_block_rules);
    create_get_namespace(out, namespace_name, data_block_tokens, data_block_rules);
    create_lexer_header(out, tokens);
    create_parser_header(out);
    writeRules(out);
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
    if (mem.type != LLIR::types::RULE_END)
        out << std::string(indentLevel, '\t');
    switch (mem.type)
    {
    case LLIR::types::RULE:
        if (!cpp_file) {
            has_data_block = false;
            rule_prev_name = std::any_cast<std::pair<std::string, std::vector<std::string>>>(mem.value);
            rule_prev_name_str = corelib::text::join(rule_prev_name.second, "_");
            out << "template <class IT>\n";
            out << std::string(indentLevel, '\t') << "::" << namespace_name << "::Rule_res " << rule_prev_name_str << "(IT pos) {\n";
            indentLevel++;
            out << std::string(indentLevel, '\t') << "auto in = pos;" ;
            isToken = false;
        }
        break;
    case LLIR::types::TOKEN:
        has_data_block = false;
        indentLevel++;
        rule_prev_name = std::any_cast<std::pair<std::string, std::vector<std::string>>>(mem.value);
        rule_prev_name_str = corelib::text::join(rule_prev_name.second, "_");
        out << namespace_name << "::Token_res " << namespace_name << "::Lexer::" << rule_prev_name_str << "(const char* pos) {\n";
        out << std::string(indentLevel, '\t') << "auto in = pos";
        isToken = true;
        break;
    case LLIR::types::RULE_END:
        if (isToken) {
            out << std::string(indentLevel, '\t') << "return {true, ::" << namespace_name << "::Token(getCurrentPos(in), in, pos, pos - in, __line(pos), __column(pos), ::" << namespace_name << "::Tokens::" << rule_prev_name_str;
            if (has_data_block)
                out << ", data";
            out << ")};\n";
        } else {
            out << std::string(indentLevel, '\t') << "return {true, ::" << namespace_name << "::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::" << namespace_name << "::Rules::" << rule_prev_name_str;
            if (has_data_block)
                out << ", data";
            out << ")};\n";
        }
        indentLevel--;
        out << std::string(indentLevel, '\t') << "}";
        break;
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
        out << "do\n";
        convertBlock(std::any_cast<LLIR::condition>(mem.value).block, out);
        out << '\n' << std::string(indentLevel, '\t') << "while";
        out << convertExpression(std::any_cast<LLIR::condition>(mem.value).expression, true);
        break;
    case LLIR::types::INCREASE_POS_COUNTER:
        out << current_pos_counter.top() << " += " + std::to_string(pos_counter_stack.top() + 1);
        pos_counter_stack.pop();
        break;
    case LLIR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH: {
        if (isToken) {
            auto var = std::any_cast<std::string>(mem.value);
            out << current_pos_counter.top() << " += " + var + ".node.length()";
        }
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
        if (isToken)            
            out << "skip_spaces(" << current_pos_counter.top() << ")";
        else
            out << "skip_spaces<::" << namespace_name << "::TokenFlow::iterator, ::" << namespace_name << "::Tokens>(pos)";
        break;
    case LLIR::types::DATA_BLOCK:
        has_data_block = true;
        out << convertDataBlock(std::any_cast<LLIR::data_block>(mem.value));
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
void LLConverter::printIR(std::ostringstream &out) {
    addHeader(out);
    addStandardFunctionsLexer(out);
    addStandardFunctionsParser(out);
    addTokensToString(tokens, out);
    addRulesToString(rules, out);
    addGetFunctions(out, data_block_tokens, data_block_rules);
    addLexerCode_Header(out);
    current_pos_counter.push("pos");
    convertLexerCode(lexer_code.getDataRef(), out);
    addLexerCode_Bottom(out,  lexer_code_access_var.var);
    convertMembers(data, out);
}
void LLConverter::addHeader(std::ostringstream &out) {
    out << "#include \"" << std::any_cast<std::string>(use["name"].data) << ".h\"\n";
}
void LLConverter::addTokensToString(std::vector<std::string> tokens, std::ostringstream &out) {
    // Implement method call conversion with proper indentation
    out << "std::string " << namespace_name << "::TokensToString(Tokens token) {\n";
    out << "\tswitch (token) {\n";
    out << "\t\tcase Tokens::NONE:" << " return \"NONE\";\n";
    for (auto token : tokens) {
        out << "\t\tcase Tokens::" << token << ":" << " return \"" << token << "\";\n";
    }
    out << "\t}\n";
    out << "\treturn \"NONE\";\n";
    out << "}\n";
}
void LLConverter::addRulesToString(std::vector<std::string> rules, std::ostringstream &out) {
    // Implement method call conversion with proper indentation
    out << "std::string " << namespace_name << "::RulesToString(Rules rule) {\n";
    out << "\tswitch (rule) {\n";
    out << "\t\tcase Rules::NONE:" << " return \"NONE\";\n";
    for (auto rule : rules) {
        out << "\t\tcase Rules::" << rule << ":" << " return \"" << rule << "\";\n";
    }
    out << "\t}\n";
    out << "\treturn \"NONE\";\n";
    out << "}\n";
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
}
void LLConverter::addStandardFunctionsParser(std::ostringstream &out) {
    out << namespace_name <<  "::Rule_res " << namespace_name << R"(::Parser::getRule(Lexer::lazy_iterator &pos) {
    return main(pos);
})" << '\n';
    out << namespace_name <<  "::Rule_res " << namespace_name << R"(::Parser::getRule(Lexer::iterator &pos) {
    return main(pos);
})" << '\n';
    out << "void ::" << namespace_name << R"(::Parser::parseFromTokens() {
    auto pos = Lexer::iterator(lexer);
    parseFromPos(pos);
})" << '\n';
    out << "void ::" << namespace_name << R"(::Parser::lazyParse() {
    auto pos = Lexer::lazy_iterator(lexer, text);
    parseFromPos(pos);
})" << '\n';
//     out << "void " << namespace_name << R"(::Parser::parseFromInput() {
//         Lexer lexer;

//         if (parallel_parsing) {
//             TokenFlow tokens;
//             std::mutex mtx;
//             std::condition_variable cv;
//             bool done = false;

//             // Token accumulation thread
//             std::future<void> token_future = std::async(std::launch::async, [&]() {
//                 while (true) {
//                     auto token = lexer.makeToken(input);  // Generate one token
//                     if (token.empty()) {
//                         // parsing has finished
//                         std::lock_guard<std::mutex> lock(mtx);
//                         done = true;
//                         cv.notify_one();
//                         return;
//                     }
//                     input += token.length();
//                     {
//                         std::lock_guard<std::mutex> lock(mtx);
//                         tokens.push_back(token);
//                     }
//                     // notify new token added
//                     cv.notify_one();
//                 }
//             });

//             // Parsing loop
//             while (true) {
//                 std::unique_lock<std::mutex> lock(mtx);
//                 cv.wait(lock, [&]() { return !tokens.empty() || done; });

//                 if (tokens.empty() && done) break; // no tokens anymore and lexical analyzation has finished

//                 auto rule_res = getRule();
//                 if (rule_res.status) {
//                     // push parsed rule to tree
//                     tree.push_back(rule_res.node);
//                     tokens.erase(tokens.begin(), std::next(tokens.begin(), rule_res.node.length()));
//                 }
//             }

//             // Ensure token accamulation is completed
//             token_future.get();
//         } else {
//             // single thread parsing
//             TokenFlow tokens;
//             while (true) {
//                 // Accumulate tokens (at least 10) before parsing
//                 for (int i = 0; i < 10; i++) {
//                     auto token = lexer.makeToken(input);  // Generate one token
//                     if (token.empty()) break;
//                     tokens.push_back(token);
//                 }
//                 if (tokens.empty()) return; // parsing has finished

//                 // parse the tokens and consume used one
//                 pos = tokens.begin();
//                 auto rule_res = getRule();
//                 if (rule_res.status) {
//                     tree.push_back(rule_res.node);
//                     tokens.erase(tokens.begin(), std::next(tokens.begin(), rule_res.node.length()));
//                 }
//             }
//         }
// })";
//     out << "\n";
}

void LLConverter::addGetFunctions(std::ostringstream &out, data_block_t datablocks_tokens, data_block_t datablocks_rules) {
    for (const auto &[name, dtb] : datablocks_tokens) {
        out << "::" << namespace_name << "::Types::" << name << "_data " << namespace_name << "::get::" << name << "(::" << namespace_name << "::Token &token) {\n";
        out << "\treturn std::any_cast<Types::" << name << "_data>(token.data());";
        out << "\n}\n";
    }
    for (const auto &[name, dtb] : datablocks_rules) {
        out << "::" << namespace_name << "::Types::" << name << "_data " << namespace_name << "::get::" << name << "(::" << namespace_name << "::Rule &rule) {\n";
        out << "\treturn std::any_cast<Types::" << name << "_data>(rule.data());";
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
void LLConverter::outputIR(std::string filename) {
    namespace_name = filename;
    std::ofstream cpp(filename + ".cpp");
    std::ofstream h(filename + ".h");
    if (!cpp) {
        throw std::runtime_error("Unable to open file for writing: " + filename + ".cpp");
    }
    if (!h) {
        throw std::runtime_error("Unable to open file for writing: " + filename + ".h");
    }
    std::ostringstream cpp_ss, h_ss;
    printIR(cpp_ss);
    outputHeader(h_ss);
    cpp << cpp_ss.str();
    h << h_ss.str();
}
extern "C" LLConverter_base* getLLConverter(LLIR& ir, Tree& tree) {
    return new LLConverter(ir, tree);
}

// IR &ir, IR &lexer_code, IR::node_ret_t& tokenizator_access_var, std::list<std::string> tokens, std::list<std::string> rules, data_block_t datablocks_tokens, data_block_t datablocks_rules, const use_prop_t &use