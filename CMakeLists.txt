cmake_minimum_required(VERSION 3.21)  # CMake 3.21+ required for initial C++20 modules support
project(ParserModule)

# Require C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Ensure the compiler supports modules
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-fmodules-ts)
    message(STATUS "Using Clang with -fmodules-ts")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-fmodules-ts)
    message(STATUS "Using GCC with -fmodules-ts")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/std:c++20 /experimental:module)
    message(STATUS "Using MSVC with /experimental:module")
else()
    message(FATAL_ERROR "Your compiler (${CMAKE_CXX_COMPILER}) (id: ${CMAKE_CXX_COMPILER_ID}) not supports c++20 modules")
endif()

# Locate module source files (.cppm or .ixx depending on compiler)
file(GLOB_RECURSE module_sources CONFIGURE_DEPENDS "src/*.cppm" "src/*.ixx")

# Add the parser library as STATIC or SHARED
add_library(parser STATIC)

# Add the module sources
target_sources(parser PRIVATE ${module_sources})

# Include public headers for the library
target_include_directories(parser PUBLIC include)

# Display compiler info for debugging

# Display compiler info for debugging
message(STATUS "Using C++ compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Module sources: ${module_sources}")