# Counted repetition

The C++ LL backend supports counts on token and production references:

```ispa
A: 'a';
B: 'b';
main: @ A=x ':' @ B=x '!' @{left, right};
```

The first `A=x` greedily matches `A` and binds `x` to the number of successful
matches. `B=x` then matches exactly that many `B` tokens. For example, `aa:bb!`
matches and `aa:b!` fails. Each successful production invocation also counts as
one match, regardless of how many tokens that production consumes. Payloads
and source lengths do not determine the count.

`A=3` matches exactly three occurrences; `A=0` matches none. Capturing a counted
matcher produces a list. The existing `A*=x` spelling has the same behavior as
`A=x`; `A+=x` requires at least one occurrence. `A* => x` registers the number
of matches of an ordinary repetition. Registration must agree with an existing
binding of the same name.

Bindings last for their declaring rule invocation. Called rules inherit them;
bindings created inside a called rule disappear when it returns. The same
cleanup happens on exceptions and failed optional rule probes. A new parse
starts with no bindings. Unbound repetitions that succeed without consuming
input are rejected to prevent infinite loops.

Explicit whitespace tokens remain ordinary counted matchers:

```ispa
__WS: ' ';
NEWLINE: '\n';
main: __WS=x 'header' NEWLINE line+;
line: __WS=x 'item' NEWLINE;
```

Here each space is one token. No automatic whitespace gap is inserted directly
beside an explicit `__WS` or `NEWLINE` reference. Repetitions of productions
with explicit whitespace boundaries also leave those tokens to the production.
The default whitespace token still includes newlines unless redefined.

Counts currently require `-a LL` and token/production references (or literals
lowered to tokens). Lexer-rule counts, counted groups/choices, `?=...`, and
Python expression bounds are rejected. LR and LALR report that counted
repetition requires LL. Configurable automatic skipping through a `__ws` rule
and external parser imports are separate work.
