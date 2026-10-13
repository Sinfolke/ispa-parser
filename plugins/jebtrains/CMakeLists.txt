cmake_minimum_required(VERSION 3.20)
project(ispa_grammar_bridge LANGUAGES CXX)

if(NOT DEFINED ISPA_ROOT)
  get_filename_component(ISPA_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
endif()

add_executable(ispa-grammar-bridge
  "${CMAKE_CURRENT_LIST_DIR}/parser_bridge.cpp"
  "${ISPA_ROOT}/Parser.cpp"
)
target_include_directories(ispa-grammar-bridge PRIVATE
  "${ISPA_ROOT}"
  "${ISPA_ROOT}/parser/stdlibs"
)
target_compile_features(ispa-grammar-bridge PRIVATE cxx_std_23)
# Intentionally do not force a compiler, standard library, or linker here.
# CMake consumes CC/CXX/CFLAGS/CXXFLAGS/LDFLAGS from the build environment.
