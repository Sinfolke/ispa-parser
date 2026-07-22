# Advanced Rules & Fail Blocks

## Overview

Advanced Rules extend the parser framework with **declarative semantic validation**, **custom diagnostics**, and **structured error recovery**. Instead of treating parsing failures as opaque exceptions or simple backtracking events, failures become explicit control-flow constructs within the grammar itself.

The primary goal is to make grammar definitions expressive enough to describe both syntax and context-sensitive validation while keeping the generated parser deterministic and efficient.

Unlike traditional parser generators that rely on embedding an interpreted scripting language, Advanced Rules are compiled into an intermediate representation (IR) and ultimately into native parser code, resulting in **zero runtime interpreter overhead**.

---

# Design Goals

Advanced Rules are designed to provide:

* Declarative semantic validation
* Context-sensitive parsing
* Structured parser recovery
* Rich compiler diagnostics
* Deterministic execution
* Zero runtime scripting overhead

Rather than executing embedded Python or another dynamic language, all semantic control flow is analyzed during generation and compiled into efficient parser logic.

---

# Motivation

Traditional parser generators typically provide one of the following approaches:

* Simple syntax errors
* Exceptions
* Backtracking
* Embedded scripting languages

While embedded scripting is flexible, it has several drawbacks:

* Runtime overhead
* Hard-to-analyze control flow
* Reduced portability
* Increased complexity
* Limited optimization opportunities

Advanced Rules solve these issues by introducing a restricted, deterministic language that is compiled directly into parser control flow.

---

# Advanced Rules

An **Advanced Rule** behaves like a normal grammar production while adding support for:

* semantic dependencies
* conditional execution
* semantic assertions
* custom diagnostics
* recovery directives
* explicit success/failure control

## Basic Syntax

```ispa
advanced rule_name {
    depends SemanticDependency

    match @ MY_TOKEN

    if SemanticDependency.checkCondition(@):
        error(""Error message goes here")
}
```

---

# Rule Directives

## `depends`

Declares external semantic providers required by the rule.

These providers may include:

* symbol tables
* type systems
* keyword resolvers
* module registries
* custom semantic analyzers

Example:

```ispa
depends Semantic
```

---

## `match`

Consumes a token or invokes another grammar rule.

Examples:

```ispa
match Identifier

match expression
```

---

## Token References

Previously matched values can be referenced using the `@` operator.

```ispa
match ID

Semantic.resolve(@)
```

# Fail Blocks

Fail blocks describe **how parsing should respond when a rule cannot continue**.

Instead of immediately aborting parsing, they provide structured recovery behavior and diagnostics.

A fail block may:

* inspect parser state
* inspect matched values
* emit diagnostics
* recover parsing
* abort parsing
* synchronize with later grammar constructs

---
## Named Fail Block

Failures may be defined separately from the grammar.

```ispa
fail declaration.invalid_identifier(name) {

    error("Invalid identifier: " + name)

    recover
}
```

Rules can invoke them using:

```ispa
%invalid_identifier
```

This separates parsing logic from diagnostic logic.

---

# Captured Parameters

Fail blocks may receive information from the parser.

## Uncaptured Tokens

Access raw tokens that were not captured.

```ispa
uncap[0]
```

Example:

```ispa
unexpected = uncap[-1]
```

---

## Captured Values

Access captured grammar values.

```ispa
cap[0]
```

Example:

```ispa
expr = cap[1]
```

---

## Named Variables

Rules may explicitly pass named variables.

```ispa
fail declaration.invalid(name = @ID)
```

Inside the fail block:

```ispa
name
```

---

# Recovery Model

Every parser failure belongs to one of three categories.

```
                  Fail Triggered
                        │
        ┌───────────────┼───────────────┐
        │               │               │
        ▼               ▼               ▼
   Hard Fail     Recoverable Fail    Soft Fail
        │               │               │
        ▼               ▼               ▼
 Abort Parsing   Synchronize Parser   Emit Diagnostic
```

---

## Hard Fail

A hard fail aborts parsing immediately.

This is the default behavior when no recovery directive is issued.

Typical uses include:

* unrecoverable grammar errors
* corrupted parser state
* invalid language constructs

---

## Recoverable Fail

Recoverable failures allow parsing to continue.

Typical recovery strategies include:

* skipping invalid tokens
* synchronizing at rule boundaries
* panic mode

This enables reporting multiple diagnostics during a single parse.

---

## Soft Fail

A soft fail emits diagnostics without changing parser state.

Typical uses include:

* warnings
* deprecated syntax
* style diagnostics
* optional semantic validation

---

# Error Handling Functions

## `error`

Emits a compiler diagnostic.

```ispa
error("Expected expression")
```

Diagnostics are associated with the current parser location.

---

## `panic_mode()`

Performs panic-mode recovery.

```ispa
panic_mode()
```

The parser discards tokens until a synchronization token (such as `;` or `}`) is encountered.

---

## `recover`

Immediately clears the current failure and resumes parsing.

```ispa
recover
```

---

## `recover after <rule>`

Resumes parsing after reaching the boundary of another grammar rule.

```ispa
recover after declaration
```

This enables more precise synchronization.

---

# Complete Example

```ispa
advanced statement {

    depends Semantic

    match ID

    if Semantic.isKeyword(@ID):
        fail statement.invalid_identifier(uncap[0])

    let t = Semantic.resolveType(@ID)

    if t.type == TEMPLATE {

        match '<'

        match expr (',' expr)*

        match '>'

        Semantic.registerTemplateUsage(@ID)

    } else {

        Semantic.registerVariable(@ID)

    }
}

fail statement.invalid_identifier(name = uncap[0]) {

    if name == "class" or name == "struct" {

        error("Type declaration keywords are not allowed here")

        panic_mode()

    } else {

        error("Invalid variable identifier: " + name)

        recover

    }

}
```

---

# Compilation Model

Advanced Rules are **not interpreted** during parser execution.

Instead, they are compiled into deterministic parser logic.

The compilation pipeline consists of several stages.

## 1. Static Analysis

The generator validates the semantic subset used inside Advanced Rules.

Supported constructs include:

* assignments
* conditionals
* comparisons
* semantic function calls
* fail invocations

Because the language is intentionally restricted, all control flow can be analyzed ahead of time.

---

## 2. Intermediate Representation

Validated rules are transformed into an intermediate representation (IR).

The IR models:

* parser states
* semantic conditions
* diagnostics
* recovery paths
* control-flow edges

This representation is deterministic and suitable for optimization.

---

## 3. Control Flow Graph Generation

The IR is lowered into a control-flow graph (CFG).

Each conditional, semantic check, and recovery directive becomes explicit control flow rather than interpreted script execution.

---

## 4. Native Code Generation

Finally, the CFG is translated into the selected backend language.

Possible targets include:

* C++
* Rust
* TypeScript
* other supported generators

The generated parser executes semantic validation directly as native code with no embedded interpreter.

---

# Advantages

Advanced Rules provide several advantages over traditional embedded scripting approaches:

* Zero runtime interpreter overhead
* Deterministic control flow
* Rich, context-aware diagnostics
* Declarative parser recovery
* Portable generated code
* Compile-time validation of semantic logic
* Easier optimization during code generation
* Clear separation between grammar definition and error handling

---

# Future Extensions

The current design leaves room for additional capabilities, including:

* pattern matching expressions
* user-defined recovery strategies
* custom diagnostic categories
* warning levels
* fix-it hints
* localized diagnostic messages
* parser tracing and debugging support
* richer semantic dependency injection
* optimization passes over the generated control-flow graph

These extensions can be introduced without changing the core execution model, as all semantic logic is represented through the intermediate representation rather than a runtime scripting engine.