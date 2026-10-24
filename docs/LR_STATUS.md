# LR and LALR backend status

The LR and LALR plugins compile the normalized `AST::Tree` into LR tables and
use `ispastdlib/lr_machine.hpp` to recognize input. They share token and AST
type generation with LL. Normalized groups, alternatives, optional members,
repetitions, and captures are lowered through reduction metadata. LR(k) table
construction exists, although the plugin currently requests one token of
lookahead. Automatic conflict resolution may extend the decision window and
use the generalized runtime for unresolved cells.

## Observable behavior

| Feature | LR/LALR status |
| --- | --- |
| Static grammar recognition, including left recursion | Supported |
| Advanced rules containing only ordinary `match` clauses | Supported |
| AST types and basic captures | Shared types; reduction-based capture assignment |
| Expected token and source rule on missing LR ACTION cell | Structured diagnostic via `getErrors()` and exception text |
| Embedded Python actions and multiple conditional `match` operations | Rejected at generation |
| Rule parameters, shared counters, dynamic patterns, external rules | Rejected at generation |
| Custom failure handlers and all recovery modes | Rejected at generation or unavailable in LR runtime |
| LR AST rule source spans | Not populated; token captures retain lexer positions |
| Generated parser API | `parse(...)` and `getErrors()`; no LL recovery context API |

The plugin entry point applies the same C++ feature guard as the CLI. This
matters because an advanced action is represented by a zero-width member in
the grammar AST; compiling it as an ordinary epsilon reduction would silently
skip the Python code.

The deterministic LR runtime reports an invalid ACTION cell without changing
the LR stack or token cursor. It retains the actual token ID, the first tokens of
valid action windows, input offset when the token has lexer metadata, and the
source rule names represented by the LR state. An LALR state can represent
multiple contexts, so its rule field may contain several names. Expected
tokens are derived from ACTION windows, including resolved conflict windows;
for lookahead longer than one token, the diagnostic currently shows only the
first token of each window. The generalized conflict runtime still uses its
own exception messages and does not populate `getErrors()`.

## Work needed for semantic parity

The deterministic runtime now stores its LR stack, semantic values, capture
destinations, cursor, and continuation in a region frame and records the active
shift/reduce/semantic/recover/accept control phase. A parser advanced rule containing only
ordinary `match` clauses compiles through the existing LR normalization path.
The runtime also exposes an optional `lr_semantic_reduce` callback at the
selected reduction point. It receives the region frame and reduced span, so a
generated action can inspect the partial stack and update the cursor. This
callback is exercised by a runtime test, but the LR generator does not yet
emit it for Python actions or fail blocks.
An optional `lr_recover` callback can handle a missing ACTION cell, update the
diagnostic, and retry after moving the region cursor or stack. The runtime
rejects a claimed recovery that makes no progress. The generator does not yet
bind source fail blocks to this hook.
The generator does not yet emit semantic control programs or push nested region
frames for Python statements, variables, conditional matches, or stream matches;
the feature guard still rejects those forms. LL lowers them into executable
parser methods with local variables, captures, rule contexts, and recovery
frames. LR must lower a `match` to a region entry and resume the enclosing
semantic program after that region returns before those forms can be enabled.
The zero-width action members already survive normalization as epsilon
productions. Executing arbitrary action code on those reductions needs a
per-invocation context for local variables and the partial AST. Nullable
action productions can also affect LR conflicts, so the table builder must
preserve the action boundary and conflict resolution must avoid committing
side effects on abandoned branches.
Actions with side effects also need defined rollback behavior when a parse
branch is abandoned. These components are not present yet; AST construction,
recovery, and dynamic conditions cannot be claimed equivalent to LL until
they are implemented and differentially tested.
