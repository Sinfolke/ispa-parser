# ISC-parser
### Warning
  something you may find here may not be actually implemented for now,
  It helps to have strict plans and quicks up implementation when you have it's details
### What is this
 ISC (Independent Self-closed Parser) is the parser which generates code that doesn't rely on any library. The output are some files you may link to your project. The output interface is not complex and inside your code you simply instance the class, paste in the input and get a ready tree. You also don't usually need to interact with the parser during parsing process as usually everything may be done in the ISC interface. Example of output see in ```concepts/output-example```
### How to implement project
 The language of parser is C++
 1. Make sure the syntax definion is done
 2. Do bootstrap. Write the parser for the syntax of this parser
 3. Begin to write the main code of the parser
    - arguments parser
      - file input
      - flags (see ```concepts/argp```)
    - Arguments processer to ART - argument tree (see ```concepts/art```)
    - parse each file      
 5. Compile the parser writing the code on C++ by own
 6. Create rules to walk on parser tree if need some optimisations or else before the compilation
 7. Since the parser is for multiple languages for each language will be different shared library responsible for outputting the result. For the first i only create library to output C++ results.
 8. After all done i can adjust parser rule syntax and use bootstrap
### 
### Parser syntax
  
  see ```concepts/syntax```

### Latest commit changes
  - Improvements to build system
  - Error handling improvements
