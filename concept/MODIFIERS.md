# ISPA Parser Modifiers Concept

Modifiers in **ISPA Parser Generator** are annotations applied to grammar elements (rules, expressions, or tokens) using square-bracket syntax `[...]`. They alter the parsing behavior, AST generation flow, or lexer mechanics for specific definitions without polluting the core language logic.

---

## 🚀 Overview

Modifiers provide fine-grained control over how individual nodes and tokens are processed by the ISPA compiler engine:

* **AST Value Optimization**: Inlining nodes to simplify the resulting AST hierarchy.
* **Lexer Directives**: Stripping out non-semantic tokens (like whitespace or comments) early in the pipeline.
* **Parser Controls**: Fine-tuning error recovery, associativity, or visibility.

---

## 💡 Syntax & Usage

Modifiers are specified directly preceding the definition or rule block using `[modifier_name]` or parameter-driven `[modifier_name(arg)]` syntax.

### 1. The `[inline]` Modifier

The `[inline]` directive instructs the compiler to collapse or flatten an AST node directly into its parent. This prevents unnecessary single-child node nesting in the generated tree.

#### Example: Inlining Single Expressions

```ispa
[inline] // Collapses the AST node into the caller's AST level
operator:
    @ PLUS | MINUS
    {@}
;
```

#### Behavior:
* **Without `[inline]`**: Produce operator rule, containing either **PLUS** or **MINUS** token as value
* **With `[inline]`**: **Directly evaluate PLUS or MINUS** token to the value calling **operator** rule

---

### 2. The `[skip]` Modifier

The `[skip]` modifier is applied to lexer tokens to indicate that matched sequences should be discarded by the lexer and omitted from token streams passed to the parser stage.

#### Example: Ignoring Whitespace

```ispa
[skip] // Automatically skips this token whenever encountered
WHITESPACE: [ ]+;
```

#### Common Use Cases:
* Ignoring spaces, tabs, and newlines.
* Stripping single-line and block comments (`// ...`, `/* ... */`).

---

## 🛠️ Summary of Common Modifiers

| Modifier | Target | Description |
| :--- | :--- | :--- |
| `[inline]` | Rules | Inlines node values directly into the calling AST node. |
| `[skip]` | Tokens | Discards matched token patterns during lexing (e.g., whitespace, comments). |
---