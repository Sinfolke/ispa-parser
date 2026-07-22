# ISPA Parser Generator

**ISPA Parser** is a high-performance, infrastructure-level parser generator written from scratch in modern C++ (C++20/C++23). It enables high-level declarative grammar specifications using ISPA Syntax Containers (`.isc`), features automatic Abstract Syntax Tree (AST) synthesis, and employs Common Language Logic (CLL) to keep grammar definitions language-agnostic.

---

## 🚀 Current State

- **Language Support**: Currently targets native **C++17 and upper**.
- **Parsing Algorithms**:
  - **LL(*) / Custom LL Engines**: It's core is implemented and highly tested. It's just needed to switch to LL(*) algorithm for DFA-based predictions
  - **LR(1) / LALR / LR(*)**: Core theory and initial algorithmic pass completed and passing preliminary unit tests. Currently need some refinement over new IRs
- **Lexing**: Deterministic Finite Automata (DFA) based tokenization layer with custom lexer generation.
- **AST Generation**: Fully automatic AST construction with field mapping and typed captures (primitives, arrays, objects).
---

## ✨ Features
- **Declarative AST Mapping**: Automatically capture tokens and sub-rules using `@` and map captured fields directly into structural tree representations via `@{field1, field2, ...}`.
- **Nested Rules & Encapsulation**: Declare sub-rules, nested tokens (`#subrule`), and local context rules directly within parent rules.
---

## 📝 Syntax & Usage (Documentation)

### 1. Basic Rule Structure & Captures (`@` and `@{...}`)

Captures (`@`) specify which matched elements should be stored in the AST node. The binding construct `@{...}` maps captured items to named properties in the node output.

```ispa
condition:
    'if' '(' @ expr ')' @ stmt 'else' @ stmt
    @{expression, true_stmt, false_stmt}
    ;
```

### 2. Sub-Rules & Nested Rules (`#rule`)

Rules can contain encapsulated nested rules (`#name`) to prevent global namespace pollution:

```ispa
expr:
    #logical
    
    #logical:
        @ compare (@ LOGICAL_OP @ compare)*
        @{left, op, right}
        ;
    #compare:
        @ arithmetic (@ COMPARE_OP @ arithmetic)*
        @{first, operators, sequence}
        ;
    ;
```

### 3. Alternative Choices & Values

```ispa
stmt:
    ( '{' @ #value '}' )
    | @ #value
    {@}
    ;
```

### 4. Grammar Inheritance & Templates

Base rules can be extended or overridden, allowing grammar modularity:
- Define reusable templates with slot placeholders.
- Extend base grammars to produce customized syntaxes without re-writing entire rule trees.
---

## 🔄 Recent Changes

- Refined AST generation pipeline and field-mapping bindings.
- Expanded C++20 module/header generation for cleaner compiled output.
- Enhanced parser table generators and DFA lexer state machine optimizations.
---

## ⚠️ Known Issues

> *This section is intentionally left open for specific issue tracking.*

- [ ] *Slow compilation by most major C++ compilers*

---

## 🔮 Future Roadmap

- [ ] **PLL Algorithm**: Finalize custom Parallel/Polynomial LL algorithm to seamlessly resolve left-recursion in LL parsers while preserving structural parity with LR parsers.
- [ ] **Multi-Target Code Generation**:
  - [ ] Python target emitter
- [ ] **Full LR Parser Stabilization**: Finalize integration and production readiness for LR(1), LALR, and LR(*) modes.
- [ ] **Grammar Standard Library (StdLib)**: Pre-packaged standard grammar definitions for common formats (JSON, XML, Math Expressions, C-like statements).
- [ ] Add features described in **concepts/**
---

## 🛠️ Build & Requirements

- **Compiler**: C++20 or C++23 compliant compiler (`GCC 11+`, `Clang 13+`, or `MSVC 2022+`)
- **Build System**: CMake 3.20+
- **Dependencies**: Integrated via CMake / `vcpkg`

**Note: Compilation is currently stable on Linux only with clang compiler. Windows support is planned for a future release.**

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
```
