#include <any>
#include <string>
#include <vector>
#include <unordered_map>

using obj_t = std::unordered_map<const char*, std::any>;
template<typename T>
using arr_t = std::vector<T>;
using use_prop_t = std::unordered_map<std::string, Parser::Rule>;