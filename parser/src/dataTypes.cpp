// STRING Rule
#include <parser.h>
#include <parser_defs.h>
Rule(string) {
    const char* pos = in;
    char quote;
    std::string data;
    ISPA_STD::skip_spaces(pos);
    if (!(*pos == '"' || *pos == '\'') )
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
    std::string sign = "+";
    std::string main, dec;
    bool hasPoint = false;

    ISPA_STD::skip_spaces(pos);
    // Check for sign
    if (*pos == '+' || *pos == '-') {
        sign = *pos;
        pos++;
    }
    ISPA_STD::skip_spaces(pos);
    // Read main number
    while (isdigit(*pos)) {
        main += *pos++;
    }
    ISPA_STD::skip_spaces(pos);
    // Check for decimal point
    if (*pos == '.') {
        if (isdigit((*pos + 1))) {
            hasPoint = true;
            pos += 2;
            ISPA_STD::skip_spaces(pos);
            while (isdigit(*pos)) {
                dec += *pos++;
            }
            ISPA_STD::skip_spaces(pos);
        }
    }
    if (main.empty())
        return {};
    std::string full = sign + main + (dec.empty() ? "" : std::string(".") + dec);
    double main_n = std::stod(main);
    double dec_n = dec.empty() ? 0.0 : std::stod(dec);
    std::unordered_map<const char*, std::any> data {
        { "sign", sign },
        { "main", main },
        { "main_n", main_n },
        { "dec", dec },
        { "dec_n", dec_n },
        { "full", sign + main + std::string(".") + dec }
    };
    RULE_SUCCESSD(in, pos, number, data);
}

// BOOLEAN Rule
Rule(boolean) {
    const char* pos = in;
    std::string d;
    int val;
    std::unordered_map<const char*, std::any> data;
    ISPA_STD::skip_spaces(pos);
    if (!strncmp(in, "true", sizeof("true"))) {
        d = "true";
        val = 1;
    } else if (!strncmp(in, "false", sizeof("false"))) {
        d = "false";
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
    std::vector<::Parser::Rule> data;
    ISPA_STD::skip_spaces(pos);
    if (*pos != '[') {
        return {};
    }
    pos++;
    ISPA_STD::skip_spaces(pos);
    auto any_data_f = any_data(pos);
    if (any_data_f.result)
    {
        pos += any_data_f.token.length();
        data.push_back(any_data_f.token);
        ISPA_STD::skip_spaces(pos);
        while(*pos == ',') {
            pos++;
            ISPA_STD::skip_spaces(pos);
            auto any_data_s = any_data(pos);
            if (!any_data_s.result)
                break;
            pos += any_data_s.token.length();
            ISPA_STD::skip_spaces(pos);
            data.push_back(any_data_s.token);
        }
    }
    ISPA_STD::skip_spaces(pos);
    if (*pos != ']')
        return {};
    pos++;
    RULE_SUCCESSD(in, pos, array, data);
}

// OBJECT Rule
Rule(object) {
    const char* pos = in;
    std::vector<::Parser::Rule> keys;
    std::vector<::Parser::Rule> values;

    ISPA_STD::skip_spaces(pos);
    if (*pos != '{')
        return {};
    pos++;
    ISPA_STD::skip_spaces(pos);
    auto key_res = any_data(pos);
    ::Parser::Rule_result value;
    if (key_res.result) {
        pos += key_res.token.length();
        ISPA_STD::skip_spaces(pos);
        if (*pos != ':')
            return {};
        pos++;
        ISPA_STD::skip_spaces(pos);
        value = any_data(pos);
        if (!value.result)
            return {};
        ISPA_STD::skip_spaces(pos);
        while (*pos == ',') {
            ISPA_STD::skip_spaces(pos);
            ++pos;
            auto key2_res = any_data(pos);
            if (!key2_res.result)
                break;
            pos += key2_res.token.length();
            ISPA_STD::skip_spaces(pos);
            if (*pos!= ':')
                break;
            ISPA_STD::skip_spaces(pos);
            auto value2_res = any_data(++pos);
            if (!value2_res.result)
                break;
            pos += value2_res.token.length();

            keys.push_back(key2_res.token);
            values.push_back(value2_res.token);
        }
    }
    if (*pos != '}')
        return {};
    pos++;
    std::unordered_map<const char*, std::any> data {
        { "key", key_res },
        { "value", value },
        { "keys", keys },
        { "values", values }
    };
    RULE_SUCCESSD(in, pos, object, data);
}

// ANY_DATA Rule
Rule(any_data) {
    std::any data;
    // Try each type in order
    ::Parser::Rule token;
    ::Parser::Rule_result result = boolean(in);
    if (result.result)
        token = result.token;
    result = number(in);
    if (result.result)
        token = result.token;
    result = string(in);
    if (result.result)
        token = result.token;
    result = array(in);
    if (result.result)
        token = result.token;
    result = object(in);
    if (result.result)
        token = result.token;
    result = var_refer(in);
    if (result.result)
        token = result.token;
    result = accessor(in);
    if (result.result)
        token = result.token;
    if (token.empty())
        return {};
    RULE_SUCCESSD(in, in + token.length(), any_data, token);
}
