# ISPA Python statements subset

The archive contains the statement grammar from the previous answer, split into:

- `statements.ispa`: main, simple statements, indentation-based blocks, if/elif/else, for/while, functions, classes, with, try/except/finally, imports.
- `tokens.ispa`: candidate token definitions (deduplicate against existing expression tokens).
- `example.py`: integration test input.

## Integration

1. Merge `statements.ispa` into your existing expression grammar, replacing overlapping `main`, `stmt`, `expr_stmt`, `return_stmt`, `assignment_tail`, and `assignment_target` definitions as appropriate.
2. Merge the *missing* token definitions from `tokens.ispa`; don't duplicate existing tokens.
3. Implement lexical emission of `NEWLINE`, `INDENT`, and `DEDENT`, including line continuation within grouping delimiters.
4. Require full input consumption to prevent false-positive prefix parses.
5. Run `example.py` and test negative cases.

## Limitations / caveats

This is a **draft grammar subset** reflecting the preceding response, **not a verified drop-in compilation against ISPA**. In particular:

- Your ISPA grammar may need adjustments to capture syntax (`@ ASYNC?` etc.) and the no-value / forwarded captures in `{@}` rules.
- Compound statements require indentation-aware lexing. Plain whitespace skipping isn't sufficient.
- Assignment targets, `for` targets, comprehensions, pattern matching, chained assignments, full function parameter syntax, `await`, `yield`, `except*`, and type-parameter syntax are incomplete or absent.
- Python does not allow `return`, `break`, or `continue` everywhere; that requires contextual checks.
- Keyword boundaries and longest-match operator tokenization are necessary.
- `assignment_stmt` versus `expr_stmt` requires correct alternative handling.
- A true CPython-equivalent `for ... in ...` target grammar needs special treatment so `IN` isn't consumed as a comparison operator in the target.
- Some ISPA build constraints (especially capture count/field count, empty `@` repetitions, and lexer-generated tokens) may require refining this draft.

Reference: https://github.com/python/cpython/blob/main/Grammar/python.gram
