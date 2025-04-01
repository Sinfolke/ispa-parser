#include <any>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using obj_t = std::unordered_map<const char*, std::any>;
template<typename T>
using arr_t = std::vector<T>;
using use_prop_t = std::unordered_map<std::string, Parser::Rule>;
using rule_other = std::pair<std::string, arr_t<std::string>>;
using use_place_t_part = std::pair<std::vector<std::string>, std::vector<std::vector<std::string>>>;
using use_place_t = std::vector<use_place_t_part>;