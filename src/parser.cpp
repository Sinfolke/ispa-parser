#include <parser.h>
#include <parser_defs.h>
Rule(id) {
    const char* pos = in;
    std::string val;
    ISC_STD::skip_spaces(pos);
    while (isdigit(*pos)) {
        val += *pos++;
    }
    ISC_STD::skip_spaces(pos);
    if (!isalpha(*pos) || *pos == '_') {
        return {};
    }
    do {
        val += *pos++;
    } while (isalnum(*pos) || *pos == '_');
    // construct result as valid
    // extract full string from the first group
    RULE_SUCCESSD(in, pos, id, val);
}
Rule(Import_path) {    
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    std::string v;
    while (
        not 
        (
            *pos == '"' ||
            *pos == '<' ||
            *pos == '>' ||
            *pos == '|' ||
            *pos == ':' ||
            *pos == '?' ||
            *pos == '.'
        )
    ) v += *pos++;
    if (pos == in) return {}; // zero match
    RULE_SUCCESSD(in, pos, Import_path, v);
};
Rule(Import_ext) {    
    auto pos = in;
    std::vector<::Parser::Rule> data;
    ISC_STD::skip_spaces(pos);
    while(true) {
        if (*pos == '.') {
            ++pos;
            ISC_STD::skip_spaces(pos);
            auto match_res = id(pos);
            if (match_res.result) {
                data.push_back(match_res.token);
                pos += match_res.token.length();
                continue;
            }
            --pos; // dot is skipped
        }
        break;
    }
    if (pos == in) return {}; // zero match
    RULE_SUCCESSD(in, pos, Import_ext, data);
};
Rule(Import_file) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto path_res = Import_path(pos);
    if (!path_res.result) return {};
    pos += path_res.token.length();
    ISC_STD::skip_spaces(pos);
    auto ext_res = Import_ext(pos);
    if (!ext_res.result) return {};
    pos += ext_res.token.length();
    // join
    std::string joined;
    for (auto obj : TO(std::vector<::Parser::Rule>, ext_res.token.data)) {
        joined += TO(std::string, obj.data);
    }
    std::unordered_map<const char*, std::any> data = {
        { "path", path_res },
        { "ext", TO(std::vector<Rule_result>, ext_res.token.data).back() },
        { "fullext", ext_res },
        { "fullpath", std::string( TO(std::string, path_res.token.data )) + joined }
    };
    RULE_SUCCESSD(in, pos, Import_file, data);
}
Rule(Import_general_dir) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (*pos != '[')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto path_res = Import_path(pos);
    if (!path_res.result) return {};
    pos += path_res.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos != ']')
        return {};
    
    auto _local_start = ++pos;
    std::vector<::Parser::Rule> files;
    while(true) {
        int v = ISC_STD::skip_spaces(pos);
        auto file_res = Import_file(pos);
        if (!file_res.result)
            pos -= v; //! to not include spaces into result token length
            break;
        pos += file_res.token.length();
        files.push_back(file_res.token);
    }
    if (pos == _local_start)
        return {}; // zero match
    std::unordered_map<const char*, std::any> data {
        { "path", path_res.token },
        { "files", files }
    };
    RULE_SUCCESSD(in, pos, Import_general_dir, files);
}
Rule(Import_rulespecific) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    auto file_res = Import_file(pos);
    if (!file_res.result)
        return {};
    pos += file_res.token.length();
    ISC_STD::skip_spaces(pos);
    if (*pos != '{')
        return {};
    pos++;
    ISC_STD::skip_spaces(pos);
    auto _local_start = pos;
    std::vector<::Parser::Rule> rules;
    std::vector<::Parser::Rule> rules_current_name;
    while (true) {
        ISC_STD::skip_spaces(pos);
        auto id_res = id(pos);
        if (!id_res.result)
            break;
        rules.push_back(id_res.token);
        pos += id_res.token.length();
        ISC_STD::skip_spaces(pos);
        if (*pos == '=') {
            ++pos;
            ISC_STD::skip_spaces(pos);
            auto id2_res = id(pos);
            if (!id2_res.result)
                break;
            rules_current_name.push_back(id2_res.token);
        }
    }
    if (_local_start == pos)
        return {}; // zero match
    std::unordered_map<const char*, std::any> data {
        { "path", file_res.token },
        { "tokens", rules },
        { "tokens_current_name", rules_current_name }
    };
    RULE_SUCCESSD(in, pos, Import_rulespecific, data);
}
Rule(Import) {
    auto pos = in;
    ISC_STD::skip_spaces(pos);
    if (strncmp(pos, "import", sizeof("import") - 1))
        return {};
    pos += sizeof("import") - 1;
    ISC_STD::skip_spaces(pos);
    auto first_rule_res = Import_file(pos);
    if (!first_rule_res.result) {
        first_rule_res = Import_general_dir(pos);
        if (!first_rule_res.result) {
            first_rule_res = Import_rulespecific(pos);
            if (!first_rule_res.result)
                return {};
        }
    }
    pos += first_rule_res.token.length();
    ISC_STD::skip_spaces(pos);
    std::vector<::Parser::Rule> additional_paths;
    while (*pos == ',') {
        ++pos;
        ISC_STD::skip_spaces(pos);
        auto result = Import_file(pos);
        if (!result.result) {
            result = Import_general_dir(pos);
            if (!result.result) {
                result = Import_rulespecific(pos);
                if (!result.result)
                    break;
            }
        }
        pos += result.token.length();
        additional_paths.push_back(result.token);
    }
    using obj_type = std::unordered_map<const char*, std::any>;
    std::vector<::Parser::Rule> data = {
        first_rule_res.token
    };
    // push remaining arguments inlining the array
    data.insert(data.end(), additional_paths.begin(), additional_paths.end());
    for (const auto obj : additional_paths) {
        data.push_back( obj );
    }
    RULE_SUCCESSD(in, pos, Import, data);
}
Rule(use) {
    auto pos = in;  // Start parsing from 'in'
    std::vector<::Parser::Rule> data;  // Use std::vector to store parsed data
    
    // Skip leading spaces
    ISC_STD::skip_spaces(pos);
    
    // Check if the input starts with "use"
    if (strncmp(pos, "use", 3) != 0) {
        printf("Exit 1\n");
        return {};  // Return empty result if "use" is not found
    }
    pos += 3;  // Move position past "use"
    ISC_STD::skip_spaces(pos);  // Skip spaces after "use"
    
    // Parse the first unit
    auto use_unit_res = use_unit(pos);
    if (!use_unit_res.result) {
        return {};
    }
    pos += use_unit_res.token.length();
    data.push_back(use_unit_res.token);
    
    ISC_STD::skip_spaces(pos);
    
    while (*pos == ',') {
        pos++; 
        ISC_STD::skip_spaces(pos);
        
        auto use_unit_res = use_unit(pos);
        if (!use_unit_res.result) {
            break;
        }
        pos += use_unit_res.token.length();
        data.push_back(use_unit_res.token);
        ISC_STD::skip_spaces(pos);
    }
    // Finalize the rule and return the result
    RULE_SUCCESSD(in, pos, use, data);
}
Rule(use_unit) {
    auto pos = in;
    auto id_res = id(pos);
    if (!id_res.result)
        return {};
    pos += id_res.token.length();
    ISC_STD::skip_spaces(pos);
    ::Parser::Rule dt;
    if (*pos == ':') {
        pos++;
        ISC_STD::skip_spaces(pos);
        auto res = any_data(pos);
        if (!res.result)
            return {};
        pos += res.token.length();
        dt = res.token;
    }
    std::unordered_map<const char*, std::any> data {
        { "name", id_res.token },
        { "value", dt }
    };
    printf("Returning use_unit...\n");
    RULE_SUCCESSD(in, pos, use_unit, data);
}
#undef Rule
#undef Token
size_t Parser::Parser::getCurrentPos(const char* pos) {
    return pos - text;
}
::Parser::Tree Parser::Parser::parse() {
    auto len = strlen(text);
    Tree tree;
    auto in = text;
    for (;*in;) {
        ISC_STD::skip_spaces(in);
        auto res = Import(in);
        if (!res.result) {
            res = use(in);
            if (!res.result) {
                res = Rule(in);
                if (!res.result) {
                    printf("Stopped at rule\n");
                    break;
                }
            }
        }
        std::cout << "Token length: " << res.token.length() << "\n";
        in += res.token.length();
        // match end
        ISC_STD::skip_spaces(in);
        auto end_res = end(in);
        if (!end_res.result) {
            printf("Unmatched end of rule\n");
            break;
        }
        in += end_res.token.length();
        tree.push_back(res.token);
        printf("Stopped at %ld\n", in - text);
    }
    return tree;
}