cmake_minimum_required(VERSION 3.21)  # Ensure CMake version supports modules
project(ParserModule)

# Enable C++ modules support for your compiler (Clang or GCC)
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-fmodules-ts)
endif()

# Define the module interface file
add_library(parser MODULE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/parser.ixx
)
# Add additional source files for the implementation

file(GLOB parser_sources "src/*.cpp")
target_sources(parser PRIVATE ${parser_sources})

# Include directories for header files
target_include_directories(parser PUBLIC include)

# set cxx20 standard
set_target_properties(parser PROPERTIES CXX_STANDARD 20 CXX_STANDARD_REQUIRED YES)