# ISPA Grammar for JetBrains IDEs

Recognizes `.isc` grammar files and highlights the token ranges emitted by the repository's bootstrap `Parser::Lexer`. The native bridge also runs `Parser::Parser` and returns its AST; parser-backed highlighting is used when parsing succeeds, while an IDE-side tolerant lexer keeps incomplete edits readable. No standard-library source is copied or modified.

## Build and install

Build with JDK 21, CMake 3.20+, and a C++23 compiler compatible with the parser. The native helper is built for the host OS, so build the plugin on the OS where it will run. Compiler and linker setup is taken from the environment by CMake; the plugin does not force a compiler or standard library.

Example matching the ISPA Clang/libc++ setup on this machine:

```sh
CC=/opt/llvm-23.1.2-icx/bin/clang \
CFLAGS='-stdlib=libc++ -I/opt/llvm-23.1.2-icx/include/c++/v1' \
CXX=/opt/llvm-23.1.2-icx/bin/clang++ \
CXXFLAGS='-stdlib=libc++ -I/opt/llvm-23.1.2-icx/include/c++/v1' \
LD=ld.lld \
LDFLAGS='-stdlib=libc++ -L/opt/llvm-23.1.2-icx/lib -L/home/ura/intel/oneapi/compiler/2026.1/lib' \
./gradlew buildPlugin
```

Use compiler/runtime paths appropriate to your own machine. The packaged native helper must be able to locate its C++ runtime libraries when the IDE launches it.

Install `build/distributions/ispa-grammar-0.1.0.zip` from **Settings → Plugins → ⚙ → Install Plugin from Disk**, then restart the IDE. `./gradlew runIde` starts a sandbox IDE for testing.
