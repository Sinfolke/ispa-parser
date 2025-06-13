module LLIR;
import corelib;
import hash;
import logging;
import cpuf.printf;
import std;

auto LLIR::IR::begin() -> ::stdu::vector<Data>::iterator {
    return data.begin();
}
auto LLIR::IR::end() -> stdu::vector<Data>::iterator {
    return data.end();
}
auto LLIR::IR::cbegin() -> stdu::vector<Data>::const_iterator {
    return data.cbegin();
}
auto LLIR::IR::cend() -> stdu::vector<Data>::const_iterator {
    return data.cend();
}
auto LLIR::IR::size() -> size_t {
    return data.size();
}
auto LLIR::IR::empty() -> bool {
    return data.empty();
}
auto LLIR::IR::clear() -> void {
    data.clear();
}
LLIR::DataBlockList LLIR::IR::getDataBlocks(bool isToken) {
    LLIR::DataBlockList list;
    for (const auto &[data_block, name, members] : data) {
        if (isToken) {
            if (corelib::text::isLower(name.back())) continue;
        } else {
            if (corelib::text::isUpper(name.back())) continue;
        }
        list[name] = {data_block};
    }
    return list;
}
LLIR::DataBlockList LLIR::IR::getDataBlocksTerminals() {
    return getDataBlocks(true);
}
LLIR::DataBlockList LLIR::IR::getDataBlocksNonTerminals() {
    return getDataBlocks(false);
}
auto LLIR::IR::getData() const -> const stdu::vector<Data> & {
    return data;
}
auto LLIR::IR::getDfas() const -> const stdu::vector<DFA> & {
    return dfas;
}

auto LLIR::IR::operator[](size_t index) const -> const Data& {
    return data[index];
}


/*
 ###########################
 OUTPUT TO CONSOLE FUNCTIONS
 ###########################
*/

std::string LLIR::IR::convert_var_type(LLIR::var_types type) {
    static const std::unordered_map<LLIR::var_types, std::string> typesMap = {
        {LLIR::var_types::UNDEFINED, "UNDEF"}, {LLIR::var_types::BOOLEAN, "bool"}, {LLIR::var_types::STRING, "str"}, {LLIR::var_types::NUMBER, "num"},
        {LLIR::var_types::ARRAY, "array"}, {LLIR::var_types::OBJECT, "object"}, {LLIR::var_types::FUNCTION, "function"},
        {LLIR::var_types::ANY, "any"}, {LLIR::var_types::Rule, "rule"}, {LLIR::var_types::Token, "token"},
        {LLIR::var_types::Rule_result, "Rule_result"}, {LLIR::var_types::Token_result, "Token_result"},
        {LLIR::var_types::CHAR, "char"}
    };
    return typesMap.at(type);
}


std::string LLIR::IR::convert_var_assing_values(LLIR::var_assign_values value, std::any data) {
    switch (value) {
        case LLIR::var_assign_values::STRING:
            //cpuf::printf("on String\n");
            return std::string(1, '"') + std::any_cast<std::string>(data) + std::string(1, '"');
        case LLIR::var_assign_values::VAR_REFER:
        {
            //cpuf::printf("ON var_refer\n");
            auto dt = std::any_cast<LLIR::var_refer>(data);
            std::string name = dt.var.name;
            for (const auto &el : dt.var.property_access)
                name += "." + el;
            if (dt.post_increament.value_or('\0') == '-') {
                name.insert(0, "--");
            } else if (dt.post_increament.value_or('\0') == '+') {
                name.insert(0, "++");
            }
            if (!dt.brace_expression.empty()) {
                name += '[' + convertExpression(dt.brace_expression, false) + ']';
            }
            if (dt.post_increament.value_or('\0') == '-') {
                name += "--";
            } else if (dt.post_increament.value_or('\0') == '+') {
                name += "++";
            }
            return name;
        }
        case LLIR::var_assign_values::NUMBER:
            cpuf::printf("on INT, type: {}\n", data.type().name());
            return std::to_string(std::any_cast<int>(data));
        case LLIR::var_assign_values::ARRAY:
        {
            //cpuf::printf("on array\n");
            auto arr = std::any_cast<LLIR::array>(data);
            std::string res = "[";
            for (auto &el : arr) {
                res += convertExpression(el, false);
                res += ',';
            }
            res += ']';
            return res;
        }
        case LLIR::var_assign_values::OBJECT:
        {
            //cpuf::printf("on object\n");
            auto obj = std::any_cast<LLIR::object>(data);
            std::string res = "{";
            for (const auto &[key, value] : obj) {
                res += key;
                res += ": ";
                res += convertExpression(value, false);
                res += ",";
            }
            res += "}";
            return res;
        }
        case LLIR::var_assign_values::FUNCTION_CALL:
            return convertFunctionCall(std::any_cast<function_call>(data));
        case LLIR::var_assign_values::EXPR:
            //cpuf::printf("On expr\n");
            return convertExpression(std::any_cast<stdu::vector<LLIR::expr>>(data), false);
        case LLIR::var_assign_values::CURRENT_POS:
        {
            auto dt = std::any_cast<double>(data);
            char sign = dt >= 0 ? '+' : '-';
            if (dt == 0)
                return current_pos_counter.top();
            return current_pos_counter.top() + sign + std::to_string((int) dt);
        }
        case LLIR::var_assign_values::CURRENT_CHARACTER:
            return "*pos";
        case LLIR::var_assign_values::TOKEN_NAME:
            // cpuf::printf("TOKEN_NAME: {}\n", data.type().name());
            return std::string("Tokens::") + corelib::text::join(std::any_cast<stdu::vector<std::string>>(data), "_");
    }
    switch (value) {
        case LLIR::var_assign_values::NONE:                  return "NONE";
        case LLIR::var_assign_values::True:                 return "TRUE";
        case LLIR::var_assign_values::False:                return "FALSE";
        case LLIR::var_assign_values::CURRENT_POS_COUNTER:   return "CURRENT_POS_COUNTER";
        case LLIR::var_assign_values::CURRENT_POS_SEQUENCE:  return "CURRENT_POS_SEQUENCE";
        case LLIR::var_assign_values::CURRENT_TOKEN:         return "CURRENT_TOKEN";
        case LLIR::var_assign_values::TOKEN_SEQUENCE:        return "TOKEN_SEQUENCE";
        default: return "NONE"; // Handle unknown values
    }
}
std::string LLIR::IR::convert_var_assing_types(LLIR::var_assign_types type) {
    switch (type) {
        case LLIR::var_assign_types::ASSIGN:    return "=";
        case LLIR::var_assign_types::ADD:       return "+=";
        case LLIR::var_assign_types::SUBSTR:    return "-=";
        case LLIR::var_assign_types::MULTIPLY:  return "*=";
        case LLIR::var_assign_types::DIVIDE:    return "/=";
        case LLIR::var_assign_types::MODULO:    return "%=";
        default: return "="; // Handle unknown values
    }
}
std::string LLIR::IR::conditionTypesToString(LLIR::condition_types type, std::any data) {
    if (type == LLIR::condition_types::CHARACTER) {
        //cpuf::printf("character\n");
        return std::string("'") + std::any_cast<char>(data) + std::string("'");
    } else if (type == LLIR::condition_types::ESCAPED_CHARACTER) {
        return std::string("'\\") + std::any_cast<char>(data) + std::string("'");
    } else if (type == LLIR::condition_types::CURRENT_CHARACTER) {
        //cpuf::printf("current_character\n");
        return "*pos";
    } else if (type == LLIR::condition_types::TOKEN_NAME) {
        return std::any_cast<LLIR::variable>(data).name + "->name()";
    } else if (type == LLIR::condition_types::TOKEN) {
        return "Tokens::" + std::any_cast<std::string>(data);
    } else if (type == LLIR::condition_types::NUMBER) {
        //cpuf::printf("number\n");
        return std::to_string(std::any_cast<long long>(data));
    } else if (type == LLIR::condition_types::STRING) {
        //cpuf::printf("string\n");
        return std::string(1, '"') + std::any_cast<std::string>(data) + std::string(1, '"');
    } else if (type == LLIR::condition_types::STRNCMP) {
        //cpuf::printf("strncmp\n");
        auto dt = std::any_cast<LLIR::strncmp>(data);
        if (dt.is_string) {
            return std::string("!STRNCMP(pos, \"") + dt.value.name + std::string("\")");
        } else {
            return std::string("!STRNCMP(pos, ") + dt.value.name + std::string(")");
        }
    } else if (type == LLIR::condition_types::VARIABLE) {
        cpuf::printf("type: {}", data.type().name());
        auto dt = std::any_cast<LLIR::var_refer>(data);
        std::string name = dt.var.name;
        for (const auto &el : dt.var.property_access)
            name += "." + el;
        if (dt.post_increament.value_or('\0') == '-') {
            name.insert(0, "--");
        } else if (dt.post_increament.value_or('\0') == '+') {
            name.insert(0, "++");
        }
        if (!dt.brace_expression.empty()) {
            name += '[' + convertExpression(dt.brace_expression, false) + ']';
        }
        if (dt.post_increament.value_or('\0') == '-') {
            name += "--";
        } else if (dt.post_increament.value_or('\0') == '+') {
            name += "++";
        }
        return name;
    } else if (type == LLIR::condition_types::SUCCESS_CHECK) {
        //cpuf::printf("success_check\n");
        return std::any_cast<std::string>(data) + ".res";
    } else if (type == LLIR::condition_types::HEX) {
        //cpuf::printf("hex\n");
        return std::string("0x") + std::any_cast<std::string>(data);
    } else if (type == LLIR::condition_types::BIN) {
        //cpuf::printf("bin\n");
        return std::string("0b") + std::any_cast<std::string>(data);
    } else if (type == LLIR::condition_types::RVALUE) {
        auto dt = std::any_cast<LLIR::assign>(data);
        return convert_var_assing_values(dt.kind, dt.data);
    } else if (type == LLIR::condition_types::METHOD_CALL) {
        return convertMethodCall(std::any_cast<LLIR::method_call>(data));
    } else if (type == LLIR::condition_types::FUNCTION_CALL) {
        return convertFunctionCall( std::any_cast<LLIR::function_call>(data));
    } else if (type == LLIR::condition_types::CURRENT_TOKEN) {
        if (data.has_value()) {
            auto dt = std::any_cast<LLIR::current_token>(data);
            auto op = conditionTypesToString(dt.op, std::any());
            return "CURRENT_TOKEN " + op + " " + dt.name;
        } else {
            return "CURRENT_TOKEN";
        }
    }
    static const std::unordered_map<LLIR::condition_types, std::string> condTypesMap = {
        {LLIR::condition_types::GROUP_OPEN, "("}, {LLIR::condition_types::GROUP_CLOSE, ")"},
        {LLIR::condition_types::AND, "&&"}, {LLIR::condition_types::OR, "||"}, {LLIR::condition_types::NOT, "!"},
        {LLIR::condition_types::EQUAL, "=="}, {LLIR::condition_types::NOT_EQUAL, "!="},
        {LLIR::condition_types::HIGHER, ">"}, {LLIR::condition_types::LOWER, "<"},
        {LLIR::condition_types::HIGHER_OR_EQUAL, ">="}, {LLIR::condition_types::LOWER_OR_EQUAL, "<="},
        {LLIR::condition_types::LEFT_BITWISE, "<<"}, {LLIR::condition_types::RIGHT_BITWISE, ">>"},
        {LLIR::condition_types::BITWISE_AND, "&"}, {LLIR::condition_types::BITWISE_ANDR, "^"},
        {LLIR::condition_types::ADD, "+"}, {LLIR::condition_types::SUBSTR, "-"},
        {LLIR::condition_types::MULTIPLY, "*"}, {LLIR::condition_types::DIVIDE, "/"},
        {LLIR::condition_types::MODULO, "%"}, {LLIR::condition_types::CURRENT_TOKEN, "CURRENT_TOKEN"},
        {LLIR::condition_types::TOKEN_SEQUENCE, "pos"},
    };
    return condTypesMap.at(type);
}
std::string LLIR::IR::convertFunctionCall(LLIR::function_call call) {
    std::string res = call.name + "(";
    for (auto param : call.params) {
        res += convertExpression(param, false);
    }
    res += ')';
    return res;
}
std::string LLIR::IR::convertAssign(LLIR::assign asgn) {
    if (asgn.kind == LLIR::var_assign_values::FUNCTION_CALL)
        return convertFunctionCall(std::any_cast<LLIR::function_call>(asgn.data));
    return convert_var_assing_values(asgn.kind, asgn.data);
}
void LLIR::IR::convertVariable(LLIR::variable var, std::ostream& out) {
    out << convert_var_type(var.type.type) << " " << var.name << " = " << convertAssign(var.value);
}

std::string LLIR::IR::convertExpression(LLIR::Expression expression, bool with_braces) {
    std::string result;
    if (with_braces)
        result += '(';
    for (int i = 0; i < expression.size(); i++) {
        LLIR::expr current = expression[i];
        if (
            current.id == LLIR::condition_types::AND ||
            current.id == LLIR::condition_types::OR ||
            current.id == LLIR::condition_types::EQUAL ||
            current.id == LLIR::condition_types::NOT_EQUAL
            ) {
            result += ' ';
            result += conditionTypesToString(current.id, current.value);
            result += ' ';
        } else {
            result += conditionTypesToString(current.id, current.value);
        }
    }
    if (with_braces)
        result += ")\n";
    return result;
}
void LLIR::IR::convertBlock(stdu::vector<LLIR::member> block, std::ostream& out) {
    out << std::string(indentLevel, '\t') << "{\n";
    indentLevel++;
    convertMembers(block, out);
    indentLevel--;
    out << std::string(indentLevel, '\t') << "}";
}
void LLIR::IR::convertCondition(LLIR::condition cond, std::ostream& out) {
    out << convertExpression(cond.expression, true);
    convertBlock(cond.block, out);
    if (!cond.else_block.empty()) {
        out << "\n" << std::string(indentLevel, '\t') << "else \n";
        convertBlock(cond.else_block, out);
    }
}


void LLIR::IR::convertAssignVariable(LLIR::variable_assign var, std::ostream &out) {
    out << var.name << " " << convert_var_assing_types(var.assign_type) << " " << convertAssign(var.value);
}

std::string LLIR::IR::convertMethodCall(LLIR::method_call method) {
    // Implement method call conversion with proper indentation
    std::string res = method.var_name;
    for (auto call : method.calls) {
        res += '.';
        res += convertFunctionCall(call);
    }
    return res;
}

std::string LLIR::IR::convertDataBlock(const LLIR::DataBlock &dtb) {
    // Implement method call conversion with proper indentation
    std::string res;
    res += "data = ";
    if (dtb.empty())
        return "";
    if (dtb.is_inclosed_map()) {
        res += "\n";
        for (const auto &[key, value] : dtb.getInclosedMap()) {
            res += std::string(indentLevel + 1, '\t');
            res += key;
            res += ": ";
            res += convertExpression(value.first, false);
            res += " # ";
            res += convert_var_type(value.second.type);
            res += '\n';
        }
        res += std::string(indentLevel, '\t') + ";";
    } else {
        res += convertExpression(dtb.getRegularDataBlock().first, false);
        res += " # ";
        res += convert_var_type(dtb.getRegularDataBlock().second.type);
    }
    res += '\n';
    return res;
}
void LLIR::IR::convertSwitch(const switch_statement &statement, std::ostream &out) {
    out << "switch " << convertExpression(statement.expression, true) << std::string(indentLevel, '\t') << "{\n";
    indentLevel++;
    for (const auto &c : statement.cases) {
        out << std::string(indentLevel, '\t') << "case " << convertAssign(c.name) << ": {\n";
        indentLevel++;
        convertMembers(c.block, out);
        out << '\n' << std::string(indentLevel, '\t') << "break;\n";
        indentLevel--;
        out << '\n' << std::string(indentLevel, '\t') << "}\n";
    }
    indentLevel--;
    out << std::string(indentLevel, '\t') << "}\n";
}
void LLIR::IR::convertMember(const LLIR::member& mem, std::ostream& out) {
    out << std::string(indentLevel, '\t');
    switch (mem.type)
    {
    case types::VARIABLE:
        convertVariable(std::any_cast<LLIR::variable>(mem.value), out);
        break;
    case types::METHOD_CALL:
        out << convertMethodCall(std::any_cast<LLIR::method_call>(mem.value));
        break;
    case types::IF:
        out << "if ";
        convertCondition(std::any_cast<LLIR::condition>(mem.value), out);
        break;
    case types::WHILE:
        out << "while ";
        convertCondition(std::any_cast<LLIR::condition>(mem.value), out);
        break;
    case types::DOWHILE:
        out << "do\n";
        convertBlock(std::any_cast<LLIR::condition>(mem.value).block, out);
        out << std::string(indentLevel, '\t') << "while";
        out << convertExpression(std::any_cast<LLIR::condition>(mem.value).expression, true);
        break;
    case types::INCREASE_POS_COUNTER:
        out << current_pos_counter.top() << "++";
        break;
    case LLIR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH: {
        auto var = std::any_cast<std::string>(mem.value);
        out << current_pos_counter.top() << " += " << var << ".token.length()";
        break;
    }
    case LLIR::types::RESET_POS_COUNTER:
        break;
    case types::ASSIGN_VARIABLE:
        convertAssignVariable(std::any_cast<LLIR::variable_assign>(mem.value), out);
        break;
    case types::BREAK_LOOP:
        out << "break";
        break;
    case types::CONTINUE_LOOP:
        out << "continue";
        break;
    case types::EXIT:
        out << "return {}";
        break;
    case types::ERR:
        out << "error" << std::any_cast<std::string>(mem.value) << '\n';
        break;
    case types::SKIP_SPACES:
        if (std::any_cast<bool>(mem.value)) // isToken
            out << "skipspaces(pos)";
        else
            out << "skipspaces(TOKEN_SEQUENCE)";
        break;
    case types::PUSH_POS_COUNTER: {
        out << "auto " << std::any_cast<std::string>(mem.value) << " = " << current_pos_counter.top();
        current_pos_counter.push(std::any_cast<std::string>(mem.value));
        break;
    }
    case types::POP_POS_COUNTER: {
        auto el = current_pos_counter.top();
        current_pos_counter.pop();
        out << current_pos_counter.top() << " = " << el;
        break;
    }
    case types::JUMP:
        out << "jump " << corelib::text::join(std::any_cast<stdu::vector<std::string>>(mem.value), "_");
        break;
    case types::JUMP_FROM_VARIABLE:
        out << "jump $" << std::any_cast<std::string>(mem.value);
        break;
    case types::EMPTY:
        return;
    case types::SWITCH:
        convertSwitch(std::any_cast<const switch_statement&>(mem.value), out);
        break;
    default:
        throw Error("Undefined IR member: {}\n", (int) mem.type);
    }
    out << '\n';
}

void LLIR::IR::convertMembers(const LLIR::Nodes &members, std::ostream& out) {
    for (const auto &mem : members)
        convertMember(mem, out);
}
void LLIR::IR::convertData(const LLIR::Data &data, std::ostream& out) {
    if (corelib::text::isUpper(data.name.back())) {
        // token
        out << "Rule(" << corelib::text::join(data.name, "_") << ") {";
    } else {
        // rule
        out << "Token(" << corelib::text::join(data.name, "_") << ") {";
    }
    out << '\n';
    indentLevel++;
    convertMembers(data.members, out);
    if (!data.block.empty()) {
        out << "\n\t" << convertDataBlock(data.block);
    }
    indentLevel--;
    out << "}\n";
}
void LLIR::IR::printIR(std::ostream& out) {
    current_pos_counter.push("pos");
    for (const auto &d : data)
        convertData(d, out);
}

void LLIR::IR::outputIRToFile(std::string filename) {
    int identLevel = 0;
    std::ofstream file(filename);
    if (file.is_open()) {
        printIR(file);
        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << "\n";
    }
}

void LLIR::IR::outputIRToConsole() {
    int identLevel = 0;
    printIR(std::cout);
}