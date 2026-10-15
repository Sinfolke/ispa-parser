module;
#include <tsl/ordered_map.h>
export module LLIR.Serialize;

import LangAPI;
import LLIR.API;
import dstd;
import std;

export namespace LLIR::Serialize {
    constexpr std::uint32_t FORMAT_VERSION = 1;

    // Writes one Production as a length-prefixed record.
    // Returns false (and writes nothing) if the Production contains a
    // DFADebug node — AST::RuleMember isn't serializable yet, so such
    // rules are never cached; they rebuild fully every run instead.
    auto writeProductionRecord(std::ostream &os, const Production &p) -> bool;

    // Reads one length-prefixed record written by writeProductionRecord.
    // Returns std::nullopt on any parse failure (corrupt/foreign record) —
    // callers should skip the entry and keep reading, not abort.
    auto readProductionRecord(std::istream &is) -> std::optional<Production>;
}