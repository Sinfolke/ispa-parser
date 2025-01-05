cmake_minimum_required(VERSION 3.28.3)
project(ISPA)

#enable_testing()
set(SRC_DIR ./src)
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp external/cpuf/*.cpp)
add_library(ispa-converter-cpp ${SOURCES})

#set_target_properties(isc PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable GNU extensions
set_target_properties(ispa-converter-cpp PROPERTIES CXX_STANDARD_REQUIRED 17)
set_target_properties(ispa-converter-cpp PROPERTIES CXX_STANDARD 17)
set_target_properties(ispa-converter-cpp PROPERTIES CXX_EXTENSIONS ON)

add_compile_definitions(__SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}")
add_compile_definitions(O_LEVEL=${O_LEVEL})
include_directories(mod/parser/include)
include_directories(include stdlibs)