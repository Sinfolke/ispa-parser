# Algorithm modules

The host loads `libispa-algorithm-<name>` and calls the single exported
`ispa_algorithm_v1` entry point. It returns an `Algorithm::Descriptor` defined
in `API.cppm`. LL is the default selection and uses the same loading path as LR
and LALR. LR_STAR advertises the interface but still rejects builds as unsupported.

`build(request, metadata)` receives the complete grammar, the changed-rule set,
conflict settings, and any previous metadata. It returns an opaque output with a
`to_lang_repr` callback. The host invokes that callback without knowing the output
type or choosing an algorithm-specific LangRepr constructor. Conversion consumes
the output and lexer; call it once per build. All results and holders must be
destroyed before unloading the algorithm library.

The algorithm may add, replace, or erase entries in `metadata.cache`. Keys are
single filenames and values are arbitrary binary strings. The host restores them
before building and publishes a new snapshot after successful code generation.
It does not interpret their contents. Storage is isolated by output namespace,
algorithm ID, cache version, target language, and conflict settings. Bump
`cache_version` whenever an algorithm's serialized state or lowering semantics
change. Missing or incompatible cache data must support a cold build.

LL owns its builder and serializer under `LL/IR`. Its grammar stamp invalidates
all cached productions when any rule changes, since FIRST/FOLLOW and inferred
types have cross-rule dependencies. Unchanged grammars restore available
productions; missing or corrupt records rebuild.

LR and LALR persist a versioned, checksummed `tables` snapshot. Reusable chunks
are canonical state closures and per-state ACTION proposals (including conflict
origins). Each closure tracks the alternatives it expands and the FIRST sets of
suffix symbols it reads. A row additionally depends on its outgoing transitions.
Structural edits invalidate those dependency keys; unaffected entries are reused.
Only entries visited by the current build are retained in the next snapshot.

Production references encode qualified LHS, RHS symbols, whitespace gaps, and the
occurrence among structurally identical alternatives. State references encode
sorted structural production items and lookahead names. References never persist
production/state array indices or pointers. Every build reassigns indices and
reconnects productions to the current AST, preserving fresh actions, captures,
and diagnostic positions. Adding or deleting other productions cannot shift a
cached reference onto the wrong rule.

FIRST sets, graph traversal, dense table packing, and LALR core merging still run.
The tracker reuses expensive closure expansion and table proposal construction;
it does not patch the live automaton in place. Conflict-resolution decisions are
restored only for an identical complete structural grammar and lookahead budget;
otherwise they are recomputed globally. This conservative boundary accounts for
the resolver's FIRST/FOLLOW dependencies across the grammar. Semantic-only edits
reuse structural work while LangRepr regenerates semantics from the current AST.
Malformed, incompatible, or checksum-mismatched snapshots fall back to cold builds.
`LRParser::getCacheStats()` exposes reuse/build counts for verification.

`src/ParserIR` contains the shared data-block and statement representation consumed
by lexer and LangRepr generation for all algorithms. It has no LL builder or cache
policy. The executable does not import LL implementation modules or link algorithm
libraries directly.

The host and plugins link the shared `ispacore` core so AST types, logging,
dumper settings, and other process state have one owner across runtime loads.

This is a versioned C++ plugin protocol with an `extern "C"` discovery symbol,
not a portable C ABI. Plugins must be built against the same API, compiler, and
standard library as the host. The old LR create/finish exports remain available
for existing callers.
