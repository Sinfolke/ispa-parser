# Advanced Rules & Fail Blocks

## Overview
Advanced rules and fail blocks are build on embedded Python-like pseudocode.
They are aimed to be as possible more compatible to Python.
But they are not designed to embedd existing python logic,
as they server primary as **Embedded Common Logic of the Language**
---

### Advanced Rules design goal
1. Context sensitive Lexing and Parsing
2. Advanced AST manipulations
3. Control of parsing state
---
### Fail blocks design goal
1. Meangful error messages
2. In-grammar recovery strategies
3. AST manipulations based on errors encountered"

# Motivation

Traditional parser generators are always known for pure error handling and hard to read semantic actions

### Advanced rules
1. Allow to describe your grammar in language-agnostic way
2. Let you parse as complex languages as you can imagine
3. Synchronize your parser with errors better
4. Provide enough abstractions to write grammar in low effort
5. Removes need to care and know about internals
### Fail blocks
1. Let you write whatever error message you want
2. Let you emmit several error messages based on context
3. Let you recover parsing state based on context
4. Removes post-passes on parser output
---
## Basic Syntax
### Advanced Rule
```ispa
array {
    match '[' @ Expression* ']'
    expr = @
    if len(expr.value) == 0:
        return @Undef{}
    return expr.value
}
mul_or_pointer {
    depends class Semantic:
        method isType(ID)
    match @ Expression '*' @ Expression?
    fexpr, sexpr = @
    
    if len(fexpr) == 1 and fexpr.value instanceof ID:
        t: ID = fexpr.value
        if Semantic.isType(t)
            return @Pointer {
                type: t, 
                name: cast(ID, sexpr.value)
            }
    return @Mul {
        left: fexpr, 
        right: sexpr
    }
}
```

match → command to do matching as in regular rule within Advanced rule

depends → add external dependency to this rule. 
This is **user written target language code**, or, in big future, a separate file with python pseudocode

@ → the match sequence with **Nodes**

`return @Pointer{
    type: t,
    name: cast(ID, sexpr.value)
 }` → this is mostly standard python, except `@Pointer` means AST node

As you can see, **ISPA** aims to embeedd as possible more clean python, providing some generator manipulations

### Fail blocks

```ispa
STRING: 
    '"' @ [^"\n] %quote_close '"'
    {@}
; 
array: 
    '[' @ Expression* %brace_cls ']'
    {@}
;
mul_or_pointer {
    depends class Semantic:
        method isType(ID)
    match @ Expression '*' @ Expression?
    fexpr, sexpr = @
    
    if len(fexpr) == 1 and fexpr.value instanceof ID:
        t: ID = fexpr.value
        if Semantic.isType(t)
            return @Pointer {
                type: t, 
                name: cast(ID, sexpr.value)
            }
    return @Mul {
        left: fexpr, 
        right: sexpr
    }
}
fail STRING.quote_close(cur, pos, ast, cst) { 
    if cur == '\n': 
    // now we traverse the whole partial AST that has already been accumulated to find '"' to consider end of STRING
    i = ast.value.size(); 
    while i != 0: 
        if ast.value[i] == '"': 
            if ast.value[i - 1] == '\\': 
                error("Closing quote should not be escaped") 
                return i // the fail block expects new parsing position to be returned in this concept
    i = 0 
    while i < ast.value.size():
        if ast.value[i] == ' ': 
            error("Unclosed string quote") 
            return i 
        error("unclosed quote") 
    return pos // recover from '\n' 
} 
fail array.brace_cls(cur: Token) { 
    if current == ',' // in Parser mode this will map to auto generated ']' token 
        error("Trailing comma")
    elif current == '[':
        error("Missing comma")
    else:
        error("Missing ']'")
}
```

The fail block can be also used in advanced rules:

```ispa
complex {
    match '{' @ ID '}'
    if len(@) == 1:
        fail short_id
}

fail short_id(cur, pos) {   // pass arbitary parameters after pos for more context
    error("Your Name is too short for 'complex' rule!!!")
}
```