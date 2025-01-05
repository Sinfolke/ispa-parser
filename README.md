# ispa
### About
  This is converter library to output C++ results for parser. You're welcome to do any modifications to improve generation.
  Note this library is still licensed as the main branch under **Apache 2 license**

  This branch also describe how the parser will be outputted on the target language.
### Output specifications
  How the output is done will be described in a list form. This information is required for proper interaction with AST
  1. Types
     - var = std::any
     - str = std::string
     - num = int
     - arr = std::vector\<std\:\:any\>
     - obj = std::unordered_map\<const char*, std::any\>

      Note that when you're accessing element by index (**%1**, **$1**), the type will be exact (not **std::any**). That means that
      string literal ("hello") will be of type **std::string**, ("hello")+ will be **std::vector\<std::string\>**
  2. 