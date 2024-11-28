This is an output of the parser rule

TODO: Match spaces between every rule (currently only core is implemented, spaces are completely ignored).
Implementation:
1. Write base rules
2. Make skip of spaces in between rules
    done for:
     parser
     end
     dataTypes
     Rule, Rule/*
     Cll/common/block
     Cll/common/operators
     Cll/common/template
     СLL/common/type
     Cll/condition/if
     Cll/condition/ternary
3. Fix errors in iscstdlibc++
4. Fix errors in parser.h
5. fix errors in rules if exists
6. test on real parser input & output tree to see everything is well