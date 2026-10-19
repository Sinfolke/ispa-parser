# Front-end syntax data

`UAST` owns the bootstrapped grammar parser's complete syntax output, including
optional versus absent nodes, variant alternatives, nested rules, captures,
counters, failure handlers, advanced rules, and Python subtrees. The node types
do not resolve names, validate input, or implement semantic analysis.

The driver calls `UAST::fromParser` for each input while its source buffer is
alive. The result contains owned strings and numeric source positions, with no
borrowed pointers into the parser or input. The compatibility `AST::Builder`
constructor accepting parser output performs the same copy immediately.

`UAST::parsePython` uses the bootstrapped Python parser and its indentation
lexer. The compact subtree retains each generated Python node kind, named
field, sequence, variant discriminator, scalar, absent node, and source position.
It is syntax data, not printed Python, CLL, LangAPI, or generated code.

The semantic stage preceding Builder is responsible for qualifying references
and supplying `expr::bindings` and `stmt::bindings`. Builder copies those
bindings, including optional/list flags, without resolving identifiers or
inferring capture types. Raw parser output does not contain resolved bindings.

Builder normalizes ordinary patterns and AST captures into the existing AST.
Additional nodes live in `AST.Frontend` and are attached to rules or rule members
through `FrontendFeature`; fail declarations live in `Tree::getFailBlocks()`.
Regions remain explicit groups with `RegionCapture` metadata. Unsupported
patterns still count as nonempty AST members.

`AST::requireCppSupport` must run before AST passes or any backend work. It
rejects unsupported features with a source position. The driver invokes it
before its existing semantic checks, tree passes, automata, and LLIR builders.

All new AST payloads provide private mutable and const `members()` returning a
tuple of references to every field. They friend the existing serializer's
`LLIR::Serialize::MembersAccess`, as well as the requested singular
`LLIR::Serialize::MemberAccess` declaration. No backend serializer was changed.

The generated bootstrap parser implementations now initialize their lazy
lexers and attach rule source spans. These front-end-only additions must be
preserved when replacing those generated files; the code generator is unchanged.

Imports and feature disabling belong to preprocessing. Module support is
deferred. Python lowering and backend support for the new features are deferred.

Compatibility limits:

- Existing CLL types remain because LLIR uses them, including for ordinary AST
  capture return blocks. Builder creates PythonAction for Python payloads and
  never translates Python into CLL.
- The checked-in ISPA grammar still defines `PY_RAW` as the literal `p{py}`.
  The additional Python step parses the payload it receives; arbitrary Python
  text is supported by `parsePython`, but extending the ISPA raw-block lexer is
  a separate grammar/parser change.
- Builder assumes semantically valid UAST. It no longer performs the previous
  name lookup, unique-suffix fallback, or duplicate-declaration validation.
