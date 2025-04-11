cmake_minimum_required(VERSION 3.21)
project(Parser)
enable_testing()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)
file(GLOB_RECURSE parser_sources CONFIGURE_DEPENDS "src/*.cpp")
add_library(parser STATIC ${parser_sources})
add_library(parser_stdlib STATIC stdlibs/iscstdlibc++.cpp)
target_include_directories(parser PUBLIC include stdlibs/old)
target_include_directories(parser_stdlib PUBLIC stdlibs/old)
set_target_properties(parser PROPERTIES POSITION_INDEPENDENT_CODE ON)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_definitions(__LIBC)
endif()

# Create an interface library to hold common properties
add_library(parser_test_common INTERFACE)
target_include_directories(parser_test_common INTERFACE include stdlibs/old tests/lib)
target_compile_definitions(parser_test_common INTERFACE __ROOT_DIR__="${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(parser_test_common INTERFACE parser parser_stdlib)

# Define parser_complete_test
add_executable(parser_complete_test tests/complete_test.cpp)
target_link_libraries(parser_complete_test PRIVATE parser_test_common)
add_test(NAME parser_complete_test COMMAND parser_complete_test)
# Define parser_rule_test
add_executable(parser_rule_test tests/Rule.cpp)
target_link_libraries(parser_rule_test PRIVATE parser_test_common)
add_test(NAME parser_rule_test COMMAND parser_rule_test)
# Define parser_expr_test
add_executable(parser_expr_test tests/expr.cpp)
target_link_libraries(parser_expr_test PRIVATE parser_test_common)
add_test(NAME parser_expr_test COMMAND parser_expr_test)
# Define parser_accessor_test
add_executable(parser_accessor_test tests/accessors.cpp)
target_link_libraries(parser_accessor_test PRIVATE parser_test_common)
add_test(NAME parser_accessor_test COMMAND parser_accessor_test)
# Define parser_cll_test
add_executable(parser_cll_test tests/cll.cpp)
target_link_libraries(parser_cll_test PRIVATE parser_test_common)
add_test(NAME parser_cll_test COMMAND parser_cll_test)
# Define parser_cll_ternary_test
add_executable(parser_cll_ternary_test tests/ternary.cpp)
target_link_libraries(parser_cll_ternary_test PRIVATE parser_test_common)
add_test(NAME parser_cll_ternary_test COMMAND parser_cll_ternary_test)
# Define parser_loop_test
add_executable(parser_loop_test tests/loop.cpp)
target_link_libraries(parser_loop_test PRIVATE parser_test_common)
add_test(NAME parser_loop_test COMMAND parser_loop_test)
# Define parser_cll_ternary_test
add_executable(parser_if_test tests/if.cpp)
target_link_libraries(parser_if_test PRIVATE parser_test_common)
add_test(NAME parser_if_test COMMAND parser_if_test)
# Define parser_cll_method_call_test
add_executable(parser_method_call_test tests/method_call.cpp)
target_link_libraries(parser_method_call_test PRIVATE parser_test_common)
add_test(NAME parser_method_call_test COMMAND parser_method_call_test)