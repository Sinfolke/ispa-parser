This is an output of the parser rule
Implementation:
1. Write base rules [done]
2. Make skip of spaces in between rules [done]
3. Fix errors in iscstdlibc++ [done]
4. Fix errors in parser.h     [done]
5. fix errors in rules if exists [done]
6. test on real parser input & output tree to see everything is well
    - begin test cll (possibly the most complex part of parser), not matches in 'use' rule correclty
    TODO NEXT: 
        - Refactor expr. It works incorreclty right now and is unable to handle large, complex expression, it is able to handle basic expressions

    '(' logical>(matches the expression with logical operators) ')'
        |
      compare | ternary | arithmetic | any_data
                        |    
                expr compare_op expr \
                expr '?' expr : expr \
                expr '+'|'-'|'*'|'/'(...) expr