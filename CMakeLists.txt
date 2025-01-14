cmake_minimum_required(VERSION 3.28.3)
project(ISPA)

#enable_testing()
set(SRC_DIR ./src)
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp external/cpuf/*.cpp)
add_library(ispa-converter-cpp SHARED ${SOURCES})
# export all symbols in library
if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
else()
    target_compile_options(ispa-converter-cpp PUBLIC -fvisibility=default)
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable GNU extensions
set_target_properties(ispa-converter-cpp PROPERTIES CXX_STANDARD_REQUIRED 17)
set_target_properties(ispa-converter-cpp PROPERTIES CXX_STANDARD 17)
set_target_properties(ispa-converter-cpp PROPERTIES CXX_EXTENSIONS ON)


add_compile_definitions(__SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}")
add_compile_definitions(O_LEVEL=${O_LEVEL})
include_directories(include external mod/parser/include mod/parser/stdlibs  mod/main/include)