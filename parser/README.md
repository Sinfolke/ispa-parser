Bootstrapped parser implementation

- ispa/ - the main grammar parser

- python/ - the python code, embedded into grammar

- ispa_dep_scanner/ - the modules scanner, builds everything into one TU

LL parsers retain diagnostics from the last parse in `getErrors()` and
`getContextErrors()`, including when parsing throws. Local diagnostics include
a message, expected tokens, source offset and length, and the recovery decision.
A new parse clears the diagnostics. A returned tree may contain missing captures
after recovery; check the diagnostics before using it for code generation.

Automatic recovery searches the complete remaining production and recursively
referenced productions for terminal anchors, together with the active enclosing
call sites. Grammar traversal handles recursive cycles without a depth limit.
Input scanning remains bounded by the recovery skip and error budgets. Choice
recovery uses an interior terminal only when it identifies one alternative;
shared interior terminals do not establish which branch was intended.

The Python parser has grammar-defined recovery for missing operands and
assignment values, attribute names, closing delimiters, compound-header colons,
blocks, and statement terminators. See [Python recovery](python/README.md) for
the API, limitations, and bootstrap regeneration command.
