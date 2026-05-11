#ifndef VACPARSER_H
#define VACPARSER_H
#include <string>
#include <vector>
#include <unordered_map>
#include <array>
#include <string>
#include <variant>
#include <optional>
#include <memory>
#include <ispastdlib.hpp>
namespace VacParser {
	enum class Tokens {
		AUTO_2,
		AUTO_8,
		AUTO_3,
		AUTO_4,
		AUTO_13,
		AUTO_6,
		AUTO_1,
		AUTO_12,
		AUTO_5,
		__WHITESPACE,
		AUTO_9,
		AUTO_7,
		AUTO_10,
		AUTO_11,
		STRING,
		ID,
		AUTO_0,
	};
	enum class Rules {
		candidate,
		candidate_declarator,
		alias_alias_value,
		candidate_declarator_value_weight,
		candidate_declarator_value,
		candidate_declarator_value_any,
		alias,
	};
	namespace FlatTypes {
		struct alias;
		struct AUTO_2 {
			 char value;
		};
		struct AUTO_8 {
			 char value;
		};
		struct AUTO_3 {
			 char value;
		};
		struct AUTO_4 {
			 char value;
		};
		struct AUTO_13 {
			 char value;
		};
		struct AUTO_6 {
			 char value;
		};
		struct AUTO_1 {
			 char value;
		};
		struct AUTO_12 {
			 char value;
		};
		struct AUTO_5 {
			 char value;
		};
		struct __WHITESPACE {
		};
		struct AUTO_9 {
			 char value;
		};
		struct AUTO_7 {
			 char value;
		};
		struct AUTO_10 {
			 char value;
		};
		struct AUTO_11 {
			 char value;
		};
		struct STRING {
			 std::string value;
		};
		struct ID {
			 std::string value;
		};
		struct AUTO_0 {
			 char value;
		};
		struct candidate_declarator_value_weight {
			 std::vector<::ISPA_STD::Node<Tokens, AUTO_8>> value;
		};
		struct candidate_declarator_value_any {
			 Undef list;
			 std::variant<::ISPA_STD::Node<Tokens, ID>, ::ISPA_STD::Node<Tokens, STRING>> last;
		};
		struct candidate_declarator_value {
			 std::variant<::ISPA_STD::Node<Tokens, AUTO_1>, ::ISPA_STD::Node<Tokens, AUTO_0>> modifier;
			 std::variant<::ISPA_STD::Node<Tokens, ID>, ::ISPA_STD::Node<Tokens, STRING>, ::ISPA_STD::Node<Rules, candidate_declarator_value_any>> value;
			 ::ISPA_STD::MatchResult<Rules, candidate_declarator_value_weight> weight;
		};
		struct candidate_declarator {
			 ::ISPA_STD::Node<Tokens, ID> type;
			 std::vector<::ISPA_STD::MatchResult<Rules, candidate_declarator_value>> value;
		};
		struct candidate {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 std::vector<::ISPA_STD::MatchResult<Rules, candidate_declarator>> declarator;
		};
		struct alias_alias_value {
			 std::variant<::ISPA_STD::Node<Tokens, ID>, ::ISPA_STD::Node<Tokens, STRING>> value;
			 ::ISPA_STD::MatchResult<Rules, alias_alias_value_candidate_declarator_value_weight> weight;
		};
		struct alias {
			 ::ISPA_STD::Node<Tokens, ID> name;
			 std::vector<::ISPA_STD::MatchResult<Rules, alias_alias_value>> value;
		};
	}
	namespace Types {
		using AUTO_0 = FlatTypes::AUTO_0;
		using AUTO_1 = FlatTypes::AUTO_1;
		using AUTO_10 = FlatTypes::AUTO_10;
		using AUTO_11 = FlatTypes::AUTO_11;
		using AUTO_12 = FlatTypes::AUTO_12;
		using AUTO_13 = FlatTypes::AUTO_13;
		using AUTO_2 = FlatTypes::AUTO_2;
		using AUTO_3 = FlatTypes::AUTO_3;
		using AUTO_4 = FlatTypes::AUTO_4;
		using AUTO_5 = FlatTypes::AUTO_5;
		using AUTO_6 = FlatTypes::AUTO_6;
		using AUTO_7 = FlatTypes::AUTO_7;
		using AUTO_8 = FlatTypes::AUTO_8;
		using AUTO_9 = FlatTypes::AUTO_9;
		using ID = FlatTypes::ID;
		using STRING = FlatTypes::STRING;
		using __WHITESPACE = FlatTypes::__WHITESPACE;
		struct alias : FlatTypes::alias {
			using alias_value = FlatTypes::alias_alias_value;
		};
		struct candidate : FlatTypes::candidate {
			struct declarator : FlatTypes::candidate_declarator {
				struct value : FlatTypes::candidate_declarator_value {
					using any = FlatTypes::candidate_declarator_value_any;
					using weight = FlatTypes::candidate_declarator_value_weight;
				};
			};
		};
	}
	using Token = std::variant<Types::AUTO_2, Types::AUTO_8, Types::AUTO_3, Types::AUTO_4, Types::AUTO_13, Types::AUTO_6, Types::AUTO_1, Types::AUTO_12, Types::AUTO_5, Types::__WHITESPACE, Types::AUTO_9, Types::AUTO_7, Types::AUTO_10, Types::AUTO_11, Types::STRING, Types::ID, Types::AUTO_0, Types::AUTO_2, Types::AUTO_8, Types::AUTO_3, Types::AUTO_4, Types::AUTO_13, Types::AUTO_6, Types::AUTO_1, Types::AUTO_12, Types::AUTO_5, Types::__WHITESPACE, Types::AUTO_9, Types::AUTO_7, Types::AUTO_10, Types::AUTO_11, Types::STRING, Types::ID, Types::AUTO_0>;
	class Lexer : public ::ISPA_STD::Lexer_base<Tokens, Token> {
		static ::ISPA_STD::DFAAPI::CharState dfa_state_0;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_1;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_2;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_3;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_4;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_5;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_6;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_7;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_8;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_9;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_10;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_11;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_12;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_13;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_14;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_15;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_16;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_17;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_18;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_19;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_20;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_21;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_22;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_23;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_24;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_25;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_26;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_27;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_28;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_29;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_30;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_31;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_32;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_33;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_34;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_35;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_36;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_37;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_38;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_39;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_40;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_41;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_42;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_43;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_44;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_45;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_46;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_47;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_48;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_49;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_50;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_51;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_52;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_53;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_54;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_55;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_56;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_57;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_58;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_59;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_60;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_61;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_62;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_63;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_64;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_65;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_66;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_67;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_68;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_69;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_70;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_71;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_72;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_73;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_74;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_75;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_76;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_77;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_78;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_79;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_80;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_81;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_82;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_83;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_84;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_85;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_86;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_87;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_88;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_89;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_90;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_91;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_92;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_93;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_94;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_95;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_96;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_97;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_98;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_99;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_100;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_101;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_102;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_103;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_104;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_105;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_106;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_107;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_108;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_109;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_110;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_111;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_112;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_113;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_114;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_115;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_116;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_117;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_118;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_119;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_120;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_121;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_122;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_123;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_124;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_125;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_126;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_127;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_128;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_129;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_130;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_131;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_132;
		static ::ISPA_STD::DFAAPI::MultiTableState<Tokens, Token, 0> dfa_state_133;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_134;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_135;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_136;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_137;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_138;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_139;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_140;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_141;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_142;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_143;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_144;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_145;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_146;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_147;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_148;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_149;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_150;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_151;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_152;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_153;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_154;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_155;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_156;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_157;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_158;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_159;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_160;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_161;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_162;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_163;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_164;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_165;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_166;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_167;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_168;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_169;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_170;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_171;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_172;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_173;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_174;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_175;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_176;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_177;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_178;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_179;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_180;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_181;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_182;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_183;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_184;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_185;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_186;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_187;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_188;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_189;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_190;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_191;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_192;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_193;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_194;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_195;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_196;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_197;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_198;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_199;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_200;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_201;
		static ::ISPA_STD::DFAAPI::CharState dfa_state_202;
		static ::ISPA_STD::DFAAPI::EmptyState<Tokens, Token> dfa_state_203;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 261> dfa_table_0;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_1;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_2;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_3;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_4;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_5;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_6;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 4> dfa_table_7;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 11> dfa_table_8;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 13> dfa_table_9;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 9> dfa_table_10;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 11> dfa_table_11;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 10> dfa_table_12;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_13;
		static ::ISPA_STD::DFAAPI::CharTable<Tokens, Token, 2> dfa_table_14;
	};
}
#endif // VACPARSER_H
