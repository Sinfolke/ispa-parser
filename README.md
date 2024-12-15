This is an output of the parser rule
Implementation:
1. Write base rules [done]
2. Make skip of spaces in between rules [done]
3. Fix errors in iscstdlibc++ [done]
4. Fix errors in parser.h     [done]
5. fix errors in rules if exists [done]
6. test on real parser input & output tree to see everything is well
    - continue testing 'Rule', it still has somewhere bugs
        - cll expr has bugs, unmatch complex rules
    TODO: expr likely has a bug where it matches key in inclosed data block as ID, but fails
    then due colon. Needed to add protection.