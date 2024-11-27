cmake_minimum_required(VERSION 3.21)  # CMake 3.21+ required for initial C++20 modules support
project(ParserModule)

# Require C++20
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Locate module source files (.cppm or .ixx)
file(GLOB_RECURSE parser_sources CONFIGURE_DEPENDS "src/*.cpp")

# Add the parser module
add_library(parser MODULE STATIC ${parser_sources})

# Include public headers for the library
target_include_directories(parser PUBLIC include stdlibs)