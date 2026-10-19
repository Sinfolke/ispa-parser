module;
#include <output/Parser.h>
export module UAST.Parser;
export import UAST;
import std;
export namespace UAST {
    PythonNode describe(const advanced_rule& value, const SourcePosition& position);
    main fromParser(const Parser::Types::main& root, const std::string& file = {});
}
