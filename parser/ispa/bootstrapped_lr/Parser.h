#pragma once

#include <ispastdlib/variant_io.hpp>
#include <ispastdlib/lr_conflicts.hpp>

namespace Parser {
	namespace Tokens {
		namespace AMPERSAND {
			inline const std::size_t id = 7;
		} // namespace AMPERSAND
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace AUTO {
			inline const std::size_t id = 2;
		} // namespace AUTO
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace COLON {
			inline const std::size_t id = 5;
		} // namespace COLON
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace COMMA {
			inline const std::size_t id = 26;
		} // namespace COMMA
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace COMMERCIAL_AT {
			inline const std::size_t id = 12;
		} // namespace COMMERCIAL_AT
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace EQUALS_SIGN {
			inline const std::size_t id = 6;
		} // namespace EQUALS_SIGN
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace FAIL {
			inline const std::size_t id = 3;
		} // namespace FAIL
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace ID {
			inline const std::size_t id = 32;
		} // namespace ID
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace LEFT_CURLY_BRACKET {
			inline const std::size_t id = 10;
		} // namespace LEFT_CURLY_BRACKET
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace LEFT_PARENTHESIS {
			inline const std::size_t id = 28;
		} // namespace LEFT_PARENTHESIS
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace NUMBER {
			inline const std::size_t id = 30;
		} // namespace NUMBER
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace PERCENT_SIGN {
			inline const std::size_t id = 8;
		} // namespace PERCENT_SIGN
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace PY_RAW {
			inline const std::size_t id = 31;
		} // namespace PY_RAW
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace RIGHT_CURLY_BRACKET {
			inline const std::size_t id = 29;
		} // namespace RIGHT_CURLY_BRACKET
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace RIGHT_PARENTHESIS {
			inline const std::size_t id = 27;
		} // namespace RIGHT_PARENTHESIS
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace SEMICOLON {
			inline const std::size_t id = 4;
		} // namespace SEMICOLON
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace __WS {
			inline const std::size_t id = 0;
		} // namespace __WS
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace advanced_rule {
			inline const std::size_t id = 34;
		} // namespace advanced_rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace advanced_rule {
			namespace dep_decl {
				inline const std::size_t id = 35;
			} // namespace dep_decl
		} // namespace advanced_rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace advanced_rule {
			namespace dep_decl {
				namespace DEPENDS {
					inline const std::size_t id = 1;
				} // namespace DEPENDS
			} // namespace dep_decl
		} // namespace advanced_rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace advanced_rule {
			namespace regular_match {
				inline const std::size_t id = 36;
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace advanced_rule {
			namespace regular_match {
				namespace MATCH {
					inline const std::size_t id = 25;
				} // namespace MATCH
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace grammar {
			inline const std::size_t id = 37;
		} // namespace grammar
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace grammar {
			namespace modifier {
				inline const std::size_t id = 38;
			} // namespace modifier
		} // namespace grammar
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace grammar {
			namespace modifier {
				namespace AUTO {
					inline const std::size_t id = 18;
				} // namespace AUTO
			} // namespace modifier
		} // namespace grammar
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace grammar {
			namespace modifier {
				namespace MOD {
					inline const std::size_t id = 19;
				} // namespace MOD
			} // namespace modifier
		} // namespace grammar
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace grammar {
			namespace modifier {
				namespace RIGHT_SQUARE_BRACKET {
					inline const std::size_t id = 23;
				} // namespace RIGHT_SQUARE_BRACKET
			} // namespace modifier
		} // namespace grammar
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			inline const std::size_t id = 39;
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace nested_rule {
				inline const std::size_t id = 40;
			} // namespace nested_rule
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace nested_rule {
				namespace NUMBER_SIGN {
					inline const std::size_t id = 9;
				} // namespace NUMBER_SIGN
			} // namespace nested_rule
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				inline const std::size_t id = 41;
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				namespace ANY {
					inline const std::size_t id = 15;
				} // namespace ANY
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				namespace CGROUP {
					inline const std::size_t id = 33;
				} // namespace CGROUP
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				namespace NOSPACE {
					inline const std::size_t id = 14;
				} // namespace NOSPACE
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				namespace QUANTIFIER {
					inline const std::size_t id = 13;
				} // namespace QUANTIFIER
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				namespace SPACE {
					inline const std::size_t id = 20;
				} // namespace SPACE
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				namespace STRING {
					inline const std::size_t id = 17;
				} // namespace STRING
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				namespace alternative {
					inline const std::size_t id = 42;
				} // namespace alternative
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				namespace alternative {
					namespace VERTICAL_LINE {
						inline const std::size_t id = 22;
					} // namespace VERTICAL_LINE
				} // namespace alternative
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				namespace dyn {
					inline const std::size_t id = 43;
				} // namespace dyn
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				namespace dyn {
					namespace DOLLAR_SIGN {
						inline const std::size_t id = 24;
					} // namespace DOLLAR_SIGN
				} // namespace dyn
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				namespace shared_counter_registration {
					inline const std::size_t id = 44;
				} // namespace shared_counter_registration
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace rule {
			namespace value {
				namespace shared_counter_registration {
					namespace AUTO {
						inline const std::size_t id = 11;
					} // namespace AUTO
				} // namespace shared_counter_registration
			} // namespace value
		} // namespace rule
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace template_params {
			inline const std::size_t id = 45;
		} // namespace template_params
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace template_params {
			namespace GREATER_THAN_SIGN {
				inline const std::size_t id = 21;
			} // namespace GREATER_THAN_SIGN
		} // namespace template_params
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace Tokens {
		namespace template_params {
			namespace LESS_THAN_SIGN {
				inline const std::size_t id = 16;
			} // namespace LESS_THAN_SIGN
		} // namespace template_params
	} // namespace Tokens
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace AMPERSAND {
			inline const char* const id = "AMPERSAND";
		} // namespace AMPERSAND
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace AUTO {
			inline const char* const id = "AUTO";
		} // namespace AUTO
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace COLON {
			inline const char* const id = "COLON";
		} // namespace COLON
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace COMMA {
			inline const char* const id = "COMMA";
		} // namespace COMMA
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace COMMERCIAL_AT {
			inline const char* const id = "COMMERCIAL_AT";
		} // namespace COMMERCIAL_AT
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace EQUALS_SIGN {
			inline const char* const id = "EQUALS_SIGN";
		} // namespace EQUALS_SIGN
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace FAIL {
			inline const char* const id = "FAIL";
		} // namespace FAIL
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace ID {
			inline const char* const id = "ID";
		} // namespace ID
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace LEFT_CURLY_BRACKET {
			inline const char* const id = "LEFT_CURLY_BRACKET";
		} // namespace LEFT_CURLY_BRACKET
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace LEFT_PARENTHESIS {
			inline const char* const id = "LEFT_PARENTHESIS";
		} // namespace LEFT_PARENTHESIS
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace NUMBER {
			inline const char* const id = "NUMBER";
		} // namespace NUMBER
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace PERCENT_SIGN {
			inline const char* const id = "PERCENT_SIGN";
		} // namespace PERCENT_SIGN
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace PY_RAW {
			inline const char* const id = "PY_RAW";
		} // namespace PY_RAW
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace RIGHT_CURLY_BRACKET {
			inline const char* const id = "RIGHT_CURLY_BRACKET";
		} // namespace RIGHT_CURLY_BRACKET
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace RIGHT_PARENTHESIS {
			inline const char* const id = "RIGHT_PARENTHESIS";
		} // namespace RIGHT_PARENTHESIS
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace SEMICOLON {
			inline const char* const id = "SEMICOLON";
		} // namespace SEMICOLON
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace __WS {
			inline const char* const id = "__WS";
		} // namespace __WS
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace advanced_rule {
			inline const char* const id = "advanced_rule";
		} // namespace advanced_rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace advanced_rule {
			namespace dep_decl {
				inline const char* const id = "advanced_rule.dep_decl";
			} // namespace dep_decl
		} // namespace advanced_rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace advanced_rule {
			namespace dep_decl {
				namespace DEPENDS {
					inline const char* const id = "advanced_rule.dep_decl.DEPENDS";
				} // namespace DEPENDS
			} // namespace dep_decl
		} // namespace advanced_rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace advanced_rule {
			namespace regular_match {
				inline const char* const id = "advanced_rule.regular_match";
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace advanced_rule {
			namespace regular_match {
				namespace MATCH {
					inline const char* const id = "advanced_rule.regular_match.MATCH";
				} // namespace MATCH
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace grammar {
			inline const char* const id = "grammar";
		} // namespace grammar
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace grammar {
			namespace modifier {
				inline const char* const id = "grammar.modifier";
			} // namespace modifier
		} // namespace grammar
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace grammar {
			namespace modifier {
				namespace AUTO {
					inline const char* const id = "grammar.modifier.AUTO";
				} // namespace AUTO
			} // namespace modifier
		} // namespace grammar
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace grammar {
			namespace modifier {
				namespace MOD {
					inline const char* const id = "grammar.modifier.MOD";
				} // namespace MOD
			} // namespace modifier
		} // namespace grammar
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace grammar {
			namespace modifier {
				namespace RIGHT_SQUARE_BRACKET {
					inline const char* const id = "grammar.modifier.RIGHT_SQUARE_BRACKET";
				} // namespace RIGHT_SQUARE_BRACKET
			} // namespace modifier
		} // namespace grammar
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			inline const char* const id = "rule";
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace nested_rule {
				inline const char* const id = "rule.nested_rule";
			} // namespace nested_rule
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace nested_rule {
				namespace NUMBER_SIGN {
					inline const char* const id = "rule.nested_rule.NUMBER_SIGN";
				} // namespace NUMBER_SIGN
			} // namespace nested_rule
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				inline const char* const id = "rule.value";
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				namespace ANY {
					inline const char* const id = "rule.value.ANY";
				} // namespace ANY
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				namespace CGROUP {
					inline const char* const id = "rule.value.CGROUP";
				} // namespace CGROUP
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				namespace NOSPACE {
					inline const char* const id = "rule.value.NOSPACE";
				} // namespace NOSPACE
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				namespace QUANTIFIER {
					inline const char* const id = "rule.value.QUANTIFIER";
				} // namespace QUANTIFIER
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				namespace SPACE {
					inline const char* const id = "rule.value.SPACE";
				} // namespace SPACE
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				namespace STRING {
					inline const char* const id = "rule.value.STRING";
				} // namespace STRING
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				namespace alternative {
					inline const char* const id = "rule.value.alternative";
				} // namespace alternative
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				namespace alternative {
					namespace VERTICAL_LINE {
						inline const char* const id = "rule.value.alternative.VERTICAL_LINE";
					} // namespace VERTICAL_LINE
				} // namespace alternative
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				namespace dyn {
					inline const char* const id = "rule.value.dyn";
				} // namespace dyn
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				namespace dyn {
					namespace DOLLAR_SIGN {
						inline const char* const id = "rule.value.dyn.DOLLAR_SIGN";
					} // namespace DOLLAR_SIGN
				} // namespace dyn
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				namespace shared_counter_registration {
					inline const char* const id = "rule.value.shared_counter_registration";
				} // namespace shared_counter_registration
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace rule {
			namespace value {
				namespace shared_counter_registration {
					namespace AUTO {
						inline const char* const id = "rule.value.shared_counter_registration.AUTO";
					} // namespace AUTO
				} // namespace shared_counter_registration
			} // namespace value
		} // namespace rule
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace template_params {
			inline const char* const id = "template_params";
		} // namespace template_params
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace template_params {
			namespace GREATER_THAN_SIGN {
				inline const char* const id = "template_params.GREATER_THAN_SIGN";
			} // namespace GREATER_THAN_SIGN
		} // namespace template_params
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace TokenNames {
		namespace template_params {
			namespace LESS_THAN_SIGN {
				inline const char* const id = "template_params.LESS_THAN_SIGN";
			} // namespace LESS_THAN_SIGN
		} // namespace template_params
	} // namespace TokenNames
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			inline const std::size_t id = 0;
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace __grp4 {
				inline const std::size_t id = 1;
			} // namespace __grp4
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace __grp4 {
				namespace __rop0 {
					inline const std::size_t id = 2;
				} // namespace __rop0
			} // namespace __grp4
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace __grp4 {
				namespace __tail {
					inline const std::size_t id = 3;
				} // namespace __tail
			} // namespace __grp4
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace __q2 {
				inline const std::size_t id = 4;
			} // namespace __q2
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace __q2 {
				namespace __tail {
					inline const std::size_t id = 5;
				} // namespace __tail
			} // namespace __q2
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace dep_decl {
				inline const std::size_t id = 6;
			} // namespace dep_decl
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace fail_call {
				inline const std::size_t id = 7;
			} // namespace fail_call
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace regular_match {
				inline const std::size_t id = 8;
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace regular_match {
				namespace __q2 {
					inline const std::size_t id = 9;
				} // namespace __q2
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace regular_match {
				namespace __q2 {
					namespace __tail {
						inline const std::size_t id = 10;
					} // namespace __tail
				} // namespace __q2
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace regular_match {
				namespace __rop4 {
					inline const std::size_t id = 11;
				} // namespace __rop4
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace regular_match {
				namespace unpack {
					inline const std::size_t id = 12;
				} // namespace unpack
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace regular_match {
				namespace unpack {
					namespace __q2 {
						inline const std::size_t id = 13;
					} // namespace __q2
				} // namespace unpack
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace advanced_rule {
			namespace regular_match {
				namespace unpack {
					namespace __q2 {
						namespace __tail {
							inline const std::size_t id = 14;
						} // namespace __tail
					} // namespace __q2
				} // namespace unpack
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace explicit_expr {
			inline const std::size_t id = 15;
		} // namespace explicit_expr
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace expr {
			inline const std::size_t id = 16;
		} // namespace expr
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace fail_block {
			inline const std::size_t id = 17;
		} // namespace fail_block
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace forward_declaration {
			inline const std::size_t id = 18;
		} // namespace forward_declaration
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace grammar {
			inline const std::size_t id = 19;
		} // namespace grammar
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace grammar {
			namespace __q0 {
				inline const std::size_t id = 20;
			} // namespace __q0
		} // namespace grammar
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace grammar {
			namespace __q0 {
				namespace __tail {
					inline const std::size_t id = 21;
				} // namespace __tail
			} // namespace __q0
		} // namespace grammar
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace grammar {
			namespace __rop4 {
				inline const std::size_t id = 22;
			} // namespace __rop4
		} // namespace grammar
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace grammar {
			namespace modifier {
				inline const std::size_t id = 23;
			} // namespace modifier
		} // namespace grammar
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace main {
			inline const std::size_t id = 24;
		} // namespace main
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace main {
			namespace __grp0 {
				inline const std::size_t id = 25;
			} // namespace __grp0
		} // namespace main
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace main {
			namespace __grp0 {
				namespace __rop0 {
					inline const std::size_t id = 26;
				} // namespace __rop0
			} // namespace __grp0
		} // namespace main
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace main {
			namespace __grp0 {
				namespace __tail {
					inline const std::size_t id = 27;
				} // namespace __tail
			} // namespace __grp0
		} // namespace main
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace name {
			inline const std::size_t id = 28;
		} // namespace name
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace name {
			namespace __grp2 {
				inline const std::size_t id = 29;
			} // namespace __grp2
		} // namespace name
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace name {
			namespace __grp2 {
				namespace __tail {
					inline const std::size_t id = 30;
				} // namespace __tail
			} // namespace __grp2
		} // namespace name
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace name {
			namespace __q4 {
				inline const std::size_t id = 31;
			} // namespace __q4
		} // namespace name
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace name {
			namespace __q6 {
				inline const std::size_t id = 32;
			} // namespace __q6
		} // namespace name
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace param {
			inline const std::size_t id = 33;
		} // namespace param
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace param {
			namespace __grp2 {
				inline const std::size_t id = 34;
			} // namespace __grp2
		} // namespace param
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace param {
			namespace __grp2 {
				namespace __tail {
					inline const std::size_t id = 35;
				} // namespace __tail
			} // namespace __grp2
		} // namespace param
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace params {
			inline const std::size_t id = 36;
		} // namespace params
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace params {
			namespace __q2 {
				inline const std::size_t id = 37;
			} // namespace __q2
		} // namespace params
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			inline const std::size_t id = 38;
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace __q2 {
				inline const std::size_t id = 39;
			} // namespace __q2
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace __q2 {
				namespace __tail {
					inline const std::size_t id = 40;
				} // namespace __tail
			} // namespace __q2
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace __q4 {
				inline const std::size_t id = 41;
			} // namespace __q4
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace __q6 {
				inline const std::size_t id = 42;
			} // namespace __q6
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace __q8 {
				inline const std::size_t id = 43;
			} // namespace __q8
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace __q8 {
				namespace __tail {
					inline const std::size_t id = 44;
				} // namespace __tail
			} // namespace __q8
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace ast {
				inline const std::size_t id = 45;
			} // namespace ast
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace ast {
				namespace abbr {
					inline const std::size_t id = 46;
				} // namespace abbr
			} // namespace ast
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace ast {
				namespace abbr {
					namespace __grp6 {
						inline const std::size_t id = 47;
					} // namespace __grp6
				} // namespace abbr
			} // namespace ast
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace ast {
				namespace abbr {
					namespace __grp6 {
						namespace __tail {
							inline const std::size_t id = 48;
						} // namespace __tail
					} // namespace __grp6
				} // namespace abbr
			} // namespace ast
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace ast {
				namespace full {
					inline const std::size_t id = 49;
				} // namespace full
			} // namespace ast
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace ast {
				namespace full {
					namespace __q4 {
						inline const std::size_t id = 50;
					} // namespace __q4
				} // namespace full
			} // namespace ast
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace ast {
				namespace full {
					namespace __q4 {
						namespace __tail {
							inline const std::size_t id = 51;
						} // namespace __tail
					} // namespace __q4
				} // namespace full
			} // namespace ast
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace ast {
				namespace full {
					namespace part {
						inline const std::size_t id = 52;
					} // namespace part
				} // namespace full
			} // namespace ast
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace ast {
				namespace single_value {
					inline const std::size_t id = 53;
				} // namespace single_value
			} // namespace ast
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace ast {
				namespace single_value {
					namespace __rop2 {
						inline const std::size_t id = 54;
					} // namespace __rop2
				} // namespace single_value
			} // namespace ast
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace f_binding {
				inline const std::size_t id = 55;
			} // namespace f_binding
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace f_binding {
				namespace __grp6 {
					inline const std::size_t id = 56;
				} // namespace __grp6
			} // namespace f_binding
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace f_binding {
				namespace __grp6 {
					namespace __tail {
						inline const std::size_t id = 57;
					} // namespace __tail
				} // namespace __grp6
			} // namespace f_binding
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace nested_rule {
				inline const std::size_t id = 58;
			} // namespace nested_rule
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				inline const std::size_t id = 59;
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace alternative {
					inline const std::size_t id = 60;
				} // namespace alternative
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace ast_capture {
					inline const std::size_t id = 61;
				} // namespace ast_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace ast_capture {
					namespace __q1 {
						inline const std::size_t id = 62;
					} // namespace __q1
				} // namespace ast_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace counter {
					inline const std::size_t id = 63;
				} // namespace counter
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace counter {
					namespace __q2 {
						inline const std::size_t id = 64;
					} // namespace __q2
				} // namespace counter
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace counter {
					namespace bounded {
						inline const std::size_t id = 65;
					} // namespace bounded
				} // namespace counter
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace counter {
					namespace bounded {
						namespace __rop2 {
							inline const std::size_t id = 66;
						} // namespace __rop2
					} // namespace bounded
				} // namespace counter
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace dyn {
					inline const std::size_t id = 67;
				} // namespace dyn
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace dyn {
					namespace __rop2 {
						inline const std::size_t id = 68;
					} // namespace __rop2
				} // namespace dyn
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace dyn {
					namespace dyn_expr {
						inline const std::size_t id = 69;
					} // namespace dyn_expr
				} // namespace dyn
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace fail_capture {
					inline const std::size_t id = 70;
				} // namespace fail_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace fail_capture {
					namespace __q1 {
						inline const std::size_t id = 71;
					} // namespace __q1
				} // namespace fail_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace group {
					inline const std::size_t id = 72;
				} // namespace group
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace group {
					namespace __q2 {
						inline const std::size_t id = 73;
					} // namespace __q2
				} // namespace group
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace group {
					namespace __q2 {
						namespace __tail {
							inline const std::size_t id = 74;
						} // namespace __tail
					} // namespace __q2
				} // namespace group
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace mul_capture {
					inline const std::size_t id = 75;
				} // namespace mul_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace mul_capture {
					namespace __q6 {
						inline const std::size_t id = 76;
					} // namespace __q6
				} // namespace mul_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace mul_capture {
					namespace __q6 {
						namespace __tail {
							inline const std::size_t id = 77;
						} // namespace __tail
					} // namespace __q6
				} // namespace mul_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace mul_capture {
					namespace __rop0 {
						inline const std::size_t id = 78;
					} // namespace __rop0
				} // namespace mul_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace one_capture {
					inline const std::size_t id = 79;
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q0 {
						inline const std::size_t id = 80;
					} // namespace __q0
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q10 {
						inline const std::size_t id = 81;
					} // namespace __q10
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q12 {
						inline const std::size_t id = 82;
					} // namespace __q12
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q2 {
						inline const std::size_t id = 83;
					} // namespace __q2
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q4 {
						inline const std::size_t id = 84;
					} // namespace __q4
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q8 {
						inline const std::size_t id = 85;
					} // namespace __q8
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q8 {
						namespace __tail {
							inline const std::size_t id = 86;
						} // namespace __tail
					} // namespace __q8
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace pattern {
					inline const std::size_t id = 87;
				} // namespace pattern
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace shared_counter_registration {
					inline const std::size_t id = 88;
				} // namespace shared_counter_registration
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace rule {
			namespace value {
				namespace var_capture {
					inline const std::size_t id = 89;
				} // namespace var_capture
			} // namespace value
		} // namespace rule
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace stmt {
			inline const std::size_t id = 90;
		} // namespace stmt
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace template_params {
			inline const std::size_t id = 91;
		} // namespace template_params
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace Rules {
		namespace template_params {
			namespace __q2 {
				inline const std::size_t id = 92;
			} // namespace __q2
		} // namespace template_params
	} // namespace Rules
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			inline const char* const id = "advanced_rule";
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace __grp4 {
				inline const char* const id = "advanced_rule.__grp4";
			} // namespace __grp4
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace __grp4 {
				namespace __rop0 {
					inline const char* const id = "advanced_rule.__grp4.__rop0";
				} // namespace __rop0
			} // namespace __grp4
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace __grp4 {
				namespace __tail {
					inline const char* const id = "advanced_rule.__grp4.__tail";
				} // namespace __tail
			} // namespace __grp4
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace __q2 {
				inline const char* const id = "advanced_rule.__q2";
			} // namespace __q2
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace __q2 {
				namespace __tail {
					inline const char* const id = "advanced_rule.__q2.__tail";
				} // namespace __tail
			} // namespace __q2
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace dep_decl {
				inline const char* const id = "advanced_rule.dep_decl";
			} // namespace dep_decl
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace fail_call {
				inline const char* const id = "advanced_rule.fail_call";
			} // namespace fail_call
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace regular_match {
				inline const char* const id = "advanced_rule.regular_match";
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace regular_match {
				namespace __q2 {
					inline const char* const id = "advanced_rule.regular_match.__q2";
				} // namespace __q2
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace regular_match {
				namespace __q2 {
					namespace __tail {
						inline const char* const id = "advanced_rule.regular_match.__q2.__tail";
					} // namespace __tail
				} // namespace __q2
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace regular_match {
				namespace __rop4 {
					inline const char* const id = "advanced_rule.regular_match.__rop4";
				} // namespace __rop4
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace regular_match {
				namespace unpack {
					inline const char* const id = "advanced_rule.regular_match.unpack";
				} // namespace unpack
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace regular_match {
				namespace unpack {
					namespace __q2 {
						inline const char* const id = "advanced_rule.regular_match.unpack.__q2";
					} // namespace __q2
				} // namespace unpack
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace advanced_rule {
			namespace regular_match {
				namespace unpack {
					namespace __q2 {
						namespace __tail {
							inline const char* const id = "advanced_rule.regular_match.unpack.__q2.__tail";
						} // namespace __tail
					} // namespace __q2
				} // namespace unpack
			} // namespace regular_match
		} // namespace advanced_rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace explicit_expr {
			inline const char* const id = "explicit_expr";
		} // namespace explicit_expr
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace expr {
			inline const char* const id = "expr";
		} // namespace expr
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace fail_block {
			inline const char* const id = "fail_block";
		} // namespace fail_block
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace forward_declaration {
			inline const char* const id = "forward_declaration";
		} // namespace forward_declaration
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace grammar {
			inline const char* const id = "grammar";
		} // namespace grammar
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace grammar {
			namespace __q0 {
				inline const char* const id = "grammar.__q0";
			} // namespace __q0
		} // namespace grammar
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace grammar {
			namespace __q0 {
				namespace __tail {
					inline const char* const id = "grammar.__q0.__tail";
				} // namespace __tail
			} // namespace __q0
		} // namespace grammar
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace grammar {
			namespace __rop4 {
				inline const char* const id = "grammar.__rop4";
			} // namespace __rop4
		} // namespace grammar
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace grammar {
			namespace modifier {
				inline const char* const id = "grammar.modifier";
			} // namespace modifier
		} // namespace grammar
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace main {
			inline const char* const id = "main";
		} // namespace main
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace main {
			namespace __grp0 {
				inline const char* const id = "main.__grp0";
			} // namespace __grp0
		} // namespace main
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace main {
			namespace __grp0 {
				namespace __rop0 {
					inline const char* const id = "main.__grp0.__rop0";
				} // namespace __rop0
			} // namespace __grp0
		} // namespace main
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace main {
			namespace __grp0 {
				namespace __tail {
					inline const char* const id = "main.__grp0.__tail";
				} // namespace __tail
			} // namespace __grp0
		} // namespace main
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace name {
			inline const char* const id = "name";
		} // namespace name
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace name {
			namespace __grp2 {
				inline const char* const id = "name.__grp2";
			} // namespace __grp2
		} // namespace name
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace name {
			namespace __grp2 {
				namespace __tail {
					inline const char* const id = "name.__grp2.__tail";
				} // namespace __tail
			} // namespace __grp2
		} // namespace name
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace name {
			namespace __q4 {
				inline const char* const id = "name.__q4";
			} // namespace __q4
		} // namespace name
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace name {
			namespace __q6 {
				inline const char* const id = "name.__q6";
			} // namespace __q6
		} // namespace name
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace param {
			inline const char* const id = "param";
		} // namespace param
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace param {
			namespace __grp2 {
				inline const char* const id = "param.__grp2";
			} // namespace __grp2
		} // namespace param
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace param {
			namespace __grp2 {
				namespace __tail {
					inline const char* const id = "param.__grp2.__tail";
				} // namespace __tail
			} // namespace __grp2
		} // namespace param
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace params {
			inline const char* const id = "params";
		} // namespace params
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace params {
			namespace __q2 {
				inline const char* const id = "params.__q2";
			} // namespace __q2
		} // namespace params
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			inline const char* const id = "rule";
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace __q2 {
				inline const char* const id = "rule.__q2";
			} // namespace __q2
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace __q2 {
				namespace __tail {
					inline const char* const id = "rule.__q2.__tail";
				} // namespace __tail
			} // namespace __q2
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace __q4 {
				inline const char* const id = "rule.__q4";
			} // namespace __q4
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace __q6 {
				inline const char* const id = "rule.__q6";
			} // namespace __q6
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace __q8 {
				inline const char* const id = "rule.__q8";
			} // namespace __q8
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace __q8 {
				namespace __tail {
					inline const char* const id = "rule.__q8.__tail";
				} // namespace __tail
			} // namespace __q8
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace ast {
				inline const char* const id = "rule.ast";
			} // namespace ast
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace ast {
				namespace abbr {
					inline const char* const id = "rule.ast.abbr";
				} // namespace abbr
			} // namespace ast
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace ast {
				namespace abbr {
					namespace __grp6 {
						inline const char* const id = "rule.ast.abbr.__grp6";
					} // namespace __grp6
				} // namespace abbr
			} // namespace ast
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace ast {
				namespace abbr {
					namespace __grp6 {
						namespace __tail {
							inline const char* const id = "rule.ast.abbr.__grp6.__tail";
						} // namespace __tail
					} // namespace __grp6
				} // namespace abbr
			} // namespace ast
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace ast {
				namespace full {
					inline const char* const id = "rule.ast.full";
				} // namespace full
			} // namespace ast
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace ast {
				namespace full {
					namespace __q4 {
						inline const char* const id = "rule.ast.full.__q4";
					} // namespace __q4
				} // namespace full
			} // namespace ast
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace ast {
				namespace full {
					namespace __q4 {
						namespace __tail {
							inline const char* const id = "rule.ast.full.__q4.__tail";
						} // namespace __tail
					} // namespace __q4
				} // namespace full
			} // namespace ast
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace ast {
				namespace full {
					namespace part {
						inline const char* const id = "rule.ast.full.part";
					} // namespace part
				} // namespace full
			} // namespace ast
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace ast {
				namespace single_value {
					inline const char* const id = "rule.ast.single_value";
				} // namespace single_value
			} // namespace ast
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace ast {
				namespace single_value {
					namespace __rop2 {
						inline const char* const id = "rule.ast.single_value.__rop2";
					} // namespace __rop2
				} // namespace single_value
			} // namespace ast
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace f_binding {
				inline const char* const id = "rule.f_binding";
			} // namespace f_binding
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace f_binding {
				namespace __grp6 {
					inline const char* const id = "rule.f_binding.__grp6";
				} // namespace __grp6
			} // namespace f_binding
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace f_binding {
				namespace __grp6 {
					namespace __tail {
						inline const char* const id = "rule.f_binding.__grp6.__tail";
					} // namespace __tail
				} // namespace __grp6
			} // namespace f_binding
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace nested_rule {
				inline const char* const id = "rule.nested_rule";
			} // namespace nested_rule
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				inline const char* const id = "rule.value";
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace alternative {
					inline const char* const id = "rule.value.alternative";
				} // namespace alternative
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace ast_capture {
					inline const char* const id = "rule.value.ast_capture";
				} // namespace ast_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace ast_capture {
					namespace __q1 {
						inline const char* const id = "rule.value.ast_capture.__q1";
					} // namespace __q1
				} // namespace ast_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace counter {
					inline const char* const id = "rule.value.counter";
				} // namespace counter
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace counter {
					namespace __q2 {
						inline const char* const id = "rule.value.counter.__q2";
					} // namespace __q2
				} // namespace counter
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace counter {
					namespace bounded {
						inline const char* const id = "rule.value.counter.bounded";
					} // namespace bounded
				} // namespace counter
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace counter {
					namespace bounded {
						namespace __rop2 {
							inline const char* const id = "rule.value.counter.bounded.__rop2";
						} // namespace __rop2
					} // namespace bounded
				} // namespace counter
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace dyn {
					inline const char* const id = "rule.value.dyn";
				} // namespace dyn
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace dyn {
					namespace __rop2 {
						inline const char* const id = "rule.value.dyn.__rop2";
					} // namespace __rop2
				} // namespace dyn
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace dyn {
					namespace dyn_expr {
						inline const char* const id = "rule.value.dyn.dyn_expr";
					} // namespace dyn_expr
				} // namespace dyn
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace fail_capture {
					inline const char* const id = "rule.value.fail_capture";
				} // namespace fail_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace fail_capture {
					namespace __q1 {
						inline const char* const id = "rule.value.fail_capture.__q1";
					} // namespace __q1
				} // namespace fail_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace group {
					inline const char* const id = "rule.value.group";
				} // namespace group
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace group {
					namespace __q2 {
						inline const char* const id = "rule.value.group.__q2";
					} // namespace __q2
				} // namespace group
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace group {
					namespace __q2 {
						namespace __tail {
							inline const char* const id = "rule.value.group.__q2.__tail";
						} // namespace __tail
					} // namespace __q2
				} // namespace group
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace mul_capture {
					inline const char* const id = "rule.value.mul_capture";
				} // namespace mul_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace mul_capture {
					namespace __q6 {
						inline const char* const id = "rule.value.mul_capture.__q6";
					} // namespace __q6
				} // namespace mul_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace mul_capture {
					namespace __q6 {
						namespace __tail {
							inline const char* const id = "rule.value.mul_capture.__q6.__tail";
						} // namespace __tail
					} // namespace __q6
				} // namespace mul_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace mul_capture {
					namespace __rop0 {
						inline const char* const id = "rule.value.mul_capture.__rop0";
					} // namespace __rop0
				} // namespace mul_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace one_capture {
					inline const char* const id = "rule.value.one_capture";
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q0 {
						inline const char* const id = "rule.value.one_capture.__q0";
					} // namespace __q0
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q10 {
						inline const char* const id = "rule.value.one_capture.__q10";
					} // namespace __q10
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q12 {
						inline const char* const id = "rule.value.one_capture.__q12";
					} // namespace __q12
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q2 {
						inline const char* const id = "rule.value.one_capture.__q2";
					} // namespace __q2
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q4 {
						inline const char* const id = "rule.value.one_capture.__q4";
					} // namespace __q4
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q8 {
						inline const char* const id = "rule.value.one_capture.__q8";
					} // namespace __q8
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace one_capture {
					namespace __q8 {
						namespace __tail {
							inline const char* const id = "rule.value.one_capture.__q8.__tail";
						} // namespace __tail
					} // namespace __q8
				} // namespace one_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace pattern {
					inline const char* const id = "rule.value.pattern";
				} // namespace pattern
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace shared_counter_registration {
					inline const char* const id = "rule.value.shared_counter_registration";
				} // namespace shared_counter_registration
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace rule {
			namespace value {
				namespace var_capture {
					inline const char* const id = "rule.value.var_capture";
				} // namespace var_capture
			} // namespace value
		} // namespace rule
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace stmt {
			inline const char* const id = "stmt";
		} // namespace stmt
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace template_params {
			inline const char* const id = "template_params";
		} // namespace template_params
	} // namespace RuleNames
} // namespace Parser
namespace Parser {
	namespace RuleNames {
		namespace template_params {
			namespace __q2 {
				inline const char* const id = "template_params.__q2";
			} // namespace __q2
		} // namespace template_params
	} // namespace RuleNames
} // namespace Parser
namespace Parser::FlatTypes { struct __WS; }
namespace Parser::FlatTypes { struct advanced_rule_dep_decl_DEPENDS; }
namespace Parser::FlatTypes { struct advanced_rule; }
namespace Parser::FlatTypes { struct advanced_rule_dep_decl; }
namespace Parser::FlatTypes { struct AUTO; }
namespace Parser::FlatTypes { struct FAIL; }
namespace Parser::FlatTypes { struct SEMICOLON; }
namespace Parser::FlatTypes { struct COLON; }
namespace Parser::FlatTypes { struct EQUALS_SIGN; }
namespace Parser::FlatTypes { struct AMPERSAND; }
namespace Parser::FlatTypes { struct PERCENT_SIGN; }
namespace Parser::FlatTypes { struct rule_nested_rule_NUMBER_SIGN; }
namespace Parser::FlatTypes { struct rule; }
namespace Parser::FlatTypes { struct rule_nested_rule; }
namespace Parser::FlatTypes { struct LEFT_CURLY_BRACKET; }
namespace Parser::FlatTypes { struct rule_value_shared_counter_registration_AUTO; }
namespace Parser::FlatTypes { struct rule_value; }
namespace Parser::FlatTypes { struct rule_value_shared_counter_registration; }
namespace Parser::FlatTypes { struct COMMERCIAL_AT; }
namespace Parser::FlatTypes { struct rule_value_QUANTIFIER; }
namespace Parser::FlatTypes { struct rule_value_NOSPACE; }
namespace Parser::FlatTypes { struct rule_value_ANY; }
namespace Parser::FlatTypes { struct template_params_LESS_THAN_SIGN; }
namespace Parser::FlatTypes { struct template_params; }
namespace Parser::FlatTypes { struct rule_value_STRING; }
namespace Parser::FlatTypes { struct grammar_modifier_AUTO; }
namespace Parser::FlatTypes { struct grammar; }
namespace Parser::FlatTypes { struct grammar_modifier; }
namespace Parser::FlatTypes { struct grammar_modifier_MOD; }
namespace Parser::FlatTypes { struct rule_value_SPACE; }
namespace Parser::FlatTypes { struct template_params_GREATER_THAN_SIGN; }
namespace Parser::FlatTypes { struct rule_value_alternative_VERTICAL_LINE; }
namespace Parser::FlatTypes { struct rule_value_alternative; }
namespace Parser::FlatTypes { struct grammar_modifier_RIGHT_SQUARE_BRACKET; }
namespace Parser::FlatTypes { struct rule_value_dyn_DOLLAR_SIGN; }
namespace Parser::FlatTypes { struct rule_value_dyn; }
namespace Parser::FlatTypes { struct advanced_rule_regular_match_MATCH; }
namespace Parser::FlatTypes { struct advanced_rule_regular_match; }
namespace Parser::FlatTypes { struct COMMA; }
namespace Parser::FlatTypes { struct RIGHT_PARENTHESIS; }
namespace Parser::FlatTypes { struct LEFT_PARENTHESIS; }
namespace Parser::FlatTypes { struct RIGHT_CURLY_BRACKET; }
namespace Parser::FlatTypes { struct NUMBER; }
namespace Parser::FlatTypes { struct PY_RAW; }
namespace Parser::FlatTypes { struct ID; }
namespace Parser::FlatTypes { struct rule_value_CGROUP; }
namespace Parser::FlatTypes { struct advanced_rule___grp4; }
namespace Parser::FlatTypes { struct advanced_rule___grp4___rop0; }
namespace Parser::FlatTypes { struct advanced_rule___grp4___tail; }
namespace Parser::FlatTypes { struct advanced_rule___q2; }
namespace Parser::FlatTypes { struct advanced_rule___q2___tail; }
namespace Parser::FlatTypes { struct advanced_rule_fail_call; }
namespace Parser::FlatTypes { struct advanced_rule_regular_match___q2; }
namespace Parser::FlatTypes { struct advanced_rule_regular_match___q2___tail; }
namespace Parser::FlatTypes { struct advanced_rule_regular_match___rop4; }
namespace Parser::FlatTypes { struct advanced_rule_regular_match_unpack; }
namespace Parser::FlatTypes { struct advanced_rule_regular_match_unpack___q2; }
namespace Parser::FlatTypes { struct advanced_rule_regular_match_unpack___q2___tail; }
namespace Parser::FlatTypes { struct explicit_expr; }
namespace Parser::FlatTypes { struct expr; }
namespace Parser::FlatTypes { struct fail_block; }
namespace Parser::FlatTypes { struct forward_declaration; }
namespace Parser::FlatTypes { struct grammar___q0; }
namespace Parser::FlatTypes { struct grammar___q0___tail; }
namespace Parser::FlatTypes { struct grammar___rop4; }
namespace Parser::FlatTypes { struct main; }
namespace Parser::FlatTypes { struct main___grp0; }
namespace Parser::FlatTypes { struct main___grp0___rop0; }
namespace Parser::FlatTypes { struct main___grp0___tail; }
namespace Parser::FlatTypes { struct name; }
namespace Parser::FlatTypes { struct name___grp2; }
namespace Parser::FlatTypes { struct name___grp2___tail; }
namespace Parser::FlatTypes { struct name___q4; }
namespace Parser::FlatTypes { struct name___q6; }
namespace Parser::FlatTypes { struct param; }
namespace Parser::FlatTypes { struct param___grp2; }
namespace Parser::FlatTypes { struct param___grp2___tail; }
namespace Parser::FlatTypes { struct params; }
namespace Parser::FlatTypes { struct params___q2; }
namespace Parser::FlatTypes { struct rule___q2; }
namespace Parser::FlatTypes { struct rule___q2___tail; }
namespace Parser::FlatTypes { struct rule___q4; }
namespace Parser::FlatTypes { struct rule___q6; }
namespace Parser::FlatTypes { struct rule___q8; }
namespace Parser::FlatTypes { struct rule___q8___tail; }
namespace Parser::FlatTypes { struct rule_ast; }
namespace Parser::FlatTypes { struct rule_ast_abbr; }
namespace Parser::FlatTypes { struct rule_ast_abbr___grp6; }
namespace Parser::FlatTypes { struct rule_ast_abbr___grp6___tail; }
namespace Parser::FlatTypes { struct rule_ast_full; }
namespace Parser::FlatTypes { struct rule_ast_full___q4; }
namespace Parser::FlatTypes { struct rule_ast_full___q4___tail; }
namespace Parser::FlatTypes { struct rule_ast_full_part; }
namespace Parser::FlatTypes { struct rule_ast_single_value; }
namespace Parser::FlatTypes { struct rule_ast_single_value___rop2; }
namespace Parser::FlatTypes { struct rule_f_binding; }
namespace Parser::FlatTypes { struct rule_f_binding___grp6; }
namespace Parser::FlatTypes { struct rule_f_binding___grp6___tail; }
namespace Parser::FlatTypes { struct rule_value_ast_capture; }
namespace Parser::FlatTypes { struct rule_value_ast_capture___q1; }
namespace Parser::FlatTypes { struct rule_value_counter; }
namespace Parser::FlatTypes { struct rule_value_counter___q2; }
namespace Parser::FlatTypes { struct rule_value_counter_bounded; }
namespace Parser::FlatTypes { struct rule_value_counter_bounded___rop2; }
namespace Parser::FlatTypes { struct rule_value_dyn___rop2; }
namespace Parser::FlatTypes { struct rule_value_dyn_dyn_expr; }
namespace Parser::FlatTypes { struct rule_value_fail_capture; }
namespace Parser::FlatTypes { struct rule_value_fail_capture___q1; }
namespace Parser::FlatTypes { struct rule_value_group; }
namespace Parser::FlatTypes { struct rule_value_group___q2; }
namespace Parser::FlatTypes { struct rule_value_group___q2___tail; }
namespace Parser::FlatTypes { struct rule_value_mul_capture; }
namespace Parser::FlatTypes { struct rule_value_mul_capture___q6; }
namespace Parser::FlatTypes { struct rule_value_mul_capture___q6___tail; }
namespace Parser::FlatTypes { struct rule_value_mul_capture___rop0; }
namespace Parser::FlatTypes { struct rule_value_one_capture; }
namespace Parser::FlatTypes { struct rule_value_one_capture___q0; }
namespace Parser::FlatTypes { struct rule_value_one_capture___q10; }
namespace Parser::FlatTypes { struct rule_value_one_capture___q12; }
namespace Parser::FlatTypes { struct rule_value_one_capture___q2; }
namespace Parser::FlatTypes { struct rule_value_one_capture___q4; }
namespace Parser::FlatTypes { struct rule_value_one_capture___q8; }
namespace Parser::FlatTypes { struct rule_value_one_capture___q8___tail; }
namespace Parser::FlatTypes { struct rule_value_pattern; }
namespace Parser::FlatTypes { struct rule_value_var_capture; }
namespace Parser::FlatTypes { struct stmt; }
namespace Parser::FlatTypes { struct template_params___q2; }
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, __WS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct __WS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&__WS::write_to_output, &__WS::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&__WS::write_to_output, &__WS::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_dep_decl_DEPENDS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_dep_decl_DEPENDS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule_dep_decl_DEPENDS::write_to_output, &advanced_rule_dep_decl_DEPENDS::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule_dep_decl_DEPENDS::write_to_output, &advanced_rule_dep_decl_DEPENDS::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, AUTO value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct AUTO {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&AUTO::write_to_output, &AUTO::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&AUTO::write_to_output, &AUTO::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, FAIL value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct FAIL {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&FAIL::write_to_output, &FAIL::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&FAIL::write_to_output, &FAIL::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, SEMICOLON value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct SEMICOLON {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&SEMICOLON::write_to_output, &SEMICOLON::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&SEMICOLON::write_to_output, &SEMICOLON::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, COLON value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct COLON {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&COLON::write_to_output, &COLON::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&COLON::write_to_output, &COLON::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, EQUALS_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct EQUALS_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&EQUALS_SIGN::write_to_output, &EQUALS_SIGN::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&EQUALS_SIGN::write_to_output, &EQUALS_SIGN::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, AMPERSAND value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct AMPERSAND {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&AMPERSAND::write_to_output, &AMPERSAND::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&AMPERSAND::write_to_output, &AMPERSAND::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, PERCENT_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct PERCENT_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&PERCENT_SIGN::write_to_output, &PERCENT_SIGN::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&PERCENT_SIGN::write_to_output, &PERCENT_SIGN::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_nested_rule_NUMBER_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_nested_rule_NUMBER_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_nested_rule_NUMBER_SIGN::write_to_output, &rule_nested_rule_NUMBER_SIGN::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_nested_rule_NUMBER_SIGN::write_to_output, &rule_nested_rule_NUMBER_SIGN::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_nested_rule value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_nested_rule {
			::ISPA_STD::Node<std::shared_ptr<::Parser::FlatTypes::grammar>> value;
			using NUMBER_SIGN = ::Parser::FlatTypes::rule_nested_rule_NUMBER_SIGN;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_nested_rule::write_to_output, &rule_nested_rule::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_nested_rule::write_to_output, &rule_nested_rule::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, LEFT_CURLY_BRACKET value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct LEFT_CURLY_BRACKET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&LEFT_CURLY_BRACKET::write_to_output, &LEFT_CURLY_BRACKET::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&LEFT_CURLY_BRACKET::write_to_output, &LEFT_CURLY_BRACKET::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_shared_counter_registration_AUTO value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_shared_counter_registration_AUTO {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_shared_counter_registration_AUTO::write_to_output, &rule_value_shared_counter_registration_AUTO::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_shared_counter_registration_AUTO::write_to_output, &rule_value_shared_counter_registration_AUTO::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value {
			std::variant<std::monostate, ::ISPA_STD::Node<std::shared_ptr<::Parser::FlatTypes::rule_value_one_capture>>, ::ISPA_STD::Node<std::shared_ptr<::Parser::FlatTypes::rule_value_mul_capture>>> value;
			using shared_counter_registration = ::Parser::FlatTypes::rule_value_shared_counter_registration;
			using QUANTIFIER = ::Parser::FlatTypes::rule_value_QUANTIFIER;
			using NOSPACE = ::Parser::FlatTypes::rule_value_NOSPACE;
			using ANY = ::Parser::FlatTypes::rule_value_ANY;
			using STRING = ::Parser::FlatTypes::rule_value_STRING;
			using SPACE = ::Parser::FlatTypes::rule_value_SPACE;
			using alternative = ::Parser::FlatTypes::rule_value_alternative;
			using dyn = ::Parser::FlatTypes::rule_value_dyn;
			using CGROUP = ::Parser::FlatTypes::rule_value_CGROUP;
			using ast_capture = ::Parser::FlatTypes::rule_value_ast_capture;
			using counter = ::Parser::FlatTypes::rule_value_counter;
			using fail_capture = ::Parser::FlatTypes::rule_value_fail_capture;
			using group = ::Parser::FlatTypes::rule_value_group;
			using mul_capture = ::Parser::FlatTypes::rule_value_mul_capture;
			using one_capture = ::Parser::FlatTypes::rule_value_one_capture;
			using pattern = ::Parser::FlatTypes::rule_value_pattern;
			using var_capture = ::Parser::FlatTypes::rule_value_var_capture;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value::write_to_output, &rule_value::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value::write_to_output, &rule_value::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, COMMERCIAL_AT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct COMMERCIAL_AT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&COMMERCIAL_AT::write_to_output, &COMMERCIAL_AT::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&COMMERCIAL_AT::write_to_output, &COMMERCIAL_AT::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_QUANTIFIER value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_QUANTIFIER {
			char value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_QUANTIFIER::write_to_output, &rule_value_QUANTIFIER::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_QUANTIFIER::write_to_output, &rule_value_QUANTIFIER::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_NOSPACE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_NOSPACE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_NOSPACE::write_to_output, &rule_value_NOSPACE::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_NOSPACE::write_to_output, &rule_value_NOSPACE::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_ANY value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_ANY {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_ANY::write_to_output, &rule_value_ANY::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_ANY::write_to_output, &rule_value_ANY::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, template_params_LESS_THAN_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct template_params_LESS_THAN_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&template_params_LESS_THAN_SIGN::write_to_output, &template_params_LESS_THAN_SIGN::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&template_params_LESS_THAN_SIGN::write_to_output, &template_params_LESS_THAN_SIGN::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_STRING value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_STRING {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_STRING::write_to_output, &rule_value_STRING::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_STRING::write_to_output, &rule_value_STRING::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar_modifier_AUTO value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar_modifier_AUTO {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&grammar_modifier_AUTO::write_to_output, &grammar_modifier_AUTO::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&grammar_modifier_AUTO::write_to_output, &grammar_modifier_AUTO::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar_modifier_MOD value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar_modifier_MOD {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&grammar_modifier_MOD::write_to_output, &grammar_modifier_MOD::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&grammar_modifier_MOD::write_to_output, &grammar_modifier_MOD::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_SPACE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_SPACE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_SPACE::write_to_output, &rule_value_SPACE::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_SPACE::write_to_output, &rule_value_SPACE::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, template_params_GREATER_THAN_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct template_params_GREATER_THAN_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&template_params_GREATER_THAN_SIGN::write_to_output, &template_params_GREATER_THAN_SIGN::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&template_params_GREATER_THAN_SIGN::write_to_output, &template_params_GREATER_THAN_SIGN::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_alternative_VERTICAL_LINE value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_alternative_VERTICAL_LINE {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_alternative_VERTICAL_LINE::write_to_output, &rule_value_alternative_VERTICAL_LINE::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_alternative_VERTICAL_LINE::write_to_output, &rule_value_alternative_VERTICAL_LINE::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_alternative value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_alternative {
			::ISPA_STD::Node<std::shared_ptr<::Parser::FlatTypes::rule_value_pattern>> value;
			using VERTICAL_LINE = ::Parser::FlatTypes::rule_value_alternative_VERTICAL_LINE;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_alternative::write_to_output, &rule_value_alternative::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_alternative::write_to_output, &rule_value_alternative::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar_modifier_RIGHT_SQUARE_BRACKET value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar_modifier_RIGHT_SQUARE_BRACKET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&grammar_modifier_RIGHT_SQUARE_BRACKET::write_to_output, &grammar_modifier_RIGHT_SQUARE_BRACKET::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&grammar_modifier_RIGHT_SQUARE_BRACKET::write_to_output, &grammar_modifier_RIGHT_SQUARE_BRACKET::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_dyn_DOLLAR_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_dyn_DOLLAR_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_dyn_DOLLAR_SIGN::write_to_output, &rule_value_dyn_DOLLAR_SIGN::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_dyn_DOLLAR_SIGN::write_to_output, &rule_value_dyn_DOLLAR_SIGN::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_regular_match_MATCH value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_regular_match_MATCH {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule_regular_match_MATCH::write_to_output, &advanced_rule_regular_match_MATCH::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule_regular_match_MATCH::write_to_output, &advanced_rule_regular_match_MATCH::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, COMMA value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct COMMA {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&COMMA::write_to_output, &COMMA::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&COMMA::write_to_output, &COMMA::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, RIGHT_PARENTHESIS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct RIGHT_PARENTHESIS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&RIGHT_PARENTHESIS::write_to_output, &RIGHT_PARENTHESIS::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&RIGHT_PARENTHESIS::write_to_output, &RIGHT_PARENTHESIS::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, LEFT_PARENTHESIS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct LEFT_PARENTHESIS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&LEFT_PARENTHESIS::write_to_output, &LEFT_PARENTHESIS::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&LEFT_PARENTHESIS::write_to_output, &LEFT_PARENTHESIS::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, RIGHT_CURLY_BRACKET value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct RIGHT_CURLY_BRACKET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&RIGHT_CURLY_BRACKET::write_to_output, &RIGHT_CURLY_BRACKET::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&RIGHT_CURLY_BRACKET::write_to_output, &RIGHT_CURLY_BRACKET::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, NUMBER value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct NUMBER {
			std::string full;
			std::string floating;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(full, floating);
			}
			constexpr auto members() const {
				return std::tie(full, floating);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 2>{{"full", "floating"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&NUMBER::write_to_output, &NUMBER::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&NUMBER::write_to_output, &NUMBER::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, PY_RAW value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct PY_RAW {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&PY_RAW::write_to_output, &PY_RAW::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&PY_RAW::write_to_output, &PY_RAW::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, ID value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct ID {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&ID::write_to_output, &ID::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&ID::write_to_output, &ID::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_CGROUP value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_CGROUP {
			char negative;
			std::string v;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(negative, v);
			}
			constexpr auto members() const {
				return std::tie(negative, v);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 2>{{"negative", "v"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_CGROUP::write_to_output, &rule_value_CGROUP::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_CGROUP::write_to_output, &rule_value_CGROUP::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule___grp4 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule___grp4 {
			using __rop0 = ::Parser::FlatTypes::advanced_rule___grp4___rop0;
			using __tail = ::Parser::FlatTypes::advanced_rule___grp4___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule___grp4::write_to_output, &advanced_rule___grp4::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule___grp4::write_to_output, &advanced_rule___grp4::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule___grp4___rop0 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule___grp4___rop0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule___grp4___rop0::write_to_output, &advanced_rule___grp4___rop0::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule___grp4___rop0::write_to_output, &advanced_rule___grp4___rop0::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule___grp4___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule___grp4___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule___grp4___tail::write_to_output, &advanced_rule___grp4___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule___grp4___tail::write_to_output, &advanced_rule___grp4___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule___q2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule___q2 {
			using __tail = ::Parser::FlatTypes::advanced_rule___q2___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule___q2::write_to_output, &advanced_rule___q2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule___q2::write_to_output, &advanced_rule___q2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule___q2___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule___q2___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule___q2___tail::write_to_output, &advanced_rule___q2___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule___q2___tail::write_to_output, &advanced_rule___q2___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_regular_match___q2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_regular_match___q2 {
			using __tail = ::Parser::FlatTypes::advanced_rule_regular_match___q2___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule_regular_match___q2::write_to_output, &advanced_rule_regular_match___q2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule_regular_match___q2::write_to_output, &advanced_rule_regular_match___q2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_regular_match___q2___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_regular_match___q2___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule_regular_match___q2___tail::write_to_output, &advanced_rule_regular_match___q2___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule_regular_match___q2___tail::write_to_output, &advanced_rule_regular_match___q2___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_regular_match___rop4 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_regular_match___rop4 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule_regular_match___rop4::write_to_output, &advanced_rule_regular_match___rop4::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule_regular_match___rop4::write_to_output, &advanced_rule_regular_match___rop4::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_regular_match_unpack___q2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_regular_match_unpack___q2 {
			using __tail = ::Parser::FlatTypes::advanced_rule_regular_match_unpack___q2___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule_regular_match_unpack___q2::write_to_output, &advanced_rule_regular_match_unpack___q2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule_regular_match_unpack___q2::write_to_output, &advanced_rule_regular_match_unpack___q2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_regular_match_unpack___q2___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_regular_match_unpack___q2___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule_regular_match_unpack___q2___tail::write_to_output, &advanced_rule_regular_match_unpack___q2___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule_regular_match_unpack___q2___tail::write_to_output, &advanced_rule_regular_match_unpack___q2___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar___q0 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar___q0 {
			using __tail = ::Parser::FlatTypes::grammar___q0___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&grammar___q0::write_to_output, &grammar___q0::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&grammar___q0::write_to_output, &grammar___q0::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar___q0___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar___q0___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&grammar___q0___tail::write_to_output, &grammar___q0___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&grammar___q0___tail::write_to_output, &grammar___q0___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar___rop4 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar___rop4 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&grammar___rop4::write_to_output, &grammar___rop4::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&grammar___rop4::write_to_output, &grammar___rop4::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, main___grp0 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct main___grp0 {
			using __rop0 = ::Parser::FlatTypes::main___grp0___rop0;
			using __tail = ::Parser::FlatTypes::main___grp0___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&main___grp0::write_to_output, &main___grp0::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&main___grp0::write_to_output, &main___grp0::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, main___grp0___rop0 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct main___grp0___rop0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&main___grp0___rop0::write_to_output, &main___grp0___rop0::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&main___grp0___rop0::write_to_output, &main___grp0___rop0::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, main___grp0___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct main___grp0___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&main___grp0___tail::write_to_output, &main___grp0___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&main___grp0___tail::write_to_output, &main___grp0___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, name___grp2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct name___grp2 {
			using __tail = ::Parser::FlatTypes::name___grp2___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&name___grp2::write_to_output, &name___grp2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&name___grp2::write_to_output, &name___grp2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, name___grp2___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct name___grp2___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&name___grp2___tail::write_to_output, &name___grp2___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&name___grp2___tail::write_to_output, &name___grp2___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, name___q4 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct name___q4 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&name___q4::write_to_output, &name___q4::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&name___q4::write_to_output, &name___q4::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, name___q6 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct name___q6 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&name___q6::write_to_output, &name___q6::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&name___q6::write_to_output, &name___q6::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, param___grp2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct param___grp2 {
			using __tail = ::Parser::FlatTypes::param___grp2___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&param___grp2::write_to_output, &param___grp2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&param___grp2::write_to_output, &param___grp2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, param___grp2___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct param___grp2___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&param___grp2___tail::write_to_output, &param___grp2___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&param___grp2___tail::write_to_output, &param___grp2___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, params___q2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct params___q2 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&params___q2::write_to_output, &params___q2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&params___q2::write_to_output, &params___q2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule___q2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule___q2 {
			using __tail = ::Parser::FlatTypes::rule___q2___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule___q2::write_to_output, &rule___q2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule___q2::write_to_output, &rule___q2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule___q2___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule___q2___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule___q2___tail::write_to_output, &rule___q2___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule___q2___tail::write_to_output, &rule___q2___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule___q4 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule___q4 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule___q4::write_to_output, &rule___q4::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule___q4::write_to_output, &rule___q4::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule___q6 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule___q6 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule___q6::write_to_output, &rule___q6::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule___q6::write_to_output, &rule___q6::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule___q8 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule___q8 {
			using __tail = ::Parser::FlatTypes::rule___q8___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule___q8::write_to_output, &rule___q8::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule___q8::write_to_output, &rule___q8::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule___q8___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule___q8___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule___q8___tail::write_to_output, &rule___q8___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule___q8___tail::write_to_output, &rule___q8___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_abbr___grp6 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_abbr___grp6 {
			using __tail = ::Parser::FlatTypes::rule_ast_abbr___grp6___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_ast_abbr___grp6::write_to_output, &rule_ast_abbr___grp6::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_ast_abbr___grp6::write_to_output, &rule_ast_abbr___grp6::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_abbr___grp6___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_abbr___grp6___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_ast_abbr___grp6___tail::write_to_output, &rule_ast_abbr___grp6___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_ast_abbr___grp6___tail::write_to_output, &rule_ast_abbr___grp6___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_full___q4 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_full___q4 {
			using __tail = ::Parser::FlatTypes::rule_ast_full___q4___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_ast_full___q4::write_to_output, &rule_ast_full___q4::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_ast_full___q4::write_to_output, &rule_ast_full___q4::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_full___q4___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_full___q4___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_ast_full___q4___tail::write_to_output, &rule_ast_full___q4___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_ast_full___q4___tail::write_to_output, &rule_ast_full___q4___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_single_value___rop2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_single_value___rop2 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_ast_single_value___rop2::write_to_output, &rule_ast_single_value___rop2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_ast_single_value___rop2::write_to_output, &rule_ast_single_value___rop2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_f_binding___grp6 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_f_binding___grp6 {
			using __tail = ::Parser::FlatTypes::rule_f_binding___grp6___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_f_binding___grp6::write_to_output, &rule_f_binding___grp6::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_f_binding___grp6::write_to_output, &rule_f_binding___grp6::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_f_binding___grp6___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_f_binding___grp6___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_f_binding___grp6___tail::write_to_output, &rule_f_binding___grp6___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_f_binding___grp6___tail::write_to_output, &rule_f_binding___grp6___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_ast_capture___q1 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_ast_capture___q1 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_ast_capture___q1::write_to_output, &rule_value_ast_capture___q1::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_ast_capture___q1::write_to_output, &rule_value_ast_capture___q1::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_counter___q2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_counter___q2 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_counter___q2::write_to_output, &rule_value_counter___q2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_counter___q2::write_to_output, &rule_value_counter___q2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_counter_bounded___rop2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_counter_bounded___rop2 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_counter_bounded___rop2::write_to_output, &rule_value_counter_bounded___rop2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_counter_bounded___rop2::write_to_output, &rule_value_counter_bounded___rop2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_dyn___rop2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_dyn___rop2 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_dyn___rop2::write_to_output, &rule_value_dyn___rop2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_dyn___rop2::write_to_output, &rule_value_dyn___rop2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_fail_capture___q1 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_fail_capture___q1 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_fail_capture___q1::write_to_output, &rule_value_fail_capture___q1::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_fail_capture___q1::write_to_output, &rule_value_fail_capture___q1::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_group value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_group {
			std::vector<::ISPA_STD::Node<std::shared_ptr<::Parser::FlatTypes::rule_value>>> value;
			using __q2 = ::Parser::FlatTypes::rule_value_group___q2;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_group::write_to_output, &rule_value_group::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_group::write_to_output, &rule_value_group::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_group___q2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_group___q2 {
			using __tail = ::Parser::FlatTypes::rule_value_group___q2___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_group___q2::write_to_output, &rule_value_group___q2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_group___q2::write_to_output, &rule_value_group___q2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_group___q2___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_group___q2___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_group___q2___tail::write_to_output, &rule_value_group___q2___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_group___q2___tail::write_to_output, &rule_value_group___q2___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_mul_capture value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_mul_capture {
			char type;
			std::vector<::ISPA_STD::Node<std::shared_ptr<::Parser::FlatTypes::rule_value_one_capture>>> cap;
			using __q6 = ::Parser::FlatTypes::rule_value_mul_capture___q6;
			using __rop0 = ::Parser::FlatTypes::rule_value_mul_capture___rop0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(type, cap);
			}
			constexpr auto members() const {
				return std::tie(type, cap);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 2>{{"type", "cap"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_mul_capture::write_to_output, &rule_value_mul_capture::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_mul_capture::write_to_output, &rule_value_mul_capture::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_mul_capture___q6 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_mul_capture___q6 {
			using __tail = ::Parser::FlatTypes::rule_value_mul_capture___q6___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_mul_capture___q6::write_to_output, &rule_value_mul_capture___q6::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_mul_capture___q6::write_to_output, &rule_value_mul_capture___q6::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_mul_capture___q6___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_mul_capture___q6___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_mul_capture___q6___tail::write_to_output, &rule_value_mul_capture___q6___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_mul_capture___q6___tail::write_to_output, &rule_value_mul_capture___q6___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_mul_capture___rop0 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_mul_capture___rop0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_mul_capture___rop0::write_to_output, &rule_value_mul_capture___rop0::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_mul_capture___rop0::write_to_output, &rule_value_mul_capture___rop0::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_one_capture___q0 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_one_capture___q0 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_one_capture___q0::write_to_output, &rule_value_one_capture___q0::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_one_capture___q0::write_to_output, &rule_value_one_capture___q0::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_one_capture___q10 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_one_capture___q10 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_one_capture___q10::write_to_output, &rule_value_one_capture___q10::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_one_capture___q10::write_to_output, &rule_value_one_capture___q10::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_one_capture___q12 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_one_capture___q12 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_one_capture___q12::write_to_output, &rule_value_one_capture___q12::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_one_capture___q12::write_to_output, &rule_value_one_capture___q12::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_one_capture___q2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_one_capture___q2 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_one_capture___q2::write_to_output, &rule_value_one_capture___q2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_one_capture___q2::write_to_output, &rule_value_one_capture___q2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_one_capture___q4 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_one_capture___q4 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_one_capture___q4::write_to_output, &rule_value_one_capture___q4::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_one_capture___q4::write_to_output, &rule_value_one_capture___q4::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_one_capture___q8 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_one_capture___q8 {
			using __tail = ::Parser::FlatTypes::rule_value_one_capture___q8___tail;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_one_capture___q8::write_to_output, &rule_value_one_capture___q8::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_one_capture___q8::write_to_output, &rule_value_one_capture___q8::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_one_capture___q8___tail value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_one_capture___q8___tail {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_one_capture___q8___tail::write_to_output, &rule_value_one_capture___q8___tail::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_one_capture___q8___tail::write_to_output, &rule_value_one_capture___q8___tail::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, template_params___q2 value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct template_params___q2 {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie();
			}
			constexpr auto members() const {
				return std::tie();
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 0>{{}};
			}
			constexpr auto methods() {
				return std::make_tuple(&template_params___q2::write_to_output, &template_params___q2::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&template_params___q2::write_to_output, &template_params___q2::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar_modifier value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar_modifier {
			::ISPA_STD::Node<::Parser::FlatTypes::grammar_modifier_MOD> value;
			using AUTO = ::Parser::FlatTypes::grammar_modifier_AUTO;
			using MOD = ::Parser::FlatTypes::grammar_modifier_MOD;
			using RIGHT_SQUARE_BRACKET = ::Parser::FlatTypes::grammar_modifier_RIGHT_SQUARE_BRACKET;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&grammar_modifier::write_to_output, &grammar_modifier::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&grammar_modifier::write_to_output, &grammar_modifier::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, expr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct expr {
			::ISPA_STD::Node<::Parser::FlatTypes::PY_RAW> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&expr::write_to_output, &expr::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&expr::write_to_output, &expr::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, stmt value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct stmt {
			::ISPA_STD::Node<::Parser::FlatTypes::PY_RAW> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&stmt::write_to_output, &stmt::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&stmt::write_to_output, &stmt::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_shared_counter_registration value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_shared_counter_registration {
			::ISPA_STD::Node<::Parser::FlatTypes::ID> value;
			using AUTO = ::Parser::FlatTypes::rule_value_shared_counter_registration_AUTO;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_shared_counter_registration::write_to_output, &rule_value_shared_counter_registration::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_shared_counter_registration::write_to_output, &rule_value_shared_counter_registration::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_regular_match_unpack value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_regular_match_unpack {
			std::vector<::ISPA_STD::Node<::Parser::FlatTypes::ID>> value;
			using __q2 = ::Parser::FlatTypes::advanced_rule_regular_match_unpack___q2;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule_regular_match_unpack::write_to_output, &advanced_rule_regular_match_unpack::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule_regular_match_unpack::write_to_output, &advanced_rule_regular_match_unpack::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, forward_declaration value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct forward_declaration {
			::ISPA_STD::Node<::Parser::FlatTypes::ID> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&forward_declaration::write_to_output, &forward_declaration::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&forward_declaration::write_to_output, &forward_declaration::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, param value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct param {
			::ISPA_STD::Node<::Parser::FlatTypes::ID> first_p;
			std::vector<::ISPA_STD::Node<::Parser::FlatTypes::ID>> following_p;
			using __grp2 = ::Parser::FlatTypes::param___grp2;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(first_p, following_p);
			}
			constexpr auto members() const {
				return std::tie(first_p, following_p);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 2>{{"first_p", "following_p"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&param::write_to_output, &param::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&param::write_to_output, &param::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_abbr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_abbr {
			::ISPA_STD::Node<::Parser::FlatTypes::ID> f;
			std::vector<::ISPA_STD::Node<::Parser::FlatTypes::ID>> seq;
			using __grp6 = ::Parser::FlatTypes::rule_ast_abbr___grp6;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(f, seq);
			}
			constexpr auto members() const {
				return std::tie(f, seq);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 2>{{"f", "seq"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_ast_abbr::write_to_output, &rule_ast_abbr::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_ast_abbr::write_to_output, &rule_ast_abbr::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_f_binding value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_f_binding {
			::ISPA_STD::Node<::Parser::FlatTypes::ID> f;
			std::vector<::ISPA_STD::Node<::Parser::FlatTypes::ID>> seq;
			using __grp6 = ::Parser::FlatTypes::rule_f_binding___grp6;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(f, seq);
			}
			constexpr auto members() const {
				return std::tie(f, seq);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 2>{{"f", "seq"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_f_binding::write_to_output, &rule_f_binding::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_f_binding::write_to_output, &rule_f_binding::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_ast_capture value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_ast_capture {
			::ISPA_STD::Node<::Parser::FlatTypes::ID> value;
			using __q1 = ::Parser::FlatTypes::rule_value_ast_capture___q1;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_ast_capture::write_to_output, &rule_value_ast_capture::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_ast_capture::write_to_output, &rule_value_ast_capture::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_var_capture value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_var_capture {
			::ISPA_STD::Node<::Parser::FlatTypes::ID> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_var_capture::write_to_output, &rule_value_var_capture::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_var_capture::write_to_output, &rule_value_var_capture::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, explicit_expr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct explicit_expr {
			::ISPA_STD::Node<::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&explicit_expr::write_to_output, &explicit_expr::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&explicit_expr::write_to_output, &explicit_expr::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_full_part value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_full_part {
			::ISPA_STD::Node<::Parser::FlatTypes::ID> key;
			::ISPA_STD::Node<::Parser::FlatTypes::expr> e;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(key, e);
			}
			constexpr auto members() const {
				return std::tie(key, e);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 2>{{"key", "e"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_ast_full_part::write_to_output, &rule_ast_full_part::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_ast_full_part::write_to_output, &rule_ast_full_part::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_single_value value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_single_value {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::FlatTypes::expr>, char> value;
			using __rop2 = ::Parser::FlatTypes::rule_ast_single_value___rop2;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_ast_single_value::write_to_output, &rule_ast_single_value::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_ast_single_value::write_to_output, &rule_ast_single_value::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_counter_bounded value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_counter_bounded {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::FlatTypes::NUMBER>, ::ISPA_STD::Node<::Parser::FlatTypes::ID>, ::ISPA_STD::Node<::Parser::FlatTypes::expr>> value;
			using __rop2 = ::Parser::FlatTypes::rule_value_counter_bounded___rop2;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_counter_bounded::write_to_output, &rule_value_counter_bounded::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_counter_bounded::write_to_output, &rule_value_counter_bounded::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_dyn_dyn_expr value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_dyn_dyn_expr {
			::ISPA_STD::Node<::Parser::FlatTypes::expr> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_dyn_dyn_expr::write_to_output, &rule_value_dyn_dyn_expr::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_dyn_dyn_expr::write_to_output, &rule_value_dyn_dyn_expr::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_regular_match value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_regular_match {
			std::vector<::ISPA_STD::Node<::Parser::FlatTypes::rule_value>> patterns;
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::FlatTypes::advanced_rule_regular_match_unpack>, char> assign_names;
			using MATCH = ::Parser::FlatTypes::advanced_rule_regular_match_MATCH;
			using __q2 = ::Parser::FlatTypes::advanced_rule_regular_match___q2;
			using __rop4 = ::Parser::FlatTypes::advanced_rule_regular_match___rop4;
			using unpack = ::Parser::FlatTypes::advanced_rule_regular_match_unpack;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(patterns, assign_names);
			}
			constexpr auto members() const {
				return std::tie(patterns, assign_names);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 2>{{"patterns", "assign_names"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule_regular_match::write_to_output, &advanced_rule_regular_match::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule_regular_match::write_to_output, &advanced_rule_regular_match::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_dep_decl value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_dep_decl {
			::ISPA_STD::Node<::Parser::FlatTypes::forward_declaration> value;
			using DEPENDS = ::Parser::FlatTypes::advanced_rule_dep_decl_DEPENDS;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule_dep_decl::write_to_output, &advanced_rule_dep_decl::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule_dep_decl::write_to_output, &advanced_rule_dep_decl::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, template_params value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct template_params {
			::ISPA_STD::Node<::Parser::FlatTypes::param> value;
			using LESS_THAN_SIGN = ::Parser::FlatTypes::template_params_LESS_THAN_SIGN;
			using GREATER_THAN_SIGN = ::Parser::FlatTypes::template_params_GREATER_THAN_SIGN;
			using __q2 = ::Parser::FlatTypes::template_params___q2;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&template_params::write_to_output, &template_params::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&template_params::write_to_output, &template_params::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, params value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct params {
			::ISPA_STD::Node<::Parser::FlatTypes::param> value;
			using __q2 = ::Parser::FlatTypes::params___q2;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&params::write_to_output, &params::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&params::write_to_output, &params::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast_full value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast_full {
			std::vector<::ISPA_STD::Node<::Parser::FlatTypes::rule_ast_full_part>> value;
			using __q4 = ::Parser::FlatTypes::rule_ast_full___q4;
			using part = ::Parser::FlatTypes::rule_ast_full_part;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_ast_full::write_to_output, &rule_ast_full::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_ast_full::write_to_output, &rule_ast_full::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_counter value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_counter {
			::ISPA_STD::Node<::Parser::FlatTypes::rule_value_QUANTIFIER> quantifier;
			::ISPA_STD::Node<::Parser::FlatTypes::rule_value_counter_bounded> repetitions;
			using __q2 = ::Parser::FlatTypes::rule_value_counter___q2;
			using bounded = ::Parser::FlatTypes::rule_value_counter_bounded;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(quantifier, repetitions);
			}
			constexpr auto members() const {
				return std::tie(quantifier, repetitions);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 2>{{"quantifier", "repetitions"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_counter::write_to_output, &rule_value_counter::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_counter::write_to_output, &rule_value_counter::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_dyn value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_dyn {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::FlatTypes::rule_value_dyn_dyn_expr>, ::ISPA_STD::Node<::Parser::FlatTypes::ID>> value;
			using DOLLAR_SIGN = ::Parser::FlatTypes::rule_value_dyn_DOLLAR_SIGN;
			using __rop2 = ::Parser::FlatTypes::rule_value_dyn___rop2;
			using dyn_expr = ::Parser::FlatTypes::rule_value_dyn_dyn_expr;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_dyn::write_to_output, &rule_value_dyn::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_dyn::write_to_output, &rule_value_dyn::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule {
			std::vector<::ISPA_STD::Node<::Parser::FlatTypes::advanced_rule_dep_decl>> dep;
			std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::FlatTypes::advanced_rule_regular_match>, ::ISPA_STD::Node<::Parser::FlatTypes::stmt>>> body;
			using dep_decl = ::Parser::FlatTypes::advanced_rule_dep_decl;
			using regular_match = ::Parser::FlatTypes::advanced_rule_regular_match;
			using __grp4 = ::Parser::FlatTypes::advanced_rule___grp4;
			using __q2 = ::Parser::FlatTypes::advanced_rule___q2;
			using fail_call = ::Parser::FlatTypes::advanced_rule_fail_call;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(dep, body);
			}
			constexpr auto members() const {
				return std::tie(dep, body);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 2>{{"dep", "body"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule::write_to_output, &advanced_rule::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule::write_to_output, &advanced_rule::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, name value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct name {
			::ISPA_STD::Node<::Parser::FlatTypes::ID> primary;
			std::vector<::ISPA_STD::Node<::Parser::FlatTypes::ID>> nested;
			::ISPA_STD::Node<::Parser::FlatTypes::template_params> temp_params;
			::ISPA_STD::Node<::Parser::FlatTypes::params> param;
			using __grp2 = ::Parser::FlatTypes::name___grp2;
			using __q4 = ::Parser::FlatTypes::name___q4;
			using __q6 = ::Parser::FlatTypes::name___q6;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(primary, nested, temp_params, param);
			}
			constexpr auto members() const {
				return std::tie(primary, nested, temp_params, param);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 4>{{"primary", "nested", "temp_params", "param"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&name::write_to_output, &name::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&name::write_to_output, &name::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_ast value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_ast {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::FlatTypes::rule_ast_abbr>, ::ISPA_STD::Node<::Parser::FlatTypes::rule_ast_full>, ::ISPA_STD::Node<::Parser::FlatTypes::rule_ast_single_value>> value;
			using abbr = ::Parser::FlatTypes::rule_ast_abbr;
			using full = ::Parser::FlatTypes::rule_ast_full;
			using single_value = ::Parser::FlatTypes::rule_ast_single_value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_ast::write_to_output, &rule_ast::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_ast::write_to_output, &rule_ast::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, grammar value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct grammar {
			std::vector<::ISPA_STD::Node<::Parser::FlatTypes::grammar_modifier>> mod;
			::ISPA_STD::Node<::Parser::FlatTypes::name> name;
			std::variant<std::monostate, ::ISPA_STD::Node<std::shared_ptr<::Parser::FlatTypes::rule>>, ::ISPA_STD::Node<::Parser::FlatTypes::advanced_rule>> entry;
			using modifier = ::Parser::FlatTypes::grammar_modifier;
			using __q0 = ::Parser::FlatTypes::grammar___q0;
			using __rop4 = ::Parser::FlatTypes::grammar___rop4;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(mod, name, entry);
			}
			constexpr auto members() const {
				return std::tie(mod, name, entry);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 3>{{"mod", "name", "entry"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&grammar::write_to_output, &grammar::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&grammar::write_to_output, &grammar::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, advanced_rule_fail_call value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct advanced_rule_fail_call {
			::ISPA_STD::Node<::Parser::FlatTypes::name> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&advanced_rule_fail_call::write_to_output, &advanced_rule_fail_call::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&advanced_rule_fail_call::write_to_output, &advanced_rule_fail_call::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, fail_block value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct fail_block {
			::ISPA_STD::Node<::Parser::FlatTypes::name> name;
			::ISPA_STD::Node<::Parser::FlatTypes::stmt> val;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(name, val);
			}
			constexpr auto members() const {
				return std::tie(name, val);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 2>{{"name", "val"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&fail_block::write_to_output, &fail_block::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&fail_block::write_to_output, &fail_block::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_fail_capture value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_fail_capture {
			::ISPA_STD::Node<::Parser::FlatTypes::name> value;
			using __q1 = ::Parser::FlatTypes::rule_value_fail_capture___q1;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_fail_capture::write_to_output, &rule_value_fail_capture::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_fail_capture::write_to_output, &rule_value_fail_capture::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_pattern value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_pattern {
			std::variant<std::monostate, ::ISPA_STD::Node<::Parser::FlatTypes::name>, ::ISPA_STD::Node<std::shared_ptr<::Parser::FlatTypes::rule_value_group>>, ::ISPA_STD::Node<::Parser::FlatTypes::rule_value_dyn>, ::ISPA_STD::Node<::Parser::FlatTypes::rule_value_STRING>, ::ISPA_STD::Node<::Parser::FlatTypes::rule_value_CGROUP>, ::ISPA_STD::Node<::Parser::FlatTypes::rule_value_ANY>, ::ISPA_STD::Node<::Parser::FlatTypes::rule_value_SPACE>, ::ISPA_STD::Node<::Parser::FlatTypes::rule_value_NOSPACE>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_pattern::write_to_output, &rule_value_pattern::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_pattern::write_to_output, &rule_value_pattern::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule {
			std::vector<::ISPA_STD::Node<::Parser::FlatTypes::rule_value>> v;
			::ISPA_STD::Node<::Parser::FlatTypes::rule_ast> ast_pointer;
			::ISPA_STD::Node<::Parser::FlatTypes::rule_f_binding> fail_pointer;
			std::vector<::ISPA_STD::Node<std::shared_ptr<::Parser::FlatTypes::rule_nested_rule>>> nested;
			using nested_rule = ::Parser::FlatTypes::rule_nested_rule;
			using value = ::Parser::FlatTypes::rule_value;
			using __q2 = ::Parser::FlatTypes::rule___q2;
			using __q4 = ::Parser::FlatTypes::rule___q4;
			using __q6 = ::Parser::FlatTypes::rule___q6;
			using __q8 = ::Parser::FlatTypes::rule___q8;
			using ast = ::Parser::FlatTypes::rule_ast;
			using f_binding = ::Parser::FlatTypes::rule_f_binding;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(v, ast_pointer, fail_pointer, nested);
			}
			constexpr auto members() const {
				return std::tie(v, ast_pointer, fail_pointer, nested);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 4>{{"v", "ast_pointer", "fail_pointer", "nested"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule::write_to_output, &rule::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule::write_to_output, &rule::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, main value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct main {
			std::vector<std::variant<std::monostate, ::ISPA_STD::Node<::Parser::FlatTypes::grammar>, ::ISPA_STD::Node<::Parser::FlatTypes::fail_block>>> value;
			using __grp0 = ::Parser::FlatTypes::main___grp0;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(value);
			}
			constexpr auto members() const {
				return std::tie(value);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 1>{{"value"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&main::write_to_output, &main::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&main::write_to_output, &main::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, rule_value_one_capture value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace FlatTypes {
		struct rule_value_one_capture {
			::ISPA_STD::Node<::Parser::FlatTypes::rule_value_var_capture> v_cap;
			::ISPA_STD::Node<::Parser::FlatTypes::rule_value_ast_capture> ast_cap;
			::ISPA_STD::Node<::Parser::FlatTypes::rule_value_fail_capture> fail_cap;
			::ISPA_STD::Node<std::shared_ptr<::Parser::FlatTypes::rule_value_pattern>> val;
			std::vector<::ISPA_STD::Node<std::shared_ptr<::Parser::FlatTypes::rule_value_alternative>>> alts;
			::ISPA_STD::Node<::Parser::FlatTypes::rule_value_counter> quantifier;
			::ISPA_STD::Node<::Parser::FlatTypes::rule_value_shared_counter_registration> registration;
			using __q0 = ::Parser::FlatTypes::rule_value_one_capture___q0;
			using __q10 = ::Parser::FlatTypes::rule_value_one_capture___q10;
			using __q12 = ::Parser::FlatTypes::rule_value_one_capture___q12;
			using __q2 = ::Parser::FlatTypes::rule_value_one_capture___q2;
			using __q4 = ::Parser::FlatTypes::rule_value_one_capture___q4;
			using __q8 = ::Parser::FlatTypes::rule_value_one_capture___q8;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
			constexpr auto members() {
				return std::tie(v_cap, ast_cap, fail_cap, val, alts, quantifier, registration);
			}
			constexpr auto members() const {
				return std::tie(v_cap, ast_cap, fail_cap, val, alts, quantifier, registration);
			}
			static constexpr auto members_str() {
				return std::array<std::string_view, 7>{{"v_cap", "ast_cap", "fail_cap", "val", "alts", "quantifier", "registration"}};
			}
			constexpr auto methods() {
				return std::make_tuple(&rule_value_one_capture::write_to_output, &rule_value_one_capture::print);
			}
			constexpr auto methods() const {
				return std::make_tuple(&rule_value_one_capture::write_to_output, &rule_value_one_capture::print);
			}
			static constexpr auto methods_str() {
				return std::array<std::string_view, 2>{{"write_to_output", "print"}};
			}
		};
	} // namespace FlatTypes
} // namespace Parser
namespace Parser {
	namespace Types {
		using __WS = ::Parser::FlatTypes::__WS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using advanced_rule = ::Parser::FlatTypes::advanced_rule;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using AUTO = ::Parser::FlatTypes::AUTO;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using FAIL = ::Parser::FlatTypes::FAIL;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using SEMICOLON = ::Parser::FlatTypes::SEMICOLON;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using COLON = ::Parser::FlatTypes::COLON;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using EQUALS_SIGN = ::Parser::FlatTypes::EQUALS_SIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using AMPERSAND = ::Parser::FlatTypes::AMPERSAND;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using PERCENT_SIGN = ::Parser::FlatTypes::PERCENT_SIGN;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using rule = ::Parser::FlatTypes::rule;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using LEFT_CURLY_BRACKET = ::Parser::FlatTypes::LEFT_CURLY_BRACKET;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using COMMERCIAL_AT = ::Parser::FlatTypes::COMMERCIAL_AT;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using template_params = ::Parser::FlatTypes::template_params;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using grammar = ::Parser::FlatTypes::grammar;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using COMMA = ::Parser::FlatTypes::COMMA;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using RIGHT_PARENTHESIS = ::Parser::FlatTypes::RIGHT_PARENTHESIS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using LEFT_PARENTHESIS = ::Parser::FlatTypes::LEFT_PARENTHESIS;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using RIGHT_CURLY_BRACKET = ::Parser::FlatTypes::RIGHT_CURLY_BRACKET;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using NUMBER = ::Parser::FlatTypes::NUMBER;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using PY_RAW = ::Parser::FlatTypes::PY_RAW;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using ID = ::Parser::FlatTypes::ID;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using explicit_expr = ::Parser::FlatTypes::explicit_expr;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using expr = ::Parser::FlatTypes::expr;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using fail_block = ::Parser::FlatTypes::fail_block;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using forward_declaration = ::Parser::FlatTypes::forward_declaration;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using main = ::Parser::FlatTypes::main;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using name = ::Parser::FlatTypes::name;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using param = ::Parser::FlatTypes::param;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using params = ::Parser::FlatTypes::params;
	} // namespace Types
} // namespace Parser
namespace Parser {
	namespace Types {
		using stmt = ::Parser::FlatTypes::stmt;
	} // namespace Types
} // namespace Parser
namespace Parser {
	using Token = ::ISPA_STD::RawToken<Types::__WS, Types::advanced_rule::dep_decl::DEPENDS, Types::AUTO, Types::FAIL, Types::SEMICOLON, Types::COLON, Types::EQUALS_SIGN, Types::AMPERSAND, Types::PERCENT_SIGN, Types::rule::nested_rule::NUMBER_SIGN, Types::LEFT_CURLY_BRACKET, Types::rule::value::shared_counter_registration::AUTO, Types::COMMERCIAL_AT, Types::rule::value::QUANTIFIER, Types::rule::value::NOSPACE, Types::rule::value::ANY, Types::template_params::LESS_THAN_SIGN, Types::rule::value::STRING, Types::grammar::modifier::AUTO, Types::grammar::modifier::MOD, Types::rule::value::SPACE, Types::template_params::GREATER_THAN_SIGN, Types::rule::value::alternative::VERTICAL_LINE, Types::grammar::modifier::RIGHT_SQUARE_BRACKET, Types::rule::value::dyn::DOLLAR_SIGN, Types::advanced_rule::regular_match::MATCH, Types::COMMA, Types::RIGHT_PARENTHESIS, Types::LEFT_PARENTHESIS, Types::RIGHT_CURLY_BRACKET, Types::NUMBER, Types::PY_RAW, Types::ID, Types::rule::value::CGROUP>;
} // namespace Parser
namespace Parser {
	class Lexer : public ::ISPA_STD::Lexer_base<Token> {
		static ::ISPA_STD::DFA::API::CharToClass char_class_table;
		static ::ISPA_STD::DFA::API::Table<86, 50> dfa_table;
		static ::ISPA_STD::DFA::API::Table<104, 4> action_table;
		static auto semantic_action_exec(long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token>;
		bool init_done = false;
		auto init() -> void override;
		::ISPA_STD::DFA::API::TdfaLayout<27, 26> tdfa_registers;
		static std::array<::ISPA_STD::DFA::API::DFADebug, 1> debug_array;
		static std::unordered_map<long long, std::unordered_map<long long, long long>> debug_index;
	public:
		auto makeToken(const char*& pos) -> Token override;
		constexpr auto members() {
			return std::tie();
		}
		constexpr auto members() const {
			return std::tie();
		}
		static constexpr auto members_str() {
			return std::array<std::string_view, 0>{{}};
		}
		constexpr auto methods() {
			return std::make_tuple(&Lexer::makeToken);
		}
		constexpr auto methods() const {
			return std::make_tuple(&Lexer::makeToken);
		}
		static constexpr auto methods_str() {
			return std::array<std::string_view, 1>{{"makeToken"}};
		}
	};
} // namespace Parser
namespace Parser {
	class Parser : public ::ISPA_STD::LRGeneralizedParser<Types::main, Token> {
	public:
		static auto lr_k() -> std::size_t;
		static auto lr_is_space(const Token& token) -> bool;
		static auto lr_space(std::size_t rule, std::size_t gap) -> bool;
		static auto lr_action(std::size_t state, const std::vector<std::size_t>& window) -> long long;
		static auto lr_conflict(std::size_t state, const std::vector<std::size_t>& window) -> std::vector<long long>;
		static auto lr_rule_label(std::size_t rule) -> std::string;
		static auto lr_goto(std::size_t state, std::size_t lhs) -> std::size_t;
		static auto lr_length(std::size_t rule) -> std::size_t;
		static auto lr_lhs(std::size_t rule) -> std::size_t;
		static auto lr_reduce(std::size_t rule, const std::vector<std::any>& values) -> std::any;
		static auto lr_shift(const Token& token) -> std::any;
	protected:
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::Parser::Lexer::lazy_iterator>>> auto main(IT pos) -> ::ISPA_STD::MatchResult<Types::main, IT>;
	public:
		auto parseFromTokens() -> void override;
		auto lazyParse() -> void override;
		constexpr auto members() {
			return std::tie();
		}
		constexpr auto members() const {
			return std::tie();
		}
		static constexpr auto members_str() {
			return std::array<std::string_view, 0>{{}};
		}
		constexpr auto methods() {
			return std::make_tuple(&Parser::lr_k, &Parser::lr_is_space, &Parser::lr_space, &Parser::lr_action, &Parser::lr_conflict, &Parser::lr_rule_label, &Parser::lr_goto, &Parser::lr_length, &Parser::lr_lhs, &Parser::lr_reduce, &Parser::lr_shift, &Parser::parseFromTokens, &Parser::lazyParse);
		}
		constexpr auto methods() const {
			return std::make_tuple(&Parser::lr_k, &Parser::lr_is_space, &Parser::lr_space, &Parser::lr_action, &Parser::lr_conflict, &Parser::lr_rule_label, &Parser::lr_goto, &Parser::lr_length, &Parser::lr_lhs, &Parser::lr_reduce, &Parser::lr_shift, &Parser::parseFromTokens, &Parser::lazyParse);
		}
		static constexpr auto methods_str() {
			return std::array<std::string_view, 13>{{"lr_k", "lr_is_space", "lr_space", "lr_action", "lr_conflict", "lr_rule_label", "lr_goto", "lr_length", "lr_lhs", "lr_reduce", "lr_shift", "parseFromTokens", "lazyParse"}};
		}
	};
} // namespace Parser
