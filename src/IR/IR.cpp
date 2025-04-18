#include <IR/IR.h>
#include <internal_types.h>
#include <token_management.h>
#include <corelib.h>
#include <parser.h>
#include <cpuf/hex.h>
LLIR::LLIR(const Parser::Tree &tree, bool tokensOnly, bool rulesOnly) : tree(&tree), tokensOnly(tokensOnly), rulesOnly(rulesOnly) {}
LLIR::LLIR(const Parser::Tree *tree, bool tokensOnly, bool rulesOnly) : tree(tree), tokensOnly(tokensOnly), rulesOnly(rulesOnly) {}
LLIR::LLIR(const Parser::Tree &tree, const std::vector<Parser::Rule>& rules, bool tokensOnly, bool rulesOnly) 
    : tree(&tree), rules(&rules), tokensOnly(tokensOnly), rulesOnly(rulesOnly) {}
LLIR::LLIR(const Parser::Tree *tree, const std::vector<Parser::Rule>& rules, bool tokensOnly, bool rulesOnly) 
    : tree(tree), rules(&rules), tokensOnly(tokensOnly), rulesOnly(rulesOnly) {}
LLIR::LLIR(LLIR& ir) : tree(ir.tree), data(std::move(ir.data)) {}
// a structure used to cout
void LLIR::add(LLIR &repr) {
    data.insert(data.end(), repr.data.begin(), repr.data.end());
}
void LLIR::add(std::vector<LLIR::member> repr) {
    data.insert(data.end(), repr.begin(), repr.end());
}
void LLIR::push(LLIR::member member) {
    data.push_back(member);
}
void LLIR::pop() {
    data.pop_back();
};
void LLIR::push_begin(LLIR::member member) {
    data.insert(data.begin(), member);
}
void LLIR::pop_begin() {
    data.erase(data.begin());
};
size_t LLIR::size() {
    return data.size();
}
bool LLIR::empty() {
    return data.empty();
}
auto LLIR::makeIR() -> std::vector<LLIR::node_ret_t> {
    if (rules == nullptr) {
        treeToIr(*tree);
    } else {
        LLIR ir = rulesToIr(*rules);
        update(ir);
        data = ir.data;
        success_vars = ir.success_vars;
    }
    return success_vars;
}
void LLIR::optimizeIR() {
    raiseVarsTop();
}
const std::vector<LLIR::member>& LLIR::getData() const{
    return data;
}
std::vector<LLIR::member>& LLIR::getDataRef() {
    return data;
}
const Parser::Tree* LLIR::getTree() {
    return tree;
}
void LLIR::erase_begin() {
    data.erase(data.begin());
}
void LLIR::clear_thread() {
    groups.clear();
    elements.clear();
    variable_count = 0;
    isToken = false;
    insideLoop = false;
    addSpaceSkip = false;
    success_vars.clear();
    vars.clear();
}
void LLIR::proceed(LLIR& ir) {
    variable_count = ir.variable_count;
    isToken = ir.isToken;
    insideLoop = ir.insideLoop;
    addSpaceSkip = ir.addSpaceSkip;
    fullname = ir.fullname;
    vars = ir.vars;
    isFirst = ir.isFirst;
}
void LLIR::update(LLIR &ir) {
    variable_count = ir.variable_count;
    isToken = ir.isToken;
    insideLoop = ir.insideLoop;
    addSpaceSkip = ir.addSpaceSkip;
    vars.insert(vars.end(), ir.vars.begin(), ir.vars.end());
    elements.insert(elements.end(), ir.elements.begin(), ir.elements.end());
    groups.insert(groups.end(), ir.groups.begin(), ir.groups.end());
}
void LLIR::setIsToken(bool isToken) {
    this->isToken = isToken;
}
LLIR::variable createEmptyVariable(std::string name) {
    LLIR::variable var {
        name,
        {LLIR::var_types::UNDEFINED},
        LLIR::var_assign_values::NONE,
    };
    return var;
}
std::string LLIR::generateVariableName() {
    return std::string("_") + std::to_string(variable_count++);
}
std::string LLIR::getErrorName(Parser::Rule rule) {
    if (rule.name == Parser::Rules::Rule_rule) {
        auto data = rule.as<obj_t>();
        rule = std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
    }
    switch (rule.name) {
        case Parser::Rules::Rule_group:
        {
            auto data = rule.as<obj_t>();
            auto val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "val"));
            return getErrorName(val[0]);
        }
        case Parser::Rules::Rule_csequence: 
        {
            std::string name;
            auto data = rule.as<obj_t>();
            auto _not = std::any_cast<bool>(corelib::map::get(data, "not"));
            auto val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "val"));

            if (_not) {
                name = "not ";
            }
            for (size_t i = 0; i < val.size(); i++) {
                auto r = val[i];
                switch (r.name) {
                    case Parser::Rules::Rule_csequence_symbol:
                    {
                        auto val = r.as<std::string>();
                        name += val;
                        if (i + 2 == val.size()) {
                            name += " or ";
                        } else if (i + 1 < val.size()) {
                            name += ", ";
                        }
                        break;
                    }
                    case Parser::Rules::Rule_csequence_diapason:
                    {
                        auto val = r.as<std::vector<Parser::Rule>>();
                        auto first_rule = val[0].as<std::string>();
                        auto second_rule = val[1].as<std::string>();
                        name += first_rule + "-" + second_rule;
                        if (i + 2 == val.size()) {
                            name += " or ";
                        } else if (i + 1 < val.size()) {
                            name += ", ";
                        }
                        break;
                    }
                    case Parser::Rules::Rule_csequence_escape:
                    {
                        auto val = r.as<std::string>();
                        name += '\\' + val;
                        if (i + 2 == val.size()) {
                            name += " or ";
                        } else if (i + 1 < val.size()) {
                            name += ", ";
                        }
                        break;
                    }
                }
            }
            return name;
        }
        case Parser::Rules::string: {
            return '"' + rule.as<std::string>() + '"';
        }
        case Parser::Rules::Rule_hex:
            return "0x" + rule.as<std::string>();
        case Parser::Rules::Rule_bin: 
            return "0b" + rule.as<std::string>();
        case Parser::Rules::Rule_other:
        {
            auto name = rule.as<rule_other>();
            if (name.is_autogenerated) {
                auto _tree = *tree;
                auto rule = Tokens::find_token_in_tree(_tree, name.fullname);
                if (rule == nullptr) {
                    return corelib::text::ToLower(name.name);
                }
                auto data = rule->as<obj_t>();
                auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
                return getErrorName(rules[0]);
            } else {
                return corelib::text::ToLower(name.name);
            }
        }
            break;
        case Parser::Rules::Rule_escaped:
            return "\\" + rule.as<std::string>();
            break;
        case Parser::Rules::Rule_any:
            return "any symbol";
            break;
        case Parser::Rules::Rule_op:
        {
            auto data = rule.as<std::vector<Parser::Rule>>();
            std::string result = "";
            for (auto &rule : data) {
                result += getErrorName(rule);
                if (&rule != &data.back()) {
                    result += " or ";
                }
            }
            return result;
        }
        default:
            throw Error("Get name of undefined rule '%s'", Parser::RulesToString(rule.name));
    }
}
template<typename T, std::enable_if_t<std::is_same<T, std::vector<LLIR::member>>::value || std::is_same<T, std::deque<LLIR::member>>::value, int> = 0>
void processExitStatements(T &values) {
    for (auto &el : values) {
        if (el.type == LLIR::types::IF || el.type == LLIR::types::WHILE || el.type == LLIR::types::DOWHILE) {
            auto &condition = std::any_cast<LLIR::condition&>(el.value); // Avoid unnecessary copies

            // Process the block and else block of the condition recursively
            processExitStatements(condition.block);
            processExitStatements(condition.else_block);

            // Ensure that any EXIT statements within the blocks are replaced with BREAK_LOOP
            for (auto &unit : condition.block) {
                if (unit.type == LLIR::types::EXIT) {
                    unit.type = LLIR::types::BREAK_LOOP; // Replacing EXIT with BREAK_LOOP
                } else if (unit.type == LLIR::types::IF || unit.type == LLIR::types::WHILE || unit.type == LLIR::types::DOWHILE) {
                    auto &cond = std::any_cast<LLIR::condition&>(unit.value);

                    processExitStatements(cond.block); // Recursive call on nested blocks
                    processExitStatements(cond.else_block); // Recursive call on else blocks
                }
            }
        }
    }
}


LLIR::variable LLIR::createSuccessVariable() {
    LLIR::variable var = createEmptyVariable("success" + generateVariableName());
    var.type = {LLIR::var_types::BOOLEAN};
    var.value = {LLIR::var_assign_values::_FALSE};
    return var;
}

void LLIR::addPostLoopCheck(const Parser::Rule &rule, const LLIR::variable &var, bool addError) {
    std::vector<LLIR::member> block = {{ LLIR::types::EXIT }};
    if (addError && !isFirst) {
        block.insert(block.begin(), { LLIR::types::ERR, getErrorName(rule)});
    }
    LLIR::condition check_cond = {
        { 
            {LLIR::condition_types::NOT}, 
            { LLIR::condition_types::VARIABLE, var },
        },
        block
    };
    push({LLIR::types::IF, check_cond});
}
void LLIR::handle_plus_qualifier(const Parser::Rule &rule, LLIR::condition loop, bool addError) {
    LLIR::variable var = createSuccessVariable();
    loop.block.push_back({LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::_TRUE}});
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::WHILE, loop});
    addPostLoopCheck(rule, var, addError);
}
template<typename T, std::enable_if_t<std::is_same<T, std::vector<LLIR::member>>::value || std::is_same<T, std::deque<LLIR::member>>::value, int> = 0>
void replaceToPrevChar(T &elements, int i) {
    for (; i < elements.size(); i++) {
        auto &el = elements[i];
        if (el.type == LLIR::types::IF || el.type == LLIR::types::WHILE || el.type == LLIR::types::DOWHILE) {
            // replace CURRENT_CHARACTER to PREV_CHARACTER
            auto val = std::any_cast<LLIR::condition>(el.value);
            for (auto &expr : val.expression) {
                if (expr.id == LLIR::condition_types::STRNCMP) {
                    expr.id = LLIR::condition_types::STRNCMP_PREV;
                }

            }
            replaceToPrevChar(val.block, 0);
            if (el.type == LLIR::types::IF)
                replaceToPrevChar(val.else_block, 0);
            elements[i].value = val;
        }
    }
}
std::vector<LLIR::member> createDefaultBlock(LLIR::variable var, LLIR::variable svar) {
    return {
        {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, LLIR::var_assign_types::ADD, LLIR::var_assign_values::CURRENT_POS_SEQUENCE}},
        {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::_TRUE}},
        {LLIR::types::INCREASE_POS_COUNTER}
    };
}
std::vector<LLIR::member> createDefaultBlock(LLIR::variable svar) {
    return {
        {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::_TRUE}},
        {LLIR::types::INCREASE_POS_COUNTER}
    };
}
std::vector<LLIR::member> createDefaultBlock() {
    return {
        {LLIR::types::INCREASE_POS_COUNTER}
    };
}
template<typename T, std::enable_if_t<std::is_same<T, std::vector<LLIR::member>>::value || std::is_same<T, std::deque<LLIR::member>>::value, int> = 0>
void replace_exit_to_unsuccess(T &elements, LLIR::variable svar) {
    for (auto &el : elements) {
        if (el.type == LLIR::types::IF) {
            auto block = std::any_cast<LLIR::condition>(el.value).block;
            replace_exit_to_unsuccess(block, svar);
            el.value = block;
        } else if (el.type == LLIR::types::EXIT) {
            el = {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, {LLIR::var_assign_values::_FALSE}}};
        }
    }
}
char getEscapedChar(char in) {
    switch (in)
    {
    case 'n': return '\n';   // Newline
    case 'r': return '\r';   // Carriage return
    case 't': return '\t';   // Horizontal tab
    case 'a': return '\a';   // Bell (alert)
    case 'b': return '\b';   // Backspace
    case 'f': return '\f';   // Form feed (new page)
    case 'v': return '\v';   // Vertical tab
    case '\\': return '\\';  // Backslash
    case '\'': return '\'';  // Single quote
    case '"': return '"';    // Double quote
    default: return in;      // Return the character itself if not an escape sequence
    }
}

LLIR::member LLIR::createDefaultCall(std::vector<LLIR::member> &block, LLIR::variable var, const std::string &name, std::vector<LLIR::expr> &expr) {
    auto function_call = LLIR::function_call {
        name,
        {{LLIR::var_assign_values::TOKEN_SEQUENCE}},
        
    };
    auto var_assign = LLIR::variable_assign {
        var.name, 
        LLIR::var_assign_types::ASSIGN,
        { LLIR::var_assign_values::FUNCTION_CALL, function_call }
    };
    var.property_access = {"status"};
    expr = {
        {LLIR::condition_types::VARIABLE, var}
    };
    return {LLIR::types::ASSIGN_VARIABLE, var_assign};
}
LLIR::variable LLIR::add_shadow_variable(std::vector<LLIR::member> &block, const LLIR::variable &var) {
    LLIR::variable shadow_var = createEmptyVariable("shadow" + generateVariableName());
    auto type = var.type;
    if (type.type == LLIR::var_types::Rule_result)
        type.type = LLIR::var_types::Rule;
    else if (type.type == LLIR::var_types::Token_result)
        type.type = LLIR::var_types::Token;
    shadow_var.type = {LLIR::var_types::ARRAY, {type}};
    push({LLIR::types::VARIABLE, shadow_var});
    block.push_back({LLIR::types::METHOD_CALL, LLIR::method_call { shadow_var.name, {LLIR::function_call {"push", {LLIR::assign {LLIR::var_assign_values::VARIABLE, var}}}}}});
    return shadow_var;
}
LLIR::variable LLIR::pushBasedOnQualifier(const Parser::Rule &rule, std::vector<LLIR::expr> &expr, std::vector<LLIR::member> &block, const LLIR::variable &var, const LLIR::variable &svar, char quantifier, bool add_shadow_var) {
    //block.push_back({IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}});
    LLIR::variable shadow_variable;
    if ((insideLoop || quantifier == '+' || quantifier == '*') && add_shadow_var) {
       shadow_variable = add_shadow_variable(block, var);
       add_shadow_var = false;
    }
    switch (quantifier) {
        case '+':
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            handle_plus_qualifier(rule, {expr, block});
            break;
        case '*': {
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            push({LLIR::types::WHILE, LLIR::condition{expr, block}});
            //member.push(pop);
            break;
        }
        case '?':
            push({LLIR::types::IF, LLIR::condition{expr, block}});
            break;
        default:
            // add the negative into condition
            expr.insert(expr.begin(), {LLIR::condition_types::NOT});
            expr.insert(expr.begin() + 1, {LLIR::condition_types::GROUP_OPEN});
            expr.push_back({LLIR::condition_types::GROUP_CLOSE});
            // add exit statement
            std::vector<LLIR::member> blk = {{LLIR::types::EXIT}};
            if (!isFirst) {
                blk.insert(blk.begin(), {LLIR::types::ERR, getErrorName(rule)});
            }
            push({LLIR::types::IF, LLIR::condition{expr, blk}});
            add(block);
            break;
    }
    return shadow_variable;
}
// function to push based on qualifier for Rule_other
LLIR::variable LLIR::pushBasedOnQualifier_Rule_other(const Parser::Rule &rule, std::vector<LLIR::expr> &expr, std::vector<LLIR::member> &block, const LLIR::variable &var, const LLIR::variable &svar, const LLIR::member &call, char quantifier, bool add_shadow_var) {
    //block.push_back({IR::types::ASSIGN_VARIABLE, IR::variable_assign {svar.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}});
    LLIR::variable shadow_variable;
    if (insideLoop|| quantifier == '+' || quantifier == '*') {
        shadow_variable = add_shadow_variable(block, var);
        add_shadow_var = false;
    }
    switch (quantifier) {
        case '+':
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            block.push_back(call);
            handle_plus_qualifier(rule, LLIR::condition {expr, block});
            break;
        case '*': {
            if (add_shadow_var)
                shadow_variable = add_shadow_variable(block, var);
            block.push_back(call);
            push({LLIR::types::WHILE, LLIR::condition{expr, block}});
            break;
        }
        case '?':
            push({LLIR::types::IF, LLIR::condition{expr, block}});
            break;
        default:
        {
            // add the negative into condition
            expr.insert(expr.begin(), {LLIR::condition_types::NOT});
            expr.insert(expr.begin() + 1, {LLIR::condition_types::GROUP_OPEN});
            expr.push_back({LLIR::condition_types::GROUP_CLOSE});
            // add exit statement
            std::vector<LLIR::member> blk = {{LLIR::types::EXIT}};
            if (!isFirst) {
                blk.insert(blk.begin(), {LLIR::types::ERR, getErrorName(rule)});
            }
            push({LLIR::types::IF, LLIR::condition{expr, blk}});
            add(block);
            break;
        }
    }
    return shadow_variable;
}
LLIR::variable LLIR::affectIrByQuantifier(const Parser::Rule &rule, const LLIR::variable &var, char quantifier) {
    LLIR::variable shadow_var;
    if (quantifier == '*' || quantifier == '+') {
        LLIR::condition loop = { { { LLIR::condition_types::NUMBER, (long long) 1 } }, {} };
        loop.block = data;
        data.clear();
        processExitStatements(loop.block);
        if (var.type.type != LLIR::var_types::UNDEFINED && var.type.type != LLIR::var_types::STRING)
            shadow_var = add_shadow_variable(loop.block, var);
        if (quantifier == '+') {
            handle_plus_qualifier(rule, loop);
        } else {
            push({LLIR::types::WHILE, loop});
        }
    } else if (quantifier == '?') {
        LLIR::condition loop = { { {LLIR::condition_types::NUMBER, (long long) 0} } };
        loop.block = data;
        data.clear();
        processExitStatements(loop.block);
        if (insideLoop && var.type.type != LLIR::var_types::UNDEFINED) {
            shadow_var = add_shadow_variable(loop.block, var);
        }
        push({ LLIR::types::DOWHILE, loop });
    }
    return shadow_var;
}
LLIR::assign LLIR::TreeAnyDataToIR(const Parser::Rule &value) {
    auto val = std::any_cast<Parser::Rule>(value.data);
    LLIR::assign newval;
    switch (val.name)
    {
    case Parser::Rules::string:
        //cpuf::printf("string, type: %s\n", val.data.type().name());
        newval.kind = LLIR::var_assign_values::STRING;
        newval.data = std::any_cast<std::string>(val.data);
        break;
    case Parser::Rules::var_refer:
    {        
        //cpuf::printf("var_refer\n");
        LLIR::var_refer refer;
        //cpuf::printf("1\n");
        auto data = std::any_cast<obj_t>(val.data);
        //cpuf::printf("2\n");
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        //cpuf::printf("3\n");
        auto name_str = std::any_cast<std::string>(name.data);
        //cpuf::printf("4\n");
        auto pre = std::any_cast<bool>(corelib::map::get(data, "pre"));
        //cpuf::printf("5\n");
        auto post = std::any_cast<bool>(corelib::map::get(data, "post"));
        refer.pre_increament = pre;
        refer.post_increament = post;
        refer.name = name_str;
        // skip brace expression for now as it is not used in rules for parser
        newval.kind = LLIR::var_assign_values::VAR_REFER;
        newval.data = refer;
        break;
    }

    case Parser::Rules::boolean: 
    {
        //cpuf::printf("boolean\n");
        auto data = std::any_cast<obj_t>(val.data);
        auto val = std::any_cast<int>(corelib::map::get(data, "val"));
        newval.kind = val ? LLIR::var_assign_values::_TRUE : LLIR::var_assign_values::_FALSE;
        break;
    }
    case Parser::Rules::number: 
    {
        //cpuf::printf("number\n");
        auto data = std::any_cast<obj_t>(val.data);
        auto full = std::any_cast<std::string>(corelib::map::get(data, "full"));
        newval.kind = LLIR::var_assign_values::NUMBER;
        newval.data = full;
        break;
    }
    case Parser::Rules::array:
    {
        //cpuf::printf("array\n");
        auto data = std::any_cast<std::vector<Parser::Rule>>(val.data);
        LLIR::array arr;
        for (auto &el : data) {
            arr.push_back(TreeAnyDataToIR(el));
        }
        newval.kind = LLIR::var_assign_values::ARRAY;
        newval.data = arr;
        break;
    }
    case Parser::Rules::object:
    {
        //cpuf::printf("object\n");
        auto data = std::any_cast<obj_t>(val.data);
        auto key = std::any_cast<Parser::Rule>(corelib::map::get(data, "key"));
        auto value = std::any_cast<Parser::Rule>(corelib::map::get(data, "value"));
        auto keys = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "keys"));
        auto values = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "values"));
        
        keys.insert(keys.begin(), key);
        values.insert(values.begin(), value);
        LLIR::object obj;
        for (int i = 0; i < keys.size(); i++) {
            auto key = keys[i];
            auto value = values[i];
            auto strkey = std::any_cast<std::string>(key.data);
            auto value_data = TreeAnyDataToIR(value);
            obj[strkey] = value_data;
        }
        newval.kind = LLIR::var_assign_values::OBJECT;
        newval.data = obj;
        break;
    }
    case Parser::Rules::accessor:
    {
        //cpuf::printf("accessor\n");
        auto data = std::any_cast<obj_t>(val.data);
        auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
        auto second = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "second"));
        second.insert(second.begin(), first);
        for (auto &el : second) {
            el = std::any_cast<Parser::Rule>(el.data);
        }
        LLIR::accessor mem = {second};
        newval.kind = LLIR::var_assign_values::ACCESSOR;
        newval.data = mem;
        break;
    }
    default:
        throw Error("Undefined rule");
        break;
    }
    return newval;
}
LLIR::function_call LLIR::TreeFunctionToIR(const Parser::Rule &rule) {
    LLIR::function_call call;
    auto data = std::any_cast<obj_t>(rule.data);
    call.name = std::any_cast<std::string>(std::any_cast<Parser::Rule>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name"))).data);
    auto body = std::any_cast<Parser::Rule>(corelib::map::get(data, "body")); 
    auto params = std::any_cast<std::vector<Parser::Rule>>(std::any_cast<Parser::Rule>(body.data).data);
    std::vector<LLIR::assign> new_params;
    for (auto arg : params) {
        new_params.push_back(TreeAnyDataToIR(arg));
    }
    call.params = new_params;
    return call;
}

LLIR::method_call LLIR::TreeMethodCallToIR(const Parser::Rule &rule) {
    LLIR::method_call method_call;
    auto var_rule_data = std::any_cast<obj_t>(rule.data);
    auto id = std::any_cast<Parser::Rule>(corelib::map::get(var_rule_data, "object"));
    auto call = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(var_rule_data, "call"));
    method_call.var_name = std::any_cast<std::string>(id.data);
    std::vector<LLIR::function_call> calls;
    for (auto cl : call) {
        calls.push_back(TreeFunctionToIR(cl));
    }
    method_call.calls = calls;
    return method_call;
}
LLIR::var_type LLIR::deduceVarTypeByValue(Parser::Rule mem) {
    LLIR::var_type type;
    if (mem.name == Parser::Rules::Rule_rule) {
        auto memdata = std::any_cast<obj_t>(mem.data);
        mem = std::any_cast<Parser::Rule>(corelib::map::get(memdata, "val"));
    }
    if (mem.name == Parser::Rules::Rule_group) {
        auto data = std::any_cast<obj_t>(mem.data);
        auto group = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "val"));
        if (group.size() == 0) {
            return {LLIR::var_types::UNDEFINED};
        } else {
            if (group.size() > 1) {
                for (auto i = 0; i < group.size(); i++) {
                    if (deduceVarTypeByValue(group[i]).type != LLIR::var_types::STRING)
                        return {LLIR::var_types::UNDEFINED};
                }
                return {LLIR::var_types::STRING};
            }

            return deduceVarTypeByValue(group[0]);
        }
    } else if (mem.name == Parser::Rules::Rule_op) {
        LLIR::var_type type = {LLIR::var_types::UNDEFINED};
        auto val = std::any_cast<std::vector<Parser::Rule>>(mem.data);
        if (val.size() == 0)
            return {LLIR::var_types::UNDEFINED};
        for (auto el : val) {
            auto el_data = std::any_cast<obj_t>(el.data);
            auto el_val = std::any_cast<Parser::Rule>(corelib::map::get(el_data, "val"));
            if (type.type == LLIR::var_types::UNDEFINED) {
                type = deduceVarTypeByValue(el_val);
            } else if (deduceVarTypeByValue(el_val).type != type.type) {
                return {LLIR::var_types::ANY};
            }
        }
        return type;
    } else if (mem.name == Parser::Rules::Rule_other) {
        auto data = std::any_cast<rule_other>(mem.data);
        return corelib::text::isUpper(data.name) ? LLIR::var_type {LLIR::var_types::Token} : LLIR::var_type {LLIR::var_types::Rule};
    }
    return {LLIR::var_types::STRING};
}
LLIR::var_type LLIR::cllTreeCsupportTypeToIR(const Parser::Rule &rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    bool is_unsigned = std::any_cast<bool>(corelib::map::get(data, "is_unsigned"));
    auto val = std::any_cast<std::string>(corelib::map::get(data, "val"));
    // cpuf::printf("3, type: %s\n", corelib::map::get(data, "template").type().name());
    // auto templ = std::any_cast<Parser::Rule>(corelib::map::get(data, "template"));
    // std::vector<Parser::Rule> templ_val;
    // if (templ.data.has_value()) {
    //     cpuf::printf("4\n");
    //     templ_val = std::any_cast<std::vector<Parser::Rule>>(templ.data);
    // }
    LLIR::var_types result;
    if (val == "char")
        result = LLIR::var_types::CHAR;
    else if (val == "short")
        result = LLIR::var_types::SHORT;
    else if (val == "int")
        result = LLIR::var_types::INT;
    else if (val == "long")
        result = LLIR::var_types::LONG;
    else if (val == "long long")
        result = LLIR::var_types::LONGLONG;
    
    if (is_unsigned)
        result = static_cast<LLIR::var_types>(static_cast<int>(result) + 1); // result++
    return { result };
    throw Error("Undefined csupport type");
}
LLIR::var_type LLIR::cllTreeTypeToIR(const Parser::Rule &rule) {
    auto data = std::any_cast<Parser::Rule>(rule.data);
    if (data.name == Parser::Rules::cll_csupport_types)
        return cllTreeCsupportTypeToIR(data);
    else
        return cllTreeAbstactTypeToIR(data);
}
LLIR::var_type LLIR::cllTreeAbstactTypeToIR(const Parser::Rule &rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    auto val = std::any_cast<std::string>(corelib::map::get(data, "type"));
    auto templ = std::any_cast<Parser::Rule>(corelib::map::get(data, "template"));
    std::vector<Parser::Rule> templ_val;
    if (templ.data.has_value()) {
        templ_val = std::any_cast<std::vector<Parser::Rule>>(templ.data);
    }
    if (val == "var" || val == "any")
        return {LLIR::var_types::ANY, {}};
    else if (val == "str")
        return {LLIR::var_types::STRING, {}};
    else if (val == "bool")
        return {LLIR::var_types::BOOLEAN, {}};
    else if (val == "num")
        return {LLIR::var_types::NUMBER, {}};
    else if (val == "arr") {
        LLIR::var_types type = LLIR::var_types::ARRAY;
        LLIR::var_type _template = cllTreeTypeToIR(templ_val[0]);
        return {type, {_template}};
    } else if (val == "obj") {        
        LLIR::var_types type = LLIR::var_types::OBJECT;
        LLIR::var_type _template1 = cllTreeTypeToIR(templ_val[0]);
        LLIR::var_type _template2 = cllTreeTypeToIR(templ_val[1]);
        return {type, {_template1, _template2}};
    }
    throw Error("undefined abstract type");
}
LLIR::var_assign_types LLIR::TreeOpToIR(const Parser::Rule &rule) {
    auto data = std::any_cast<Parser::Rule>(rule.data);
    if (!data.data.has_value())
        return LLIR::var_assign_types::ASSIGN;
    auto val = std::any_cast<std::string>(data.data);
    if (val == ">>")
        return LLIR::var_assign_types::BITWISE_RIGHTSHFT;
    if (val == "<<")
        return LLIR::var_assign_types::BITWISE_LEFTSHIFT;
    // all other is single character so can use switch
    switch (val[0]) {
        case '+':
            return LLIR::var_assign_types::ADD;
        case '-':
            return LLIR::var_assign_types::SUBSTR;
        case '*':
            return LLIR::var_assign_types::MULTIPLY;
        case '/':
            return LLIR::var_assign_types::DIVIDE;
        case '%':
            return LLIR::var_assign_types::MODULO;
        case '&':
            return LLIR::var_assign_types::BITWISE_AND;
        case '|':
            return LLIR::var_assign_types::BITWISE_OR;
        case '^':
            return LLIR::var_assign_types::BITWISE_ANDR;
    }
    throw Error("Undefined operator");
}
LLIR::expr LLIR::TreeOpToExpr(const Parser::Rule &rule) {
    auto data = std::any_cast<std::string>(rule.data);
    if (data == ">>")
        return {LLIR::condition_types::RIGHT_BITWISE};
    if (data == "<<")
        return {LLIR::condition_types::LEFT_BITWISE};
    // all other is single character so can use switch
    switch (data[0]) {
        case '+':
            return {LLIR::condition_types::ADD};
        case '-':
            return {LLIR::condition_types::SUBSTR};
        case '*':
            return {LLIR::condition_types::MULTIPLY};
        case '/':
            return {LLIR::condition_types::DIVIDE};
        case '%':
            return {LLIR::condition_types::MODULO};
        case '&':
            return {LLIR::condition_types::BITWISE_AND};
        case '|':
            return {LLIR::condition_types::BITWISE_OR};
        case '^':
            return {LLIR::condition_types::BITWISE_ANDR};
        default:
            throw Error("Undefined operator");
    }
}
LLIR::expr LLIR::TreeCompareOpToExpr(const Parser::Rule &rule) {
    auto data = std::any_cast<std::string>(rule.data);
    if (data == "==")
        return {LLIR::condition_types::EQUAL};
    if (data == "!=")
        return {LLIR::condition_types::NOT_EQUAL};
    if (data == ">")
        return {LLIR::condition_types::HIGHER};
    if (data == "<")
        return {LLIR::condition_types::LOWER};
    if (data == ">=")
        return {LLIR::condition_types::HIGHER_OR_EQUAL};
    if (data == "<=")
        return {LLIR::condition_types::LOWER_OR_EQUAL};
    throw Error("undefined compare operator");
}
LLIR::expr LLIR::TreeLogicalOpToIR(const Parser::Rule &rule) {
    auto data = std::any_cast<Parser::Rule>(rule.data);
    if (data.name == Parser::Rules::logical_and)
        return {LLIR::condition_types::AND};
    else if (data.name == Parser::Rules::logical_or)
        return {LLIR::condition_types::OR};
    throw Error("undefined logical operator");
}
LLIR::var_assign_types LLIR::TreeAssignmentOpToIR(const Parser::Rule &rule) {
    auto data = std::any_cast<Parser::Rule>(rule.data);
    if (!data.data.has_value())
        return LLIR::var_assign_types::ASSIGN;
    auto v = TreeOpToIR(data);
    v = static_cast<LLIR::var_assign_types>(static_cast<int>(v) + static_cast<int>(LLIR::var_assign_types::ASSIGN));
    return v;
}
LLIR::var_assign_types LLIR::TreeOperatorsToIR(const Parser::Rule &rule) {
    if (rule.name == Parser::Rules::op)
        return TreeOpToIR(rule);
    else if (rule.name == Parser::Rules::assignment_op)
        return TreeAssignmentOpToIR(rule);
    else
        throw Error("Undefined operator");
}
std::vector<LLIR::expr> LLIR::TreeExprGroupToIR(const Parser::Rule &rule) {
    std::vector<LLIR::expr> expr;
    auto data = std::any_cast<Parser::Rule>(rule.data);
    auto expression = TreeExprToIR(data);
    expr.push_back({LLIR::condition_types::GROUP_OPEN});
    expr.insert(expr.end(), expression.begin(), expression.end());
    expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    return expr;
}
std::vector<LLIR::expr> LLIR::TreeExprArithmetic_forToIR(const Parser::Rule &rule) {
    std::vector<LLIR::expr> expr;
    auto data = std::any_cast<Parser::Rule>(rule.data);
    switch (data.name)
    {
    case Parser::Rules::expr_group:
    {
        auto group_res = TreeExprGroupToIR(data);
        expr.insert(expr.end(), group_res.begin(), group_res.end());
        break;
    }
    case Parser::Rules::method_call:
        expr.push_back({LLIR::condition_types::METHOD_CALL, TreeMethodCallToIR(data)});
        break;
    case Parser::Rules::cll_function_call:
        expr.push_back({LLIR::condition_types::FUNCTION_CALL, TreeFunctionToIR(data)});
        break;
    case Parser::Rules::any_data:
        expr.push_back({LLIR::condition_types::ANY_DATA, TreeAnyDataToIR(data)});
        break;
    default:
        throw Error("Undefined data in arithmetic_for %s", Parser::RulesToString(data.name));
        break;
    }
    return expr;
}
std::vector<LLIR::expr> LLIR::TreeExprArithmeticToIR(const Parser::Rule &rule) {
    // if (rule.name == Parser::Rules::cll_function_call)
    auto data = std::any_cast<obj_t>(rule.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto operators = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "operators"));
    auto sequence = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "sequence"));
    std::vector<LLIR::expr> cond;
    auto res = TreeExprArithmetic_forToIR(first);
    cond.insert(cond.end(), res.begin(), res.end());
    for (int i = 0; i < operators.size(); i++) {
        cond.push_back(TreeOpToExpr(operators[i]));
        res = TreeExprArithmetic_forToIR(sequence[i]);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
std::vector<LLIR::expr> LLIR::TreeExprCompareToIR_unit(const Parser::Rule &rule) {
    switch (rule.name)
    {
    case Parser::Rules::expr_arithmetic:
        return TreeExprArithmeticToIR(rule);
    case Parser::Rules::expr_for_arithmetic:
        return TreeExprArithmetic_forToIR(rule);
    case Parser::Rules::expr_group:
        return TreeExprGroupToIR(rule);
    default:
        throw Error("Undefined expr compare unit\n");
        break;
    }
}
std::vector<LLIR::expr> LLIR::TreeExprCompareToIR(const Parser::Rule &rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto operators = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "operators"));
    auto sequence = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "sequence"));

    std::vector<LLIR::expr> cond;
    auto res = TreeExprCompareToIR_unit(first);
    cond.insert(cond.end(), res.begin(), res.end());
    for (int i = 0; i < operators.size(); i++) {
        cond.push_back(TreeCompareOpToExpr(operators[i]));
        res = TreeExprCompareToIR_unit(sequence[i]);
        cond.insert(cond.end(), res.begin(), res.end());
    }
    return cond;
}
std::vector<LLIR::expr> LLIR::TreeExprLogicalUnitToIR(const Parser::Rule &rule) {
    switch (rule.name)
    {
    case Parser::Rules::expr_compare:
        return TreeExprCompareToIR(rule);
    case Parser::Rules::expr_arithmetic:
        return TreeExprArithmeticToIR(rule);
    case Parser::Rules::expr_for_arithmetic:
        return TreeExprArithmetic_forToIR(rule);
    default:
        throw Error("Undefined unit\n");
    }
} 
std::vector<LLIR::expr> LLIR::TreeExprLogicalToIR(const Parser::Rule &rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    auto left = std::any_cast<Parser::Rule>(corelib::map::get(data, "left"));
    auto op = std::any_cast<Parser::Rule>(corelib::map::get(data, "op"));
    auto right = std::any_cast<Parser::Rule>(corelib::map::get(data, "right"));

    std::vector<LLIR::expr> cond;
    auto left_res = TreeExprLogicalUnitToIR(left);
    auto op_res = TreeLogicalOpToIR(op);
    auto rigth_res = TreeExprLogicalUnitToIR(right);
    cond.insert(cond.end(), left_res.begin(), left_res.end());
    cond.push_back(op_res);
    cond.insert(cond.end(), rigth_res.begin(), rigth_res.end());
    return cond;
}
std::vector<LLIR::expr> LLIR::TreeExprToIR(const Parser::Rule &expr) {
    auto val = std::any_cast<Parser::Rule>(expr.data);
    switch(val.name) {
        case Parser::Rules::expr_logical:
            return TreeExprLogicalToIR(val);
        case Parser::Rules::expr_compare:
            return TreeExprCompareToIR(val);
        case Parser::Rules::expr_arithmetic:
            return TreeExprArithmeticToIR(val);
        case Parser::Rules::expr_group:
            return TreeExprGroupToIR(val);
        case Parser::Rules::cll_function_call:
            return {{LLIR::condition_types::FUNCTION_CALL, TreeFunctionToIR(val)}};
        case Parser::Rules::any_data:
            return {{LLIR::condition_types::ANY_DATA, TreeAnyDataToIR(val)}};
        case Parser::Rules::method_call:
            return {{LLIR::condition_types::METHOD_CALL, TreeMethodCallToIR(val)}};
    }
    throw Error("Undefined tree unit: %s", Parser::RulesToString(val.name));
}

// Function to compare two `templ` arrays
bool LLIR::compare_templ(const std::vector<LLIR::var_type>& templ1, const std::vector<LLIR::var_type>& templ2) {
    if (templ1.size() != templ2.size()) return false;

    for (size_t i = 0; i < templ1.size(); ++i) {
        if (templ1[i].type != templ2[i].type) return false;
        if (!compare_templ(templ1[i].templ, templ2[i].templ)) return false;  // Recursively compare nested `templ`
    }
    return true;
}
bool LLIR::compare_types(std::list<LLIR::var_type> types) {
    if (types.empty())
        return false;
    LLIR::var_type first_type = types.front();
    bool is_same = true;
    bool begin = true;
    for (auto el : types) {
        if (begin) {
            begin = false;
            continue;
        }
        if (first_type.type != el.type || compare_templ(first_type.templ, el.templ)) {
            is_same = false;
            break;
        }
    }
    return is_same;
}
LLIR::variable LLIR::getElementbyAccessor(LLIR::accessor &accessor, bool is_match_rule) {
    enum class accessor_states {
        GROUP, ELEMENT, CHAR, UNKNOWN
    };
    accessor_states state = accessor_states::UNKNOWN;
    LLIR::variable* elements_pointer = nullptr;
    LLIR::var_group* group_pointer = nullptr; 
    for (auto &unit : accessor.elements) {
        auto num = std::any_cast<Parser::Rule>(unit.data);
        auto num_data = std::any_cast<obj_t>(num.data);
        auto num_main = std::any_cast<double>(corelib::map::get(num_data, "main_n")) - 1;
        switch (unit.name)
        {
        case Parser::Rules::accessors_group:
            //cpuf::printf("accessor $%d\n", (int) num_main);
            if (state == accessor_states::ELEMENT)
                throw Error("accessor %% cannot refer to accessor $");
            else if (state == accessor_states::GROUP) {
                if (num_main > group_pointer->end)
                    throw Error("Group %d does not exist", (int) group_pointer->end + num_main);
                group_pointer += (int) num_main;
            } else {
                state = accessor_states::GROUP;
                if (num_main > groups.size())
                    throw Error("Group %d does not exist", (int) num_main);
                //cpuf::printf("Accessing %d, group size: %llu\n", (int) num_main, groups.size());
                group_pointer = &groups[num_main];
            }
            break;
        case Parser::Rules::accessors_element:
            //cpuf::printf("accessor %%%d\n", (int) num_main);
            if (state == accessor_states::ELEMENT) {
                if (&elements_pointer[(int) num_main] >= elements.data() + elements.size())
                    throw Error("Element does not exist");
                elements_pointer += (int) num_main;
            } else if (state == accessor_states::GROUP) {
                if (group_pointer->begin + (int) num_main >= elements.size())
                    throw Error("Element does not exist: %d", group_pointer->begin + (int) num_main);
                elements_pointer = &elements[group_pointer->begin + (int) num_main];
            } else {
                if (num_main >= elements.size())
                    throw Error("Element does not exist. elements size(): %llu while num_main: %d", elements.size(), (int) num_main);
                elements_pointer = &elements[num_main];
            }
            state = accessor_states::ELEMENT;
            break;
        case Parser::Rules::accessors_char:
            //cpuf::printf("accessor ^%d\n", (int) num_main);
            if (state != accessor_states::UNKNOWN)
                throw Error("accessor ^ cannot be reffered by another accessor");
            if (is_match_rule)
                throw Error("accessor ^ cannot be used as a match rule");
            break;
        default:
            break;
        }
    }
    return state == accessor_states::ELEMENT ? *elements_pointer : group_pointer->var;
}
void LLIR::inlineExprAccessor(LLIR::assign &data) {
    if (data.kind == LLIR::var_assign_values::ACCESSOR) {
        auto accessor = std::any_cast<LLIR::accessor>(data.data);
        if (accessor.elements[0].name == Parser::Rules::accessors_char) {
            if (accessor.elements.size() > 1)
                throw Error("Cannot refer subaccessor for accessor '^");

            auto num = std::any_cast<Parser::Rule>(accessor.elements[0].data);
            auto num_data = std::any_cast<obj_t>(num.data);
            auto num_main = std::any_cast<double>(corelib::map::get(num_data, "main_n")) - 1;
            data.kind = LLIR::var_assign_values::CURRENT_POS;
            data.data = num_main;
            return;
        }
        // a regular accessor
        auto var = getElementbyAccessor(accessor, false);
        data.kind = LLIR::var_assign_values::VARIABLE;
        data.data = var;
    } else if (data.kind == LLIR::var_assign_values::EXPR) {
        auto dt = std::any_cast<std::vector<LLIR::expr>>(data.data);
        inlineExprAccessor(dt);
        data.data = dt;

    }
}
void LLIR::inlineExprAccessor(std::vector<LLIR::expr> &expr) {
    for (auto &unit : expr) {
        if (unit.id == LLIR::condition_types::ANY_DATA) {
            auto data = std::any_cast<LLIR::assign>(unit.value);
            inlineExprAccessor(data);
            unit.value = data;
        }
    }
}
void LLIR::inlineAccessors(std::vector<LLIR::member> &values) {
    if (values.empty() || elements.empty())
        return;
    for (auto it = values.begin(); it != values.end(); it++) {
        auto el = *it;
        if (el.type == LLIR::types::ACCESSOR) {
            auto accessor = std::any_cast<LLIR::accessor>(el.value);
            auto var = getElementbyAccessor(accessor, true);
            std::vector<LLIR::expr> expr = {
                {LLIR::condition_types::STRNCMP, LLIR::strncmp{0, var}}
            };
            // go to reverse to get names of var and svar
            bool insideLoop;
            LLIR::variable accessor_var, accessor_shadow, accessor_svar;
            for (auto reverse_it = std::make_reverse_iterator(it + 1); reverse_it != values.rend(); reverse_it++) {
                if (reverse_it->type == LLIR::types::INSIDE_LOOP) {
                    insideLoop = true;
                    reverse_it = std::make_reverse_iterator(values.erase(std::prev(reverse_it.base())));
                } else if (reverse_it->type == LLIR::types::VARIABLE) {
                    auto data = std::any_cast<LLIR::variable>(reverse_it->value);
                    if (accessor_svar.name.empty()) {
                        accessor_svar = data;
                    } else if (accessor_shadow.name.empty()) {
                        accessor_shadow = data;
                    } else {
                        accessor_var = data;
                        break;
                    }
                }
            }
            if (accessor_var.name.empty() || accessor_svar.name.empty())
                throw Error("Cannot find variable and success variable for accessor");
            // replace accessor with rule
            it = values.erase(it); // Erase the accessor element and update iterator
            std::vector<LLIR::member> block = createDefaultBlock(accessor_var, accessor_svar);
            LLIR result_rule(tree);
            result_rule.proceed(*this);
            pushBasedOnQualifier(Tokens::make_rule(Parser::Rules::accessor), expr, block, accessor_var, accessor_svar, false);
            // replace_exit_to_unsuccess(result_rule.elements, accessor_svar);
            it = values.insert(it, result_rule.data.begin(), result_rule.data.end()); // Insert new elements and update iterator
            if (it != values.end())
                std::advance(it, result_rule.elements.size() - 1); // Move iterator past the newly inserted elements
        } else if (el.type == LLIR::types::IF || el.type == LLIR::types::WHILE || el.type == LLIR::types::DOWHILE) {
            auto dt = std::any_cast<LLIR::condition>(el.value);
            inlineExprAccessor(dt.expression);
            inlineAccessors(dt.block);
            it->value = dt;
        } else if (el.type == LLIR::types::VARIABLE) {
            auto data = std::any_cast<LLIR::variable>(el.value);
            inlineExprAccessor(data.value);
            it->value = data;
        } else if (el.type == LLIR::types::ASSIGN_VARIABLE) {
            auto data = std::any_cast<LLIR::variable_assign>(el.value);
            inlineExprAccessor(data.value);
            it->value = data;
        }
    }
}
LLIR::var_type LLIR::deduceTypeFromAnyData(const Parser::Rule &value) {
    auto val = std::any_cast<Parser::Rule>(value.data);
    LLIR::var_type type;
    switch (val.name)
    {
    case Parser::Rules::string:
        type.type = LLIR::var_types::STRING;
        break;
    case Parser::Rules::var_refer:
    {        
        LLIR::var_refer refer;
        auto data = std::any_cast<obj_t>(val.data);
        auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
        auto name_str = std::any_cast<std::string>(name.data);
        auto var = std::find_if(vars.begin(), vars.end(), [&name_str](const LLIR::variable var) {return var.name == name_str;});
        if (var == vars.end())
            throw Error("Requested variable in expression could not be found: %s", name_str);
        if (var->type.type == LLIR::var_types::Token_result) {
            type.type = LLIR::var_types::Token;
        } else if (var->type.type == LLIR::var_types::Rule_result) {
            type.type = LLIR::var_types::Rule;
        } else {
            type = var->type;
        }
        break;
    }
    case Parser::Rules::boolean: 
    {
        type.type = LLIR::var_types::BOOLEAN;
        break;
    }
    case Parser::Rules::number: 
    {
        
        type.type = LLIR::var_types::NUMBER;
        break;
    }
    case Parser::Rules::array:
    {
        //cpuf::printf("array\n");
        auto data = std::any_cast<std::vector<Parser::Rule>>(val.data);
        std::list<LLIR::var_type> types;
        
        for (auto &el : data) {
            types.push_back(deduceTypeFromAnyData(el));
        }
        bool is_same = compare_types(types);
        type.type = LLIR::var_types::ARRAY;
        type.templ = {is_same ? types.front() : LLIR::var_type {LLIR::var_types::ANY}};
        break;
    }
    case Parser::Rules::object:
    {
        //cpuf::printf("object\n");
        auto data = std::any_cast<obj_t>(val.data);
        auto key = std::any_cast<Parser::Rule>(corelib::map::get(data, "key"));
        auto value = std::any_cast<Parser::Rule>(corelib::map::get(data, "value"));
        auto keys = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "keys"));
        auto values = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "values"));
        
        keys.insert(keys.begin(), key);
        values.insert(values.begin(), value);
        std::list <LLIR::var_type> types;
        for (int i = 0; i < keys.size(); i++) {
            auto key = keys[i];
            auto value = values[i];
            auto type = deduceTypeFromAnyData(value);
            types.push_back(type);
        }
        bool is_same = compare_types(types);
        type.type = LLIR::var_types::OBJECT;
        type.templ = {is_same ? std::vector<LLIR::var_type> {{LLIR::var_types::STRING}, types.front()} : std::vector<LLIR::var_type> {{LLIR::var_types::STRING}, {LLIR::var_types::ANY}}};
        break;
    }
    case Parser::Rules::accessor:
    {
        //cpuf::printf("accessor\n");
        auto accessor = std::any_cast<LLIR::accessor>(TreeAnyDataToIR(value).data);
        auto name = getElementbyAccessor(accessor, false);
        auto var = std::find_if(vars.begin(), vars.end(), [&name](const LLIR::variable var) {
            return var.name == name.name;
        });
        if (var == vars.end())
            throw Error("Requested variable in expression could not be found: %s", name.name);
        if (var->type.type == LLIR::var_types::Token_result) {
            type.type = LLIR::var_types::Token;
        } else if (var->type.type == LLIR::var_types::Rule_result) {
            type.type = LLIR::var_types::Rule;
        } else {
            type = var->type;
        }
        break;
    }
    default:
        throw Error("Undefined rule");
        break;
    }
    return type;
}
LLIR::var_type LLIR::deduceTypeFromExpr(const Parser::Rule &expr) {
    switch (expr.name) {
        // case Parser::Rules::expr_logical:
        //     return exprLogicalDeduceType(data);
        // case Parser::Rules::expr_compare:
        //     return exprCompareDeduceType(data);
        // case Parser::Rules::expr_arithmetic:
        //     return exprArithmeticDeduceType(data);
        // case Parser::Rules::expr_group:
        //     return deduceTypeFromExpr(std::any_cast<Parser::Rule>(data.data));
        case Parser::Rules::any_data:
            return deduceTypeFromAnyData(expr);
        default:
            throw Error("Undefined expression unit: %s", Parser::RulesToString(expr.name));
    }
}
LLIR::data_block LLIR::TreeDataBlockToIR(const Parser::Rule &rule) {
    if (rule.empty())
        return {};
    auto val = std::any_cast<Parser::Rule>(rule.data);
    LLIR::data_block datablock;
    if (val.name == Parser::Rules::Rule_data_block_inclosed_map) {
        // inclosed map
        datablock.is_inclosed_map = true;
        LLIR::inclosed_map map;
        auto keys = std::any_cast<std::vector<Parser::Rule>>(val.data);
        for (auto &key : keys) {
            auto data = std::any_cast<obj_t>(key.data);
            auto k = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
            auto v = std::any_cast<Parser::Rule>(corelib::map::get(data, "val"));
            if (v.name == Parser::Rules::expr) {
                auto expr = TreeExprToIR(v);
                inlineExprAccessor(expr);
                map[std::any_cast<std::string>(k.data)] = {expr, deduceTypeFromExpr(std::any_cast<Parser::Rule>(v.data))};
            } 
        }
        datablock.value = {LLIR::var_assign_values::INCLOSED_MAP, map};
    } else if (val.name == Parser::Rules::any_data) {
        datablock.is_inclosed_map = false;
        datablock.value = TreeAnyDataToIR(val);
        datablock.assign_type = deduceTypeFromExpr(val);
        inlineExprAccessor(datablock.value);
    } else throw Error("Undefined data block val\n");
    return datablock;
}
LLIR::node_ret_t LLIR::processGroup(const Parser::Rule &rule, char quantifier) {
    //cpuf::printf("group\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto variable = corelib::map::get(data, "variable").has_value() ? std::any_cast<Parser::Rule>(corelib::map::get(data, "variable")) : Parser::Rule();
    auto val = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "val"));
    // create variable with name of "var" or with auto-generated one
    auto var = (!variable.empty() && variable.name == Parser::Rules::id) ?
                        createEmptyVariable(std::any_cast<std::string>(variable.data)) :
                        createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();

    if (quantifier == '*' || quantifier == '+')
        insideLoop = true;

    auto values = rulesToIr(val);
    groups.push_back({var, elements.size(), elements.size() + values.elements.size() - 1});
    update(values);
    var.type = {deduceVarTypeByValue(rule)};
    if ((quantifier == '*' || quantifier == '+') && var.type.type != LLIR::var_types::UNDEFINED && var.type.type != LLIR::var_types::STRING) {
        var.type.templ = {{var.type.type}};
        var.type.type = LLIR::var_types::ARRAY;
    }
    std::vector<LLIR::member> var_members;
    auto switch_type = var.type.type == LLIR::var_types::ARRAY ? var.type.templ[0].type : var.type.type;
    switch (switch_type) {
        case LLIR::var_types::STRING:
            // it is a string so add all values
            for (auto node : values.success_vars) {
                if (node.var.name == "" && node.svar.name == "")
                    continue;
                var_members.push_back(
                    {
                        LLIR::types::ASSIGN_VARIABLE, 
                        LLIR::variable_assign {var.name, LLIR::var_assign_types::ADD, LLIR::assign { LLIR::var_assign_values::VARIABLE, node.var }}
                    }
                );
            }
            break;
        case LLIR::var_types::Token:
        case LLIR::var_types::Rule:
            // it is token so perform a single assign
            var_members.push_back( LLIR::member
                {
                    LLIR::types::ASSIGN_VARIABLE,
                    LLIR::variable_assign {var.name, LLIR::var_assign_types::ASSIGN, LLIR::assign { LLIR::var_assign_values::VARIABLE,  values.success_vars[0].var }}
                }
            );
            var.type = values.success_vars[0].var.type;
            if (var.type.type == LLIR::var_types::Rule_result)
                var.type.type = LLIR::var_types::Rule;
            else if (var.type.type == LLIR::var_types::Token_result)
                var.type.type = LLIR::var_types::Token;
            break;
    }
    std::string begin_var_name = "begin" + generateVariableName();
    std::vector<LLIR::expr> svar_expr = {};
    //cpuf::printf("success_vars.size(): %d\n", success_vars.size());
    if (!values.success_vars.empty()) {
        bool first = true;
        for (auto el : values.success_vars) {
            if (el.qualifier == '*' || el.qualifier == '?' || el.svar.name.empty())
                continue;
            if (!first)
                svar_expr.push_back({LLIR::condition_types::AND});

            svar_expr.push_back({LLIR::condition_types::VARIABLE, el.svar});
            first = false;
        }
    }
    // for (int i = 0; i < node_ret.size(); i++) {
    //     if (i != 0)
    //         svar_expr.push_back({IR::condition_types::AND});
    //     svar_expr.push_back({IR::condition_types::VARIABLE, node_ret[i].svar});
    // }
    std::vector<LLIR::member> svar_cond;
    if (svar_expr.empty()) {
        svar_cond = {
            {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::_TRUE}},
            {LLIR::types::POP_POS_COUNTER}
        };
    } else {
        svar_cond = {{
            LLIR::types::IF,
            LLIR::condition {
                svar_expr,
                {
                    {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {svar.name, LLIR::var_assign_types::ASSIGN, LLIR::var_assign_values::_TRUE}},
                    {LLIR::types::POP_POS_COUNTER}
                }
            }
        }};
    }

    if (!values.data.empty() && values.data.back().type == LLIR::types::SKIP_SPACES) {
        values.pop();
    }
    values.add(var_members);
    auto shadow_var = values.affectIrByQuantifier(rule, var, quantifier);

    if (!shadow_var.name.empty()) {
        groups.back().var = shadow_var;
    }
    if (var.type.type != LLIR::var_types::UNDEFINED) {
        push({LLIR::types::VARIABLE, var});
    }
    push({LLIR::types::VARIABLE, svar});
    push({LLIR::types::PUSH_POS_COUNTER, begin_var_name});
    if (!variable.empty() && variable.name == Parser::Rules::method_call) 
    {
        LLIR::method_call method_call = TreeMethodCallToIR(std::any_cast<Parser::Rule>(variable.data));
        add(values);
        push({LLIR::types::METHOD_CALL, method_call});
    } else {
        add(values);
    }
    add(svar_cond);
    if (var.type.type == LLIR::var_types::UNDEFINED)
        return LLIR::node_ret_t {svar, {}, {}, quantifier};
    return LLIR::node_ret_t {svar, var, shadow_var, quantifier};
}
LLIR::node_ret_t LLIR::processRuleCsequence(const Parser::Rule &rule, char quantifier) {
    //cpuf::printf("csequence\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto _not = std::any_cast<bool>(corelib::map::get(data, "not"));
    auto values = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "val"));

    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::STRING};
    bool is_negative = false;
    std::vector<LLIR::expr> expr;

    if (_not) {
        expr = {
            {LLIR::condition_types::NOT},
            {LLIR::condition_types::GROUP_OPEN}
        };
        is_negative = true;
    }

    bool first = true;
    for (auto &value : values) {
        if (!first)
            expr.push_back({LLIR::condition_types::OR});

        switch (value.name) {
            case Parser::Rules::Rule_csequence_diapason: {
                auto range_data = std::any_cast<std::vector<Parser::Rule>>(value.data);
                auto first = std::any_cast<std::string>(range_data[0].data)[0];
                auto second = std::any_cast<std::string>(range_data[1].data)[0];
                expr.insert(expr.end(), {
                    {LLIR::condition_types::GROUP_OPEN},
                    {LLIR::condition_types::CURRENT_CHARACTER},
                    {LLIR::condition_types::HIGHER_OR_EQUAL},
                    {LLIR::condition_types::CHARACTER, first},
                    {LLIR::condition_types::AND},
                    {LLIR::condition_types::CURRENT_CHARACTER},
                    {LLIR::condition_types::LOWER_OR_EQUAL},
                    {LLIR::condition_types::CHARACTER, second},
                    {LLIR::condition_types::GROUP_CLOSE}
                });
                break;
            }
            case Parser::Rules::Rule_csequence_escape:
                expr.insert(expr.end(), {
                    {LLIR::condition_types::CURRENT_CHARACTER},
                    {LLIR::condition_types::EQUAL},
                    {LLIR::condition_types::CHARACTER, getEscapedChar(std::any_cast<std::string>(value.data)[0])}
                });
                break;
            case Parser::Rules::Rule_csequence_symbol:
                expr.insert(expr.end(), {
                    {LLIR::condition_types::CURRENT_CHARACTER},
                    {LLIR::condition_types::EQUAL},
                    {LLIR::condition_types::CHARACTER, (char) std::any_cast<std::string>(value.data)[0]}
                });
                break;
            default:
                throw Error("undefined csequence subrule");
        }
        first = false;
    }
    if (is_negative) {
        if (quantifier == '+' || quantifier == '*')
            expr.insert(expr.end(), {
                {LLIR::condition_types::AND}, {LLIR::condition_types::CURRENT_CHARACTER}, {LLIR::condition_types::NOT_EQUAL}, {LLIR::condition_types::CHARACTER, '\0'}, 
            });
        expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    }
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    std::vector<LLIR::member> block = createDefaultBlock(var, svar);
    pushBasedOnQualifier(rule, expr, block, var, svar, quantifier, false);
    return {svar, var, {}, quantifier};
}
LLIR::node_ret_t LLIR::processString(const Parser::Rule &rule, char quantifier) {
    //cpuf::printf("string, data: %s\n", std::any_cast<std::string>(rule.data));
    auto data = std::any_cast<std::string>(rule.data);
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::STRING};
    std::vector<LLIR::expr> expr;
    if (data.size() == 0)
        return {};
    if (data.size() == 1) {
        // micro optimization - compare as single character for single character strings
        expr = {
            {LLIR::condition_types::CURRENT_CHARACTER},
            {LLIR::condition_types::EQUAL},
            {LLIR::condition_types::CHARACTER, data[0]}
        };
    } else {
        expr = {
            {LLIR::condition_types::STRNCMP, LLIR::strncmp{1, data}}
        };
    }

    std::vector<LLIR::member> block = createDefaultBlock(var, svar);
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    pushBasedOnQualifier(rule, expr, block, var, svar, quantifier, false);
    return {svar, var, {}, quantifier};
}
LLIR::node_ret_t LLIR::process_Rule_hex(const Parser::Rule &rule, char quantifier) {
    //cpuf::printf("hex\n");
    auto data = std::any_cast<std::string>(rule.data);
    std::vector<LLIR::expr> expr = {};
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::STRING};
    std::vector<LLIR::member> block = createDefaultBlock(var, svar);
    bool is_first = true, is_negative = false;
    if (quantifier == '\0') {
        expr.push_back({LLIR::condition_types::NOT});
        expr.push_back({LLIR::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    if (data.size() % 2 != 0)
        data.insert(data.begin(), '0');
    for (int i = 0; i < data.size(); i += 2) {
        std::string hex(data.data() + i, 2);
        if (!is_first)
            expr.push_back({LLIR::condition_types::AND});
        is_first = false;
        expr.push_back({LLIR::condition_types::CURRENT_CHARACTER});
        expr.push_back({LLIR::condition_types::EQUAL});
        expr.push_back({LLIR::condition_types::HEX, hex});
    }
    if (is_negative) {
        expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    }
    //cpuf::printf("hex_open\n");
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(rule, expr, block, var, svar, quantifier, false);
    return {svar, var, shadow_var, quantifier};
}
LLIR::node_ret_t LLIR::process_Rule_bin(const Parser::Rule &rule, char quantifier) {
    //cpuf::printf("hex\n");
    auto data = std::any_cast<std::string>(rule.data);
    std::vector<LLIR::expr> expr = {};
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    std::vector<LLIR::member> block = {
        {LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {var.name, LLIR::var_assign_types::ADD, LLIR::var_assign_values::CURRENT_POS_SEQUENCE}},
        {LLIR::types::INCREASE_POS_COUNTER},
    };
    bool is_first = true, is_negative = false;
    if (quantifier == '\0') {
        expr.push_back({LLIR::condition_types::NOT});
        expr.push_back({LLIR::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    while (data.size() % 8 != 0)
        data.insert(data.begin(), '0');
    for (int i = 0; i < data.size(); i += 8) {
        std::string bin(data.data() + i, 8);
        auto as_hex = hex::from_binary(bin);
        as_hex.erase(as_hex.begin(), as_hex.begin() + 2);
        if (!is_first)
            expr.push_back({LLIR::condition_types::AND});
        is_first = false;
        expr.push_back({LLIR::condition_types::CURRENT_CHARACTER});
        expr.push_back({LLIR::condition_types::EQUAL});
        expr.push_back({LLIR::condition_types::HEX, as_hex});
    }
    if (is_negative) {
        expr.push_back({LLIR::condition_types::GROUP_CLOSE});
    }
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    auto shadow_var = pushBasedOnQualifier(rule, expr, block, var, svar, quantifier, false);
    return {svar, var, shadow_var, quantifier};
}
LLIR::node_ret_t LLIR::processAccessor(const Parser::Rule &rule, char quantifier) {
    //cpuf::printf("accessor\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto second = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "second"));
    auto svar = createSuccessVariable();
    auto var = createEmptyVariable(generateVariableName());
    auto shadow_var = createEmptyVariable("shadow" + generateVariableName());
    second.insert(second.begin(), first);
    for (auto &el : second) {
        el = std::any_cast<Parser::Rule>(el.data);
    }
    auto mem = LLIR::member {
        LLIR::types::ACCESSOR,
        LLIR::accessor { second, quantifier }
    };
    if (insideLoop)
        push({LLIR::types::INSIDE_LOOP});
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, shadow_var});
    push({LLIR::types::VARIABLE, svar});
    push(mem);
    return {svar, var, shadow_var};
}
LLIR::node_ret_t LLIR::process_Rule_other(const Parser::Rule &rule, char quantifier) {
    //cpuf::printf("Rule_other");
    auto name = std::any_cast<rule_other>(rule.data);
    auto name_str = corelib::text::join(name.fullname, "_");
    //cpuf::printf(", name: %s\n", name_str);

    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    LLIR::variable shadow_var;
    bool isCallingToken = corelib::text::isUpper(name.name);
    if (!isToken && isCallingToken) {
        var.type.type = LLIR::var_types::Token;
    } else {
        var.type = isCallingToken ? LLIR::var_type {LLIR::var_types::Token_result} : LLIR::var_type {LLIR::var_types::Rule_result};
    }
    auto block = createDefaultBlock(var, svar);
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    if (isToken) {
        // if (!isCallingToken)
        //     throw Error("Cannot call rule from token");
        // remove variable assignemnt
        block.back().type = LLIR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH;
        block.back().value = var.name;
        var.property_access = {"node"};
        block.erase(block.begin());
        std::vector<LLIR::expr> expr;
        auto call = createDefaultCall(block, var, name_str, expr);
        push(call);
        shadow_var = pushBasedOnQualifier_Rule_other(rule, expr, block, var, svar, call, quantifier);

    } else {
        if (isCallingToken) {
            block[0] = {
                LLIR::types::ASSIGN_VARIABLE, 
                LLIR::variable_assign {
                    var.name,
                    LLIR::var_assign_types::ASSIGN,
                    LLIR::var_assign_values::CURRENT_TOKEN
                }
            };
            std::vector<LLIR::expr> expr = {
                {LLIR::condition_types::CURRENT_TOKEN, LLIR::current_token {LLIR::condition_types::EQUAL, name_str}},
            };
            shadow_var = pushBasedOnQualifier(rule, expr, block, var, svar, quantifier);
        } else {
            block.back().type = LLIR::types::INCREASE_POS_COUNTER_BY_TOKEN_LENGTH;
            block.back().value = var.name;
            var.property_access = {"node"};
            block.erase(block.begin()); // remove variable assignment
            std::vector<LLIR::expr> expr;
            auto call = createDefaultCall(block, var, name_str, expr);
            push(call);
            shadow_var = pushBasedOnQualifier_Rule_other(rule, expr, block, var, svar, call, quantifier);

        }

    }
    return {svar, var, shadow_var, quantifier};
}
LLIR::node_ret_t LLIR::process_Rule_escaped(const Parser::Rule &rule, char quantifier) {
    //cpuf::printf("Rule_escaped\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto c = std::any_cast<std::string>(corelib::map::get(data, "c"));
    auto num = std::any_cast<Parser::Rule>(corelib::map::get(data, "num"));
    obj_t num_data;
    double num_main;
    if (num.data.has_value()) {
        num_data = num.as<obj_t>();
        num_main = std::any_cast<double>(corelib::map::get(num_data, "main_n"));
    } else {
        num_main = -1;
    }

    std::vector<LLIR::expr> expression;
    if (quantifier != '\0')
        UWarning(std::string("Qualifier '%c' after \\") + c + std::string(" ignored"), quantifier, c).print();
    switch (c[0]) {
        case 's':
            // do not add skip of spaces
            addSpaceSkip = false;
            if (data.size() > 0) {
                // remove previous skip of spaces if it does exists
                for (auto rit = this->data.rbegin(); rit != this->data.rend(); rit++) {
                    if (rit->type == LLIR::types::SKIP_SPACES) {
                        this->data.erase(rit.base());
                        break;
                    }
                }
            }

            if (num_main == 0) {
                //cpuf::printf("on_exit\n");
                return {{}, {}};
            } else if (num_main != -1) {
                UWarning("Number after \\s ignored").print();
            }
            //cpuf::printf("ON_EXPRESSION\n");
            expression = {
                {LLIR::condition_types::CURRENT_CHARACTER},
                {LLIR::condition_types::NOT_EQUAL},
                {LLIR::condition_types::CHARACTER, ' '}
            };
            break;
        default:
            throw Error("Undefined char '%c'", c[0]);
            
    }
    //cpuf::printf("escaped_open\n");

    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::STRING};
    std::vector<LLIR::member> block = {{LLIR::types::EXIT}};
    if (!isFirst) {
        block.insert(block.begin(), {LLIR::types::ERR, getErrorName(rule)});
    }
    auto block_after = createDefaultBlock(var, svar);
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    push({LLIR::types::IF, LLIR::condition{expression, block}});
    add(block_after);
    //cpuf::printf("escaped_close\n");
    return {svar, var, {}, quantifier};
}
LLIR::node_ret_t LLIR::process_Rule_any(const Parser::Rule &rule, char quantifier) {
    //cpuf::printf("Rule_any\n");
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    var.type = {LLIR::var_types::STRING};
    std::vector<LLIR::expr> expression;
    std::vector<LLIR::member> block = {{LLIR::types::EXIT}};
    if (!isFirst) {
        block.insert(block.begin(), {LLIR::types::ERR, getErrorName(rule)});
    }
    std::vector<LLIR::member> block_after = createDefaultBlock(var, svar);
    expression = {
        {LLIR::condition_types::CURRENT_CHARACTER},
        {LLIR::condition_types::EQUAL},
        {LLIR::condition_types::CHARACTER, '\0'}
    };
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    push({LLIR::types::IF, LLIR::condition{expression, block}});
    add(block_after);
    return {svar, var};
}
std::vector<LLIR::member> LLIR::convert_op_rule(std::vector<Parser::Rule> &rules, size_t index, LLIR::variable &var, LLIR::variable &svar) {
    if (index >= rules.size()) {
        return {{LLIR::types::EXIT}};
    }

    LLIR::node_ret_t success_var;
    std::vector<std::vector<LLIR::member>> blocks;
    std::vector<std::vector<LLIR::expr>> conditions;
    auto rule = rules[index++];
    LLIR new_ir(tree);
    new_ir.proceed(*this);
    auto rule_data = std::any_cast<obj_t>(rule.data);
    auto rule_val = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
    auto quantifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));
    char quantifier_c;
    if (quantifier.data.has_value()) {
        quantifier_c = std::any_cast<char>(quantifier.data);
    } else {
        quantifier_c = '\0';
    }
    char new_qualifier;
    if (quantifier_c == '+')
        new_qualifier = '*';
    else if (quantifier_c == '\0')
        new_qualifier = '?';
    if (rule_val.name == Parser::Rules::Rule_group || rule_val.name == Parser::Rules::accessor)
        new_ir.ruleToIr(rule, new_qualifier);
    else    
        new_ir.ruleToIr(rule);
    variable_count = new_ir.variable_count;
    vars = new_ir.vars;
    success_var = new_ir.success_vars[0];
    groups.insert(groups.end(), new_ir.groups.begin(), new_ir.groups.end());
    for (auto el : new_ir.groups) {
        for (int i = el.begin; i < el.end; i++) {
            elements.push_back(new_ir.elements[i]);
        }
    }
    std::vector<int> erase_indices;
    std::vector<int> push_indices;
    if (rule_val.name == Parser::Rules::Rule_group || rule_val.name == Parser::Rules::accessor) {
        new_ir.data.back().type = LLIR::types::RESET_POS_COUNTER; // remove space skip
        auto cond = LLIR::condition {
            std::vector<LLIR::expr> {
                {LLIR::condition_types::NOT}, {LLIR::condition_types::VARIABLE, success_var.svar}
            },
            convert_op_rule(rules, index, var, svar),
        };
        auto v = !success_var.shadow_var.name.empty() && var.type.type != LLIR::var_types::STRING ? success_var.shadow_var : success_var.var;
        auto assign_type = v.type.type == LLIR::var_types::STRING ? LLIR::var_assign_types::ADD : LLIR::var_assign_types::ASSIGN;
        if (!v.name.empty()) {
            cond.else_block = {{
                LLIR::types::ASSIGN_VARIABLE,
                LLIR::variable_assign 
                {
                    var.name,
                    LLIR::var_assign_types::ASSIGN,
                    LLIR::assign {
                        LLIR::var_assign_values::VARIABLE,
                        v
                    }
                }
            }};
        } 
        new_ir.push({LLIR::types::IF, cond});
    } else {
        replaceToPrevChar(new_ir.data, 0);
        for (int i = 0; i < new_ir.data.size(); i++) {
            auto &el = new_ir.data[i];
            if (el.type == LLIR::types::IF) {
                auto val = std::any_cast<LLIR::condition>(el.value);
                // get recursively nested block
                val.block = convert_op_rule(rules, index, var, svar);
                // change condition and remove it's content into else blocks
                for (int j = i + 1; j < new_ir.data.size(); j++) {
                    auto el = new_ir.data[j];
                    erase_indices.push_back(j);
                    if (el.type != LLIR::types::SKIP_SPACES) {
                        if (el.type == LLIR::types::ASSIGN_VARIABLE) {
                            auto assignment = std::any_cast<LLIR::variable_assign>(el.value);
                            assignment.assign_type = LLIR::var_assign_types::ASSIGN;
                            el.value = assignment;
                        }
                        val.else_block.push_back(el);
                    }
                }
                // push into else block an assignment to variable
                if (var.type.type == LLIR::var_types::ARRAY) {
                    val.else_block.push_back({LLIR::types::METHOD_CALL, LLIR::method_call { var.name, {LLIR::function_call {"push", {LLIR::assign {LLIR::var_assign_values::VARIABLE, success_var.var}}}}}});
                } else {
                    auto v = !success_var.shadow_var.name.empty() && var.type.type != LLIR::var_types::STRING ? success_var.shadow_var : success_var.var;
                    auto assign_type = v.type.type == LLIR::var_types::STRING ? LLIR::var_assign_types::ADD : LLIR::var_assign_types::ASSIGN;
                    val.else_block.push_back({
                        LLIR::types::ASSIGN_VARIABLE,
                        LLIR::variable_assign 
                        {
                            var.name,
                            LLIR::var_assign_types::ASSIGN,
                            LLIR::assign {
                                LLIR::var_assign_values::VARIABLE,
                                v
                            }
                        }
                    });
                }
                
                // update the value
                el.value = val;
            }
        }
    }

    // Erase marked indices in reverse to prevent shifting issues
    for (int i = erase_indices.size() - 1; i >= 0; i--) {
        new_ir.data.erase(new_ir.data.begin() + erase_indices[i]);
    }
    return new_ir.data;
}

LLIR::node_ret_t LLIR::process_Rule_op(const Parser::Rule &rule, char quantifier) {
    // cpuf::printf("Rule_op\n");
    auto rules = std::any_cast<std::vector<Parser::Rule>>(rule.data);
    auto var = createEmptyVariable(generateVariableName());
    auto svar = createSuccessVariable();
    auto block = createDefaultBlock(var, svar);
    // Add success variable
    var.type = {deduceVarTypeByValue(rule)};
    if (insideLoop && var.type.type != LLIR::var_types::STRING) {
        var.type.templ = {{var.type.type}};
        var.type.type = LLIR::var_types::ARRAY;
    }
    push({LLIR::types::VARIABLE, var});
    push({LLIR::types::VARIABLE, svar});
    // Convert rules into IR
    // for (auto rule : op) {
    //     auto rule_data = std::any_cast<obj_t>(rule.data);
    //     auto rule_val = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
    //     auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));
    //     if (rule_val.name == Parser::Rules::Rule_other) {
    //         auto data = std::any_cast<obj_t>(rule_val.data);
    //         auto id = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    //         auto id_str = std::any_cast<std::string>(id.data);
    //     }
    // }
    auto res = convert_op_rule(rules, 0, var, svar);
    add(res);
    block.erase(block.begin()); // remove variable assignment (it is done in else blocks)
    block.erase(block.end() - 1);
    // Append default block
    add(block);
    return {svar, var, {}, quantifier};
}
void LLIR::process_cll_var(const Parser::Rule &rule) {
    // get data section
    auto data = std::any_cast<obj_t>(rule.data);
    auto type = std::any_cast<Parser::Rule>(corelib::map::get(data, "type"));
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "id"));
    auto name_str = std::any_cast<std::string>(name.data);
    auto op = std::any_cast<Parser::Rule>(corelib::map::get(data, "operator"));
    auto value = std::any_cast<Parser::Rule>(corelib::map::get(data, "value"));

    LLIR::var_type ir_type;
    LLIR::var_assign_types assign_types;
    LLIR::assign assign;
    if (type.data.has_value()) {
        ir_type = cllTreeTypeToIR(type);
    }
    if (op.data.has_value()) {
        assign_types = TreeOpToIR(op);
        if (value.name == Parser::Rules::expr)
            assign = {LLIR::var_assign_values::EXPR, TreeExprToIR(value)};
        // else
        //     assign = TreeTernaryToIR(value);
    }
    if (type.data.has_value()) {
        LLIR::variable var = {name_str, ir_type, assign};
        push({LLIR::types::VARIABLE, var});
        vars.push_back(var);
    } else {
        push({LLIR::types::ASSIGN_VARIABLE, LLIR::variable_assign {name_str, assign_types, assign}});
    }
}
LLIR::condition LLIR::process_cll_cond(const Parser::Rule &rule) {
    auto data = std::any_cast<obj_t>(rule.data);
    auto expr = std::any_cast<Parser::Rule>(corelib::map::get(data, "expr"));
    auto block = std::any_cast<Parser::Rule>(corelib::map::get(data, "block"));
    auto block_data = std::any_cast<std::vector<Parser::Rule>>(block.data);
    auto block_ir = rulesToIr(block_data);
    variable_count = block_ir.variable_count;
    LLIR::condition cond;
    cond.expression = TreeExprToIR(expr);
    cond.block.assign(block_ir.data.begin(), block_ir.data.end());
    return cond;
}
LLIR::node_ret_t LLIR::process_cll(const Parser::Rule &rule) {
    addSpaceSkip = false;
    auto rule_val = std::any_cast<Parser::Rule>(rule.data);
    LLIR::condition cond;
    switch (rule_val.name)
    {
    case Parser::Rules::cll_var:
        process_cll_var(rule_val);
        break;
    case Parser::Rules::cll_if:
        cond = process_cll_cond(rule_val);
        push({LLIR::types::IF, cond});
        break;
    case Parser::Rules::loop_while:
    {
        cond = process_cll_cond(rule_val);
        push({LLIR::types::WHILE, cond});
        break;
    }
    default:
        break;
    }
    return {{}, {}};
}

void LLIR::ruleToIr(const Parser::Rule &rule_rule, char custom_quantifier) {
    auto rule_data = std::any_cast<obj_t>(rule_rule.data);
    auto rule = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
    auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));
    char quantifier_char = '\0';
    if (custom_quantifier != -1) {
        quantifier_char = custom_quantifier;
    } else if (qualifier.data.has_value()) {
        quantifier_char = std::any_cast<char>(qualifier.data);
    }
    if (!isToken && (rule.name != Parser::Rules::Rule_other && rule.name != Parser::Rules::Rule_group && rule.name != Parser::Rules::Rule_op && rule.name != Parser::Rules::cll && rule.name != Parser::Rules::linear_comment && rule.name != Parser::Rules::accessor)  ) {
        //throw Error("Rule having literals. Name: %s", Parser::RulesToString(rule.name));
        //return;
    }
    addSpaceSkip = true;
    LLIR::node_ret_t success_var;
    switch (rule.name) {
        case Parser::Rules::Rule_group: 
            success_var = processGroup(rule, quantifier_char);
            break;
        case Parser::Rules::Rule_csequence:
            success_var = processRuleCsequence(rule, quantifier_char);
            break;
        case Parser::Rules::string:
            success_var = processString(rule, quantifier_char);
            break;
        case Parser::Rules::accessor:
            success_var = processAccessor(rule, quantifier_char);
            break;
        case Parser::Rules::Rule_hex:
            success_var = process_Rule_hex(rule, quantifier_char);
            break;
        case Parser::Rules::Rule_bin: 
            success_var = process_Rule_bin(rule, quantifier_char);
            break;
        case Parser::Rules::Rule_other:
            success_var = process_Rule_other(rule, quantifier_char);
            break;
        case Parser::Rules::Rule_escaped:
            success_var = process_Rule_escaped(rule, quantifier_char);
            break;
        case Parser::Rules::Rule_any:
            success_var = process_Rule_any(rule, quantifier_char);
            break;
        case Parser::Rules::Rule_op:
            success_var = process_Rule_op(rule, quantifier_char);
            break;
        case Parser::Rules::cll:
            success_var = process_cll(rule);
            break;
        case Parser::Rules::linear_comment:
            return;
        default:
            throw Error("Converting undefined rule: %s,%s", Parser::RulesToString(rule_rule.name), Parser::RulesToString(rule.name));
    }
    isFirst = false;
    if (!success_var.shadow_var.name.empty())
        elements.push_back(success_var.shadow_var);
    else if (!success_var.var.name.empty()) {
        elements.push_back(success_var.var);
    }
    if (addSpaceSkip && isToken)
        push({LLIR::types::SKIP_SPACES, isToken});
    vars.push_back(success_var.var);
    vars.push_back(success_var.svar);
    vars.push_back(success_var.shadow_var);
    success_vars.push_back(success_var);
}
LLIR LLIR::rulesToIr(const std::vector<Parser::Rule> &rules) {
    LLIR result(tree);
    result.proceed(*this);
    for (const auto &rule : rules) {
        result.ruleToIr(rule);
    }
    return result;
}

void LLIR::treeToIr(const Parser::Tree &tree) {
    for (auto &el : tree) {
        if (el.name == Parser::Rules::id)
            cpuf::printf("file: %s\n", std::any_cast<std::string>(el.data));
        if (el.name != Parser::Rules::Rule)
            continue;
        auto data = std::any_cast<obj_t>(el.data);
        auto name = std::any_cast<std::string>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name")).data);
        auto rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "rule"));
        auto data_block = std::any_cast<Parser::Rule>(corelib::map::get(data, "data_block"));
        auto nested_rules = std::any_cast<std::vector<Parser::Rule>>(corelib::map::get(data, "nestedRules"));
        isToken = corelib::text::isUpper(name);
        fullname.push_back(name);
        LLIR new_ir(tree);
        new_ir.proceed(*this);
        bool to_add = true;
        if (corelib::text::isLower(name)) {
            if (tokensOnly)
                to_add = false;
        }
        if (corelib::text::isUpper(name)) {
            if (rulesOnly)
                to_add = false;
        }
        if (!nested_rules.empty()) {
            new_ir.treeToIr(nested_rules);
            add(new_ir);
        }
        if (to_add) {
            auto values = rulesToIr(rules);
            if (!values.data.empty() && values.data.back().type == LLIR::types::SKIP_SPACES)
                values.pop(); // remove skip of spaces at the end
            update(values);
            inlineAccessors(values.data);
            push({ isToken ? LLIR::types::TOKEN : LLIR::types::RULE, std::pair<std::string, std::vector<std::string>> {name, fullname}});  
            add(values);
            if (data_block.data.has_value())
                push({LLIR::types::DATA_BLOCK, TreeDataBlockToIR(data_block)});
            push({LLIR::types::RULE_END});
        }
        fullname.pop_back();
        clear_thread();
    }
}
