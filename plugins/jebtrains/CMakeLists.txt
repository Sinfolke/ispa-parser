cmake_minimum_required(VERSION 3.22)
project(ispa_grammar_bridge LANGUAGES CXX)

if(NOT DEFINED ISPA_ROOT)
  get_filename_component(ISPA_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../" ABSOLUTE)
endif()
set(ISPA_BUILD_EXECUTABLES OFF CACHE BOOL "" FORCE)
set(ISPA_BUILD_SELF_PARSER ON CACHE BOOL "" FORCE)
set(ISPA_BUILD_PYTHON_PARSER OFF CACHE BOOL "" FORCE)
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
