
Rule(cll_csupport_types)
{
    auto pos = in;
    bool is_unsigned = false;
    std::string val;
    if (!strncmp(pos, "unsigned", sizeof("unsigned") - 1))
    {
        is_unsigned = true;
        pos += sizeof("unsigned") - 1;
    }
    if (!strncmp(pos, "char", sizeof("char") - 1))
    {
        val = "char";
        pos += sizeof("char") - 1;
    } else if (!strncmp(pos, "short", sizeof("short") - 1))
    {
        val = "short";
        pos += sizeof("short") - 1;
    } else if (!strncmp(pos, "int", sizeof("int") - 1))
    {
        val = "int";
        pos += sizeof("int") - 1;
    } else if (!strncmp(pos, "long", sizeof("long") - 1)) 
    {
        val = "long";
        pos += sizeof("long") - 1;
    } else if (!strncmp(pos, "long long", sizeof("long long") - 1))
    {
        val = "long long";
        pos += sizeof("long long") - 1;
    } else if (is_unsigned)
    {
        // other cannot be unsigned
        return {}
    } else if (strncmp(pos, "float", sizeof("float") - 1))
    {
        val = "float";
        pos += sizeof("float") - 1;
    } else if (!strncmp(pos, "double", sizeof("double") - 1))
    {
        val = "double";
        pos += sizeof("double") - 1;
    } else
    {
        if (!strncmp(pos, "deque", sizeof("deque") - 1))
        {
            val = "deque";
            pos += sizeof("deque") - 1;
        } else if (!strncmp(pos, "vector", sizeof("vector") - 1))
        {
            val = "vector";
            pos += sizeof("vector") - 1;
        } else if (strncmp(pos, "queue", sizeof("queue") - 1))
        {
            val = "queue";
            pos += sizeof("queue") - 1;
        } else if (strncmp(pos, "stack", sizeof("stack") - 1))
        {
            val = "stack";
            pos += sizeof("stack") - 1;
        } else if (strncmp(pos, "list", sizeof("list") - 1)) 
        {
            val = "list";
            pos += sizeof("list") - 1;
        } else if (strncmp(pos, "forward_list", sizeof("forward_list") - 1)) 
        {
            val = "forward_list";
            pos += sizeof("forward_list") - 1;
        } else return {};
        auto template_res = cll_template(cll_template_content_typename);
    }
}
Rule(cll_type)
{

}