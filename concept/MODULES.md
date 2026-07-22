# ISPA Parser Module System Concept

The **Module System** in **ISPA Parser Generator** provides encapsulation, dependency management, standard library reusability, and generic grammar templating. It allows complex language grammars to be split across multiple files, imported with namespace protection, and parameterized using generic templates.

> **Status**: Planned feature set to be implemented immediately following backend stabilization.

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

from main import NUMBER, STRING;

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
from expr import *;   // Imports all exported symbols directly into local scope
from expr import expr; // Selective import of specific rules/tokens

main: expr;

NUMBER: [0-9]+;
STRING: '"' [^"]* '"';
```

#### Import Variations Overview:
* **`import <module>;`**: Keeps imported rules scoped under `<module>::`.
* **`from <module> import *;`**: Exposes all rules and tokens directly within the current module.
* **`from <module> import <symbol>;`**: Exposes only the specified symbols locally.

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

1. **Symbol Isolation**: Rules inside a module are private by default unless referenced as entry points or exported.
2. **Circular Dependency Detection**: Cyclic imports are validated during the AST build pass.
3. **Template Instantiation**: Generic modules are monomorphized at compile-time when imported with concrete generic arguments.
