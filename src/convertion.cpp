#include <convertion.h>

class Converter {
    std::string value;
};
std::unordered_map<std::string, Converter> Rules;

void processRule(use_prop_t &use_prop, obj_t &data) {
    auto rules = std::any_cast<arr_t<Parser::Rule>>(corelib::map::get(data, "rule"));
    for (auto &rule : rules) {
        auto rule_d = std::any_cast<Parser::Rule>(corelib::map::get(std::any_cast<obj_t>(rule.data), "val"));
        auto qualifier = std::any_cast<Parser::Rule>(corelib::map::get(std::any_cast<obj_t>(rule.data), "qualifier"));

        switch (rule_d.name)
        {
        // case Parser::Rules:: :
        //     break;
        
        default:
            break;
        }
    }
}

std::string convert(Parser::Tree &tree) {
    std::string buf; // a buffer where the output will be storred
    // HERE WE ACCAMULATE PROPERTIES SET BY USE
    use_prop_t use_prop;
    for (const auto& member : tree) {
        if (member.name == Parser::Rules::use) {
            auto data = std::any_cast<arr_t<Parser::Rule>>(member.data);
            for (const auto& el : data) {
                auto el_data = std::any_cast<obj_t>(el.data);
                auto el_name = std::any_cast<Parser::Rule> (corelib::map::get(el_data, "name"));
                use_prop[std::any_cast<std::string> (el_name.data)] = std::any_cast<Parser::Rule> (corelib::map::get(el_data, "value"));
            }
        }
    }
    for (auto &member : tree) {
        switch (member.name) {
            case Parser::Rules::Rule:
                auto data = std::any_cast<obj_t>(member.data);
                auto name = std::any_cast<Parser::Rule>(corelib::map::get(data, "name"));
                auto name_str = std::any_cast<std::string>(name.data);
                Rules[name_str] = {};

                processRule(use_prop, data);
            break;
        }
    }
    return buf;
}