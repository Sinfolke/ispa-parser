# ISPA Grammar for JetBrains IDEs

Recognizes `.isc` files with semantic colors for rule and token declarations, references, parameters, and captures. Module directives, features, comments, character classes, and embedded Python have tolerant highlighting while editing. Native parser errors appear in the editor, including the expected symbols and where parsing stopped. Token highlighting remains available after parsing fails; UTF-8 native positions are translated to UTF-16 editor positions.

Validation is local to the current file. Import (including `import extern python ispa_python as python;`) and detach directives are checked without resolving external modules. Embedded `p{...}` expressions and statements are validated by the bundled Python parser and highlighted while editing. No Python IDE plugin is required. The native helper has a two-second timeout; lexical highlighting remains available if it cannot run.

## Build and install

Build with JDK 21, CMake 3.22+, and a C++23 compiler compatible with the parser. The native helper is built for the host OS, so build the plugin on the OS where it will run. Compiler and linker setup is taken from the environment by CMake; the plugin does not force a compiler or standard library.

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

Install `build/distributions/ispa-grammar-0.2.0.zip` from **Settings → Plugins → ⚙ → Install Plugin from Disk**, then restart the IDE. `./gradlew runIde` starts a sandbox IDE for testing.

The native build links `ISPA::Parser` from `parser/CMakeLists.txt`, using the current bootstrap in `../../parser/ispa/bootstrapped_)` and linking its bundled Python dependency. A standalone CMake build can override the parser with `-DISPA_BOOTSTRAPPED_DIR=/path/to/generated/parser`. Gradle tracks generated ISPA and Python parser sources and the shared standard library for rebuilds.

Run `./gradlew test` for lexer restart, Unicode protocol, and packaged helper tests. Run `python3 tests/bridge_test.py build/native-build/ispa-grammar-bridge` for native parsing and error-position tests.
