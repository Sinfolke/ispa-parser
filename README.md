# ISC-parser
## PROJECT IS NOT BEGAN
 As you may see there is nothing currently. I haven't began the project yet but going to do it later. I'm doing some library named "cpuf" as i need some features i couldn't find
## What is this
 ISC (Independent Self-closed Parser) is the parser which generates code that doesn't rely on anything. Therefore you don't have to link them to your project.
## How to implement project
 The language of parser is C++
 1. Make sure the syntax definion is done
 2. Do bootstrap. Write the parser for the syntax of this parser
 3. Begin to write the main code of the parser
    - arguments parser
      - file input
      - flags
        - Sn single (compile all into single file)
        - Md module (make it as a module)
        - O\s*%d optimisation (0-3, as in C)
        - V\s*%d version (the version of parser for case rules are not compatible with the newer versions)
          !! May not be added
      - additional features
        - --ciu compile if upgraded (implement some mechanisms so therefore the rules will be recompiled if were changed to make the output be upgraded. Need when the parser is the part of some project with a cmake)
   - Arguments processer to ART (argument tree).
     example:
     struct ART {
       std::forward_list<std::string> in;
       std::unordered_map<std::string, std::string> flags;
       struct {
         book ciu = false;
       } addition;
     };
  - parse each file
            
 5. Compile the parser writing the code on C++ by own
 6. Create rules to walk on parser tree if need some optimisations or else before the compilation
 7. Since the parser is for multiple languages for each language will be different shared library responsible for outputting the result. For the first i only create library to output C++ results.
 8. After all done i can adjust parser rule syntax and use itself to compile and get upgraded parser
## Parser rules
  // describe rules later...
