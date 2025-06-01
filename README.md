# ispa
### Warning
  something you may find here may not be actually implemented for now,
  It helps to have strict plans and quicks up implementation when you have it's details
### What is this
 ispa is a parser generator to generate standalone parser from rules. The generated parser does not rely on any library; its output is a direct implementation of your rule, aiming to be simple and minimalistic while retaining most of the potential benefits. With the common language logic (CLL) inside you can parse any complex input. AST construction is done with simple data blocks where you just specify how the data of your rule should be stored in your node.
### How to implement project
 The language ispa written is C++
 1. Make sure the syntax definion is done
 2. Do bootstrap. Write the parser for the syntax of this parser
 3. Begin to write the main code of the parser
 4. Hand-write the parser
 5. Create rules to walk on parser tree if need some optimisations or else before the compilation
 6. Convert rules into IR. First convert high level constructs, then cll and accessor
 7. Optimize the IR
 8. Since the parser is for multiple languages each language has own shared library for output. First it should output only C++ results.
 9. After all done i can adjust parser rule syntax and do bootstrap
10. Ensure bootstrapping works out of box
11. Add proper error handling (panic mode, error production)
     1. Create Error IR
     2. For every error case automatically determine rules for recovery
     3. lower to LLIR
     4. Insert error handling instead of every return {}
12. Add modules
13. Add templates 
14. Add inheritance 
15. Add internal error handling for parser in rules 
### Todo
  Add handle of variables in Rule_other (*?)

  Add handle of ${} in string (?)

  Necessary:

    Add proper linking between rules for non-terminal

    Add handle of qualifier in matched() function

    Add remove of unused variables (required IR optimization)

    Add insertion of NOT when one rule shadows another

    Add automatic generation of recovery by panic mode strategy

    ? Add automatic generation of recovery by error production

    ? Add automatic generation of error by phase level recovery 

### Parser syntax
  
  see ```concepts/syntax```

### Latest commit changes
  - Testing of parser output
