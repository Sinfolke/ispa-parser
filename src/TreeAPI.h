#include <vector>
#include <string>
#include <any>
#include <unordered_map>
#include <variant>
namespace TreeAPI {
    enum class Names {
        CllExpr,
        RulePrefix,
        RuleQuantifier,
        RuleName,
        RuleGroup,
        RuleMemberOp,
        RuleMemberCsequence,
        RuleAny,
        RuleNospace,
        RuleEscaped,
        hex,
        bin,
        RuleMember,
        RegularDataBlockWKeys,
        RegularDataBlock,
        TemplatedDataBlock,
        DataBlock,
        Rule
    };
    enum class RuleNames {
        RulePrefix,
        RuleQuantifier,
        RuleName,
        RuleGroup,
        RuleMemberOp,
        RuleMemberCsequence,
        RuleAny,
        RuleNospace,
        RuleEscaped,
        RuleMember,
        Rule
    };
    class CllExpr {};
    class RulePrefix {
        public:
            enum class Kind {
                keyvalue, value
            };
            RulePrefix(bool is_key_value, const std::string &name)
                : is_key_value(is_key_value), name(name) {}
            bool is_key_value;
            std::string name;
    };
    class RuleQuantifier {
        public:
            RuleQuantifier(const char quantifier) : quantifier(quantifier) {}
            char quantifier = '\0';
            bool empty() const {
                return quantifier == '\0';
            }
    };
    class RuleMemberName {
        public:
            RuleMemberName(const std::vector<std::string> &name) : name(name) {}
            RuleMemberName(std::vector<std::string> &&name) : name(std::move(name)) {}
            std::vector<std::string> name;
    };
    class RuleMemberGroup {
        public:
            RuleMemberGroup(const std::vector<RuleMember> values) : values(values) {}
            RuleMemberGroup(std::vector<RuleMember> &&values) : values(std::move(values)) {}
            std::vector<RuleMember> values;
    };
    class RuleMemberOp {
        public:
            RuleMemberOp(const std::vector<RuleMember> &options) : options(options) {}
            RuleMemberOp(const std::vector<RuleMember> &&options) : options(std::move(options)) {}
            std::vector<RuleMember> options;
    };
    class RuleMemberCsequence {
        public:
            RuleMemberCsequence(const std::vector<char> &characters, const std::vector<char> &escaped, const std::vector<std::pair<char, char>> &diapasons)
                : characters(characters), escaped(escaped), diapasons(diapasons) {}
            RuleMemberCsequence(const std::vector<char> &&characters, const std::vector<char> &&escaped, const std::vector<std::pair<char, char>> &&diapasons)
                : characters(std::move(characters)), escaped(std::move(escaped)), diapasons(std::move(diapasons)) {}
            std::vector<char> characters;
            std::vector<char> escaped;
            std::vector<std::pair<char, char>> diapasons;
        
    };
    class RuleMemberAny {};
    class RuleMemberNospace {};
    class RuleMemberEscaped {
        public:
            RuleMemberEscaped(char c) : c(c) {}
            char c;
    };
    class RuleMemberHex {
        public:
            RuleMemberHex(const std::string &hex_chars) : hex_chars(hex_chars) {}
            RuleMemberHex(const std::string &&hex_chars) : hex_chars(std::move(hex_chars)) {}
            std::string hex_chars;
            auto begin() {
                return hex_chars.begin();
            }
            auto end() {
                return hex_chars.end();
            }
    };
    class RuleMemberBin {
        public:
            RuleMemberBin(const std::vector<int> &bin_chars) : bin_chars(bin_chars) {}
            RuleMemberBin(const std::vector<int> &&bin_chars) : bin_chars(std::move(bin_chars)) {}
            std::vector<int> bin_chars;
            auto begin() {
                return bin_chars.begin();
            }
            auto end() {
                return bin_chars.end();
            }
    };
    class RuleMember {
        public:
            RulePrefix prefix;
            RuleQuantifier quantifier;
            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberName &name) : prefix(prefix), quantifier(quantifier), value(name) {}
            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberName &&name) : prefix(prefix), quantifier(quantifier), value(std::move(name)) {}
            
            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberGroup &group) : prefix(prefix), quantifier(quantifier), value(group) {}
            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberGroup &&group) : prefix(prefix), quantifier(quantifier), value(std::move(group)) {}

            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberOp &op) : prefix(prefix), quantifier(quantifier), value(op) {}
            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberOp &&op) : prefix(prefix), quantifier(quantifier), value(std::move(op)) {}

            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberCsequence &csequence) : prefix(prefix), quantifier(quantifier), value(csequence) {}
            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberCsequence &&csequence) : prefix(prefix), quantifier(quantifier), value(std::move(csequence)) {}

            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberAny &any) : prefix(prefix), quantifier(quantifier), value(any) {}
            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberAny &&any) : prefix(prefix), quantifier(quantifier), value(std::move(any)) {}

            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberNospace &no_space) : prefix(prefix), quantifier(quantifier), value(no_space) {}
            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberNospace &&no_space) : prefix(prefix), quantifier(quantifier), value(std::move(no_space)) {}

            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberEscaped &escaped) : prefix(prefix), quantifier(quantifier), value(escaped) {}
            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberEscaped &&escaped) : prefix(prefix), quantifier(quantifier), value(std::move(escaped)) {}

            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberHex &hex) : prefix(prefix), quantifier(quantifier), value(hex) {}
            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberHex &&hex) : prefix(prefix), quantifier(quantifier), value(std::move(hex)) {}
            
            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberBin &bin) : prefix(prefix), quantifier(quantifier), value(bin) {}
            RuleMember(RulePrefix &prefix, RuleQuantifier& quantifier, RuleMemberBin &&bin) : prefix(prefix), quantifier(quantifier), value(std::move(bin)) {}
            std::variant<RuleMemberName, RuleMemberGroup, RuleMemberOp, RuleMemberCsequence, RuleMemberAny, RuleMemberNospace, RuleMemberEscaped, RuleMemberHex, RuleMemberBin> value;

            bool isName() const {
                return std::holds_alternative<RuleMemberName>(value);
            }
            bool isGroup() const {
                return std::holds_alternative<RuleMemberGroup>(value);
            }
            bool isOp() const {
                return std::holds_alternative<RuleMemberOp>(value);
            }
            bool isCsequence() const {
                return std::holds_alternative<RuleMemberCsequence>(value);
            }
            bool isAny() const {
                return std::holds_alternative<RuleMemberAny>(value);
            }
            bool isNospace() const {
                return std::holds_alternative<RuleMemberNospace>(value);
            }
            bool isEscaped() const {
                return std::holds_alternative<RuleMemberEscaped>(value);
            }
            bool isHex() const {
                return std::holds_alternative<RuleMemberHex>(value);
            }
            bool isBin() const {
                return std::holds_alternative<RuleMemberBin>(value);
            }
            decltype(RuleMemberName::name)& getName() const {
                return std::get<RuleMemberName&>(value).name;
            }
            decltype(RuleMemberGroup::values)& getGroup() const {
                return std::get<RuleMemberGroup&>(value).values;
            }
            decltype(RuleMemberOp::options)& getOp() const {
                return std::get<RuleMemberOp&>(value).options;
            }
            RuleMemberCsequence& getCsequence() const {
                return std::get<RuleMemberCsequence&>(value);
            }
            decltype(RuleMemberEscaped::c)& getEscaped() const {
                return std::get<RuleMemberEscaped&>(value).c;
            }
            RuleMemberHex& getHex() const {
                return std::get<RuleMemberHex&>(value);
            }
            RuleMemberBin& getBin() const {
                return std::get<RuleMemberBin&>(value);
            }
    }; 
    class RegularDataBlockWKeys {
        public:
        std::unordered_map<std::string, CllExpr> value;

        bool empty() const {
            return value.empty();
        }
        auto begin() {
            return value.begin();
        }
        auto end() {
            return value.end();
        }
        CllExpr& operator[](const std::string &name) {
            return value[name];
        }
    };
    using RegularDataBlock = CllExpr;
    class TemplatedDataBlock {
        std::vector<std::string> names;

        auto empty() const {
            return names.empty();
        }
        auto begin() {
            return names.begin();
        }
        auto end() {
            return names.end();
        }
    };
    class DataBlock {
        std::variant<RegularDataBlock, RegularDataBlockWKeys, TemplatedDataBlock> value;
        public:
            bool isRegularDataBlock() {
                return std::holds_alternative<RegularDataBlock>(value) || std::holds_alternative<RegularDataBlockWKeys>(value);
            }
            bool isWithKeys() {
                return std::holds_alternative<RegularDataBlockWKeys>(value);
            }
            bool isTemplatedDataBlock() {
                return std::holds_alternative<TemplatedDataBlock>(value);
            }
            RegularDataBlock& getRegDataBlock() {
                return std::get<RegularDataBlock&>(value);
            }
            RegularDataBlockWKeys& getRegDataBlockWKeys() {
                return std::get<RegularDataBlockWKeys&>(value);
            }
            TemplatedDataBlock& getTemplatedDataBlock() {
                return std::get<TemplatedDataBlock&>(value);
            }
    };
    class Rule {
        public:
            Rule(const std::vector<std::string> &name, const std::vector<TreeAPI::RuleMember> &members, const TreeAPI::DataBlock &data_block)
                : name(name), members(members), data_block(data_block) {}
            Rule(std::vector<std::string> &&name, std::vector<TreeAPI::RuleMember> &&members, TreeAPI::DataBlock &&data_block)
                : name(std::move(name)), members(std::move(members)), data_block(std::move(data_block)) {}
            std::vector<std::string> name;
            std::vector<TreeAPI::RuleMember> members;
            TreeAPI::DataBlock data_block;
    };
};