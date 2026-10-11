#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <vector>
#include <unordered_map>
#include <array>
#include <string>
#include <variant>
#include <optional>
#include <memory>
#include <ispastdlib.hpp>
namespace Parser {
	enum class Tokens {
		NONE,
		AUTO_5,
		AUTO_4,
		AUTO_2,
		AUTO_1,
		AUTO_3,
		rule_value_STRING,
		__WS,
		rule_value_SPACE,
		NUMBER,
		AUTO_0,
		rule_value_QUANTIFIER,
		ID,
	};
	enum class Rules {
		NONE,
		main,
		rule_value_alternative,
		rule_value_pattern,
		rule_value_group,
		rule_value,
		rule_capture,
		rule,
	};
	namespace FlatTypes {
		struct AUTO_5;
		struct AUTO_4;
		struct AUTO_2;
		struct AUTO_1;
		struct AUTO_3;
		struct rule_value_STRING;
		struct rule;
		struct rule_value;
		struct __WS;
		struct rule_value_SPACE;
		struct NUMBER;
		struct AUTO_0;
		struct rule_value_QUANTIFIER;
		struct ID;
		struct main;
		struct rule_value_alternative;
		struct rule_value_pattern;
		struct rule_value_group;
		struct rule_capture;
	}
	namespace FlatTypes {
		struct AUTO_5 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const AUTO_5 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct AUTO_4 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const AUTO_4 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct AUTO_2 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const AUTO_2 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct AUTO_1 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const AUTO_1 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct AUTO_3 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const AUTO_3 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_STRING {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_STRING &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct __WS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const __WS &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_SPACE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_SPACE &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct NUMBER {
			std::string full;
			std::string floating;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const NUMBER &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct AUTO_0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const AUTO_0 &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_QUANTIFIER {
			char value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_QUANTIFIER &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct ID {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const ID &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_alternative {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value_pattern>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_alternative &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_group {
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value>>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_group &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value {
			::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value_pattern>> v;
			std::vector<::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value_alternative>>> alts;
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_QUANTIFIER> quantifier;
			using STRING = ::Parser::FlatTypes::rule_value_STRING;
			using SPACE = ::Parser::FlatTypes::rule_value_SPACE;
			using QUANTIFIER = ::Parser::FlatTypes::rule_value_QUANTIFIER;
			using alternative = ::Parser::FlatTypes::rule_value_alternative;
			using pattern = ::Parser::FlatTypes::rule_value_pattern;
			using group = ::Parser::FlatTypes::rule_value_group;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_value_pattern {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, std::shared_ptr<::Parser::FlatTypes::rule_value_group>>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_SPACE>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::rule_value_STRING>, ::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_value_pattern &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule_capture {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule_capture &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct rule {
			::ISPA_STD::Node<::Parser::Tokens, ::Parser::FlatTypes::ID> name;
			std::vector<::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule_value>> v;
			using value = ::Parser::FlatTypes::rule_value;
			using capture = ::Parser::FlatTypes::rule_capture;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const rule &value) -> std::ostream&;
	}
	namespace FlatTypes {
		struct main {
			::ISPA_STD::Node<::Parser::Rules, ::Parser::FlatTypes::rule> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
		auto operator<<(std::ostream &os, const main &value) -> std::ostream&;
	}
	namespace Types {
		using AUTO_5 = ::Parser::FlatTypes::AUTO_5;
		using AUTO_4 = ::Parser::FlatTypes::AUTO_4;
		using AUTO_2 = ::Parser::FlatTypes::AUTO_2;
		using AUTO_1 = ::Parser::FlatTypes::AUTO_1;
		using AUTO_3 = ::Parser::FlatTypes::AUTO_3;
		using rule = ::Parser::FlatTypes::rule;
		using __WS = ::Parser::FlatTypes::__WS;
		using NUMBER = ::Parser::FlatTypes::NUMBER;
		using AUTO_0 = ::Parser::FlatTypes::AUTO_0;
		using ID = ::Parser::FlatTypes::ID;
		using main = ::Parser::FlatTypes::main;
	}
	using Token = std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_5>, ::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_4>, ::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_2>, ::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_1>, ::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_3>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING>, ::ISPA_STD::Node<::Parser::Tokens, Types::__WS>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE>, ::ISPA_STD::Node<::Parser::Tokens, Types::NUMBER>, ::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_0>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>>;
	class Lexer : public ::ISPA_STD::Lexer_base<::Parser::Tokens, Token> {
		static ::ISPA_STD::DFA::API::CharToClass char_class_table;
		static ::ISPA_STD::DFA::API::Table<21, 129> dfa_table;
		static ::ISPA_STD::DFA::API::Table<211, 4> action_table;
		static auto semantic_action_exec(long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token>;
		bool init_done;
		auto init() -> void override;
		::ISPA_STD::DFA::API::TdfaLayout<14, 14> tdfa_registers;
		static std::array<::ISPA_STD::DFA::API::DFADebug, 226> debug_array;
		static std::unordered_map<long long, std::unordered_map<long long, long long>> debug_index;
	public: 
		auto makeToken(const char*& pos) -> Token override;
	};
	class Parser : public ::ISPA_STD::LLParser_base<::Parser::Tokens, ::Parser::Rules, Types::main, Token> {
		template<typename IT>
		auto main(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::main, IT>{
			::ISPA_STD::MatchResult<Rules, Types::rule, IT> rule_0;
			bool success_1;
			success_1 = false;
			rule_0 = rule(pos);
			if (!(rule_0.status)) {
				return {};
			}
			success_1 = true;
			pos = rule_0.it;
			Types::main result;
			::ISPA_STD::assign_compatible(result.value, rule_0.node);
			::ISPA_STD::MatchResult<Rules, Types::main, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto rule_value_alternative(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::alternative, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_0> AUTO_0_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, IT> rule_value_pattern_4;
			bool success_5;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_0>>((*pos)))) {
				return {};
			}
			AUTO_0_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_0>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			rule_value_pattern_4 = rule_value_pattern(pos);
			if (!(rule_value_pattern_4.status)) {
				return {};
			}
			success_5 = true;
			pos = rule_value_pattern_4.it;
			Types::rule::value::alternative result;
			::ISPA_STD::assign_compatible(result.value, rule_value_pattern_4.node);
			::ISPA_STD::MatchResult<Rules, Types::rule::value::alternative, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto rule_value_pattern(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, IT>{
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::Rules, Types::rule::value::group>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE>, ::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING>, ::ISPA_STD::Node<::Parser::Tokens, Types::ID>> _0;
			bool success_1;
			success_1 = false;
			// grammar `@  ( ID |  rule::value::STRING |  rule::value::SPACE |  rule::value::group)`: choice; reset match status before selecting an alternative
			success_1 = false;
			switch (static_cast<Tokens>((*pos).index())) {
				case Tokens::AUTO_1: {
					::ISPA_STD::MatchResult<Rules, Types::rule::value::group, IT> rule_value_group_2;
					bool success_3 = false;
					rule_value_group_2 = rule_value_group(pos);
					if (!(rule_value_group_2.status)) {
						return {};
					}
					success_3 = true;
					pos = rule_value_group_2.it;
					if (!success_3) {
						return {};
					}
					_0 = rule_value_group_2.node;
					success_1 = true;
					break;
				}
				case Tokens::ID: {
					::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_4;
					bool success_5 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos)))) {
						return {};
					}
					ID_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
					success_5 = true;
					pos++;
					if (!success_5) {
						return {};
					}
					_0 = ID_4;
					success_1 = true;
					break;
				}
				case Tokens::rule_value_SPACE: {
					::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE> rule_value_SPACE_6;
					bool success_7 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE>>((*pos)))) {
						return {};
					}
					rule_value_SPACE_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::SPACE>>((*pos));
					success_7 = true;
					pos++;
					if (!success_7) {
						return {};
					}
					_0 = rule_value_SPACE_6;
					success_1 = true;
					break;
				}
				case Tokens::rule_value_STRING: {
					::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING> rule_value_STRING_8;
					bool success_9 = false;
					if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING>>((*pos)))) {
						return {};
					}
					rule_value_STRING_8 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::STRING>>((*pos));
					success_9 = true;
					pos++;
					if (!success_9) {
						return {};
					}
					_0 = rule_value_STRING_8;
					success_1 = true;
					break;
				}
			}
			if (!success_1) {
				return {};
			}
			Types::rule::value::pattern result;
			::ISPA_STD::assign_compatible(result.value, _0);
			::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto rule_value_group(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value::group, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_1> AUTO_1_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::rule::value, IT> rule_value_5;
			bool success_6;
			::ISPA_STD::Node<::Parser::Rules, Types::rule::value> element_7;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value>> shadow_8;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value>> uvar_4;
			bool success_9;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_10;
			bool success_11;
			::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_2> AUTO_2_12;
			bool success_13;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_1>>((*pos)))) {
				return {};
			}
			AUTO_1_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_1>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_6 = false;
			// grammar `@  rule::value+;`: repeat named rule; collect every matched value
			success_9 = false;
			while (true) {
				rule_value_5 = rule_value(pos);
				if (!(rule_value_5.status)) {
					break;
				}
				success_6 = true;
				pos = rule_value_5.it;
				element_7 = rule_value_5.node;
				shadow_8.push_back(element_7);
				success_9 = true;
			}
			if (!success_9) {
				return {};
			}
			::ISPA_STD::assign_compatible(uvar_4, shadow_8);
			success_11 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_10 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_11 = true;
				pos++;
			}
			success_13 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_2>>((*pos)))) {
				return {};
			}
			AUTO_2_12 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_2>>((*pos));
			success_13 = true;
			pos++;
			Types::rule::value::group result;
			::ISPA_STD::assign_compatible(result.value, uvar_4);
			::ISPA_STD::MatchResult<Rules, Types::rule::value::group, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto rule_value(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::value, IT>{
			::ISPA_STD::MatchResult<Rules, Types::rule::value::pattern, IT> rule_value_pattern_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::MatchResult<Rules, Types::rule::value::alternative, IT> rule_value_alternative_5;
			bool success_6;
			::ISPA_STD::Node<::Parser::Rules, Types::rule::value::alternative> element_7;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value::alternative>> shadow_8;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value::alternative>> uvar_4;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_9;
			bool success_10;
			::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER> rule_value_QUANTIFIER_11;
			bool success_12;
			success_1 = false;
			rule_value_pattern_0 = rule_value_pattern(pos);
			if (!(rule_value_pattern_0.status)) {
				return {};
			}
			success_1 = true;
			pos = rule_value_pattern_0.it;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_6 = false;
			// grammar `@  rule::value::alternative*;`: repeat named rule; collect every matched value
			while (true) {
				rule_value_alternative_5 = rule_value_alternative(pos);
				if (!(rule_value_alternative_5.status)) {
					break;
				}
				success_6 = true;
				pos = rule_value_alternative_5.it;
				element_7 = rule_value_alternative_5.node;
				shadow_8.push_back(element_7);
			}
			::ISPA_STD::assign_compatible(uvar_4, shadow_8);
			success_10 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_9 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_10 = true;
				pos++;
			}
			success_12 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER>>((*pos))) {
				rule_value_QUANTIFIER_11 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::rule::value::QUANTIFIER>>((*pos));
				success_12 = true;
				pos++;
			}
			Types::rule::value result;
			::ISPA_STD::assign_compatible(result.v, rule_value_pattern_0);
			::ISPA_STD::assign_compatible(result.alts, uvar_4);
			::ISPA_STD::assign_compatible(result.quantifier, rule_value_QUANTIFIER_11);
			::ISPA_STD::MatchResult<Rules, Types::rule::value, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto rule_capture(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule::capture, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_3> AUTO_3_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			bool success_8;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> group_4;
			bool success_6;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> uvar_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_7;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_3>>((*pos)))) {
				return {};
			}
			AUTO_3_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_3>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_6 = false;
			auto begin_9 = pos;
			// grammar ` (@  ID)?;`: optional group; try at most once
			while (false) {
				// grammar ` (@  ID)?;`: optional body; failed alternative leaves this group
				if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*begin_9)))) {
					break;
				}
				ID_7 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*begin_9));
				success_8 = true;
				begin_9++;
			}
			if (success_8) {
				group_4 = ID_7;
				success_6 = true;
				::ISPA_STD::assign_compatible(uvar_5, group_4);
			}
			// grammar ` (@  ID)?;`: optional group end; release saved position
			pos = begin_9;
			Types::rule::capture result;
			::ISPA_STD::assign_compatible(result.value, ID_7);
			::ISPA_STD::MatchResult<Rules, Types::rule::capture, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
		template<typename IT>
		auto rule(IT pos) -> ::ISPA_STD::MatchResult<Rules, Types::rule, IT>{
			::ISPA_STD::Node<::Parser::Tokens, Types::ID> ID_0;
			bool success_1;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_2;
			bool success_3;
			::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_4> AUTO_4_4;
			bool success_5;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_6;
			bool success_7;
			::ISPA_STD::MatchResult<Rules, Types::rule::value, IT> rule_value_9;
			bool success_10;
			::ISPA_STD::Node<::Parser::Rules, Types::rule::value> element_11;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value>> shadow_12;
			std::vector<::ISPA_STD::Node<::Parser::Rules, Types::rule::value>> uvar_8;
			bool success_13;
			::ISPA_STD::Node<::Parser::Tokens, Types::__WS> __WS_14;
			bool success_15;
			::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_5> AUTO_5_16;
			bool success_17;
			success_1 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos)))) {
				return {};
			}
			ID_0 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::ID>>((*pos));
			success_1 = true;
			pos++;
			success_3 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_2 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_3 = true;
				pos++;
			}
			success_5 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_4>>((*pos)))) {
				return {};
			}
			AUTO_4_4 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_4>>((*pos));
			success_5 = true;
			pos++;
			success_7 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_6 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_7 = true;
				pos++;
			}
			success_10 = false;
			// grammar `@  rule::value+;`: repeat named rule; collect every matched value
			success_13 = false;
			while (true) {
				rule_value_9 = rule_value(pos);
				if (!(rule_value_9.status)) {
					break;
				}
				success_10 = true;
				pos = rule_value_9.it;
				element_11 = rule_value_9.node;
				shadow_12.push_back(element_11);
				success_13 = true;
			}
			if (!success_13) {
				return {};
			}
			::ISPA_STD::assign_compatible(uvar_8, shadow_12);
			success_15 = false;
			if (std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos))) {
				__WS_14 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::__WS>>((*pos));
				success_15 = true;
				pos++;
			}
			success_17 = false;
			if (!(std::holds_alternative<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_5>>((*pos)))) {
				return {};
			}
			AUTO_5_16 = std::get<::ISPA_STD::Node<::Parser::Tokens, Types::AUTO_5>>((*pos));
			success_17 = true;
			pos++;
			Types::rule result;
			::ISPA_STD::assign_compatible(result.name, ID_0);
			::ISPA_STD::assign_compatible(result.v, uvar_8);
			::ISPA_STD::MatchResult<Rules, Types::rule, IT> match_result;
			match_result.status = true;
			match_result.node.set_data(result);
			match_result.it = pos;
			return match_result;
		}
	public: 
		auto parseFromTokens() -> void override;
		auto lazyParse() -> void override;
	};
}
#endif // PARSER_H
