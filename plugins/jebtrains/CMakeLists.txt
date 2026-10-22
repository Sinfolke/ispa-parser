cmake_minimum_required(VERSION 3.22)
project(ispa_grammar_bridge LANGUAGES CXX)

if(NOT DEFINED ISPA_ROOT)
  get_filename_component(ISPA_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)
endif()
# Prefer the current modular bootstrap; callers may select another generated
# parser explicitly with ISPA_BOOTSTRAPPED_DIR / ISPA_PARSER_MODE.
if(NOT ISPA_BOOTSTRAPPED_DIR AND EXISTS "${ISPA_ROOT}/parser/ispa/bootstrapped/Parser.h")
  set(ISPA_BOOTSTRAPPED_DIR "${ISPA_ROOT}/parser/ispa/bootstrapped" CACHE PATH "ISPA parser for the IDE")
  set(ISPA_PARSER_MODE BOOTSTRAPPED CACHE STRING "Generated parser layout")
endif()
set(ISPA_BUILD_DEP_PARSER OFF CACHE BOOL "" FORCE)
set(ISPA_BUILD_EXECUTABLES OFF CACHE BOOL "" FORCE)
set(ISPA_BUILD_SELF_PARSER ON CACHE BOOL "" FORCE)
set(ISPA_BUILD_PYTHON_PARSER ON CACHE BOOL "" FORCE)
add_subdirectory("${ISPA_ROOT}/parser" "${CMAKE_CURRENT_BINARY_DIR}/parser_build")
add_executable(ispa-grammar-bridge
  "${CMAKE_CURRENT_LIST_DIR}/parser_bridge.cpp"
)
target_include_directories(ispa-grammar-bridge PRIVATE
  "${ISPA_ROOT}"
)
target_link_libraries(ispa-grammar-bridge PRIVATE ISPA::Parser)
target_compile_features(ispa-grammar-bridge PRIVATE cxx_std_23)
# Intentionally do not force a compiler, standard library, or linker here.
# CMake consumes CC/CXX/CFLAGS/CXXFLAGS/LDFLAGS from the build environment.

if(ISPA_BOOTSTRAPPED_DIR)
  file(READ "${ISPA_BOOTSTRAPPED_DIR}/Parser.h" ISPA_PARSER_HEADER)
elseif(EXISTS "${ISPA_ROOT}/parser/ispa/incremental/Parser.h")
  file(READ "${ISPA_ROOT}/parser/ispa/incremental/Parser.h" ISPA_PARSER_HEADER)
else()
  file(READ "${ISPA_ROOT}/parser/ispa/bootstrapped/Parser.h" ISPA_PARSER_HEADER)
endif()
if(ISPA_PARSER_HEADER MATCHES "Types::modules::common::ID")
  target_compile_definitions(ispa-grammar-bridge PRIVATE ISPA_MODULAR_PARSER=1)
endif()
