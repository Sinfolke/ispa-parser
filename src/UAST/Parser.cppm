module;
#include <output/Parser.h>
export module UAST.Parser;
export import UAST;
import std;
export namespace UAST {
    // Generic tree dump of an advanced rule (kinds, field names, positions).
    // `position` is the rule's own position; the file name of every node comes from it.
    PythonNode describe(const advanced_rule& value, const SourcePosition& position);
}
