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
1. Clang compiler with libc++ on ubuntu, latest ubuntu version
2. MSVC cl compiler on windows
3. Exact version of cmake 4.3.2

**Note: YOU WILL NOT BE ABLE TO BUILD THIS WITH GCC YET**

**Note: build with clang is not tested on windows**

### Build on Ubuntu
Generate cmake build files. **Change ISPA_SOURCE_DIR to your local path**:
```sh
export ISPA_SOURCE_DIR=/mnt/5EE9F38E0E9F2DC9/ispa-parser
export CC=clang-20
export CXX=clang++-20
export CFLAGS="-stdlib=libc++"
export CXXFLAGS="-stdlib=libc++"
export LDFLAGS="-stdlib=libc++"
cmake -B cmake-build-release \ 
-DCMAKE_BUILD_TYPE=Release \
-DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake \
-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=$ISPA_SOURCE_DIR/cmake/toolchains/clang-libcpp.cmake \
-DVCPKG_TARGET_TRIPLET=x64-linux-libcxx \
-DVCPKG_OVERLAY_TRIPLETS=$ISPA_SOURCE_DIR/cmake/triplets
```
Build:
```sh
cmake --build cmake-build-release
```
---

### Build on Windows
Note:

- Change CMAKE_TOOLCHAIN_FILE to your vcpkg installation path if this does not work
- You might need to provide CMAKE_CXX_COMPILER variable pointing to cl.exe
- You might need to configure other variables MSVC require to build
```bat
cmake -B cmake-build-release -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="$VCPKG_INSTALLATION_ROOT/scripts/buildsystems/vcpkg.cmake"
```