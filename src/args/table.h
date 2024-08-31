#include <unordered_map>
#include <variant>
#include <string>
#include <optional>
#include "argf.h"
namespace arg {
    using resfunc = const char*(*)(const std::string strval);
    struct value {
        resfunc processfun;
        std::string val;
    };
    std::unordered_map<const char*, value> table {
        { "o", argf::storev },
        { "lang",  argf::lang }
    };

    std::string fetch(const char* name) {
        for (auto [key, val] : table) {
            if (key == name) return val;
        }
        return NULL;
    }
    const char* parse(const char* str) {}

}