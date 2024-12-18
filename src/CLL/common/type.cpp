#include <parser.h>
#include <parser_defs.h>

Rule(cll_csupport_types)
{
    auto pos = in;
    bool is_unsigned = false;
    std::string val;
    std::vector<std::any> templated;
    ISC_STD::skip_spaces(pos);
    if (!strncmp(pos, "unsigned", sizeof("unsigned") - 1))
    {
        is_unsigned = true;
        pos += sizeof("unsigned") - 1;
    }
    ISC_STD::skip_spaces(pos);
    if (!strncmp(pos, "char", sizeof("char") - 1))
    {
        val = "char";
        pos += sizeof("char") - 1;
    } 
    else if (!strncmp(pos, "short", sizeof("short") - 1))
    {
        val = "short";
        pos += sizeof("short") - 1;
    } 
    else if (!strncmp(pos, "int", sizeof("int") - 1))
    {
        val = "int";
        pos += sizeof("int") - 1;
    } 
    else if (!strncmp(pos, "long", sizeof("long") - 1)) 
    {
        val = "long";
        pos += sizeof("long") - 1;
    } 
    else if (!strncmp(pos, "long long", sizeof("long long") - 1))
    {
        val = "long long";
        pos += sizeof("long long") - 1;
    } 
    else if (is_unsigned)
    {
        // other cannot be unsigned
        return {};
    } 
    else if (!strncmp(pos, "float", sizeof("float") - 1))
    {
        val = "float";
        pos += sizeof("float") - 1;
    } 
    else if (!strncmp(pos, "double", sizeof("double") - 1))
    {
        val = "double";
        pos += sizeof("double") - 1;
    } 
    else
    {
        if (!strncmp(pos, "deque", sizeof("deque") - 1))
        {
            val = "deque";
            pos += sizeof("deque") - 1;
        } 
        else if (!strncmp(pos, "vector", sizeof("vector") - 1))
        {
            val = "vector";
            pos += sizeof("vector") - 1;
        } 
        else if (!strncmp(pos, "queue", sizeof("queue") - 1))
        {
            val = "queue";
            pos += sizeof("queue") - 1;
        } 
        else if (!strncmp(pos, "stack", sizeof("stack") - 1))
        {
            val = "stack";
            pos += sizeof("stack") - 1;
        } 
        else if (!strncmp(pos, "list", sizeof("list") - 1)) 
        {
            val = "list";
            pos += sizeof("list") - 1;
        } 
        else if (!strncmp(pos, "forward_list", sizeof("forward_list") - 1)) 
        {
            val = "forward_list";
            pos += sizeof("forward_list") - 1;
        } else return {};

        ISC_STD::skip_spaces(pos);
        // cll_template

        if (*pos != '<') {
            return {};  // Return if the opening '<' is not present
        }
        pos++;
        ISC_STD::skip_spaces(pos);

        // Begin parsing content
        auto content_res = cll_template_typename(pos); // Directly use `cll_template_typename` as the `content` function
        if (!content_res.result) {
            return {};  // Return if parsing fails
        }
        pos += content_res.token.length();

        templated.push_back(content_res.token);

        // Parse subsequent elements separated by commas
        // while (*pos == ',') {
        //     ++pos;
        //     ISC_STD::skip_spaces(pos);
        //     content_res = cll_template_typename(pos); // Call `cll_template_typename` again
        //     if (!content_res.result) {
        //         break;  // Stop parsing if further content fails
        //     }
        //     pos += content_res.token.length();
        //     templated.push_back(content_res.token);
        //     ISC_STD::skip_spaces(pos);
        // }

        // Ensure the closing '>' is present
        ISC_STD::skip_spaces(pos);
        if (*pos != '>') {
            return {};  // Return if closing '>' is not found
        }
        pos++;
    }

    std::unordered_map<const char*, std::any> data {
        { "val", val },
        { "templated", templated }
    };
    RULE_SUCCESSD(in, pos, cll_csupport_types, data);
}
Rule(cll_type)
{
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto res = cll_csupport_types(pos);
    if (!res.result) {
        res = cll_type_abstract(pos);
        if (!res.result)
            return {};
    }
    pos += res.token.length();
    RULE_SUCCESSD(in, pos, cll_type, res);
}
Rule(cll_type_abstract) 
{
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    std::string type;
    ::Parser::Rule templ;
    if (
        !strncmp(pos, "var", 3) || !strncmp(pos, "any", 3) || !strncmp(pos, "num", 3) ||
        !strncmp(pos, "str", 3)
    ) {
        type.append(pos, 3);
        pos += 3;
    
    } else if (!strncmp(pos, "bool", 4)) {
        type.append(pos, 4);
        pos += 4;
    } else if (!strncmp(pos, "arr", 3) || !strncmp(pos, "obj", 3)) {
        type.append(pos, 3);
        pos += 3;
        printf("Cll_type_enter_obj\n");
        ISC_STD::skip_spaces(pos);
        if (*pos != '<') {
            return {};
        }
        pos++;
        ISC_STD::skip_spaces(pos);
        auto cll_template_res = cll_template_typename(pos);
        if (!cll_template_res.result)
        {
            return {};
        }
        pos += cll_template_res.token.length();
        ISC_STD::skip_spaces(pos);
        if (*pos != '>') 
        {
            return {};
        }
        pos++;
        ISC_STD::skip_spaces(pos);
        templ = cll_template_res.token;
    } else return {};
    std::unordered_map<const char*, std::any> data {
        { "type", type },
        { "template", templ }
    };
    RULE_SUCCESSD(in, pos, cll_type_abstract, data);
}