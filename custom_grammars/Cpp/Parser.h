#pragma once
#ifndef PARSER
#define PARSER

#include <string>
#include <unordered_map>
#include <iterator>
#include <array>
#include <memory>
#include <ispastdlib.hpp>
#ifndef PARSER_OBJ_TYPE
#define PARSER_OBJ_TYPE std::unordered_map
#endif
#ifndef PARSER_ARR_TYPE
#define PARSER_ARR_TYPE std::vector
#endif
#ifndef PARSER_ANY_TYPE
#define PARSER_ANY_TYPE std::any
#endif
#ifndef PARSER_NUM_TYPE
#define PARSER_NUM_TYPE double
#endif
#ifndef PARSER_STR_TYPE
#define PARSER_STR_TYPE std::string
#endif
#ifndef PARSER_BOOL_TYPE
#define PARSER_BOOL_TYPE bool
#endif
namespace Parser {
	using str_t = PARSER_STR_TYPE;
	using num_t = PARSER_NUM_TYPE;
	using bool_t = PARSER_BOOL_TYPE;
	using any_t = PARSER_ANY_TYPE;
	template<typename T>
	using arr_t = PARSER_ARR_TYPE<T>;
	template<typename Key, typename Value>
	using obj_t = PARSER_OBJ_TYPE<Key, Value>;
	enum class Tokens {
		NONE, AUTO_24, AUTO_23, AUTO_22, AUTO_20, AUTO_19, AUTO_11, AUTO_8, AUTO_6, AUTO_2, AUTO_0, CARET, GREATEREQUAL, SIZEOF, NOT, MINUS, PLUS, MOD, STAR, DOT, ALIGNOF, ASSIGN, OR, AND, AUTO_1, AUTO_21, expression_assignment_assignmentOp_AND, DIV, expression_assignment_assignmentOp_XOR, expression_assignment_assignmentOp_MINUS, expression_assignment_assignmentOp_PLUS, AUTO_12, expression_assignment_assignmentOp_DIV, expression_assignment_assignmentOp_LEFTSHIFT, TILDE, AUTO_5, expression_assignment_assignmentOp_RIGHTSHIFT, expression_assignment_assignmentOp_MOD, expression_equality_NOTEQUAL, AUTO_15, AUTO_3, expression_equality_EQUAL, AUTO_16, ID, expression_unaryExpression_prefixUnaryExpression_UNARYOPERATOR, AUTO_14, __WHITESPACE, AUTO_13, AUTO_9, GREATER, expression_assignment_assignmentOp_ASSIGN, LESS, AUTO_10, AUTO_17, ARROW, AUTO_7, DOTSTAR, expression_assignment_assignmentOp_OR, ARROWSTAR, AUTO_18, expression_assignment_assignmentOp_STAR, AUTO_4, LESSEQUAL
	};
	enum class Rules {
		NONE, literal, bracedInitList, typeSpecifierSeq, typeNameSpecifier, initializerList, trailingReturnType, parameterDeclarationClause, expression_throw, initializerClause, expression_cast, operatorFunctionId, templateId, expression_new_declarator, expression_shift, expression_assignment_assignmentOp, className, expression_assignment_assign, decltypeSpecifier, expression_assignment, expression_postfixExpression_postfixIncrementDecrement, expression_conditional, theTypeName, expression_logicalAnd, expression_lambda_introducer_capture_captureList_capture, expression_exclusiveOr, expression_qualifiedId_nestedNameSpecifier_templ, newDeclarator, compoundStatement, conversionFunctionId, expression__and, namespaceName, expression_relational, expression_additive, expression_qualifiedId, expression_unaryExpression_alignof, expression_pointerMember, expression_cast_parentheses, attributeSpecifierSeq, literalOperatorId, expression_shift_shiftOp, expression_new_initializer_parenthesesList, expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorParen, expression, expression_equality, expression_multiplicative, expression_lambda_introducer_capture_captureList_capture_initcapture, expression_new_declarator_pointerOperatorWithNewDeclarator, expression_new_initializer, expression_inclusiveOr, expression_delete, expression_new_placement, expression_new, expression_noExcept, expression_pseudoDestructorName_pseudoDestructorCore, simpleTypeSpecifier, expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorArray, expression_pseudoDestructorName_pseudoDestructorName1, expression_new_typeId, expression_pseudoDestructorName, expression_postfixExpression_typeConstructionArguments, expression_unaryExpression, expression_postfixExpression_typeidExpression, expression_postfixExpression_castExpression, expression_new_declarator_noPointerNewDeclarator, expression_unqualifiedId, expression_postfixExpression_memberAccessTarget, expression_postfixExpression_memberAccess, theTypeId, expression_postfixExpression, expression_postfixExpression_typeConstruction, expression_postfixExpression_functionCallArguments, expression_unaryExpression_sizeof, expression_new_bracedTypeId, expression_lambda_introducer_capture_captureList_capture_simpleCapture, expression_lambda_declarator, expression_postfixExpression_functionCall, expression_logicalOr, expression_pseudoDestructorName_pseudoDestructorName3, expression_expressionList, exceptionSpecification, expression_lambda_introducer_capture_captureList, expression_lambda_introducer, expression_unaryExpression_prefixUnaryExpression, expression_lambda_introducer_capture_captureList_capture_simpleCapture_name, pointerOperator, expression_constant, expression_pseudoDestructorName_pseudoDestructorName2, simpleTemplateId, expression_lambda, expression_unqualifiedId_destructor, expression_qualifiedId_nestedNameSpecifier, expression_lambda_introducer_capture_captureDefault, expression_unaryExpression_sizeofArgument, expression_idExpression, expression_group, expression_lambda_introducer_capture, expression_primary, initializer, expression_lambda_introducer_capture_list
	};
	using Rule = ISPA_STD::Node<Rules>;
	using Rule_res = ISPA_STD::match_result<Rules>;
	using Token = ISPA_STD::Node<Tokens>;
	using Token_res = ISPA_STD::match_result<Tokens>;
	using TokenFlow = ISPA_STD::TokenFlow<Tokens>;
	using RuleSeq = ISPA_STD::Seq<Rules>;
	using TokenSeq = ISPA_STD::Seq<Tokens>;
	constexpr const char* TokensToString(Tokens token) {
		switch (token) {
			case Tokens::NONE: return "NONE";
			case Tokens::AUTO_24: return "AUTO_24";
			case Tokens::AUTO_23: return "AUTO_23";
			case Tokens::AUTO_22: return "AUTO_22";
			case Tokens::AUTO_20: return "AUTO_20";
			case Tokens::AUTO_19: return "AUTO_19";
			case Tokens::AUTO_11: return "AUTO_11";
			case Tokens::AUTO_8: return "AUTO_8";
			case Tokens::AUTO_6: return "AUTO_6";
			case Tokens::AUTO_2: return "AUTO_2";
			case Tokens::AUTO_0: return "AUTO_0";
			case Tokens::CARET: return "CARET";
			case Tokens::GREATEREQUAL: return "GREATEREQUAL";
			case Tokens::SIZEOF: return "SIZEOF";
			case Tokens::NOT: return "NOT";
			case Tokens::MINUS: return "MINUS";
			case Tokens::PLUS: return "PLUS";
			case Tokens::MOD: return "MOD";
			case Tokens::STAR: return "STAR";
			case Tokens::DOT: return "DOT";
			case Tokens::ALIGNOF: return "ALIGNOF";
			case Tokens::ASSIGN: return "ASSIGN";
			case Tokens::OR: return "OR";
			case Tokens::AND: return "AND";
			case Tokens::AUTO_1: return "AUTO_1";
			case Tokens::AUTO_21: return "AUTO_21";
			case Tokens::expression_assignment_assignmentOp_AND: return "expression_assignment_assignmentOp_AND";
			case Tokens::DIV: return "DIV";
			case Tokens::expression_assignment_assignmentOp_XOR: return "expression_assignment_assignmentOp_XOR";
			case Tokens::expression_assignment_assignmentOp_MINUS: return "expression_assignment_assignmentOp_MINUS";
			case Tokens::expression_assignment_assignmentOp_PLUS: return "expression_assignment_assignmentOp_PLUS";
			case Tokens::AUTO_12: return "AUTO_12";
			case Tokens::expression_assignment_assignmentOp_DIV: return "expression_assignment_assignmentOp_DIV";
			case Tokens::expression_assignment_assignmentOp_LEFTSHIFT: return "expression_assignment_assignmentOp_LEFTSHIFT";
			case Tokens::TILDE: return "TILDE";
			case Tokens::AUTO_5: return "AUTO_5";
			case Tokens::expression_assignment_assignmentOp_RIGHTSHIFT: return "expression_assignment_assignmentOp_RIGHTSHIFT";
			case Tokens::expression_assignment_assignmentOp_MOD: return "expression_assignment_assignmentOp_MOD";
			case Tokens::expression_equality_NOTEQUAL: return "expression_equality_NOTEQUAL";
			case Tokens::AUTO_15: return "AUTO_15";
			case Tokens::AUTO_3: return "AUTO_3";
			case Tokens::expression_equality_EQUAL: return "expression_equality_EQUAL";
			case Tokens::AUTO_16: return "AUTO_16";
			case Tokens::ID: return "ID";
			case Tokens::expression_unaryExpression_prefixUnaryExpression_UNARYOPERATOR: return "expression_unaryExpression_prefixUnaryExpression_UNARYOPERATOR";
			case Tokens::AUTO_14: return "AUTO_14";
			case Tokens::__WHITESPACE: return "__WHITESPACE";
			case Tokens::AUTO_13: return "AUTO_13";
			case Tokens::AUTO_9: return "AUTO_9";
			case Tokens::GREATER: return "GREATER";
			case Tokens::expression_assignment_assignmentOp_ASSIGN: return "expression_assignment_assignmentOp_ASSIGN";
			case Tokens::LESS: return "LESS";
			case Tokens::AUTO_10: return "AUTO_10";
			case Tokens::AUTO_17: return "AUTO_17";
			case Tokens::ARROW: return "ARROW";
			case Tokens::AUTO_7: return "AUTO_7";
			case Tokens::DOTSTAR: return "DOTSTAR";
			case Tokens::expression_assignment_assignmentOp_OR: return "expression_assignment_assignmentOp_OR";
			case Tokens::ARROWSTAR: return "ARROWSTAR";
			case Tokens::AUTO_18: return "AUTO_18";
			case Tokens::expression_assignment_assignmentOp_STAR: return "expression_assignment_assignmentOp_STAR";
			case Tokens::AUTO_4: return "AUTO_4";
			case Tokens::LESSEQUAL: return "LESSEQUAL";
		}
		return "NONE";
	}
	constexpr const char* RulesToString(Rules rule) {
		switch (rule) {
			case Rules::NONE: return "NONE";
			case Rules::literal: return "literal";
			case Rules::bracedInitList: return "bracedInitList";
			case Rules::typeSpecifierSeq: return "typeSpecifierSeq";
			case Rules::typeNameSpecifier: return "typeNameSpecifier";
			case Rules::initializerList: return "initializerList";
			case Rules::trailingReturnType: return "trailingReturnType";
			case Rules::parameterDeclarationClause: return "parameterDeclarationClause";
			case Rules::expression_throw: return "expression_throw";
			case Rules::initializerClause: return "initializerClause";
			case Rules::expression_cast: return "expression_cast";
			case Rules::operatorFunctionId: return "operatorFunctionId";
			case Rules::templateId: return "templateId";
			case Rules::expression_new_declarator: return "expression_new_declarator";
			case Rules::expression_shift: return "expression_shift";
			case Rules::expression_assignment_assignmentOp: return "expression_assignment_assignmentOp";
			case Rules::className: return "className";
			case Rules::expression_assignment_assign: return "expression_assignment_assign";
			case Rules::decltypeSpecifier: return "decltypeSpecifier";
			case Rules::expression_assignment: return "expression_assignment";
			case Rules::expression_postfixExpression_postfixIncrementDecrement: return "expression_postfixExpression_postfixIncrementDecrement";
			case Rules::expression_conditional: return "expression_conditional";
			case Rules::theTypeName: return "theTypeName";
			case Rules::expression_logicalAnd: return "expression_logicalAnd";
			case Rules::expression_lambda_introducer_capture_captureList_capture: return "expression_lambda_introducer_capture_captureList_capture";
			case Rules::expression_exclusiveOr: return "expression_exclusiveOr";
			case Rules::expression_qualifiedId_nestedNameSpecifier_templ: return "expression_qualifiedId_nestedNameSpecifier_templ";
			case Rules::newDeclarator: return "newDeclarator";
			case Rules::compoundStatement: return "compoundStatement";
			case Rules::conversionFunctionId: return "conversionFunctionId";
			case Rules::expression__and: return "expression__and";
			case Rules::namespaceName: return "namespaceName";
			case Rules::expression_relational: return "expression_relational";
			case Rules::expression_additive: return "expression_additive";
			case Rules::expression_qualifiedId: return "expression_qualifiedId";
			case Rules::expression_unaryExpression_alignof: return "expression_unaryExpression_alignof";
			case Rules::expression_pointerMember: return "expression_pointerMember";
			case Rules::expression_cast_parentheses: return "expression_cast_parentheses";
			case Rules::attributeSpecifierSeq: return "attributeSpecifierSeq";
			case Rules::literalOperatorId: return "literalOperatorId";
			case Rules::expression_shift_shiftOp: return "expression_shift_shiftOp";
			case Rules::expression_new_initializer_parenthesesList: return "expression_new_initializer_parenthesesList";
			case Rules::expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorParen: return "expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorParen";
			case Rules::expression: return "expression";
			case Rules::expression_equality: return "expression_equality";
			case Rules::expression_multiplicative: return "expression_multiplicative";
			case Rules::expression_lambda_introducer_capture_captureList_capture_initcapture: return "expression_lambda_introducer_capture_captureList_capture_initcapture";
			case Rules::expression_new_declarator_pointerOperatorWithNewDeclarator: return "expression_new_declarator_pointerOperatorWithNewDeclarator";
			case Rules::expression_new_initializer: return "expression_new_initializer";
			case Rules::expression_inclusiveOr: return "expression_inclusiveOr";
			case Rules::expression_delete: return "expression_delete";
			case Rules::expression_new_placement: return "expression_new_placement";
			case Rules::expression_new: return "expression_new";
			case Rules::expression_noExcept: return "expression_noExcept";
			case Rules::expression_pseudoDestructorName_pseudoDestructorCore: return "expression_pseudoDestructorName_pseudoDestructorCore";
			case Rules::simpleTypeSpecifier: return "simpleTypeSpecifier";
			case Rules::expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorArray: return "expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorArray";
			case Rules::expression_pseudoDestructorName_pseudoDestructorName1: return "expression_pseudoDestructorName_pseudoDestructorName1";
			case Rules::expression_new_typeId: return "expression_new_typeId";
			case Rules::expression_pseudoDestructorName: return "expression_pseudoDestructorName";
			case Rules::expression_postfixExpression_typeConstructionArguments: return "expression_postfixExpression_typeConstructionArguments";
			case Rules::expression_unaryExpression: return "expression_unaryExpression";
			case Rules::expression_postfixExpression_typeidExpression: return "expression_postfixExpression_typeidExpression";
			case Rules::expression_postfixExpression_castExpression: return "expression_postfixExpression_castExpression";
			case Rules::expression_new_declarator_noPointerNewDeclarator: return "expression_new_declarator_noPointerNewDeclarator";
			case Rules::expression_unqualifiedId: return "expression_unqualifiedId";
			case Rules::expression_postfixExpression_memberAccessTarget: return "expression_postfixExpression_memberAccessTarget";
			case Rules::expression_postfixExpression_memberAccess: return "expression_postfixExpression_memberAccess";
			case Rules::theTypeId: return "theTypeId";
			case Rules::expression_postfixExpression: return "expression_postfixExpression";
			case Rules::expression_postfixExpression_typeConstruction: return "expression_postfixExpression_typeConstruction";
			case Rules::expression_postfixExpression_functionCallArguments: return "expression_postfixExpression_functionCallArguments";
			case Rules::expression_unaryExpression_sizeof: return "expression_unaryExpression_sizeof";
			case Rules::expression_new_bracedTypeId: return "expression_new_bracedTypeId";
			case Rules::expression_lambda_introducer_capture_captureList_capture_simpleCapture: return "expression_lambda_introducer_capture_captureList_capture_simpleCapture";
			case Rules::expression_lambda_declarator: return "expression_lambda_declarator";
			case Rules::expression_postfixExpression_functionCall: return "expression_postfixExpression_functionCall";
			case Rules::expression_logicalOr: return "expression_logicalOr";
			case Rules::expression_pseudoDestructorName_pseudoDestructorName3: return "expression_pseudoDestructorName_pseudoDestructorName3";
			case Rules::expression_expressionList: return "expression_expressionList";
			case Rules::exceptionSpecification: return "exceptionSpecification";
			case Rules::expression_lambda_introducer_capture_captureList: return "expression_lambda_introducer_capture_captureList";
			case Rules::expression_lambda_introducer: return "expression_lambda_introducer";
			case Rules::expression_unaryExpression_prefixUnaryExpression: return "expression_unaryExpression_prefixUnaryExpression";
			case Rules::expression_lambda_introducer_capture_captureList_capture_simpleCapture_name: return "expression_lambda_introducer_capture_captureList_capture_simpleCapture_name";
			case Rules::pointerOperator: return "pointerOperator";
			case Rules::expression_constant: return "expression_constant";
			case Rules::expression_pseudoDestructorName_pseudoDestructorName2: return "expression_pseudoDestructorName_pseudoDestructorName2";
			case Rules::simpleTemplateId: return "simpleTemplateId";
			case Rules::expression_lambda: return "expression_lambda";
			case Rules::expression_unqualifiedId_destructor: return "expression_unqualifiedId_destructor";
			case Rules::expression_qualifiedId_nestedNameSpecifier: return "expression_qualifiedId_nestedNameSpecifier";
			case Rules::expression_lambda_introducer_capture_captureDefault: return "expression_lambda_introducer_capture_captureDefault";
			case Rules::expression_unaryExpression_sizeofArgument: return "expression_unaryExpression_sizeofArgument";
			case Rules::expression_idExpression: return "expression_idExpression";
			case Rules::expression_group: return "expression_group";
			case Rules::expression_lambda_introducer_capture: return "expression_lambda_introducer_capture";
			case Rules::expression_primary: return "expression_primary";
			case Rules::initializer: return "initializer";
			case Rules::expression_lambda_introducer_capture_list: return "expression_lambda_introducer_capture_list";
		}
		return "NONE";
	}
	namespace Types {
		struct expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorParen {
			::Parser::Rule expr;
			::Parser::Rule attrSpecSeq;
		};
		struct expression_postfixExpression_postfixIncrementDecrement {
			::Parser::Rule expr;
			::Parser::Token op;
		};
		using expression_new_declarator_noPointerNewDeclarator = ::Parser::Rule;
		using expression_unqualifiedId = ::Parser::any_t;
		using expression_throw = ::Parser::Rule;
		using expression_new_declarator = ::Parser::Rule;
		using expression_new_initializer = ::Parser::Rule;
		struct expression_shift {
			::Parser::Rule additive;
			::Parser::arr_t<::Parser::Rule> shiftOp;
		};
		using expression_assignment_assignmentOp = ::Parser::Token;
		struct expression_assignment_assign {
			::Parser::Rule logicalOr;
			::Parser::Rule assignmentOp;
			::Parser::Rule initializerClause;
		};
		struct expression_cast_parentheses {
			::Parser::Rule type;
			::Parser::Rule cast;
		};
		using expression_assignment = ::Parser::Rule;
		struct expression_conditional {
			::Parser::Rule logicalOr;
			::Parser::Rule first;
			::Parser::Rule second;
		};
		struct expression_logicalAnd {
			::Parser::Rule inclusive;
			::Parser::arr_t<::Parser::Rule> inclusives;
		};
		using expression_constant = ::Parser::Rule;
		struct expression_exclusiveOr {
			::Parser::Rule andExpr;
			::Parser::arr_t<::Parser::Rule> andExpressions;
		};
		using expression_lambda_introducer_capture_captureList_capture = ::Parser::Rule;
		struct expression_lambda {
			::Parser::Rule introducer;
			::Parser::Rule declarator;
			::Parser::Rule stmt;
		};
		using expression_qualifiedId_nestedNameSpecifier_templ = ::Parser::Rule;
		struct expression__and {
			::Parser::Rule equality;
			::Parser::arr_t<::Parser::Rule> equalities;
		};
		struct expression_relational {
			::Parser::Rule shift;
			::Parser::Token ops;
			::Parser::arr_t<::Parser::Rule> shifts;
		};
		struct expression_additive {
			::Parser::Rule multi;
			::Parser::Token operators;
		};
		struct expression_qualifiedId {
			::Parser::Rule name;
			::Parser::Rule uid;
		};
		struct expression_pointerMember {
			::Parser::Rule first_cast;
			::Parser::Rule second_cast;
			::Parser::Token sep;
		};
		using expression_unaryExpression_alignof = ::Parser::Rule;
		using expression_expressionList = ::Parser::Rule;
		using expression_shift_shiftOp = ::Parser::Token;
		using expression_cast = ::Parser::Rule;
		using expression_new_initializer_parenthesesList = ::Parser::Rule;
		struct expression_new_declarator_pointerOperatorWithNewDeclarator {
			::Parser::Rule pointerOp;
			::Parser::Rule decl;
		};
		struct expression_lambda_introducer_capture_captureList_capture_initcapture {
			::Parser::Token ref;
			::Parser::Token id;
			::Parser::Rule initializer;
		};
		struct expression_equality {
			::Parser::Rule rel;
			::Parser::Token ops;
			::Parser::arr_t<::Parser::Rule> rels;
		};
		struct expression {
			::Parser::Rule assignmentExpr;
			::Parser::arr_t<::Parser::Rule> assignmentExpressions;
		};
		struct expression_multiplicative {
			::Parser::Rule pointerMember;
			::Parser::arr_t<::Parser::Rule> pointerMembers;
			::Parser::Token operators;
		};
		struct expression_inclusiveOr {
			::Parser::Rule exclusive;
			::Parser::arr_t<::Parser::Rule> exclusives;
		};
		struct expression_delete {
			::Parser::Token braces;
			::Parser::Rule castExpr;
		};
		using expression_new_placement = ::Parser::Rule;
		struct expression_new {
			::Parser::Token prefix;
			::Parser::Rule placement;
			::Parser::Rule typeId;
			::Parser::Rule initializer;
		};
		using expression_noExcept = ::Parser::Rule;
		struct expression_pseudoDestructorName_pseudoDestructorCore {
			::Parser::Rule prefix_type;
			::Parser::Rule postfix_type;
		};
		struct expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorArray {
			::Parser::Rule noPointerNewDeclarator;
			::Parser::Rule constExpr;
			::Parser::Rule attrSpecSeq;
		};
		struct expression_pseudoDestructorName_pseudoDestructorName1 {
			::Parser::Rule specifier;
			::Parser::Rule destructorCore;
		};
		using expression_new_typeId = ::Parser::Rule;
		using expression_pseudoDestructorName = ::Parser::Rule;
		using expression_postfixExpression_typeConstructionArguments = ::Parser::Rule;
		using expression_unaryExpression = ::Parser::Rule;
		using expression_postfixExpression_typeidExpression = ::Parser::Rule;
		struct expression_postfixExpression_castExpression {
			::Parser::Token cast;
			::Parser::Rule type;
			::Parser::Rule expr;
		};
		struct expression_postfixExpression_memberAccess {
			::Parser::Rule postfix;
			::Parser::Token sep;
			::Parser::Rule target;
		};
		using expression_postfixExpression_memberAccessTarget = ::Parser::Rule;
		using expression_postfixExpression = ::Parser::Rule;
		struct expression_postfixExpression_typeConstruction {
			::Parser::Rule type;
			::Parser::Rule args;
		};
		using expression_postfixExpression_functionCallArguments = ::Parser::any_t;
		using expression_unaryExpression_sizeof = ::Parser::Rule;
		using expression_new_bracedTypeId = ::Parser::Rule;
		using expression_lambda_introducer_capture_captureList_capture_simpleCapture = ::Parser::any_t;
		struct expression_lambda_declarator {
			::Parser::Rule parameter;
			::Parser::Token mutable;
			::Parser::Rule return_type;
			::Parser::Rule exceptionSpec;
			::Parser::Rule attributes;
		};
		struct expression_postfixExpression_functionCall {
			::Parser::Rule postfixExpr;
			::Parser::Rule funCallArgs;
		};
		using expression_pseudoDestructorName_pseudoDestructorName3 = ::Parser::Rule;
		struct expression_logicalOr {
			::Parser::Rule logicalAnd;
			::Parser::arr_t<::Parser::Rule> logicalAnds;
		};
		struct expression_lambda_introducer_capture_captureList {
			::Parser::Rule capture;
			::Parser::arr_t<::Parser::Rule> captureList;
			::Parser::Token ellipsis;
		};
		using expression_lambda_introducer = ::Parser::Rule;
		struct expression_lambda_introducer_capture_captureList_capture_simpleCapture_name {
			::Parser::Token ref;
			::Parser::Token id;
		};
		struct expression_unaryExpression_prefixUnaryExpression {
			::Parser::Token op;
			::Parser::Rule expr;
		};
		struct expression_pseudoDestructorName_pseudoDestructorName2 {
			::Parser::Rule specifier;
			::Parser::Rule templateId;
			::Parser::Rule type;
		};
		using expression_unqualifiedId_destructor = ::Parser::Rule;
		using expression_qualifiedId_nestedNameSpecifier = ::Parser::any_t;
		using expression_lambda_introducer_capture_captureDefault = ::Parser::Token;
		using expression_unaryExpression_sizeofArgument = ::Parser::any_t;
		using expression_idExpression = ::Parser::Rule;
		using expression_group = ::Parser::Rule;
		using expression_lambda_introducer_capture = ::Parser::Rule;
		using expression_primary = ::Parser::any_t;
		struct expression_lambda_introducer_capture_list {
			::Parser::Rule def;
			::Parser::Rule captureList;
		};
	}

	namespace get {
		const ::Parser::Types::expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorParen& expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorParen(const ::Parser::Rule &rule);
		::Parser::Types::expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorParen& expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorParen(::Parser::Rule &rule);
		const ::Parser::Types::expression_postfixExpression_postfixIncrementDecrement& expression_postfixExpression_postfixIncrementDecrement(const ::Parser::Rule &rule);
		::Parser::Types::expression_postfixExpression_postfixIncrementDecrement& expression_postfixExpression_postfixIncrementDecrement(::Parser::Rule &rule);
		const ::Parser::Types::expression_new_declarator_noPointerNewDeclarator& expression_new_declarator_noPointerNewDeclarator(const ::Parser::Rule &rule);
		::Parser::Types::expression_new_declarator_noPointerNewDeclarator& expression_new_declarator_noPointerNewDeclarator(::Parser::Rule &rule);
		const ::Parser::Types::expression_unqualifiedId& expression_unqualifiedId(const ::Parser::Rule &rule);
		::Parser::Types::expression_unqualifiedId& expression_unqualifiedId(::Parser::Rule &rule);
		const ::Parser::Types::expression_throw& expression_throw(const ::Parser::Rule &rule);
		::Parser::Types::expression_throw& expression_throw(::Parser::Rule &rule);
		const ::Parser::Types::expression_new_declarator& expression_new_declarator(const ::Parser::Rule &rule);
		::Parser::Types::expression_new_declarator& expression_new_declarator(::Parser::Rule &rule);
		const ::Parser::Types::expression_new_initializer& expression_new_initializer(const ::Parser::Rule &rule);
		::Parser::Types::expression_new_initializer& expression_new_initializer(::Parser::Rule &rule);
		const ::Parser::Types::expression_shift& expression_shift(const ::Parser::Rule &rule);
		::Parser::Types::expression_shift& expression_shift(::Parser::Rule &rule);
		const ::Parser::Types::expression_assignment_assignmentOp& expression_assignment_assignmentOp(const ::Parser::Rule &rule);
		::Parser::Types::expression_assignment_assignmentOp& expression_assignment_assignmentOp(::Parser::Rule &rule);
		const ::Parser::Types::expression_assignment_assign& expression_assignment_assign(const ::Parser::Rule &rule);
		::Parser::Types::expression_assignment_assign& expression_assignment_assign(::Parser::Rule &rule);
		const ::Parser::Types::expression_cast_parentheses& expression_cast_parentheses(const ::Parser::Rule &rule);
		::Parser::Types::expression_cast_parentheses& expression_cast_parentheses(::Parser::Rule &rule);
		const ::Parser::Types::expression_assignment& expression_assignment(const ::Parser::Rule &rule);
		::Parser::Types::expression_assignment& expression_assignment(::Parser::Rule &rule);
		const ::Parser::Types::expression_conditional& expression_conditional(const ::Parser::Rule &rule);
		::Parser::Types::expression_conditional& expression_conditional(::Parser::Rule &rule);
		const ::Parser::Types::expression_logicalAnd& expression_logicalAnd(const ::Parser::Rule &rule);
		::Parser::Types::expression_logicalAnd& expression_logicalAnd(::Parser::Rule &rule);
		const ::Parser::Types::expression_constant& expression_constant(const ::Parser::Rule &rule);
		::Parser::Types::expression_constant& expression_constant(::Parser::Rule &rule);
		const ::Parser::Types::expression_exclusiveOr& expression_exclusiveOr(const ::Parser::Rule &rule);
		::Parser::Types::expression_exclusiveOr& expression_exclusiveOr(::Parser::Rule &rule);
		const ::Parser::Types::expression_lambda_introducer_capture_captureList_capture& expression_lambda_introducer_capture_captureList_capture(const ::Parser::Rule &rule);
		::Parser::Types::expression_lambda_introducer_capture_captureList_capture& expression_lambda_introducer_capture_captureList_capture(::Parser::Rule &rule);
		const ::Parser::Types::expression_lambda& expression_lambda(const ::Parser::Rule &rule);
		::Parser::Types::expression_lambda& expression_lambda(::Parser::Rule &rule);
		const ::Parser::Types::expression_qualifiedId_nestedNameSpecifier_templ& expression_qualifiedId_nestedNameSpecifier_templ(const ::Parser::Rule &rule);
		::Parser::Types::expression_qualifiedId_nestedNameSpecifier_templ& expression_qualifiedId_nestedNameSpecifier_templ(::Parser::Rule &rule);
		const ::Parser::Types::expression__and& expression__and(const ::Parser::Rule &rule);
		::Parser::Types::expression__and& expression__and(::Parser::Rule &rule);
		const ::Parser::Types::expression_relational& expression_relational(const ::Parser::Rule &rule);
		::Parser::Types::expression_relational& expression_relational(::Parser::Rule &rule);
		const ::Parser::Types::expression_additive& expression_additive(const ::Parser::Rule &rule);
		::Parser::Types::expression_additive& expression_additive(::Parser::Rule &rule);
		const ::Parser::Types::expression_qualifiedId& expression_qualifiedId(const ::Parser::Rule &rule);
		::Parser::Types::expression_qualifiedId& expression_qualifiedId(::Parser::Rule &rule);
		const ::Parser::Types::expression_pointerMember& expression_pointerMember(const ::Parser::Rule &rule);
		::Parser::Types::expression_pointerMember& expression_pointerMember(::Parser::Rule &rule);
		const ::Parser::Types::expression_unaryExpression_alignof& expression_unaryExpression_alignof(const ::Parser::Rule &rule);
		::Parser::Types::expression_unaryExpression_alignof& expression_unaryExpression_alignof(::Parser::Rule &rule);
		const ::Parser::Types::expression_expressionList& expression_expressionList(const ::Parser::Rule &rule);
		::Parser::Types::expression_expressionList& expression_expressionList(::Parser::Rule &rule);
		const ::Parser::Types::expression_shift_shiftOp& expression_shift_shiftOp(const ::Parser::Rule &rule);
		::Parser::Types::expression_shift_shiftOp& expression_shift_shiftOp(::Parser::Rule &rule);
		const ::Parser::Types::expression_cast& expression_cast(const ::Parser::Rule &rule);
		::Parser::Types::expression_cast& expression_cast(::Parser::Rule &rule);
		const ::Parser::Types::expression_new_initializer_parenthesesList& expression_new_initializer_parenthesesList(const ::Parser::Rule &rule);
		::Parser::Types::expression_new_initializer_parenthesesList& expression_new_initializer_parenthesesList(::Parser::Rule &rule);
		const ::Parser::Types::expression_new_declarator_pointerOperatorWithNewDeclarator& expression_new_declarator_pointerOperatorWithNewDeclarator(const ::Parser::Rule &rule);
		::Parser::Types::expression_new_declarator_pointerOperatorWithNewDeclarator& expression_new_declarator_pointerOperatorWithNewDeclarator(::Parser::Rule &rule);
		const ::Parser::Types::expression_lambda_introducer_capture_captureList_capture_initcapture& expression_lambda_introducer_capture_captureList_capture_initcapture(const ::Parser::Rule &rule);
		::Parser::Types::expression_lambda_introducer_capture_captureList_capture_initcapture& expression_lambda_introducer_capture_captureList_capture_initcapture(::Parser::Rule &rule);
		const ::Parser::Types::expression_equality& expression_equality(const ::Parser::Rule &rule);
		::Parser::Types::expression_equality& expression_equality(::Parser::Rule &rule);
		const ::Parser::Types::expression& expression(const ::Parser::Rule &rule);
		::Parser::Types::expression& expression(::Parser::Rule &rule);
		const ::Parser::Types::expression_multiplicative& expression_multiplicative(const ::Parser::Rule &rule);
		::Parser::Types::expression_multiplicative& expression_multiplicative(::Parser::Rule &rule);
		const ::Parser::Types::expression_inclusiveOr& expression_inclusiveOr(const ::Parser::Rule &rule);
		::Parser::Types::expression_inclusiveOr& expression_inclusiveOr(::Parser::Rule &rule);
		const ::Parser::Types::expression_delete& expression_delete(const ::Parser::Rule &rule);
		::Parser::Types::expression_delete& expression_delete(::Parser::Rule &rule);
		const ::Parser::Types::expression_new_placement& expression_new_placement(const ::Parser::Rule &rule);
		::Parser::Types::expression_new_placement& expression_new_placement(::Parser::Rule &rule);
		const ::Parser::Types::expression_new& expression_new(const ::Parser::Rule &rule);
		::Parser::Types::expression_new& expression_new(::Parser::Rule &rule);
		const ::Parser::Types::expression_noExcept& expression_noExcept(const ::Parser::Rule &rule);
		::Parser::Types::expression_noExcept& expression_noExcept(::Parser::Rule &rule);
		const ::Parser::Types::expression_pseudoDestructorName_pseudoDestructorCore& expression_pseudoDestructorName_pseudoDestructorCore(const ::Parser::Rule &rule);
		::Parser::Types::expression_pseudoDestructorName_pseudoDestructorCore& expression_pseudoDestructorName_pseudoDestructorCore(::Parser::Rule &rule);
		const ::Parser::Types::expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorArray& expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorArray(const ::Parser::Rule &rule);
		::Parser::Types::expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorArray& expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorArray(::Parser::Rule &rule);
		const ::Parser::Types::expression_pseudoDestructorName_pseudoDestructorName1& expression_pseudoDestructorName_pseudoDestructorName1(const ::Parser::Rule &rule);
		::Parser::Types::expression_pseudoDestructorName_pseudoDestructorName1& expression_pseudoDestructorName_pseudoDestructorName1(::Parser::Rule &rule);
		const ::Parser::Types::expression_new_typeId& expression_new_typeId(const ::Parser::Rule &rule);
		::Parser::Types::expression_new_typeId& expression_new_typeId(::Parser::Rule &rule);
		const ::Parser::Types::expression_pseudoDestructorName& expression_pseudoDestructorName(const ::Parser::Rule &rule);
		::Parser::Types::expression_pseudoDestructorName& expression_pseudoDestructorName(::Parser::Rule &rule);
		const ::Parser::Types::expression_postfixExpression_typeConstructionArguments& expression_postfixExpression_typeConstructionArguments(const ::Parser::Rule &rule);
		::Parser::Types::expression_postfixExpression_typeConstructionArguments& expression_postfixExpression_typeConstructionArguments(::Parser::Rule &rule);
		const ::Parser::Types::expression_unaryExpression& expression_unaryExpression(const ::Parser::Rule &rule);
		::Parser::Types::expression_unaryExpression& expression_unaryExpression(::Parser::Rule &rule);
		const ::Parser::Types::expression_postfixExpression_typeidExpression& expression_postfixExpression_typeidExpression(const ::Parser::Rule &rule);
		::Parser::Types::expression_postfixExpression_typeidExpression& expression_postfixExpression_typeidExpression(::Parser::Rule &rule);
		const ::Parser::Types::expression_postfixExpression_castExpression& expression_postfixExpression_castExpression(const ::Parser::Rule &rule);
		::Parser::Types::expression_postfixExpression_castExpression& expression_postfixExpression_castExpression(::Parser::Rule &rule);
		const ::Parser::Types::expression_postfixExpression_memberAccess& expression_postfixExpression_memberAccess(const ::Parser::Rule &rule);
		::Parser::Types::expression_postfixExpression_memberAccess& expression_postfixExpression_memberAccess(::Parser::Rule &rule);
		const ::Parser::Types::expression_postfixExpression_memberAccessTarget& expression_postfixExpression_memberAccessTarget(const ::Parser::Rule &rule);
		::Parser::Types::expression_postfixExpression_memberAccessTarget& expression_postfixExpression_memberAccessTarget(::Parser::Rule &rule);
		const ::Parser::Types::expression_postfixExpression& expression_postfixExpression(const ::Parser::Rule &rule);
		::Parser::Types::expression_postfixExpression& expression_postfixExpression(::Parser::Rule &rule);
		const ::Parser::Types::expression_postfixExpression_typeConstruction& expression_postfixExpression_typeConstruction(const ::Parser::Rule &rule);
		::Parser::Types::expression_postfixExpression_typeConstruction& expression_postfixExpression_typeConstruction(::Parser::Rule &rule);
		const ::Parser::Types::expression_postfixExpression_functionCallArguments& expression_postfixExpression_functionCallArguments(const ::Parser::Rule &rule);
		::Parser::Types::expression_postfixExpression_functionCallArguments& expression_postfixExpression_functionCallArguments(::Parser::Rule &rule);
		const ::Parser::Types::expression_unaryExpression_sizeof& expression_unaryExpression_sizeof(const ::Parser::Rule &rule);
		::Parser::Types::expression_unaryExpression_sizeof& expression_unaryExpression_sizeof(::Parser::Rule &rule);
		const ::Parser::Types::expression_new_bracedTypeId& expression_new_bracedTypeId(const ::Parser::Rule &rule);
		::Parser::Types::expression_new_bracedTypeId& expression_new_bracedTypeId(::Parser::Rule &rule);
		const ::Parser::Types::expression_lambda_introducer_capture_captureList_capture_simpleCapture& expression_lambda_introducer_capture_captureList_capture_simpleCapture(const ::Parser::Rule &rule);
		::Parser::Types::expression_lambda_introducer_capture_captureList_capture_simpleCapture& expression_lambda_introducer_capture_captureList_capture_simpleCapture(::Parser::Rule &rule);
		const ::Parser::Types::expression_lambda_declarator& expression_lambda_declarator(const ::Parser::Rule &rule);
		::Parser::Types::expression_lambda_declarator& expression_lambda_declarator(::Parser::Rule &rule);
		const ::Parser::Types::expression_postfixExpression_functionCall& expression_postfixExpression_functionCall(const ::Parser::Rule &rule);
		::Parser::Types::expression_postfixExpression_functionCall& expression_postfixExpression_functionCall(::Parser::Rule &rule);
		const ::Parser::Types::expression_pseudoDestructorName_pseudoDestructorName3& expression_pseudoDestructorName_pseudoDestructorName3(const ::Parser::Rule &rule);
		::Parser::Types::expression_pseudoDestructorName_pseudoDestructorName3& expression_pseudoDestructorName_pseudoDestructorName3(::Parser::Rule &rule);
		const ::Parser::Types::expression_logicalOr& expression_logicalOr(const ::Parser::Rule &rule);
		::Parser::Types::expression_logicalOr& expression_logicalOr(::Parser::Rule &rule);
		const ::Parser::Types::expression_lambda_introducer_capture_captureList& expression_lambda_introducer_capture_captureList(const ::Parser::Rule &rule);
		::Parser::Types::expression_lambda_introducer_capture_captureList& expression_lambda_introducer_capture_captureList(::Parser::Rule &rule);
		const ::Parser::Types::expression_lambda_introducer& expression_lambda_introducer(const ::Parser::Rule &rule);
		::Parser::Types::expression_lambda_introducer& expression_lambda_introducer(::Parser::Rule &rule);
		const ::Parser::Types::expression_lambda_introducer_capture_captureList_capture_simpleCapture_name& expression_lambda_introducer_capture_captureList_capture_simpleCapture_name(const ::Parser::Rule &rule);
		::Parser::Types::expression_lambda_introducer_capture_captureList_capture_simpleCapture_name& expression_lambda_introducer_capture_captureList_capture_simpleCapture_name(::Parser::Rule &rule);
		const ::Parser::Types::expression_unaryExpression_prefixUnaryExpression& expression_unaryExpression_prefixUnaryExpression(const ::Parser::Rule &rule);
		::Parser::Types::expression_unaryExpression_prefixUnaryExpression& expression_unaryExpression_prefixUnaryExpression(::Parser::Rule &rule);
		const ::Parser::Types::expression_pseudoDestructorName_pseudoDestructorName2& expression_pseudoDestructorName_pseudoDestructorName2(const ::Parser::Rule &rule);
		::Parser::Types::expression_pseudoDestructorName_pseudoDestructorName2& expression_pseudoDestructorName_pseudoDestructorName2(::Parser::Rule &rule);
		const ::Parser::Types::expression_unqualifiedId_destructor& expression_unqualifiedId_destructor(const ::Parser::Rule &rule);
		::Parser::Types::expression_unqualifiedId_destructor& expression_unqualifiedId_destructor(::Parser::Rule &rule);
		const ::Parser::Types::expression_qualifiedId_nestedNameSpecifier& expression_qualifiedId_nestedNameSpecifier(const ::Parser::Rule &rule);
		::Parser::Types::expression_qualifiedId_nestedNameSpecifier& expression_qualifiedId_nestedNameSpecifier(::Parser::Rule &rule);
		const ::Parser::Types::expression_lambda_introducer_capture_captureDefault& expression_lambda_introducer_capture_captureDefault(const ::Parser::Rule &rule);
		::Parser::Types::expression_lambda_introducer_capture_captureDefault& expression_lambda_introducer_capture_captureDefault(::Parser::Rule &rule);
		const ::Parser::Types::expression_unaryExpression_sizeofArgument& expression_unaryExpression_sizeofArgument(const ::Parser::Rule &rule);
		::Parser::Types::expression_unaryExpression_sizeofArgument& expression_unaryExpression_sizeofArgument(::Parser::Rule &rule);
		const ::Parser::Types::expression_idExpression& expression_idExpression(const ::Parser::Rule &rule);
		::Parser::Types::expression_idExpression& expression_idExpression(::Parser::Rule &rule);
		const ::Parser::Types::expression_group& expression_group(const ::Parser::Rule &rule);
		::Parser::Types::expression_group& expression_group(::Parser::Rule &rule);
		const ::Parser::Types::expression_lambda_introducer_capture& expression_lambda_introducer_capture(const ::Parser::Rule &rule);
		::Parser::Types::expression_lambda_introducer_capture& expression_lambda_introducer_capture(::Parser::Rule &rule);
		const ::Parser::Types::expression_primary& expression_primary(const ::Parser::Rule &rule);
		::Parser::Types::expression_primary& expression_primary(::Parser::Rule &rule);
		const ::Parser::Types::expression_lambda_introducer_capture_list& expression_lambda_introducer_capture_list(const ::Parser::Rule &rule);
		::Parser::Types::expression_lambda_introducer_capture_list& expression_lambda_introducer_capture_list(::Parser::Rule &rule);
	}
	class Lexer : public ISPA_STD::Lexer_base<Tokens> {
		public:
			using ISPA_STD::Lexer_base<Tokens>::Lexer_base;
        /**
         * @param os the output stream
         * Print the tokens into an output stream
         */
        void printTokens(std::ostream& os);
        /**
         * @param os the output stream
         * @param token the token to print
         * Prints a single token into an output stream
         */
        static void printToken(std::ostream& os, const Token& token);		private:
			Token makeToken(const char*& pos);
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 9> dfa_state_0;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_1;
		static const ISPA_STD::DFAAPI::MultiTableEmptyState<::Parser::Tokens> dfa_state_2;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_3;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_4;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_5;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_6;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 9> dfa_state_7;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_8;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_9;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_10;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_11;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_12;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 9> dfa_state_13;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_14;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_15;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 9> dfa_state_16;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_17;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 9> dfa_state_18;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_19;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_20;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_21;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_22;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_23;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_24;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_25;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_26;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_27;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_28;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_29;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_30;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_31;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_32;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_33;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_34;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_35;
		static const ISPA_STD::DFAAPI::CharTableState<62> dfa_state_36;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_37;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_38;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_39;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_40;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_41;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_42;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_43;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_44;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_45;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_46;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_47;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_48;
		static const ISPA_STD::DFAAPI::CharTableState<62> dfa_state_49;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_50;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_51;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_52;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_53;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_54;
		static const ISPA_STD::DFAAPI::CharTableState<62> dfa_state_55;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_56;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_57;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_58;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_59;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_60;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_61;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_62;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_63;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_64;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_65;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_66;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_67;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_68;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_69;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_70;
		static const ISPA_STD::DFAAPI::CharTableState<2> dfa_state_71;
		static const ISPA_STD::DFAAPI::CharTableState<62> dfa_state_72;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_73;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_74;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_75;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_76;
		static const ISPA_STD::DFAAPI::CharTableState<63> dfa_state_77;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_78;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_79;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_80;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_81;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_82;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_83;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_84;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_85;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_86;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_87;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_88;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_89;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_90;
		static const ISPA_STD::DFAAPI::CharEmptyState<::Parser::Tokens> dfa_state_91;
		static const ISPA_STD::DFAAPI::CharTableState<3> dfa_state_92;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 9> dfa_state_93;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_94;
		static const ISPA_STD::DFAAPI::CharTableState<1> dfa_state_95;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_96;
		static const ISPA_STD::DFAAPI::MultiTableState<::Parser::Tokens, 9> dfa_state_97;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_98;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 5> dfa_table_0;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 3> dfa_table_1;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 6> dfa_table_2;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_3;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_4;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 5> dfa_table_5;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 5> dfa_table_6;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_7;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 6> dfa_table_8;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 5> dfa_table_9;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 3> dfa_table_10;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 3> dfa_table_11;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 4> dfa_table_12;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 3> dfa_table_13;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 5> dfa_table_14;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_15;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 63> dfa_table_16;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_17;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 2> dfa_table_18;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 4> dfa_table_19;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 70> dfa_table_20;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 69> dfa_table_21;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 70> dfa_table_22;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 73> dfa_table_23;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 69> dfa_table_24;
		static const ::ISPA_STD::DFAAPI::CharTable<::Parser::Tokens, 79> dfa_table_25;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 6> dfa_table_26;
		static const ::ISPA_STD::DFAAPI::MultiTable<::Parser::Tokens, 4> dfa_table_27;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_0;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_1;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_2;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_3;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_4;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_5;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_6;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_7;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_8;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_9;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_10;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_11;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_12;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_13;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_14;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_15;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_16;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_17;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_18;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_19;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_20;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_21;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_22;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_23;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_24;
		static const ::ISPA_STD::DFAAPI::SpanCharTable<::Parser::Tokens> dfa_span_25;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_26;
		static const ::ISPA_STD::DFAAPI::SpanMultiTable<::Parser::Tokens> dfa_span_27;
		static const ISPA_STD::fcdt_table<Tokens> first_character_dispatch_table;
	};
	class Parser : public ISPA_STD::LLParser_base<Tokens, Rules> {
		public:
            /**
             * @param os the output stream
             * Print the ast into output stream
             */
            void printAST(std::ostream& os);
            /**
             * @param os the output stream
             * @param rule the rule to print
             * Prints a single rule into an output stream
             */
            static void printRule(std::ostream &os, const Token &token, std::size_t &indentLevel, bool addSpaceOnBegin);
            static void printRule(std::ostream &os, const Rule &rule, std::size_t &indentLevel, bool addSpaceOnBegin);
            static void printRule(std::ostream &os, const std::any& data, std::size_t &indentLevel, bool addSpaceOnBegin);
		private:
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 28> dfa_state_0;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_1;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_2;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_3;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_4;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_5;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_6;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_7;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_8;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_9;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_10;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_11;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_12;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_13;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_14;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_15;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_16;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 31> dfa_state_17;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_18;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_19;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_20;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_21;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_22;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_23;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_24;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_25;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> dfa_state_26;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_27;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_28;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_29;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_30;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_31;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 21> dfa_state_32;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_33;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 20> dfa_state_34;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_35;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_36;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_37;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 57> dfa_state_38;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_39;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_40;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_41;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_42;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 31> dfa_state_43;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_44;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_45;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_46;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_47;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_48;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_49;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 18> dfa_state_50;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_51;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_52;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_53;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_54;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_55;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_56;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_57;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_58;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_59;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_60;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_61;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_62;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_63;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_64;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_65;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_66;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_67;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_68;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_69;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_70;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_71;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_72;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_73;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_74;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_75;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 33> dfa_state_76;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> dfa_state_77;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 51> dfa_state_78;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_79;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> dfa_state_80;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_81;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_82;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_83;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_84;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_85;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 12> dfa_state_86;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_87;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 57> dfa_state_88;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_89;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_90;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 20> dfa_state_91;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_92;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_93;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_94;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_95;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_96;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_97;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_98;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_99;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 18> dfa_state_100;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_101;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_102;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_103;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_104;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_105;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_106;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_107;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 13> dfa_state_108;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_109;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 22> dfa_state_110;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_111;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_112;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 23> dfa_state_113;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_114;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 16> dfa_state_115;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> dfa_state_116;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_117;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_118;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_119;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_120;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_121;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> dfa_state_122;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 49> dfa_state_123;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_124;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_125;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_126;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_127;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_128;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_129;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_130;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_131;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_132;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_133;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_134;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_135;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_136;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_137;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_138;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_139;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_140;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_141;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_142;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_143;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_144;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_145;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_146;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_147;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_148;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_149;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_150;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_151;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 57> dfa_state_152;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 31> dfa_state_153;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_154;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_155;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_156;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_157;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_158;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_159;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_160;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_161;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_162;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_163;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 18> dfa_state_164;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_165;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_166;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_167;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_168;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_169;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_170;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_171;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_172;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_173;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_174;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 11> dfa_state_175;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 13> dfa_state_176;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_177;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_178;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_179;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_180;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_181;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_182;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_183;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_184;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_185;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_186;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 35> dfa_state_187;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> dfa_state_188;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 52> dfa_state_189;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_190;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_191;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_192;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_193;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_194;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_195;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_196;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_197;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_198;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_199;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_200;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_201;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_202;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_203;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_204;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_205;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_206;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_207;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_208;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_209;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_210;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_211;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_212;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 57> dfa_state_213;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_214;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_215;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_216;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 31> dfa_state_217;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_218;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_219;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_220;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_221;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 10> dfa_state_222;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_223;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_224;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_225;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_226;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_227;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_228;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_229;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_230;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_231;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 33> dfa_state_232;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_233;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 18> dfa_state_234;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_235;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_236;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_237;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 32> dfa_state_238;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_239;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_240;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_241;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_242;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_243;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_244;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_245;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_246;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_247;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_248;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_249;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 57> dfa_state_250;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 31> dfa_state_251;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_252;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_253;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_254;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_255;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_256;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 18> dfa_state_257;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_258;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_259;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_260;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_261;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_262;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_263;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_264;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_265;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 33> dfa_state_266;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_267;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_268;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_269;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> dfa_state_270;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_271;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_272;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 29> dfa_state_273;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_274;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_275;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_276;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 32> dfa_state_277;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> dfa_state_278;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 51> dfa_state_279;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_280;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_281;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_282;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_283;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_284;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_285;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_286;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 57> dfa_state_287;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 31> dfa_state_288;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_289;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_290;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_291;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_292;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_293;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_294;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_295;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_296;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_297;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> dfa_state_298;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_299;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 29> dfa_state_300;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_301;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_302;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_303;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 41> dfa_state_304;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_305;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_306;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> dfa_state_307;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_308;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_309;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_310;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_311;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_312;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_313;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_314;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_315;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_316;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_317;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_318;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_319;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_320;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_321;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_322;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_323;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_324;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_325;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 57> dfa_state_326;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_327;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_328;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_329;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_330;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_331;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_332;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 14> dfa_state_333;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_334;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_335;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_336;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_337;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_338;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_339;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_340;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_341;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_342;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_343;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_344;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_345;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_346;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_347;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_348;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_349;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_350;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_351;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 35> dfa_state_352;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_353;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 1> dfa_state_354;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 37> dfa_state_355;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_356;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_357;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 7> dfa_state_358;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_359;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_360;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_361;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_362;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_363;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_364;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_365;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_366;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_367;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_368;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_369;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_370;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_371;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_372;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_373;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_374;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_375;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_376;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_377;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_378;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_379;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 57> dfa_state_380;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_381;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_382;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_383;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_384;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 31> dfa_state_385;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_386;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_387;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_388;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_389;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_390;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_391;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 18> dfa_state_392;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_393;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_394;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_395;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_396;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_397;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_398;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_399;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_400;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_401;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_402;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 34> dfa_state_403;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_404;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_405;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 33> dfa_state_406;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_407;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_408;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_409;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 17> dfa_state_410;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 18> dfa_state_411;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 5> dfa_state_412;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 6> dfa_state_413;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_414;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 36> dfa_state_415;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_416;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 4> dfa_state_417;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_418;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_419;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_420;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 8> dfa_state_421;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 3> dfa_state_422;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_423;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_424;
		static const ISPA_STD::DFAAPI::TokenTableState<::Parser::Tokens, 2> dfa_state_425;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 96> dfa_table_0;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 116> dfa_table_1;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_2;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 118> dfa_table_3;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 9> dfa_table_4;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_5;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_6;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_7;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_8;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_9;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_10;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 7> dfa_table_11;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 124> dfa_table_12;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 22> dfa_table_13;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 7> dfa_table_14;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 105> dfa_table_15;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 111> dfa_table_16;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 112> dfa_table_17;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 5> dfa_table_18;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 20> dfa_table_19;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_20;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 110> dfa_table_21;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 5> dfa_table_22;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 5> dfa_table_23;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 6> dfa_table_24;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_25;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 5> dfa_table_26;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 5> dfa_table_27;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 4> dfa_table_28;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 5> dfa_table_29;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 17> dfa_table_30;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 7> dfa_table_31;
		static const ::ISPA_STD::DFAAPI::TokenTable<::Parser::Tokens, 116> dfa_table_32;

		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_0;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_1;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_2;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_3;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_4;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_5;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_6;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_7;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_8;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_9;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_10;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_11;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_12;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_13;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_14;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_15;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_16;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_17;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_18;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_19;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_20;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_21;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_22;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_23;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_24;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_25;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_26;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_27;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_28;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_29;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_30;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_31;
		static const ::ISPA_STD::DFAAPI::SpanTokenTable<::Parser::Tokens> dfa_span_32;
			Rule_res getRule(Lexer::lazy_iterator&);
			Rule_res getRule(Lexer::iterator&);
		void parseFromTokens();
		void lazyParse();
		template <class IT>
		::Parser::Rule_res literal(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::literal)};
		}
		template <class IT>
		::Parser::Rule_res bracedInitList(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::bracedInitList)};
		}
		template <class IT>
		::Parser::Rule_res typeSpecifierSeq(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::typeSpecifierSeq)};
		}
		template <class IT>
		::Parser::Rule_res typeNameSpecifier(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::typeNameSpecifier)};
		}
		template <class IT>
		::Parser::Rule_res initializerList(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::initializerList)};
		}
		template <class IT>
		::Parser::Rule_res trailingReturnType(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::trailingReturnType)};
		}
		template <class IT>
		::Parser::Rule_res parameterDeclarationClause(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::parameterDeclarationClause)};
		}
		template <class IT>
		::Parser::Rule_res expression_throw(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_0))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = expression_assignment(pos);
			if (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
			}
			skip_spaces(pos);
			::Parser::Types::expression_throw data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_throw, data)};
		}
		template <class IT>
		::Parser::Rule_res initializerClause(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::initializerClause)};
		}
		template <class IT>
		::Parser::Rule_res expression_cast(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_0, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_unaryExpression(pos);

					break;

				}
				case 1: {
					_0 = expression_cast_parentheses(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_cast data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_cast, data)};
		}
		template <class IT>
		::Parser::Rule_res operatorFunctionId(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::operatorFunctionId)};
		}
		template <class IT>
		::Parser::Rule_res templateId(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::templateId)};
		}
		template <class IT>
		::Parser::Rule_res expression_new_declarator(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_1, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_new_declarator_pointerOperatorWithNewDeclarator(pos);

					break;

				}
				case 1: {
					_0 = expression_new_declarator_noPointerNewDeclarator(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_new_declarator data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_new_declarator, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_shift(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::arr_t<::Parser::Rule> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = expression_additive(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				_4 = expression_shift_shiftOp(begin_10);
				if (!(_4.status))
				{
					break;
				}
				success_5 = true;
				begin_10 += _4.node.length();
				shadow_6.push_back(_4.node);
				skip_spaces(begin_10);
				_7 = expression_additive(begin_10);
				if (!(_7.status))
				{
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::expression_shift data;
			data.shiftOp = shadow_6;
			data.additive = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_shift, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_assignment_assignmentOp(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_2, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = *pos;

					break;

				}
				case 1: {
					_0 = *pos;

					break;

				}
				case 2: {
					_0 = *pos;

					break;

				}
				case 3: {
					_0 = *pos;

					break;

				}
				case 4: {
					_0 = *pos;

					break;

				}
				case 5: {
					_0 = *pos;

					break;

				}
				case 6: {
					_0 = *pos;

					break;

				}
				case 7: {
					_0 = *pos;

					break;

				}
				case 8: {
					_0 = *pos;

					break;

				}
				case 9: {
					_0 = *pos;

					break;

				}
				case 10: {
					_0 = *pos;

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_assignment_assignmentOp data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_assignment_assignmentOp, data)};
		}
		template <class IT>
		::Parser::Rule_res className(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::className)};
		}
		template <class IT>
		::Parser::Rule_res expression_assignment_assign(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			_0 = expression_logicalOr(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			_2 = expression_assignment_assignmentOp(pos);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			_4 = initializerClause(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_assignment_assign data;
			data.initializerClause = _4.node;
			data.assignmentOp = _2.node;
			data.logicalOr = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_assignment_assign, data)};
		}
		template <class IT>
		::Parser::Rule_res decltypeSpecifier(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::decltypeSpecifier)};
		}
		template <class IT>
		::Parser::Rule_res expression_assignment(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_3, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_conditional(pos);

					break;

				}
				case 1: {
					_0 = expression_assignment_assign(pos);

					break;

				}
				case 2: {
					_0 = expression_throw(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_assignment data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_assignment, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_postfixExpression_postfixIncrementDecrement(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			_0 = expression_postfixExpression(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::POSTFIX))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_postfixExpression_postfixIncrementDecrement data;
			data.op = _2;
			data.expr = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_postfixExpression_postfixIncrementDecrement, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_conditional(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			success_1 = false;
			_0 = expression_logicalOr(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_1))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			_4 = expression(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			success_7 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_2))
			{
				return {};
			}
			_6 = *pos;
			success_7 = true;
			pos += 1;
			skip_spaces(pos);
			success_9 = false;
			_8 = expression_assignment(pos);
			if (!(_8.status))
			{
				return {};
			}
			success_9 = true;
			pos += _8.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_conditional data;
			data.second = _8.node;
			data.first = _4.node;
			data.logicalOr = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_conditional, data)};
		}
		template <class IT>
		::Parser::Rule_res theTypeName(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::theTypeName)};
		}
		template <class IT>
		::Parser::Rule_res expression_logicalAnd(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = expression_inclusiveOr(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_3))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = expression_inclusiveOr(begin_10);
				if (!(_7.status))
				{
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::expression_logicalAnd data;
			data.inclusives = shadow_9;
			data.inclusive = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_logicalAnd, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_lambda_introducer_capture_captureList_capture(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_4, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_lambda_introducer_capture_captureList_capture_simpleCapture(pos);

					break;

				}
				case 1: {
					_0 = expression_lambda_introducer_capture_captureList_capture_initcapture(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_lambda_introducer_capture_captureList_capture data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_lambda_introducer_capture_captureList_capture, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_exclusiveOr(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = expression__and(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_4))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = expression__and(begin_10);
				if (!(_7.status))
				{
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::expression_exclusiveOr data;
			data.andExpressions = shadow_9;
			data.andExpr = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_exclusiveOr, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_qualifiedId_nestedNameSpecifier_templ(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_5))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = simpleTemplateId(pos);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_qualifiedId_nestedNameSpecifier_templ data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_qualifiedId_nestedNameSpecifier_templ, data)};
		}
		template <class IT>
		::Parser::Rule_res newDeclarator(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::newDeclarator)};
		}
		template <class IT>
		::Parser::Rule_res compoundStatement(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::compoundStatement)};
		}
		template <class IT>
		::Parser::Rule_res conversionFunctionId(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::conversionFunctionId)};
		}
		template <class IT>
		::Parser::Rule_res expression__and(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = expression_equality(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_6))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = expression_equality(begin_10);
				if (!(_7.status))
				{
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::expression__and data;
			data.equalities = shadow_9;
			data.equality = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression__and, data)};
		}
		template <class IT>
		::Parser::Rule_res namespaceName(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::namespaceName)};
		}
		template <class IT>
		::Parser::Rule_res expression_relational(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = 1;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			int dfa_lookup_result_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = expression_shift(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = 1;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				dfa_lookup_result_6 = ISPA_STD::DFA<Tokens>::decide(dfa_span_5, begin_10, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
				switch (dfa_lookup_result_6)
				{
					case 0: {
						_4 = *begin_10;

						break;

					}
					case 1: {
						_4 = *begin_10;

						break;

					}
					case 2: {
						_4 = *begin_10;

						break;

					}
					case 3: {
						_4 = *begin_10;

						break;

					}
				}
;
				skip_spaces(begin_10);
				_7 = expression_shift(begin_10);
				if (!(_7.status))
				{
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::expression_relational data;
			data.shifts = shadow_9;
			data.ops = _4;
			data.shift = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_relational, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_additive(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = 1;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			int dfa_lookup_result_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = expression_multiplicative(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = 1;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				dfa_lookup_result_6 = ISPA_STD::DFA<Tokens>::decide(dfa_span_6, begin_10, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
				switch (dfa_lookup_result_6)
				{
					case 0: {
						_4 = *begin_10;

						break;

					}
					case 1: {
						_4 = *begin_10;

						break;

					}
				}
;
				skip_spaces(begin_10);
				_7 = expression_multiplicative(begin_10);
				if (!(_7.status))
				{
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::expression_additive data;
			data.operators = _4;
			data.multi = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_additive, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_qualifiedId(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			_0 = expression_qualifiedId_nestedNameSpecifier(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			if (pos->name() == ::Parser::Tokens::AUTO_5)
			{
				_2 = *pos;
				success_3 = true;
				pos += 1;
			}
			skip_spaces(pos);
			success_5 = false;
			_4 = expression_unqualifiedId(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_qualifiedId data;
			data.uid = _4.node;
			data.name = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_qualifiedId, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_unaryExpression_alignof(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_7))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			_4 = theTypeId(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			success_7 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_6 = *pos;
			success_7 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_unaryExpression_alignof data = _4.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_unaryExpression_alignof, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_pointerMember(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = 1;
			int dfa_lookup_result_4;
			::Parser::Rule_res _5;
			::Parser::bool_t success_6 = false;
			success_1 = false;
			_0 = expression_cast(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = 1;
			dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_7, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_4)
			{
				case 0: {
					_2 = *pos;

					break;

				}
				case 1: {
					_2 = *pos;

					break;

				}
			}
;
			skip_spaces(pos);
			success_6 = false;
			_5 = expression_cast(pos);
			if (!(_5.status))
			{
				return {};
			}
			success_6 = true;
			pos += _5.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_pointerMember data;
			data.sep = _2;
			data.second_cast = _5.node;
			data.first_cast = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_pointerMember, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_cast_parentheses(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = theTypeId(pos);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			success_7 = false;
			_6 = expression_cast(pos);
			if (!(_6.status))
			{
				return {};
			}
			success_7 = true;
			pos += _6.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_cast_parentheses data;
			data.cast = _6.node;
			data.type = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_cast_parentheses, data)};
		}
		template <class IT>
		::Parser::Rule_res attributeSpecifierSeq(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::attributeSpecifierSeq)};
		}
		template <class IT>
		::Parser::Rule_res literalOperatorId(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::literalOperatorId)};
		}
		template <class IT>
		::Parser::Rule_res expression_shift_shiftOp(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = 1;
			int dfa_lookup_result_4;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::GREATER))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = 1;
			dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_8, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_4)
			{
				case 0: {
					_2 = *pos;

					break;

				}
				case 1: {
					_2 = *pos;

					break;

				}
			}
;
			skip_spaces(pos);
			success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::LESS))
			{
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_shift_shiftOp data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_shift_shiftOp, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_new_initializer_parenthesesList(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = expression_expressionList(pos);
			if (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
			}
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_new_initializer_parenthesesList data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_new_initializer_parenthesesList, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorParen(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = expression(pos);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			success_7 = false;
			_6 = attributeSpecifierSeq(pos);
			if (_6.status)
			{
				success_7 = true;
				pos += _6.node.length();
			}
			skip_spaces(pos);
			::Parser::Types::expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorParen data;
			data.attrSpecSeq = _6.node;
			data.expr = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorParen, data)};
		}
		template <class IT>
		::Parser::Rule_res expression(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = expression_assignment(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_10))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = expression_assignment(begin_10);
				if (!(_7.status))
				{
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::expression data;
			data.assignmentExpressions = shadow_9;
			data.assignmentExpr = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_equality(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = 1;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			int dfa_lookup_result_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = expression_relational(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = 1;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				dfa_lookup_result_6 = ISPA_STD::DFA<Tokens>::decide(dfa_span_9, begin_10, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
				switch (dfa_lookup_result_6)
				{
					case 0: {
						_4 = *begin_10;

						break;

					}
					case 1: {
						_4 = *begin_10;

						break;

					}
				}
;
				skip_spaces(begin_10);
				_7 = expression_relational(begin_10);
				if (!(_7.status))
				{
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::expression_equality data;
			data.rels = shadow_9;
			data.ops = _4;
			data.rel = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_equality, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_multiplicative(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = 1;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			int dfa_lookup_result_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = expression_pointerMember(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = 1;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				dfa_lookup_result_6 = ISPA_STD::DFA<Tokens>::decide(dfa_span_10, begin_10, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
				switch (dfa_lookup_result_6)
				{
					case 0: {
						_4 = *begin_10;

						break;

					}
					case 1: {
						_4 = *begin_10;

						break;

					}
					case 2: {
						_4 = *begin_10;

						break;

					}
				}
;
				skip_spaces(begin_10);
				_7 = expression_pointerMember(begin_10);
				if (!(_7.status))
				{
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::expression_multiplicative data;
			data.operators = _4;
			data.pointerMembers = shadow_9;
			data.pointerMember = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_multiplicative, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_lambda_introducer_capture_captureList_capture_initcapture(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (pos->name() == ::Parser::Tokens::AND)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
			}
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			_4 = initializer(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_lambda_introducer_capture_captureList_capture_initcapture data;
			data.initializer = _4.node;
			data.id = _2;
			data.ref = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_lambda_introducer_capture_captureList_capture_initcapture, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_new_declarator_pointerOperatorWithNewDeclarator(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			_0 = pointerOperator(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			_2 = newDeclarator(pos);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_new_declarator_pointerOperatorWithNewDeclarator data;
			data.decl = _2.node;
			data.pointerOp = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_new_declarator_pointerOperatorWithNewDeclarator, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_new_initializer(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_11, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_new_initializer_parenthesesList(pos);

					break;

				}
				case 1: {
					_0 = bracedInitList(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_new_initializer data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_new_initializer, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_inclusiveOr(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = expression_exclusiveOr(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_11))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = expression_exclusiveOr(begin_10);
				if (!(_7.status))
				{
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::expression_inclusiveOr data;
			data.exclusives = shadow_9;
			data.exclusive = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_inclusiveOr, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_delete(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::Token _6;
			::Parser::Rule_res _9;
			::Parser::bool_t success_10 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_12))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_7 = false;
			success_5 = false;
			success_3 = false;
			auto begin_8 = pos;
			do
			{
				if (!(begin_8->name() == ::Parser::Tokens::AUTO_13))
				{
					break;
				}
				_4 = *begin_8;
				success_5 = true;
				begin_8 += 1;
				skip_spaces(begin_8);
				if (!(begin_8->name() == ::Parser::Tokens::AUTO_14))
				{
					break;
				}
				_6 = *begin_8;
				success_7 = true;
				begin_8 += 1;
			}
			while(0);
			if (success_5 && success_7)
			{
				success_3 = true;
				pos = begin_8;
			}
			skip_spaces(pos);
			success_10 = false;
			_9 = expression_cast(pos);
			if (!(_9.status))
			{
				return {};
			}
			success_10 = true;
			pos += _9.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_delete data;
			data.castExpr = _9.node;
			data.braces = _4;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_delete, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_new_placement(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = expression_expressionList(pos);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_new_placement data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_new_placement, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_new(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Rule_res _6;
			::Parser::bool_t success_7 = 1;
			int dfa_lookup_result_8;
			::Parser::Rule_res _9;
			::Parser::bool_t success_10 = false;
			success_1 = false;
			if (pos->name() == ::Parser::Tokens::AUTO_15)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
			}
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_16))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			_4 = expression_new_placement(pos);
			if (_4.status)
			{
				success_5 = true;
				pos += _4.node.length();
			}
			skip_spaces(pos);
			success_7 = 1;
			dfa_lookup_result_8 = ISPA_STD::DFA<Tokens>::decide(dfa_span_12, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_8)
			{
				case 0: {
					_6 = expression_new_typeId(pos);

					break;

				}
				case 1: {
					_6 = expression_new_bracedTypeId(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			success_10 = false;
			_9 = expression_new_initializer(pos);
			if (_9.status)
			{
				success_10 = true;
				pos += _9.node.length();
			}
			skip_spaces(pos);
			::Parser::Types::expression_new data;
			data.initializer = _9.node;
			data.typeId = _6.node;
			data.placement = _4.node;
			data.prefix = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_new, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_noExcept(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_17))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			_4 = expression(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			success_7 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_6 = *pos;
			success_7 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_noExcept data = _4.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_noExcept, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_pseudoDestructorName_pseudoDestructorCore(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::Token _4;
			::Parser::Token _7;
			::Parser::bool_t success_8 = false;
			::Parser::Rule_res _9;
			::Parser::bool_t success_10 = false;
			success_5 = false;
			success_3 = false;
			success_1 = false;
			auto begin_6 = pos;
			do
			{
				_2 = theTypeName(begin_6);
				if (!(_2.status))
				{
					break;
				}
				success_3 = true;
				begin_6 += _2.node.length();
				skip_spaces(begin_6);
				if (!(begin_6->name() == ::Parser::Tokens::AUTO_15))
				{
					break;
				}
				_4 = *begin_6;
				success_5 = true;
				begin_6 += 1;
			}
			while(0);
			if (success_3 && success_5)
			{
				success_1 = true;
				pos = begin_6;
			}
			skip_spaces(pos);
			success_8 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_18))
			{
				return {};
			}
			_7 = *pos;
			success_8 = true;
			pos += 1;
			skip_spaces(pos);
			success_10 = false;
			_9 = theTypeName(pos);
			if (!(_9.status))
			{
				return {};
			}
			success_10 = true;
			pos += _9.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_pseudoDestructorName_pseudoDestructorCore data;
			data.postfix_type = _9.node;
			data.prefix_type = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_pseudoDestructorName_pseudoDestructorCore, data)};
		}
		template <class IT>
		::Parser::Rule_res simpleTypeSpecifier(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::simpleTypeSpecifier)};
		}
		template <class IT>
		::Parser::Rule_res expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorArray(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			success_1 = false;
			_0 = expression_new_declarator_noPointerNewDeclarator(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_13))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			_4 = expression_constant(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			success_7 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_14))
			{
				return {};
			}
			_6 = *pos;
			success_7 = true;
			pos += 1;
			skip_spaces(pos);
			success_9 = false;
			_8 = attributeSpecifierSeq(pos);
			if (_8.status)
			{
				success_9 = true;
				pos += _8.node.length();
			}
			skip_spaces(pos);
			::Parser::Types::expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorArray data;
			data.attrSpecSeq = _8.node;
			data.constExpr = _4.node;
			data.noPointerNewDeclarator = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorArray, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_pseudoDestructorName_pseudoDestructorName1(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			_0 = expression_qualifiedId_nestedNameSpecifier(pos);
			if (_0.status)
			{
				success_1 = true;
				pos += _0.node.length();
			}
			skip_spaces(pos);
			success_3 = false;
			_2 = expression_pseudoDestructorName_pseudoDestructorCore(pos);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_pseudoDestructorName_pseudoDestructorName1 data;
			data.destructorCore = _2.node;
			data.specifier = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_pseudoDestructorName_pseudoDestructorName1, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_new_typeId(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			_0 = typeSpecifierSeq(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			_2 = expression_new_declarator(pos);
			if (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
			}
			skip_spaces(pos);
			::Parser::Types::expression_new_typeId data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_new_typeId, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_pseudoDestructorName(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_13, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_pseudoDestructorName_pseudoDestructorName1(pos);

					break;

				}
				case 1: {
					_0 = expression_pseudoDestructorName_pseudoDestructorName2(pos);

					break;

				}
				case 2: {
					_0 = expression_pseudoDestructorName_pseudoDestructorName3(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_pseudoDestructorName data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_pseudoDestructorName, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_postfixExpression_typeConstructionArguments(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::any_t _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_14, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					::Parser::bool_t success_4 = false;
					auto begin_11 = pos;
					if (success_6 && success_10)
					{
						success_4 = true;
						pos = begin_11;
					}
					skip_spaces(pos);

					break;

				}
				case 1: {
					_0 = bracedInitList(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_postfixExpression_typeConstructionArguments data = _7.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_postfixExpression_typeConstructionArguments, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_unaryExpression(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_15, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_postfixExpression(pos);

					break;

				}
				case 1: {
					_0 = expression_unaryExpression_prefixUnaryExpression(pos);

					break;

				}
				case 2: {
					_0 = expression_unaryExpression_sizeof(pos);

					break;

				}
				case 3: {
					_0 = expression_unaryExpression_alignof(pos);

					break;

				}
				case 4: {
					_0 = expression_noExcept(pos);

					break;

				}
				case 5: {
					_0 = expression_new(pos);

					break;

				}
				case 6: {
					_0 = expression_delete(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_unaryExpression data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_unaryExpression, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_postfixExpression_typeidExpression(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = 1;
			int dfa_lookup_result_6;
			::Parser::Token _7;
			::Parser::bool_t success_8 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_19))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = 1;
			dfa_lookup_result_6 = ISPA_STD::DFA<Tokens>::decide(dfa_span_16, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_6)
			{
				case 0: {
					_4 = expression(pos);

					break;

				}
				case 1: {
					_4 = theTypeId(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			success_8 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_7 = *pos;
			success_8 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_postfixExpression_typeidExpression data = _4.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_postfixExpression_typeidExpression, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_postfixExpression_castExpression(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule_res _10;
			::Parser::bool_t success_11 = false;
			::Parser::Token _12;
			::Parser::bool_t success_13 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::CAST))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_20))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			_4 = theTypeId(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			success_7 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_21))
			{
				return {};
			}
			_6 = *pos;
			success_7 = true;
			pos += 1;
			skip_spaces(pos);
			success_9 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_8 = *pos;
			success_9 = true;
			pos += 1;
			skip_spaces(pos);
			success_11 = false;
			_10 = expression(pos);
			if (!(_10.status))
			{
				return {};
			}
			success_11 = true;
			pos += _10.node.length();
			skip_spaces(pos);
			success_13 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_12 = *pos;
			success_13 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_postfixExpression_castExpression data;
			data.expr = _10.node;
			data.type = _4.node;
			data.cast = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_postfixExpression_castExpression, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_new_declarator_noPointerNewDeclarator(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_17, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorParen(pos);

					break;

				}
				case 1: {
					_0 = expression_new_declarator_noPointerNewDeclarator_noPointerNewDeclaratorArray(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_new_declarator_noPointerNewDeclarator data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_new_declarator_noPointerNewDeclarator, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_unqualifiedId(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::any_t _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_18, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = *pos;

					break;

				}
				case 1: {
					_0 = operatorFunctionId(pos);

					break;

				}
				case 2: {
					_0 = conversionFunctionId(pos);

					break;

				}
				case 3: {
					_0 = literalOperatorId(pos);

					break;

				}
				case 4: {
					_0 = expression_unqualifiedId_destructor(pos);

					break;

				}
				case 5: {
					_0 = templateId(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_unqualifiedId data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_unqualifiedId, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_postfixExpression_memberAccessTarget(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::any_t _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_19, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					::Parser::bool_t success_4 = false;
					auto begin_9 = pos;
					if (success_8)
					{
						success_4 = true;
						pos = begin_9;
					}
					skip_spaces(pos);

					break;

				}
				case 1: {
					_0 = expression_pseudoDestructorName(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_postfixExpression_memberAccessTarget data = _7.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_postfixExpression_memberAccessTarget, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_postfixExpression_memberAccess(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = 1;
			int dfa_lookup_result_4;
			::Parser::Rule_res _5;
			::Parser::bool_t success_6 = false;
			success_1 = false;
			_0 = expression_postfixExpression(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = 1;
			dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_20, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_4)
			{
				case 0: {
					_2 = *pos;

					break;

				}
				case 1: {
					_2 = *pos;

					break;

				}
			}
;
			skip_spaces(pos);
			success_6 = false;
			_5 = expression_postfixExpression_memberAccessTarget(pos);
			if (!(_5.status))
			{
				return {};
			}
			success_6 = true;
			pos += _5.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_postfixExpression_memberAccess data;
			data.target = _5.node;
			data.sep = _2;
			data.postfix = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_postfixExpression_memberAccess, data)};
		}
		template <class IT>
		::Parser::Rule_res theTypeId(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::theTypeId)};
		}
		template <class IT>
		::Parser::Rule_res expression_postfixExpression(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_21, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_primary(pos);

					break;

				}
				case 1: {
					_0 = expression_postfixExpression_functionCall(pos);

					break;

				}
				case 2: {
					_0 = expression_postfixExpression_typeConstruction(pos);

					break;

				}
				case 3: {
					_0 = expression_postfixExpression_memberAccess(pos);

					break;

				}
				case 4: {
					_0 = expression_postfixExpression_postfixIncrementDecrement(pos);

					break;

				}
				case 5: {
					_0 = expression_cast(pos);

					break;

				}
				case 6: {
					_0 = expression_postfixExpression_typeidExpression(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_postfixExpression data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_postfixExpression, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_postfixExpression_typeConstruction(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			::Parser::Rule_res _3;
			::Parser::bool_t success_4 = false;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_22, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = simpleTypeSpecifier(pos);

					break;

				}
				case 1: {
					_0 = typeNameSpecifier(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			success_4 = false;
			_3 = expression_postfixExpression_typeConstructionArguments(pos);
			if (!(_3.status))
			{
				return {};
			}
			success_4 = true;
			pos += _3.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_postfixExpression_typeConstruction data;
			data.args = _3.node;
			data.type = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_postfixExpression_typeConstruction, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_postfixExpression_functionCallArguments(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::any_t _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_23, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_expressionList(pos);

					break;

				}
				case 1: {
					_0 = bracedInitList(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_postfixExpression_functionCallArguments data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_postfixExpression_functionCallArguments, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_unaryExpression_sizeof(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::SIZEOF))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = expression_unaryExpression_sizeofArgument(pos);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_unaryExpression_sizeof data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_unaryExpression_sizeof, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_new_bracedTypeId(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = theTypeId(pos);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_new_bracedTypeId data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_new_bracedTypeId, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_lambda_introducer_capture_captureList_capture_simpleCapture(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::any_t _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_24, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_lambda_introducer_capture_captureList_capture_simpleCapture_name(pos);

					break;

				}
				case 1: {
					_0 = *pos;

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_lambda_introducer_capture_captureList_capture_simpleCapture data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_lambda_introducer_capture_captureList_capture_simpleCapture, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_lambda_declarator(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Rule_res _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule_res _10;
			::Parser::bool_t success_11 = false;
			::Parser::Rule_res _12;
			::Parser::bool_t success_13 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = parameterDeclarationClause(pos);
			if (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
			}
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			success_7 = false;
			if (pos->name() == ::Parser::Tokens::AUTO_22)
			{
				_6 = *pos;
				success_7 = true;
				pos += 1;
			}
			skip_spaces(pos);
			success_9 = false;
			_8 = exceptionSpecification(pos);
			if (_8.status)
			{
				success_9 = true;
				pos += _8.node.length();
			}
			skip_spaces(pos);
			success_11 = false;
			_10 = attributeSpecifierSeq(pos);
			if (_10.status)
			{
				success_11 = true;
				pos += _10.node.length();
			}
			skip_spaces(pos);
			success_13 = false;
			_12 = trailingReturnType(pos);
			if (_12.status)
			{
				success_13 = true;
				pos += _12.node.length();
			}
			skip_spaces(pos);
			::Parser::Types::expression_lambda_declarator data;
			data.attributes = _10.node;
			data.exceptionSpec = _8.node;
			data.return_type = _12.node;
			data.mutable = _6;
			data.parameter = _2.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_lambda_declarator, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_postfixExpression_functionCall(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			success_1 = false;
			_0 = expression_postfixExpression(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			_4 = expression_postfixExpression_functionCallArguments(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			success_7 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_6 = *pos;
			success_7 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_postfixExpression_functionCall data;
			data.funCallArgs = _4.node;
			data.postfixExpr = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_postfixExpression_functionCall, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_logicalOr(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			success_1 = false;
			_0 = expression_logicalAnd(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_23))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = expression_logicalAnd(begin_10);
				if (!(_7.status))
				{
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			::Parser::Types::expression_logicalOr data;
			data.logicalAnds = shadow_9;
			data.logicalAnd = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_logicalOr, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_pseudoDestructorName_pseudoDestructorName3(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_18))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = decltypeSpecifier(pos);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_pseudoDestructorName_pseudoDestructorName3 data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_pseudoDestructorName_pseudoDestructorName3, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_expressionList(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			_0 = initializerList(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_expressionList data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_expressionList, data)};
		}
		template <class IT>
		::Parser::Rule_res exceptionSpecification(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::exceptionSpecification)};
		}
		template <class IT>
		::Parser::Rule_res expression_lambda_introducer_capture_captureList(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_8 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::arr_t<::Parser::Token> shadow_6;
			::Parser::Rule_res _7;
			::Parser::arr_t<::Parser::Rule> shadow_9;
			::Parser::Token _11;
			::Parser::bool_t success_12 = false;
			success_1 = false;
			_0 = expression_lambda_introducer_capture(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_8 = false;
			success_5 = false;
			success_3 = false;
			auto begin_10 = pos;
			while (1)
			{
				if (!(begin_10->name() == ::Parser::Tokens::AUTO_10))
				{
					break;
				}
				_4 = *begin_10;
				success_5 = true;
				begin_10 += 1;
				shadow_6.push_back(_4);
				skip_spaces(begin_10);
				_7 = expression_lambda_introducer_capture(begin_10);
				if (!(_7.status))
				{
					break;
				}
				success_8 = true;
				begin_10 += _7.node.length();
				shadow_9.push_back(_7.node);
			}
			if (success_5 && success_8)
			{
				success_3 = true;
				pos = begin_10;
			}
			skip_spaces(pos);
			success_12 = false;
			if (pos->name() == ::Parser::Tokens::AUTO_24)
			{
				_11 = *pos;
				success_12 = true;
				pos += 1;
			}
			skip_spaces(pos);
			::Parser::Types::expression_lambda_introducer_capture_captureList data;
			data.ellipsis = _11;
			data.captureList = shadow_9;
			data.capture = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_lambda_introducer_capture_captureList, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_lambda_introducer(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_13))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = expression_lambda_introducer_capture(pos);
			if (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
			}
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_14))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_lambda_introducer data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_lambda_introducer, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_unaryExpression_prefixUnaryExpression(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			::Parser::Rule_res _3;
			::Parser::bool_t success_4 = false;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_25, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = *pos;

					break;

				}
				case 1: {
					_0 = *pos;

					break;

				}
				case 2: {
					_0 = *pos;

					break;

				}
			}
;
			skip_spaces(pos);
			success_4 = false;
			_3 = expression_unaryExpression(pos);
			if (!(_3.status))
			{
				return {};
			}
			success_4 = true;
			pos += _3.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_unaryExpression_prefixUnaryExpression data;
			data.expr = _3.node;
			data.op = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_unaryExpression_prefixUnaryExpression, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_lambda_introducer_capture_captureList_capture_simpleCapture_name(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			success_1 = false;
			if (pos->name() == ::Parser::Tokens::AND)
			{
				_0 = *pos;
				success_1 = true;
				pos += 1;
			}
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_lambda_introducer_capture_captureList_capture_simpleCapture_name data;
			data.id = _2;
			data.ref = _0;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_lambda_introducer_capture_captureList_capture_simpleCapture_name, data)};
		}
		template <class IT>
		::Parser::Rule_res pointerOperator(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::pointerOperator)};
		}
		template <class IT>
		::Parser::Rule_res expression_constant(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			_0 = expression_conditional(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_constant data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_constant, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_pseudoDestructorName_pseudoDestructorName2(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Token _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			::Parser::Token _6;
			::Parser::bool_t success_7 = false;
			::Parser::Token _8;
			::Parser::bool_t success_9 = false;
			::Parser::Rule_res _10;
			::Parser::bool_t success_11 = false;
			success_1 = false;
			_0 = expression_qualifiedId_nestedNameSpecifier(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_5))
			{
				return {};
			}
			_2 = *pos;
			success_3 = true;
			pos += 1;
			skip_spaces(pos);
			success_5 = false;
			_4 = simpleTemplateId(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			success_7 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_15))
			{
				return {};
			}
			_6 = *pos;
			success_7 = true;
			pos += 1;
			skip_spaces(pos);
			success_9 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_18))
			{
				return {};
			}
			_8 = *pos;
			success_9 = true;
			pos += 1;
			skip_spaces(pos);
			success_11 = false;
			_10 = theTypeName(pos);
			if (!(_10.status))
			{
				return {};
			}
			success_11 = true;
			pos += _10.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_pseudoDestructorName_pseudoDestructorName2 data;
			data.type = _10.node;
			data.templateId = _4.node;
			data.specifier = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_pseudoDestructorName_pseudoDestructorName2, data)};
		}
		template <class IT>
		::Parser::Rule_res simpleTemplateId(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::simpleTemplateId)};
		}
		template <class IT>
		::Parser::Rule_res expression_lambda(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Rule_res _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			_0 = expression_lambda_introducer(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_3 = false;
			_2 = expression_lambda_declarator(pos);
			if (_2.status)
			{
				success_3 = true;
				pos += _2.node.length();
			}
			skip_spaces(pos);
			success_5 = false;
			_4 = compoundStatement(pos);
			if (!(_4.status))
			{
				return {};
			}
			success_5 = true;
			pos += _4.node.length();
			skip_spaces(pos);
			::Parser::Types::expression_lambda data;
			data.stmt = _4.node;
			data.declarator = _2.node;
			data.introducer = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_lambda, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_unqualifiedId_destructor(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = 1;
			int dfa_lookup_result_4;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_18))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = 1;
			dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_26, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_4)
			{
				case 0: {
					_2 = className(pos);

					break;

				}
				case 1: {
					_2 = decltypeSpecifier(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_unqualifiedId_destructor data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_unqualifiedId_destructor, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_qualifiedId_nestedNameSpecifier(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::bool_t success_9 = false;
			::Parser::bool_t success_3 = false;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_12 = false;
			::Parser::Token _8;
			::Parser::arr_t<::Parser::Token> shadow_10;
			success_9 = false;
			success_3 = false;
			success_1 = false;
			auto begin_11 = pos;
			success_12 = false;
			while (1)
			{
				auto begin_7 = begin_11;
				if (success_5)
				{
					success_3 = true;
					begin_11 = begin_7;
				}
				skip_spaces(begin_11);
				if (!(begin_11->name() == ::Parser::Tokens::AUTO_15))
				{
					break;
				}
				_8 = *begin_11;
				success_9 = true;
				begin_11 += 1;
				shadow_10.push_back(_8);
				success_12 = true;
			}
			if (!success_12)
			{
				reportError(pos, "");
				return {};
			}
			if (success_5 && success_3 && success_9)
			{
				success_1 = true;
				pos = begin_11;
			}
			skip_spaces(pos);
			::Parser::Types::expression_qualifiedId_nestedNameSpecifier data = _4;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_qualifiedId_nestedNameSpecifier, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_lambda_introducer_capture_captureDefault(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_28, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = *pos;

					break;

				}
				case 1: {
					_0 = *pos;

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_lambda_introducer_capture_captureDefault data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_lambda_introducer_capture_captureDefault, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_unaryExpression_sizeofArgument(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::any_t _2;
			::Parser::bool_t success_3 = 1;
			int dfa_lookup_result_4;
			::Parser::Token _5;
			::Parser::bool_t success_6 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = 1;
			dfa_lookup_result_4 = ISPA_STD::DFA<Tokens>::decide(dfa_span_29, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_4)
			{
				case 0: {
					_2 = *pos;

					break;

				}
				case 1: {
					_2 = theTypeId(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			success_6 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_5 = *pos;
			success_6 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_unaryExpression_sizeofArgument data = _2;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_unaryExpression_sizeofArgument, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_idExpression(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_30, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_unqualifiedId(pos);

					break;

				}
				case 1: {
					_0 = expression_qualifiedId(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_idExpression data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_idExpression, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_group(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			::Parser::Rule_res _2;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::bool_t success_5 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_8))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			success_3 = false;
			_2 = expression(pos);
			if (!(_2.status))
			{
				return {};
			}
			success_3 = true;
			pos += _2.node.length();
			skip_spaces(pos);
			success_5 = false;
			if (!(pos->name() == ::Parser::Tokens::AUTO_9))
			{
				return {};
			}
			_4 = *pos;
			success_5 = true;
			pos += 1;
			skip_spaces(pos);
			::Parser::Types::expression_group data = _2.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_group, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_lambda_introducer_capture(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_31, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = expression_lambda_introducer_capture_captureList(pos);

					break;

				}
				case 1: {
					_0 = expression_lambda_introducer_capture_list(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_lambda_introducer_capture data = _0.node;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_lambda_introducer_capture, data)};
		}
		template <class IT>
		::Parser::Rule_res expression_primary(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::any_t _0;
			::Parser::bool_t success_1 = 1;
			int dfa_lookup_result_2;
			success_1 = 1;
			dfa_lookup_result_2 = ISPA_STD::DFA<Tokens>::decide(dfa_span_32, pos, &ISPA_STD::LLParser_base<Tokens, Rules>::PANIC_MODE);
			switch (dfa_lookup_result_2)
			{
				case 0: {
					_0 = literal(pos);

					break;

				}
				case 1: {
					_0 = *pos;

					break;

				}
				case 2: {
					_0 = expression_group(pos);

					break;

				}
				case 3: {
					_0 = expression_idExpression(pos);

					break;

				}
				case 4: {
					_0 = expression_lambda(pos);

					break;

				}
			}
;
			skip_spaces(pos);
			::Parser::Types::expression_primary data = _0;
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_primary, data)};
		}
		template <class IT>
		::Parser::Rule_res initializer(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Token _0;
			::Parser::bool_t success_1 = false;
			success_1 = false;
			if (!(pos->name() == ::Parser::Tokens::ID))
			{
				return {};
			}
			_0 = *pos;
			success_1 = true;
			pos += 1;
			skip_spaces(pos);
			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::initializer)};
		}
		template <class IT>
		::Parser::Rule_res expression_lambda_introducer_capture_list(IT pos) {
			auto in = pos;
			skip_spaces(pos);
			::Parser::Rule_res _0;
			::Parser::bool_t success_1 = false;
			::Parser::bool_t success_7 = false;
			::Parser::bool_t success_5 = false;
			::Parser::bool_t success_3 = false;
			::Parser::Token _4;
			::Parser::Rule_res _6;
			success_1 = false;
			_0 = expression_lambda_introducer_capture_captureDefault(pos);
			if (!(_0.status))
			{
				return {};
			}
			success_1 = true;
			pos += _0.node.length();
			skip_spaces(pos);
			success_7 = false;
			success_5 = false;
			success_3 = false;
			auto begin_8 = pos;
			do
			{
				if (!(begin_8->name() == ::Parser::Tokens::AUTO_10))
				{
					break;
				}
				_4 = *begin_8;
				success_5 = true;
				begin_8 += 1;
				skip_spaces(begin_8);
				_6 = expression_lambda_introducer_capture_captureList(begin_8);
				if (!(_6.status))
				{
					break;
				}
				success_7 = true;
				begin_8 += _6.node.length();
			}
			while(0);
			if (success_5 && success_7)
			{
				success_3 = true;
				pos = begin_8;
			}
			skip_spaces(pos);
			::Parser::Types::expression_lambda_introducer_capture_list data;
			data.captureList = _6.node;
			data.def = _0.node;

			return {true, ::Parser::Rule(in->startpos(), in->start(), pos->end(), pos - in, pos->line(), pos->column(), ::Parser::Rules::expression_lambda_introducer_capture_list, data)};
		}
	};

} // Parser


#endif // PARSER
