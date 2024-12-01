cmake_minimum_required(VERSION 3.21)
project(ParserModule)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

file(GLOB_RECURSE parser_sources CONFIGURE_DEPENDS "src/*.cpp")
add_library(parser MODULE STATIC ${parser_sources})
target_include_directories(parser PUBLIC include stdlibs)