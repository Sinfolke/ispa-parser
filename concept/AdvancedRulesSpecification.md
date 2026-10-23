# Advanced Rules Specification

> For current implementation details and examples, see
> [Advanced Rules and Fail Blocks](ADVANCED_RULES_AND_FAIL_BLOCKS.md). This
> older syntax note may not match the current runtime surface.

This document does not describe the goal nor problems it solve (refer for [Advanced Rules Specification](https://github.com/Sinfolke/ispa-parser-generator/blob/main/concept/FAIL_BLOCKS_AND_ADVANCED_RULES.md) if you need this). It's goal
is to describe specifications of Advanced Rules, their syntax and edge cases.

# Syntax
## 1. Grammar-level
### 1.1 Match
match is designed to match regular grammar constructs.
it's values can later be extracted. 
@ here is not allowed. @ID is allowed
```ispa
name {
    match '(' @ex Expression ')'
}
```


