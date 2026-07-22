# ISPA Parser Rules, Templates & Inheritance Concept

Rule templates and rule inheritance in **ISPA Parser Generator** provide a mechanism for creating reusable, customizable, and modular grammar components. 

By parameterizing rules and allowing downstream grammars to detach, extend, or override sub-rules, ISPA enables grammar standard libraries (e.g., standard math expressions or C-like operator hierarchies) to be customized without re-writing entire rule trees.

---

## 🚀 Key Features

* **Rule Templates (`rule<P1, P2>`)**: Define generalized grammar structures with parameter placeholders. Templated rules cannot be instantiated directly; they must be specialized/inherited.
* **Global Specialization (`expr<>`)**: Implicitly maps template parameters to matching symbols in the global scope.
* **Sub-rule Detachment (`detach rule_name`)**: Selectively remove unused sub-rules (and their references) from inherited rules.
* **Sub-rule Overriding (`#subrule`)**: Redefine nested rules within inherited templates to adapt matching behavior.
* **Rule Aliasing (`expression = expr<...>`)**: Create clean top-level rule definitions bound to parameterized templates.

---

## 💡 Syntax & Usage

### 1. Defining a Templated Rule (`rule<Params...>`)

A templated rule acts as an abstract syntax pattern. It can define nested sub-rules, inline operators, and placeholder tokens.

```ispa
// Abstract expression template with token placeholders ID and NUMBER
expr<ID, NUMBER>:
    (expr '||' expr)
    | (expr '&&' expr)
    | (expr '==' expr)
    | (expr '!=' expr)
    | (expr '<' expr)
    | (expr '>' expr)
    | (expr '<=' expr)
    | (expr '>=' expr)
    | term
    | (expr '?' expr ':' expr)
    | (ID '=' expr)

    #term:
        (term '*' factor)
        | (term '/' factor)
        | (term '%' factor)
        | factor
        ;

    #factor:
        addition
        | substract
        | negative
        | group
        | function_call
        | variable
        | NUMBER
        ;

    [inline] #addition:
        ('+' factor)
        ;
    [inline] #substract:
        ('-' factor)
        ;
    [inline] #negative:
        ('!' factor)
        ;
    [inline] #group:
        ('(' expr ')')
        ;
    [inline] #function_call:
        (ID '(' arg_list? ')')
        ;
    [inline] #variable:
        ID ('[' expr ']')?
        ;
    [inline] #arg_list:
        expr (',' expr)*
        ;
;
```

---

### 2. Rule Specialization & Inheritance

To use a templated rule, it must be inherited and specialized into a non-templated rule.

#### A. Detaching & Overriding Rules

When specializing a rule, you can use `detach` to strip unwanted features and re-define `#subrules` to change behavior:

```ispa
// Inherit from expr<ID, NUMBER> and customize it
expr : expr<ID, NUMBER>:
    // Detach removes specified sub-rules and their references from factor
    detach function_call, 
           variable
    detach arg_list

    // Override parent rule matching
    expr '||' expr

    // Override a specific sub-rule to change operator behavior
    #addition:
        factor '+' factor
        ;
;
```

#### B. Implicit Global Parameter Binding (`rule<>`)

If the template parameter names match globally defined rules or tokens in the scope, you can specialize using empty diamond operators `<>`:

```ispa
// Automatically binds template parameters 'ID' and 'NUMBER' to global definitions
expr : expr<>;
```

#### C. Rule Aliasing (`rule = base_template<...>`)

You can directly assign a specialized template instance to a new rule identifier:

```ispa
expression = expr<ID, NUMBER>;

ID: [a-zA-Z0-9]+;
NUMBER: [0-9]+;
```

---

## 🏗️ Production Considerations & Open Questions

> *Note: Rule inheritance is currently a design concept undergoing evaluation for production feasibility.*

1. **Rule Detachment Mechanics**:
   * *Static AST Pruning*: When `detach` is called, the compiler must rewrite the parent rule's match alternatives to remove references to the detached rule.
   * *Dangling Reference Detection*: If a rule is detached, any parent rule strictly requiring it must raise a build-time compiler error.

2. **Parsing Table Overhead**:
   * Templated inheritance generates new monomorphized rule variants during compilation. Ensure table generators (LL / LR) optimize identical sub-rule expansions to prevent table explosion.

3. **Alternative Syntax Options for Production**:
   * *Composition over Inheritance*: Evaluating whether module-level generics (`module expr<ID, NUMBER>`) or rule inheritance provides cleaner mental models for grammar authors.
