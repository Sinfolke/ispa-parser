# ISPA Parser Module System Concept

The **Module System** in **ISPA Parser Generator** provides encapsulation, dependency management, standard library reusability, and generic grammar templating. It allows complex language grammars to be split across multiple files, imported with namespace protection, and parameterized using generic templates.

> **Status**: Recursive source discovery, explicit imports, module isolation, features, and local detach are implemented. Generic module instantiation remains planned.

---

## 🚀 Key Features

* **Explicit Entry Rules**: Exported entry rules determine how external callers or parent modules invoke a module.
* **Namespaced & Explicit Imports**: Flexible import syntax supporting namespaced imports, wildcard imports, or selective symbol imports.
* **Grammar Templating (`module name<T1, T2>`)**: Generic modules that accept symbols or rules as parameters for building modular, re-usable syntax libraries (e.g., JSON, Math expressions).

---

## 💡 Syntax & Usage

### 1. Declaring Modules & Entry Rules (`module <name> -> <entry_rule>`)

Every module defines its name and may explicitly specifies which rule acts as its default entry point when evaluated directly:

```ispa
// Defines module 'expr' with entry point 'expr'
module expr -> expr;

NUMBER: [0-9]+;
STRING: '"' [^"\\]* '"';

expr: 
    expr '+' expr 
    | NUMBER
    | STRING
;
```

---

### 2. Imports & Symbol Resolution

ISPA supports multiple import modes to maintain clean symbol resolution and prevent namespace collisions:

```ispa
module main -> main; // Defines main module with entry rule 'main'

import expr;          // Namespaced import (accessible via expr.)
import * from expr;   // Imports all exported symbols directly into local scope
import {expr} from expr; // Selective import of specific rules/tokens

main: expr;

```

#### Import Variations Overview:
* **`import <module>;`**: Keeps imported rules scoped under `<module>::`.
* **`import * from <module>;`**: Exposes all rules and tokens directly within the current module.
* **`import {<symbol>} from <module>;`**: Exposes only the specified symbols locally.

---

### 3. Templated / Generic Modules

Modules can accept generic parameters to define reusable syntax components without binding to concrete token definitions.

#### Example: Generic JSON Parser Library

```ispa
// Templated library expecting NUMBER and STRING types from caller
module json<NUMBER, STRING> -> main;

main: 
    NUMBER | STRING | OBJECT | ARRAY
;

OBJECT:
    '{' (NUMBER | STRING) '}'
;

ARRAY:
    '[' (NUMBER | STRING) ']'
;
```

When importing a templated module, concrete rules or tokens are passed to instantiate the template:

```ispa
import json<MY_NUMBER, MY_STRING> as my_json;
```

---

## 🛠️ Module Resolution & Architecture

1. **Symbol Isolation**: A module can only reference another module through explicit import bindings; selected imports keep unselected symbols out of the caller’s scope.
2. **Recursive Modules**: Cyclic imports are allowed. Declarations are registered across all modules before imports and features are resolved.
3. **Template Instantiation**: Generic modules are monomorphized at compile-time when imported with concrete generic arguments.


## Preprocessing and local grammar features

Pass source roots with `--dir` (or repeated `-d` options). Every root is scanned
recursively for `.isc` files; overlapping roots and explicit source files are
deduplicated. A file's default module name is its path relative to the first
matching root, without `.isc`, using `.` between directories. For example,
`lib/cpp.isc` is `lib.cpp`. An explicit `module cpp -> main;` declaration can
supply a name and entry instead.

```sh
ispa --lang cpp --dir grammars grammars/main.isc -o output/Parser
```

The first explicit input selects the root module. Without explicit inputs, the
module named `main` is preferred; otherwise a single module with an entry is
selected. Ambiguous entries require an explicit root file. Existing split
grammars containing no module directives retain their shared scope.

Imports use the dependency scanner's syntax:

```ispa
import lib.cpp;                       // lib->cpp->declaration
import lib.cpp as cpp;                // cpp->declaration
import {declaration, expression} from lib.cpp;
import * from lib.cpp;
```

Local rule scopes are searched before the module's imported bindings. Imported
rules resolve their private helpers in their defining module. Importing one
rule does not make those helpers visible to the caller, and imports are not
implicitly re-exported. Missing modules, missing symbols, conflicting bindings,
and duplicate module names are diagnosed before generation. Cyclic imports are
allowed, including mutually recursive rules defined in different modules.
A qualified module name can also invoke its explicit entry, or its `main` rule.

A feature names a list of symbols in the declaring module's visible scope:

```ispa
// lib/cpp.isc
cpp_constexpr: 'constexpr';
feature cpp_constexpr { cpp_constexpr };
declaration: cpp_constexpr? 'declaration';
required_declaration: cpp_constexpr 'required';
```

An importer can remove a symbol or an imported feature locally:

```ispa
import * from lib.cpp;
detach feature cpp_constexpr;  // or: detach cpp_constexpr;
main: declaration;
```

Here `declaration` keeps matching `'declaration'`, while
`required_declaration` is unavailable in this importer. Unavailable required
references propagate through callers until stable. Unavailable alternatives are
pruned independently, and `?` / `*` references disappear without removing their
caller. Optional-only callers can become epsilon productions. Detaching a
parent rule also removes its nested declarations. Captured fields corresponding
to removed optional members are removed from the caller's data block.

Affected imported definitions are copied before rewriting; other importers keep
the original grammar. If propagation removes the selected entry, generation
reports an error. Feature names follow the same qualified, selective, and
wildcard import rules as grammar symbols.

`Modules::preprocess(directories, files)` owns the prepared source text and
returns the source catalog, declarations, import bindings, features, and detach
sets. Directives and comments are replaced with spaces while preserving offsets
and newlines. Pass the catalog to `AST::Builder::setModules()` and label each
parsed top-level entry with `setSourceFiles()`. Keep the project alive while
parsing and building because parser nodes retain source slices.
