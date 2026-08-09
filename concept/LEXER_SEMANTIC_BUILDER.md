# Lexer Semantic Builder

## The problem

We want an easy way to define complex tokens, possibly with recursion and
complex data types. 
Building a DFA supporting this all is often a bad practise:
1. States grows, minimization becomes harder
2. Slower generation and compilation time
3. DFA runtime and types become complex to maintain
4. Hard to maintain correctly that complex logic
5. Errors are the worst possible

## The solution

Token construction is moved to Action and LR-like tables

### LR-like table
Initially the concept was using SHIFT and REDUCE commands in a separate table,
but the concept moved to BEGIN, END and REDUCE commands
DFA state may point to LR state by index <DFA.size() + LR state>. It can point to
BEGIN command to capture something, END to stop capturing this and REDUCE to push
all captured content as token known by REDUCE command

### Action table
An action table can be pointed by <DFA.size() + LR.size() + Action state>
This is large switch function where it can execute semantic actions, potentially
allowing context sensitive lexing and some advanced token construction ways. This
also would be used for errors inside lexer (e.g action state calls fail function)

