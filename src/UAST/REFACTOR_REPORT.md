# UAST refactor report

## Baseline and validation

- Initial command: `/usr/local/bin/cmake --build cmake-build-release -j 2`.
  The existing Clang 23.1.2/libc++ Release configuration selects the bootstrapped
  parser. Initial regeneration needed access to the vcpkg cache outside the
  filesystem sandbox.
- The unchanged checkout failed with 14 errors in `src/AST/Builder.cpp`, including
  obsolete parser fields `registration`, `ast_cap`, `val`, `alts`, `quantifier`,
  and `rule.data`. The initial CTest invocation reported `tests_NOT_BUILT`.
  The build log is `/tmp/ispa-uast-baseline-build.log` in this workspace.
- Final Release build succeeds. All 19 discovered GoogleTests pass, including
  both existing C++ integration tests, conversion of the complete checked-in
  ISPA grammar, guards for unsupported features, and serialization round trips
  of all 15 new AST node types.
- Tests run with the vcpkg libc++ library directory and LLVM libc++ directory in
  `LD_LIBRARY_PATH`. The integration harness invokes `clang++` directly, so a
  temporary PATH wrapper selects `/opt/llvm-23.1.2-icx/bin/clang++` with libc++
  flags matching the configured build. It does not modify project toolchains.
- Final test command:

  ```sh
  env PATH=/tmp/ispa-uast-toolchain:/usr/local/bin:/usr/bin:/bin \
    LD_LIBRARY_PATH="$PWD/cmake-build-release/vcpkg_installed/x64-linux-libcxx/lib:/opt/llvm-23.1.2-icx/lib" \
    /usr/local/bin/ctest --test-dir cmake-build-release --output-on-failure
  ```

- A sample with a captured `[a-z]+` token and a captured `main` rule was generated
  at the first buildable checkpoint and again in a fresh output directory after
  the complete refactor. Both `Parser.h` and `Parser.cpp` are byte-identical.
  These artifacts are `/tmp/ispa-uast-baseline` and
  `/tmp/ispa-uast-checkpoint-final`.
- Comparison against output from the original checkout cannot be verified:
  that checkout does not build. The sample comparison is not an exhaustive
  equivalence proof for every historical grammar.

## Files added

- `src/UAST/Types.cppm`: owned grammar syntax types, source positions, binding
  metadata, and a compact Python syntax tree.
- `src/UAST/Parser.cppm`, `src/UAST/Parser.cpp`: exhaustive grammar parser
  adapters and structural advanced-rule snapshots.
- `src/UAST/Python.cppm`, `src/UAST/Python.cpp`: bootstrapped Python parsing and
  exhaustive conversion of its 200 output types into the compact subtree.
- `src/UAST/README.md`, `src/UAST/REFACTOR_REPORT.md`: contracts and verification.
- `src/AST/Frontend.cppm`: serializable front-end AST nodes.
- `src/AST/BackendGuard.cppm`, `src/AST/BackendGuard.cpp`: pre-backend rejection.
- `tests/UAST.cpp`, `tests/UASTBackendGuard.cpp`,
  `tests/UASTSerialization.cpp`: conversion, positions, ownership, guards,
  bootstrap grammar, and serialization coverage.
- `../../parser/python/bootstrapped_0`: the supplied regenerated Python
  parser header, replacing the old `Parser.h` namespace/API.

## Files changed

- `src/AST/Builder.cppm`, `src/AST/Builder.cpp`: convert UAST, retain new feature
  data and Python payloads, and leave resolution and validation to the preceding
  semantic stage.
- `src/AST/API.cppm`: add feature/source data to Rule and RuleMember; their
  `members()` now includes every member without changing public member order.
- `src/AST/API.cpp`: recognize feature-bearing members as nonempty.
- `src/AST/Tree.cppm`: own fail declarations.
- `src/main.cpp`: create UAST while each input buffer is alive and call the guard
  before any AST passes or backend work.
- `CMakeLists.txt`: add the bootstrapped Python implementation source and its
  include directory to the existing `ispa_modules` target. No targets or CI
  structure were changed.
- `parser/ispa/bootstrapped/Parser.cpp`: retain rule spans and initialize the
  lazy lexer input so offsets are valid.
- `../../parser/python/bootstrapped_0` renamed/regenerated as
  `PyRawParser.cpp`; `Parser.h` replaced by `PyRawParser.h`.
  The supplied namespace/API update avoids collisions with the ISPA parser.
  Rule spans and lazy-input initialization were added to this front-end parser.
- `parser/python/parser.hpp`, `parser/python/main.cpp`: incorporate the supplied
  Python parser namespace/API adaptation needed by the integration.
- `tests/compile/lexer.cpp`: use the existing RawToken `print()` API instead of
  the unavailable stream insertion operator. No runtime change was necessary.

The unrelated workspace changes in `external/cpuf`, `parser/CMakeLists.txt`, and
`treeAPI.txt` remain outside the refactor commits.

## Backend touches

None. DFA/NFA construction, LLIR, language representation, converters, and code
generation have no changes. Generated bootstrap parser implementations are
front-end inputs; their span fixes do not modify the code generator.

## Decisions and remaining limits

- Region captures remain explicit group nodes with `RegionCapture` metadata.
  Their region scope and `@` versus `%` distinction are retained.
- New features are typed nodes in `FrontendFeature`, attached to rules or rule
  members. This preserves all existing backend-used variants and public fields.
- Python is an owned structural tree retaining node kinds, field names, scalar
  payloads, variants, sequences, absent nodes, and positions. AST PythonAction
  carries this tree, supplied capture bindings, and an optional AST-block target
  name. Dynamic patterns and expression bounds also carry PythonAction payloads.
  There is no Python-to-CLL or Python-to-LangAPI lowering.
- All new AST nodes have private mutable/const `members()` tying every field and
  friend the existing plural `MembersAccess`. They also have the required
  singular `MemberAccess` friend declaration. Tests exercise the actual existing
  `MembersAccess` reflection mechanism without changing the backend serializer.
- The guard rejects fail declarations/bindings/markers, regions, dynamic patterns,
  bounded counters, shared registrations, Python actions, advanced rules,
  variable captures, parameterized/modifier syntax, and explicit `\\s` atoms.
  Plain EBNF and ordinary AST captures retain the existing lowering path.
- CLL compatibility types remain: LLIR directly uses them, including CllExpr for
  ordinary AST capture return blocks. Deleting them would require non-additive
  backend changes. Builder no longer creates CLL for Python; only the legacy
  `{@}` capture-return representation uses that existing expression path.
- The checked-in ISPA grammar defines `PY_RAW` as the placeholder literal
  `p{py}`. The additional parsing step handles received raw payloads, and direct
  Python parsing is tested with assignment, conditional, return, and expression
  syntax. General raw-block extraction requires a separate lexer/grammar update;
  this refactor does not claim to extend that syntax.
- Qualified names and action binding metadata are the responsibility of the
  preceding semantic stage. Builder does not infer or resolve capture bindings.
- Imports and feature disabling remain preprocessing concerns. Module support
  was omitted as clarified. No semantic analysis was implemented.
