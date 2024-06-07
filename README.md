# ISC-parser
## PROJECT IS NOT BEGAN
 As you may see there is nothing currently. I haven't began the project yet but going to do it later. I'm doing some library named "cpuf" as i need some features i couldn't find
## What is this
 ISC (Independent Self-closed Parser) is the parser which generates code that doesn't rely on any library (unless some buildtin). The output is a single or several files with the code to parse on target language. Unless link these files to project you doesn't have to do more. Furthermore the output interface is not complex. Example of output see in ```concepts/output-example.cpp```
## How to implement project
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
 8. After all done i can adjust parser rule syntax and use itself to compile and get upgraded parser
## Parser rules
  // describe rules later...
