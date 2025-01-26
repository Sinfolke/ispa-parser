#include <IR.h>
#include <internal_types.h>
#include <token_management.h>
#include <corelib.h>
#include <parser.h>
#include <cpuf/hex.h>
// a structure used to cout
void IR::ir::add(IR::ir repr) {
    elements.insert(elements.end(), repr.elements.begin(), repr.elements.end());
}
void IR::ir::add(arr_t<IR::member> repr) {
    elements.insert(elements.end(), repr.begin(), repr.end());
}
void IR::ir::push(IR::member member) {
    elements.push_back(member);
}
size_t IR::ir::size() {
    return elements.size();
}
IR::var_type deduceTypeOfSingleUnit(Parser::Rule rule) {
    return IR::var_type::UNDEFINED;
}
void push_to_elements(arr_t<IR::element_count> &elements, IR::ir &member) {
    elements.push_back({member.size(), elements.size() > 0 ? elements.back().index_in_rule : 0});
}
void push_to_elements_increament(arr_t<IR::element_count> &elements, IR::ir &member) {
    elements.push_back({member.size(), elements.size() > 0 ? elements.back().index_in_rule + 1 : 0});
}
IR::variable createEmptyVariable(std::string name, int assign_next_rules=0) {
    IR::variable var {
        IR::var_type::UNDEFINED,
        name,
        IR::var_assign_values::NONE,
        assign_next_rules
    };
    return var;
}
std::string generateVariableName(int &variable_count) {
    return std::string("_") + std::to_string(variable_count++);
}
void processExitStatements(IR::ir &values) {
    for (auto &el : values.elements) {
        if (el.type == IR::types::IF) {
            auto condition = std::any_cast<IR::condition>(el.value);
            for (auto &unit : condition.block) {
                if (unit.type == IR::types::EXIT) {
                    unit.type = IR::types::BREAK_LOOP;
                }
            }
            el.value = condition;
        }
    }
}

IR::variable createSuccessVariable(int &variable_count) {
    IR::variable var = createEmptyVariable(generateVariableName(variable_count));
    var.type = IR::var_type::BOOLEAN;
    var.value = IR::var_assign_values::_FALSE;
    return var;
}

void addPostLoopCheck(IR::ir &new_ir, const IR::variable &var) {
    IR::condition check_cond = {
        { { IR::condition_types::VARIABLE, var.name },
          { IR::condition_types::EQUAL },
          { IR::condition_types::NUMBER, false } },
        { { IR::types::EXIT } }
    };
    new_ir.push({IR::types::IF, check_cond});
}
void handle_plus_qualifier(IR::condition loop, IR::ir &new_ir, int &variable_count) {
    IR::variable var = createSuccessVariable(variable_count);
    loop.block.push_back({IR::types::ASSIGN_VARIABLE, IR::variable_assign {var.name, IR::var_assign_types::ASSIGN, IR::var_assign_values::_TRUE}});
    new_ir.push({IR::types::VARIABLE, var});
    new_ir.push({IR::types::WHILE, loop});
    addPostLoopCheck(new_ir, var);
}
arr_t<IR::member> createDefaultBlock(IR::variable var) {
    return {
        {IR::types::ASSIGN_VARIABLE, IR::variable_assign {var.name, IR::var_assign_types::ADD, IR::var_assign_values::CURRENT_POS_SEQUENCE}},
        {IR::types::INCREASE_POS_COUNTER}
    };
}
arr_t<IR::member> createDefaultBlock() {
    return {
        {IR::types::INCREASE_POS_COUNTER}
    };
}
void pushBasedOnQualifier(arr_t<IR::expr> expr, arr_t<IR::member> block, IR::ir &member, char qualifier_char, int &variable_count) {
    switch (qualifier_char) {
        case '+':
            handle_plus_qualifier({expr, block}, member, variable_count);
            break;
        case '*':
            member.push({IR::types::WHILE, IR::condition{expr, block}});
            break;
        case '?':
            member.push({IR::types::IF, IR::condition{expr, block}});
            break;
        default:
            member.push({IR::types::IF, IR::condition{expr, {{IR::types::EXIT}}}});
            member.add(block);
            break;
    }
}
void affectIrByQualifier(IR::ir values, char qualifier, int &variable_count) {
    IR::ir new_ir;
    if (qualifier == '*' || qualifier == '+') {
        IR::condition loop = { { { IR::condition_types::NUMBER, 1 } }, {} };
        processExitStatements(values);
        loop.block = values.elements;
        new_ir.push({IR::types::WHILE, loop});
        if (qualifier == '+') {
            new_ir.elements.clear();
            handle_plus_qualifier(loop, new_ir, variable_count);
        }
    } else if (qualifier == '?') {
        IR::condition loop = { { {IR::condition_types::NUMBER, 0} }, values.elements };
        processExitStatements(values);
        new_ir.push({ IR::types::DOWHILE, loop });
    } else {
        return;
    }
    values = new_ir;
}
void processGroup(Parser::Rule rule, IR::ir &member, int &variable_count, char qualifier_char, bool isToken) {
    cpuf::printf("group\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto variable = corelib::map::get(data, "variable").has_value() ? std::any_cast<Parser::Rule>(corelib::map::get(data, "variable")) : Parser::Rule();
    auto val = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));
    auto values = rulesToIr(val, isToken);
    auto method_call = IR::member {IR::types::METHOD_CALL};
    // create variable with name of "var" or with auto-generated one
    auto var = (!variable.empty() && variable.name == Parser::Rules::id) ?
                        createEmptyVariable(std::any_cast<std::string>(variable.data), values.size()) :
                        createEmptyVariable(generateVariableName(variable_count), values.size());
    affectIrByQualifier(values, qualifier_char, variable_count);

    if (!variable.empty() && variable.name == Parser::Rules::method_call) {
        auto var_rule = std::any_cast<Parser::Rule>(variable.data);
        auto var_rule_data = std::any_cast<obj_t>(var_rule.data);
        method_call.value = var_rule_data;
        member.push({IR::types::VARIABLE, var});
        member.push({IR::types::GROUP});
        member.add(values);
        member.push({IR::types::METHOD_CALL, method_call});
    } else {
        member.push({IR::types::VARIABLE, var});
        member.push({IR::types::GROUP, values});
    }
}
void processRuleCsequence(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    cpuf::printf("csequence\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto _not = std::any_cast<bool>(corelib::map::get(data, "not"));
    auto values = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "val"));

    auto var = createEmptyVariable(generateVariableName(variable_count));
    var.type = IR::var_type::STRING;
    bool is_negative = false;
    arr_t<IR::expr> expr;

    if ((!_not && qualifier_char == '\0') || _not) {
        expr = {
            {IR::condition_types::NOT},
            {IR::condition_types::GROUP_OPEN}
        };
        is_negative = true;
    }

    bool first = true;
    for (auto &value : values) {
        if (!first)
            expr.push_back({IR::condition_types::AND});
        first = false;

        switch (value.name) {
            case Parser::Rules::Rule_csequence_diapason: {
                auto range_data = std::any_cast<arr_t<char>>(value.data);
                expr.insert(expr.end(), {
                    {IR::condition_types::GROUP_OPEN},
                    {IR::condition_types::CURRENT_CHARACTER},
                    {IR::condition_types::HIGHER_OR_EQUAL},
                    {IR::condition_types::CHARACTER, range_data[0]},
                    {IR::condition_types::AND},
                    {IR::condition_types::CURRENT_CHARACTER},
                    {IR::condition_types::LOWER_OR_EQUAL},
                    {IR::condition_types::CHARACTER, range_data[1]},
                    {IR::condition_types::GROUP_CLOSE}
                });
                break;
            }
            case Parser::Rules::Rule_csequence_escape:
            case Parser::Rules::Rule_csequence_symbol: {
                auto char_data = std::any_cast<std::string>(value.data);
                expr.insert(expr.end(), {
                    {IR::condition_types::CURRENT_CHARACTER},
                    {IR::condition_types::EQUAL},
                    {IR::condition_types::CHARACTER, char_data}
                });
                break;
            }
            default:
                throw Error("undefined csequence subrule");
        }
    }

    if (is_negative) {
        expr.push_back({IR::condition_types::GROUP_CLOSE});
    }
    member.push({IR::types::VARIABLE, var});
    arr_t<IR::member> block = createDefaultBlock(var);

    pushBasedOnQualifier(expr, block, member, qualifier_char, variable_count);
}
void processString(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    cpuf::printf("string, data: %s\n", std::any_cast<std::string>(rule.data));
    auto data = std::any_cast<std::string>(rule.data);
    auto var = createEmptyVariable(generateVariableName(variable_count));
    var.type = IR::var_type::STRING;
    arr_t<IR::expr> expr = {
        {IR::condition_types::STRNCMP, data}
    };
    arr_t<IR::member> block = createDefaultBlock(var);
    member.push({IR::types::VARIABLE, var});
    pushBasedOnQualifier(expr, block, member, qualifier_char, variable_count);
}
void process_Rule_hex(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    cpuf::printf("hex\n");
    auto data = std::any_cast<std::string_view>(rule.data);
    std::string data_str(data.data(), data.size());
    arr_t<IR::expr> expr = {};
    auto var = createEmptyVariable(generateVariableName(variable_count));
    arr_t<IR::member> block = createDefaultBlock(var);
    bool is_first = true, is_negative = false;
    if (qualifier_char == '\0') {
        expr.push_back({IR::condition_types::NOT});
        expr.push_back({IR::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    if (data.size() % 2 != 0)
        data_str.insert(data_str.begin(), '0');
    for (int i = 0; i < data_str.size(); i += 2) {
        std::string hex(data_str.data() + i, 2);
        if (!is_first)
            expr.push_back({IR::condition_types::AND});
        is_first = false;
        expr.push_back({IR::condition_types::CURRENT_CHARACTER});
        expr.push_back({IR::condition_types::EQUAL});
        expr.push_back({IR::condition_types::NUMBER, (char) hex::to_decimal(hex)});
    }
    pushBasedOnQualifier(expr, block, member, qualifier_char, variable_count);
}
void process_Rule_bin(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    cpuf::printf("hex\n");
    auto data = std::any_cast<std::string_view>(rule.data);
    std::string data_str(data.data(), data.size());
    arr_t<IR::expr> expr = {};
    auto var = createEmptyVariable(generateVariableName(variable_count));
    arr_t<IR::member> block = {
        {IR::types::ASSIGN_VARIABLE, IR::variable_assign {var.name, IR::var_assign_types::ADD, IR::var_assign_values::CURRENT_POS_SEQUENCE}},
        {IR::types::INCREASE_POS_COUNTER},
    };
    bool is_first = true, is_negative = false;
    if (qualifier_char == '\0') {
        expr.push_back({IR::condition_types::NOT});
        expr.push_back({IR::condition_types::GROUP_OPEN});
        is_negative = true;
    }
    while (data.size() % 4 != 0)
        data_str.insert(data_str.begin(), '0');
    for (int i = 0; i < data_str.size(); i += 2) {
        std::string bin(data_str.data() + i, 4);
        if (!is_first)
            expr.push_back({IR::condition_types::AND});
        is_first = false;
        expr.push_back({IR::condition_types::CURRENT_CHARACTER});
        expr.push_back({IR::condition_types::EQUAL});
        expr.push_back({IR::condition_types::NUMBER, (char) hex::to_decimal(hex::from_binary(bin))});
    }
    pushBasedOnQualifier(expr, block, member, qualifier_char, variable_count);
}
void processAccessor(const Parser::Rule &rule, IR::ir &member, char qualifier_char) {
    cpuf::printf("accessor\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto first = std::any_cast<Parser::Rule>(corelib::map::get(data, "first"));
    auto second = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "second"));
    second.insert(second.begin(), first);
    for (auto &el : second) {
        el = std::any_cast<Parser::Rule>(el.data);
    }
    auto mem = IR::member {
        IR::types::ACCESSOR,
        IR::accessor { second, qualifier_char }
    };
    member.push(mem);
}
void process_Rule_other(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool isToken) {
    cpuf::printf("Rule_other");
    auto data = std::any_cast<obj_t>(rule.data);
    auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
    auto name_str = std::any_cast<std::string>(name.data);
    cpuf::printf(", name: %s\n", name_str);

    auto var = createEmptyVariable(generateVariableName(variable_count));
    bool isCallingToken = isupper(name_str[0]);
    var.type = isCallingToken ? IR::var_type::Token : IR::var_type::Rule;
    if (isToken) {

    }
}
void process_Rule_escaped(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool &add_space) {
    cpuf::printf("Rule_escaped\n");
    auto data = std::any_cast<obj_t>(rule.data);
    auto c = std::any_cast<std::string>(corelib::map::get(data, "c"));
    auto num = std::any_cast<Parser::Rule>(corelib::map::get(data, "num"));
    obj_t num_data;
    double num_dec;
    if (num.data.has_value()) {
        num_data = num.as<obj_t>();
        num_dec = std::any_cast<double>(corelib::map::get(num_data, "main_n"));
    } else {
        num_dec = -1;
    }
    auto var = createEmptyVariable(generateVariableName(variable_count));
    arr_t<IR::expr> expression;
    arr_t<IR::member> block = createDefaultBlock(var);
    if (qualifier_char != '\0')
        UWarning("Qualifier after \\%s ignored", c).print();
    switch (c[0]) {
        case 's':
            if (num_dec == 0) {
                // means do not add skip of spaces
                add_space = false;
                return;
            } else {
                UWarning("Number after \\s ignored").print();
            }
            expression = {
                {IR::condition_types::CURRENT_CHARACTER},
                {IR::condition_types::EQUAL},
                {IR::condition_types::CHARACTER, ' '}
            };
            break;
            
    }
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::IF, IR::condition{expression, block}});
}
void process_Rule_any(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char, bool &add_space) {
    cpuf::printf("Rule_any, type: %s\n", rule.data.type().name());
    auto var = createEmptyVariable(generateVariableName(variable_count));
    arr_t<IR::expr> expression;
    arr_t<IR::member> block = createDefaultBlock(var);
    if (qualifier_char != '\0')
        UWarning("Qualifier after . ignored").print();
    expression = {
        {IR::condition_types::CURRENT_CHARACTER},
        {IR::condition_types::NOT_EQUAL},
        {IR::condition_types::CHARACTER, '\0'}
    };
    member.push({IR::types::VARIABLE, var});
    member.push({IR::types::IF, IR::condition{expression, block}});
}
void process_Rule_op(const Parser::Rule &rule, IR::ir &member, int &variable_count, char qualifier_char) {
    cpuf::printf("Rule_op, type: %s\n", rule.data.type().name());
    auto op = std::any_cast<arr_t<Parser::Rule>>(rule.data);
    auto var = createEmptyVariable(generateVariableName(variable_count));
    auto succcess_var = createSuccessVariable(variable_count);
    arr_t<IR::expr> expression;
    arr_t<IR::member> block = createDefaultBlock(var);
    for (auto &rule : op) {
        cpuf::printf("rule name: %s\n", Parser::RulesToString(rule.name));
        //auto rule_data = rule.as<obj_t>();
    }
}
void ruleToIr(Parser::Rule &rule_rule, IR::ir &member, arr_t<IR::element_count> &elements, int &variable_count, bool isToken) {
    member.push({ IR::types::RULE, });
    auto rule_data = std::any_cast<obj_t>(rule_rule.data);
    if (corelib::map::get(rule_data, "val").type() == typeid(std::unordered_map<const char*, std::any>)) {
        auto group = std::any_cast<obj_t>(corelib::map::get(rule_data, "val"));
        for (const auto &key : group) {
            cpuf::printf("key: %s\n", key.first);
        }
    }
    auto rule = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "val"));
    auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(rule_data, "qualifier"));
    char qualifier_char = '\0';
    if (qualifier.data.type() == typeid(char)) {
        qualifier_char = std::any_cast<char>(qualifier.data);
    }
    if (!isToken && (rule.name != Parser::Rules::Rule_other && rule.name != Parser::Rules::Rule_group && rule.name != Parser::Rules::Rule_op && rule.name != Parser::Rules::cll && rule.name != Parser::Rules::linear_comment && rule.name != Parser::Rules::accessor)  ) {
        throw Error("Rule having literals. Name: %s", Parser::RulesToString(rule.name));
        return;
    }
    bool add_space_skip = true;
    switch (rule.name) {
        case Parser::Rules::Rule_group: 
            processGroup(rule, member, variable_count, qualifier_char, isToken);
            break;
        case Parser::Rules::Rule_csequence:
            processRuleCsequence(rule, member, variable_count, qualifier_char);
            break;
        case Parser::Rules::string:
            processString(rule, member, variable_count, qualifier_char);
            break;
        case Parser::Rules::accessor:
            processAccessor(rule, member, qualifier_char);
            break;
        case Parser::Rules::Rule_hex:
            process_Rule_hex(rule, member, variable_count, qualifier_char);
            break;
        case Parser::Rules::Rule_bin: 
            process_Rule_bin(rule, member, variable_count, qualifier_char);
            break;
        case Parser::Rules::Rule_other:
            process_Rule_other(rule, member, variable_count, qualifier_char, isToken);
            break;
        case Parser::Rules::Rule_escaped:
            process_Rule_escaped(rule, member, variable_count, qualifier_char, add_space_skip);
            break;
        case Parser::Rules::Rule_any:
            process_Rule_any(rule, member, variable_count, qualifier_char, add_space_skip);
            break;
        case Parser::Rules::Rule_op:
            process_Rule_op(rule, member, variable_count, qualifier_char);
            break;
        case Parser::Rules::cll:
            break;
        case Parser::Rules::linear_comment:
            return;
        default:
            return;
            throw Error("Converting undefined rule");
    }
}
IR::ir rulesToIr(arr_t<Parser::Rule> rules, bool isToken) {
    IR::ir result;
    arr_t<IR::element_count> elements;
    int variable_count = 0;
    for (auto &rule : rules) {
        ruleToIr(rule, result, elements, variable_count, isToken);
    }
    return result;
}
IR::ir treeToIr(Parser::Tree &tree) {
    IR::ir result_ir;
    for (auto &el : tree) {
        if (el.name != Parser::Rules::Rule)
            continue;
        auto data = std::any_cast<obj_t>(el.data);
        auto name = std::any_cast<std::string>(std::any_cast<Parser::Rule>(corelib::map::get(data, "name")).data);
        auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
        cpuf::printf("Processing %s\n", name);
        result_ir.add(rulesToIr(rules, isupper(name[0])));
    }
    return result_ir;
}