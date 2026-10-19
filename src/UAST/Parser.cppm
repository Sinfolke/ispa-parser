module;
#include <output/Parser.h>
export module UAST.Parser;
export import UAST;
import std;
export namespace UAST {
    main fromParser(const Parser::Types::main& root, const std::string& file = {});
}
