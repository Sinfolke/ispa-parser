# ispa
### Warning
  something you may find here may not be actually implemented for now,
  It helps to have strict plans and quicks up implementation when you have it's details
### What is this
 ispa (Independent Standalone Parser) is a declarative language to generate parser from a rule. Generated parser doesn't rely on any library, the output is a direct logic of your rule which aims to be simple and minimalistic, while maintain the most of opportunities you could gain out. With the common language logic (CLL) inside you don't generally need to interact with the parser - that's what makes it standalone and those easer to learn. AST construction is done with simple data blocks - you just specify how the data of your rule should be stored in the token/rule.
 Example of output see in ```concepts/output-example``` (a bit outdated)
### How to implement project
 The language ispa written is C++
 1. Make sure the syntax definion is done
 2. Do bootstrap. Write the parser for the syntax of this parser
 3. Begin to write the main code of the parser
    - arguments parser
      - file input
      - flags (see ```concepts/argp```) (not exists)
    - Arguments processer to ART - argument tree (see ```concepts/art```) (not exists)
    - parse each file      
 5. Compile the parser writing the code on C++ by own
 6. Create rules to walk on parser tree if need some optimisations or else before the compilation
 7. Implement core library. The parser without optimizations can be converted using "on" calls
 8. Since the parser is for multiple languages for each language will be different shared library responsible for outputting the result. For the first i only create library to output C++ results.
 9. After all done i can adjust parser rule syntax and do bootstrap
### 
### Parser syntax
  
  see ```concepts/syntax```

### Latest commit changes
  - Improvements to build system
  - Error handling improvements
