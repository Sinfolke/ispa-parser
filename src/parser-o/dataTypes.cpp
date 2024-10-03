
// STRING Rule
Rule(string) {
    const char* pos = in;
    char quote;
    std::string data;
    if (not (*pos == '"' || *pos == '\'') )
        return {};
    quote = *pos++;
    // Capture the string content
    while (*pos != quote) {
        if (*pos == '\\') {
            data += *pos++; // Skip escape character
        }
        data += *pos++;
    }
    pos++; // Skip the closing quote
    RULE_SUCCESSD(in, pos, string, data);
}

// NUMBER Rule
Rule(number) {
    const char* pos = in;
    std::string sign(1, *pos);
    std::string main, dec;
    bool hasPoint = false;

    // Check for sign
    if (*pos == '+' || *pos == '-') {
        pos++;
    }

    // Read main number
    while (isdigit(*pos)) {
        main += *pos++;
    }

    // Check for decimal point
    if (*pos == '.' || *pos == ',') {
        hasPoint = true;
        pos++;
        while (isdigit(*pos)) {
            dec += *pos++;
        }
    }

    std::string full = sign + main + (hasPoint ? (".") + dec : "");
    double main_n = std::stod(main);
    double dec_n = hasPoint ? std::stod(dec) : 0.0;
    std::unordered_map<const char*, std::any> data {
        { "sign", sign },
        { "main", main },
        { "main_n", main_n },
        { "dec", dec },
        { "dec_n", dec_n },
        { "full", main + point + dec }
    };
    RULE_SUCCESSD(in, pos, boolean, data);
}

// BOOLEAN Rule
Rule(boolean) {
    const char* pos = in;
    string_part d;
    int val;
    std::unordered_map<const char*, std::any> data;
    if (not strncmp(in, "true", sizeof("true"))) {
        d = string_part(in, sizeof("true"));
        val = 1;
    } else if (not strncmp(in, "false", sizeof("false"))) {
        d = string_part(in, sizeof("false"));
        val = 0;
    } else {
        return {};
    }
    data = {
        { "val", val},
        { "lit", d }
    };
    RULE_SUCCESSD(in, pos, boolean, data);
}

// ARRAY Rule
Rule(array) {
    const char* pos = in;
    std::vector<std::any> data;
    if (*pos != '[')
        return {};
    auto any_data_f = any_data(++pos);
    if (!any_data_f.result) 
        goto arrayClose; // should be closed immediately
    
    data.push(any_data_f.token);
    pos += any_data_f.token.length();
    while(*pos == ',') {
        auto any_data_s = any_data(pos + 1);
        if (!any_data_s.result)
            break;
        pos += any_data_s.token.length();
    }
    arrayClose:
    if (*pos != ']')
        return {};
    RULE_SUCCESSD(in, pos, array, data);
}

// OBJECT Rule
Rule(object) {
    const char* pos = in;
    std::unordered_map<std::string, std::any> data;
    std::vector<std::string> keys;
    std::vector<std::any> values;

    if (*pos != '{')
    return {};
    ++pos;
    auto id_res = id(pos);
    if (not id_res.result)
        goto objectClose; // should be closed immediately
    pos += id_res.token.length();
    if (*pos != ':')
        return {};
    auto any_data_res = any_data(++pos);
    if (!any_data_res.result)
        return {};
    data[TO (std::string, id_res.token.data )] = any_data.token.data;
    while (*pos == ',') {
        ++pos;
        id_res = id(pos);
        if (not id_res.result)
            break;
        pos += id_res.token.length();
        if (*pos!= ':')
            break;
        any_data_res = any_data(++pos);
        if (!any_data_res.result)
            break;
        data[TO(std::string, id_res.token.data)] = any_data_res.token.data;
        pos += any_data_res.token.length();
    }
    objectClose:
    if (*pos != '}')
        return {};
    RULE_SUCCESSD(in, pos, object, data);
}

// ANY_DATA Rule
Rule(any_data) {
    const char* pos = in;
    std::any data;

    // Try each type in order
    Rule result = boolean(in);
    if (result.result)
        return result.token;
    result = number(in);
    if (result.result)
        return result.token;
    result = string(in);
    if (result.result)
        return result.token;
    result = array(in);
    if (result.result)
        return result.token;
    result = object(in);
    if (result.result)
        return result.token;
    return {};
}
