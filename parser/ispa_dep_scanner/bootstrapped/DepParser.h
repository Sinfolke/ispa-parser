#pragma once

#include <ispastdlib.hpp>

namespace DepParser {
	namespace Tokens {
		namespace AUTO {
			inline const std::size_t id = 2;
		} // namespace AUTO
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace COMMA {
			inline const std::size_t id = 8;
		} // namespace COMMA
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace ID {
			inline const std::size_t id = 11;
		} // namespace ID
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace SEMICOLON {
			inline const std::size_t id = 4;
		} // namespace SEMICOLON
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace __WS {
			inline const std::size_t id = 9;
		} // namespace __WS
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_detach {
			inline const std::size_t id = 14;
		} // namespace mod_detach
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_detach {
			namespace DETACH {
				inline const std::size_t id = 5;
			} // namespace DETACH
		} // namespace mod_detach
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_import {
			inline const std::size_t id = 15;
		} // namespace mod_import
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_import {
			namespace IMPORT {
				inline const std::size_t id = 13;
			} // namespace IMPORT
		} // namespace mod_import
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_import {
			namespace import_value {
				inline const std::size_t id = 16;
			} // namespace import_value
		} // namespace mod_import
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					inline const std::size_t id = 17;
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace FROM {
						inline const std::size_t id = 6;
					} // namespace FROM
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						inline const std::size_t id = 18;
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						namespace ALL {
							inline const std::size_t id = 12;
						} // namespace ALL
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						namespace items {
							inline const std::size_t id = 19;
						} // namespace items
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						namespace items {
							namespace LEFT_CURLY_BRACKET {
								inline const std::size_t id = 10;
							} // namespace LEFT_CURLY_BRACKET
						} // namespace items
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						namespace items {
							namespace RIGHT_CURLY_BRACKET {
								inline const std::size_t id = 7;
							} // namespace RIGHT_CURLY_BRACKET
						} // namespace items
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_import {
			namespace import_value {
				namespace module_import {
					inline const std::size_t id = 20;
				} // namespace module_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace mod_import {
			namespace import_value {
				namespace module_import {
					namespace AS {
						inline const std::size_t id = 3;
					} // namespace AS
				} // namespace module_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace name {
			inline const std::size_t id = 21;
		} // namespace name
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace name {
			namespace template_params {
				inline const std::size_t id = 22;
			} // namespace template_params
		} // namespace name
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace name {
			namespace template_params {
				namespace GREATER_THAN_SIGN {
					inline const std::size_t id = 0;
				} // namespace GREATER_THAN_SIGN
			} // namespace template_params
		} // namespace name
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace Tokens {
		namespace name {
			namespace template_params {
				namespace LESS_THAN_SIGN {
					inline const std::size_t id = 1;
				} // namespace LESS_THAN_SIGN
			} // namespace template_params
		} // namespace name
	} // namespace Tokens
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace AUTO {
			inline const char* const id = "AUTO";
		} // namespace AUTO
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace COMMA {
			inline const char* const id = "COMMA";
		} // namespace COMMA
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace ID {
			inline const char* const id = "ID";
		} // namespace ID
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace SEMICOLON {
			inline const char* const id = "SEMICOLON";
		} // namespace SEMICOLON
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace __WS {
			inline const char* const id = "__WS";
		} // namespace __WS
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_detach {
			inline const char* const id = "mod_detach";
		} // namespace mod_detach
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_detach {
			namespace DETACH {
				inline const char* const id = "mod_detach.DETACH";
			} // namespace DETACH
		} // namespace mod_detach
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_import {
			inline const char* const id = "mod_import";
		} // namespace mod_import
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_import {
			namespace IMPORT {
				inline const char* const id = "mod_import.IMPORT";
			} // namespace IMPORT
		} // namespace mod_import
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_import {
			namespace import_value {
				inline const char* const id = "mod_import.import_value";
			} // namespace import_value
		} // namespace mod_import
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					inline const char* const id = "mod_import.import_value.from_import";
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace FROM {
						inline const char* const id = "mod_import.import_value.from_import.FROM";
					} // namespace FROM
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						inline const char* const id = "mod_import.import_value.from_import.selection";
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						namespace ALL {
							inline const char* const id = "mod_import.import_value.from_import.selection.ALL";
						} // namespace ALL
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						namespace items {
							inline const char* const id = "mod_import.import_value.from_import.selection.items";
						} // namespace items
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						namespace items {
							namespace LEFT_CURLY_BRACKET {
								inline const char* const id = "mod_import.import_value.from_import.selection.items.LEFT_CURLY_BRACKET";
							} // namespace LEFT_CURLY_BRACKET
						} // namespace items
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						namespace items {
							namespace RIGHT_CURLY_BRACKET {
								inline const char* const id = "mod_import.import_value.from_import.selection.items.RIGHT_CURLY_BRACKET";
							} // namespace RIGHT_CURLY_BRACKET
						} // namespace items
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_import {
			namespace import_value {
				namespace module_import {
					inline const char* const id = "mod_import.import_value.module_import";
				} // namespace module_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace mod_import {
			namespace import_value {
				namespace module_import {
					namespace AS {
						inline const char* const id = "mod_import.import_value.module_import.AS";
					} // namespace AS
				} // namespace module_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace name {
			inline const char* const id = "name";
		} // namespace name
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace name {
			namespace template_params {
				inline const char* const id = "name.template_params";
			} // namespace template_params
		} // namespace name
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace name {
			namespace template_params {
				namespace GREATER_THAN_SIGN {
					inline const char* const id = "name.template_params.GREATER_THAN_SIGN";
				} // namespace GREATER_THAN_SIGN
			} // namespace template_params
		} // namespace name
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace TokenNames {
		namespace name {
			namespace template_params {
				namespace LESS_THAN_SIGN {
					inline const char* const id = "name.template_params.LESS_THAN_SIGN";
				} // namespace LESS_THAN_SIGN
			} // namespace template_params
		} // namespace name
	} // namespace TokenNames
} // namespace DepParser
namespace DepParser {
	namespace Rules {
		namespace main {
			inline const std::size_t id = 0;
		} // namespace main
	} // namespace Rules
} // namespace DepParser
namespace DepParser {
	namespace Rules {
		namespace mod_detach {
			inline const std::size_t id = 1;
		} // namespace mod_detach
	} // namespace Rules
} // namespace DepParser
namespace DepParser {
	namespace Rules {
		namespace mod_import {
			inline const std::size_t id = 2;
		} // namespace mod_import
	} // namespace Rules
} // namespace DepParser
namespace DepParser {
	namespace Rules {
		namespace mod_import {
			namespace import_value {
				inline const std::size_t id = 3;
			} // namespace import_value
		} // namespace mod_import
	} // namespace Rules
} // namespace DepParser
namespace DepParser {
	namespace Rules {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					inline const std::size_t id = 4;
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Rules
} // namespace DepParser
namespace DepParser {
	namespace Rules {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						inline const std::size_t id = 5;
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Rules
} // namespace DepParser
namespace DepParser {
	namespace Rules {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						namespace items {
							inline const std::size_t id = 6;
						} // namespace items
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Rules
} // namespace DepParser
namespace DepParser {
	namespace Rules {
		namespace mod_import {
			namespace import_value {
				namespace module_import {
					inline const std::size_t id = 7;
				} // namespace module_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace Rules
} // namespace DepParser
namespace DepParser {
	namespace Rules {
		namespace module_path {
			inline const std::size_t id = 8;
		} // namespace module_path
	} // namespace Rules
} // namespace DepParser
namespace DepParser {
	namespace Rules {
		namespace name {
			inline const std::size_t id = 9;
		} // namespace name
	} // namespace Rules
} // namespace DepParser
namespace DepParser {
	namespace Rules {
		namespace name {
			namespace param {
				inline const std::size_t id = 10;
			} // namespace param
		} // namespace name
	} // namespace Rules
} // namespace DepParser
namespace DepParser {
	namespace Rules {
		namespace name {
			namespace template_params {
				inline const std::size_t id = 11;
			} // namespace template_params
		} // namespace name
	} // namespace Rules
} // namespace DepParser
namespace DepParser {
	namespace RuleNames {
		namespace main {
			inline const char* const id = "main";
		} // namespace main
	} // namespace RuleNames
} // namespace DepParser
namespace DepParser {
	namespace RuleNames {
		namespace mod_detach {
			inline const char* const id = "mod_detach";
		} // namespace mod_detach
	} // namespace RuleNames
} // namespace DepParser
namespace DepParser {
	namespace RuleNames {
		namespace mod_import {
			inline const char* const id = "mod_import";
		} // namespace mod_import
	} // namespace RuleNames
} // namespace DepParser
namespace DepParser {
	namespace RuleNames {
		namespace mod_import {
			namespace import_value {
				inline const char* const id = "mod_import.import_value";
			} // namespace import_value
		} // namespace mod_import
	} // namespace RuleNames
} // namespace DepParser
namespace DepParser {
	namespace RuleNames {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					inline const char* const id = "mod_import.import_value.from_import";
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace RuleNames
} // namespace DepParser
namespace DepParser {
	namespace RuleNames {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						inline const char* const id = "mod_import.import_value.from_import.selection";
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace RuleNames
} // namespace DepParser
namespace DepParser {
	namespace RuleNames {
		namespace mod_import {
			namespace import_value {
				namespace from_import {
					namespace selection {
						namespace items {
							inline const char* const id = "mod_import.import_value.from_import.selection.items";
						} // namespace items
					} // namespace selection
				} // namespace from_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace RuleNames
} // namespace DepParser
namespace DepParser {
	namespace RuleNames {
		namespace mod_import {
			namespace import_value {
				namespace module_import {
					inline const char* const id = "mod_import.import_value.module_import";
				} // namespace module_import
			} // namespace import_value
		} // namespace mod_import
	} // namespace RuleNames
} // namespace DepParser
namespace DepParser {
	namespace RuleNames {
		namespace module_path {
			inline const char* const id = "module_path";
		} // namespace module_path
	} // namespace RuleNames
} // namespace DepParser
namespace DepParser {
	namespace RuleNames {
		namespace name {
			inline const char* const id = "name";
		} // namespace name
	} // namespace RuleNames
} // namespace DepParser
namespace DepParser {
	namespace RuleNames {
		namespace name {
			namespace param {
				inline const char* const id = "name.param";
			} // namespace param
		} // namespace name
	} // namespace RuleNames
} // namespace DepParser
namespace DepParser {
	namespace RuleNames {
		namespace name {
			namespace template_params {
				inline const char* const id = "name.template_params";
			} // namespace template_params
		} // namespace name
	} // namespace RuleNames
} // namespace DepParser
namespace DepParser::FlatTypes { struct name_template_params_GREATER_THAN_SIGN; }
namespace DepParser::FlatTypes { struct name; }
namespace DepParser::FlatTypes { struct name_template_params; }
namespace DepParser::FlatTypes { struct name_template_params_LESS_THAN_SIGN; }
namespace DepParser::FlatTypes { struct AUTO; }
namespace DepParser::FlatTypes { struct mod_import_import_value_module_import_AS; }
namespace DepParser::FlatTypes { struct mod_import; }
namespace DepParser::FlatTypes { struct mod_import_import_value; }
namespace DepParser::FlatTypes { struct mod_import_import_value_module_import; }
namespace DepParser::FlatTypes { struct SEMICOLON; }
namespace DepParser::FlatTypes { struct mod_detach_DETACH; }
namespace DepParser::FlatTypes { struct mod_detach; }
namespace DepParser::FlatTypes { struct mod_import_import_value_from_import_FROM; }
namespace DepParser::FlatTypes { struct mod_import_import_value_from_import; }
namespace DepParser::FlatTypes { struct mod_import_import_value_from_import_selection_items_RIGHT_CURLY_BRACKET; }
namespace DepParser::FlatTypes { struct mod_import_import_value_from_import_selection; }
namespace DepParser::FlatTypes { struct mod_import_import_value_from_import_selection_items; }
namespace DepParser::FlatTypes { struct COMMA; }
namespace DepParser::FlatTypes { struct __WS; }
namespace DepParser::FlatTypes { struct mod_import_import_value_from_import_selection_items_LEFT_CURLY_BRACKET; }
namespace DepParser::FlatTypes { struct ID; }
namespace DepParser::FlatTypes { struct mod_import_import_value_from_import_selection_ALL; }
namespace DepParser::FlatTypes { struct mod_import_IMPORT; }
namespace DepParser::FlatTypes { struct main; }
namespace DepParser::FlatTypes { struct module_path; }
namespace DepParser::FlatTypes { struct name_param; }
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, name_template_params_GREATER_THAN_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct name_template_params_GREATER_THAN_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, name_template_params_LESS_THAN_SIGN value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct name_template_params_LESS_THAN_SIGN {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, AUTO value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct AUTO {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_import_import_value_module_import_AS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_import_import_value_module_import_AS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, SEMICOLON value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct SEMICOLON {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_detach_DETACH value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_detach_DETACH {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_import_import_value_from_import_FROM value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_import_import_value_from_import_FROM {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_import_import_value_from_import_selection_items_RIGHT_CURLY_BRACKET value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_import_import_value_from_import_selection_items_RIGHT_CURLY_BRACKET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, COMMA value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct COMMA {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, __WS value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct __WS {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_import_import_value_from_import_selection_items_LEFT_CURLY_BRACKET value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_import_import_value_from_import_selection_items_LEFT_CURLY_BRACKET {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, ID value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct ID {
			std::string value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_import_import_value_from_import_selection_ALL value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_import_import_value_from_import_selection_ALL {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_import_IMPORT value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_import_IMPORT {
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, module_path value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct module_path {
			::ISPA_STD::Node<::DepParser::FlatTypes::ID> primary;
			std::vector<::ISPA_STD::Node<::DepParser::FlatTypes::ID>> nested;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, name_param value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct name_param {
			::ISPA_STD::Node<::DepParser::FlatTypes::ID> first_p;
			std::vector<::ISPA_STD::Node<::DepParser::FlatTypes::ID>> following_p;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_import_import_value_module_import value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_import_import_value_module_import {
			::ISPA_STD::Node<::DepParser::FlatTypes::module_path> source;
			::ISPA_STD::Node<::DepParser::FlatTypes::ID> alias;
			using AS = ::DepParser::FlatTypes::mod_import_import_value_module_import_AS;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_detach value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_detach {
			::ISPA_STD::Node<::DepParser::FlatTypes::module_path> value;
			using DETACH = ::DepParser::FlatTypes::mod_detach_DETACH;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_import_import_value_from_import_selection_items value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_import_import_value_from_import_selection_items {
			::ISPA_STD::Node<::DepParser::FlatTypes::module_path> first;
			std::vector<::ISPA_STD::Node<::DepParser::FlatTypes::module_path>> sequence;
			using RIGHT_CURLY_BRACKET = ::DepParser::FlatTypes::mod_import_import_value_from_import_selection_items_RIGHT_CURLY_BRACKET;
			using LEFT_CURLY_BRACKET = ::DepParser::FlatTypes::mod_import_import_value_from_import_selection_items_LEFT_CURLY_BRACKET;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, name_template_params value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct name_template_params {
			::ISPA_STD::Node<::DepParser::FlatTypes::name_param> value;
			using GREATER_THAN_SIGN = ::DepParser::FlatTypes::name_template_params_GREATER_THAN_SIGN;
			using LESS_THAN_SIGN = ::DepParser::FlatTypes::name_template_params_LESS_THAN_SIGN;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_import_import_value_from_import_selection value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_import_import_value_from_import_selection {
			std::variant<std::monostate, ::ISPA_STD::Node<::DepParser::FlatTypes::mod_import_import_value_from_import_selection_items>, ::ISPA_STD::Node<::DepParser::FlatTypes::mod_import_import_value_from_import_selection_ALL>> value;
			using items = ::DepParser::FlatTypes::mod_import_import_value_from_import_selection_items;
			using ALL = ::DepParser::FlatTypes::mod_import_import_value_from_import_selection_ALL;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, name value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct name {
			::ISPA_STD::Node<::DepParser::FlatTypes::ID> primary;
			std::vector<::ISPA_STD::Node<::DepParser::FlatTypes::ID>> nested;
			::ISPA_STD::Node<::DepParser::FlatTypes::name_template_params> temp_params;
			using template_params = ::DepParser::FlatTypes::name_template_params;
			using param = ::DepParser::FlatTypes::name_param;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_import_import_value_from_import value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_import_import_value_from_import {
			::ISPA_STD::Node<::DepParser::FlatTypes::mod_import_import_value_from_import_selection> sel;
			::ISPA_STD::Node<::DepParser::FlatTypes::module_path> source;
			using FROM = ::DepParser::FlatTypes::mod_import_import_value_from_import_FROM;
			using selection = ::DepParser::FlatTypes::mod_import_import_value_from_import_selection;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_import_import_value value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_import_import_value {
			std::variant<std::monostate, ::ISPA_STD::Node<::DepParser::FlatTypes::mod_import_import_value_from_import>, ::ISPA_STD::Node<::DepParser::FlatTypes::mod_import_import_value_module_import>> value;
			using module_import = ::DepParser::FlatTypes::mod_import_import_value_module_import;
			using from_import = ::DepParser::FlatTypes::mod_import_import_value_from_import;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, mod_import value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct mod_import {
			::ISPA_STD::Node<::DepParser::FlatTypes::mod_import_import_value> value;
			using import_value = ::DepParser::FlatTypes::mod_import_import_value;
			using IMPORT = ::DepParser::FlatTypes::mod_import_IMPORT;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		auto operator<<(std::ostream & os, main value) -> std::ostream &;
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace FlatTypes {
		struct main {
			std::variant<std::monostate, ::ISPA_STD::Node<::DepParser::FlatTypes::mod_detach>, ::ISPA_STD::Node<::DepParser::FlatTypes::mod_import>> value;
			auto write_to_output(::ISPA_STD::ASTPrinter<std::ostream>& printer) const -> void;
			auto print(std::ostream& os) const -> void;
			auto to_string() const -> std::string;
		};
	} // namespace FlatTypes
} // namespace DepParser
namespace DepParser {
	namespace Types {
		using name = ::DepParser::FlatTypes::name;
	} // namespace Types
} // namespace DepParser
namespace DepParser {
	namespace Types {
		using AUTO = ::DepParser::FlatTypes::AUTO;
	} // namespace Types
} // namespace DepParser
namespace DepParser {
	namespace Types {
		using mod_import = ::DepParser::FlatTypes::mod_import;
	} // namespace Types
} // namespace DepParser
namespace DepParser {
	namespace Types {
		using SEMICOLON = ::DepParser::FlatTypes::SEMICOLON;
	} // namespace Types
} // namespace DepParser
namespace DepParser {
	namespace Types {
		using mod_detach = ::DepParser::FlatTypes::mod_detach;
	} // namespace Types
} // namespace DepParser
namespace DepParser {
	namespace Types {
		using COMMA = ::DepParser::FlatTypes::COMMA;
	} // namespace Types
} // namespace DepParser
namespace DepParser {
	namespace Types {
		using __WS = ::DepParser::FlatTypes::__WS;
	} // namespace Types
} // namespace DepParser
namespace DepParser {
	namespace Types {
		using ID = ::DepParser::FlatTypes::ID;
	} // namespace Types
} // namespace DepParser
namespace DepParser {
	namespace Types {
		using main = ::DepParser::FlatTypes::main;
	} // namespace Types
} // namespace DepParser
namespace DepParser {
	namespace Types {
		using module_path = ::DepParser::FlatTypes::module_path;
	} // namespace Types
} // namespace DepParser
namespace DepParser {
	using Token = ::ISPA_STD::RawToken<Types::name::template_params::GREATER_THAN_SIGN, Types::name::template_params::LESS_THAN_SIGN, Types::AUTO, Types::mod_import::import_value::module_import::AS, Types::SEMICOLON, Types::mod_detach::DETACH, Types::mod_import::import_value::from_import::FROM, Types::mod_import::import_value::from_import::selection::items::RIGHT_CURLY_BRACKET, Types::COMMA, Types::__WS, Types::mod_import::import_value::from_import::selection::items::LEFT_CURLY_BRACKET, Types::ID, Types::mod_import::import_value::from_import::selection::ALL, Types::mod_import::IMPORT>;
} // namespace DepParser
namespace DepParser {
	class Lexer : public ::ISPA_STD::Lexer_base<Token> {
		static ::ISPA_STD::DFA::API::CharToClass char_class_table;
		static ::ISPA_STD::DFA::API::Table<31, 25> dfa_table;
		static ::ISPA_STD::DFA::API::Table<36, 4> action_table;
		static auto semantic_action_exec(long long state, const ::ISPA_STD::DFA::API::Captures& captures, long long start_pos, const char* start, long long length, long long line) -> std::pair<long long, Token>;
		bool init_done = false;
		auto init() -> void override;
		::ISPA_STD::DFA::API::TdfaLayout<3, 2> tdfa_registers;
		static std::array<::ISPA_STD::DFA::API::DFADebug, 1> debug_array;
		static std::unordered_map<long long, std::unordered_map<long long, long long>> debug_index;
	public:
		auto makeToken(const char*& pos) -> Token override;
	};
} // namespace DepParser
namespace DepParser {
	class Parser : public ::ISPA_STD::LLParser<Types::main, Token> {
	protected:
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::lazy_iterator>>> auto main(IT pos) -> ::ISPA_STD::MatchResult<Types::main, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::lazy_iterator>>> auto mod_detach(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_detach, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::lazy_iterator>>> auto mod_import(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_import, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::lazy_iterator>>> auto mod_import_import_value(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::lazy_iterator>>> auto mod_import_import_value_from_import(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::lazy_iterator>>> auto mod_import_import_value_from_import_selection(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import::selection, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::lazy_iterator>>> auto mod_import_import_value_from_import_selection_items(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::from_import::selection::items, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::lazy_iterator>>> auto mod_import_import_value_module_import(IT pos) -> ::ISPA_STD::MatchResult<Types::mod_import::import_value::module_import, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::lazy_iterator>>> auto module_path(IT pos) -> ::ISPA_STD::MatchResult<Types::module_path, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::lazy_iterator>>> auto name(IT pos) -> ::ISPA_STD::MatchResult<Types::name, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::lazy_iterator>>> auto name_param(IT pos) -> ::ISPA_STD::MatchResult<Types::name::param, IT>;
		template<typename IT, class = std::enable_if_t<std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::iterator> || std::is_same_v<std::remove_const_t<std::remove_reference_t<IT>>, ::DepParser::Lexer::lazy_iterator>>> auto name_template_params(IT pos) -> ::ISPA_STD::MatchResult<Types::name::template_params, IT>;
	public:
		auto parseFromTokens() -> void override;
		auto lazyParse() -> void override;
	};
} // namespace DepParser
