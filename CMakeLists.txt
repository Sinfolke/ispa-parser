cmake_minimum_required(VERSION 3.28.3)
project(ISPA)

enable_testing()
add_subdirectory(mod/parser)    # include parser
set(SRC_DIR ./src)
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp external/cpuf/*.cpp)
add_executable(ispa ${SOURCES})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
    if (NOT O_LEVEL)
        set(O_LEVEL g)
    endif()
else()
    # RELEASE
    # -fno-semantic-interposition
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        add_compile_options(-ffast-math -fno-protect-parens)
    else()
        message(STATUS "Found compiler not support direct optimization control")
    endif()
    if (NOT O_LEVEL)
        set(O_LEVEL, 2)
    endif()
endif()

if (NOT DISABLE_TRACER)
    # Enable call tracer
    add_compile_definitions(ENABLE_TRACER)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        add_compile_options(/Zi)
    else()
        add_compile_options(-g1)
    endif()
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_definitions(__LIBC)
    # to somehow find backtrace.h
    include_directories(
        /usr/lib/gcc/x86_64-linux-gnu/14/include 
        /usr/lib/gcc/x86_64-linux-gnu/13/include 
        /usr/lib/gcc/x86_64-linux-gnu/12/include 
        /usr/lib/gcc/x86_64-linux-gnu/11/include
        /usr/lib/gcc/x86_64-linux-gnu/10/include
    )
endif()
if (WIN32)
    find_package(Boost REQUIRED COMPONENTS stacktrace_noop)
    target_link_libraries(ispa Boost::stacktrace_noop)
else()
    find_package(Boost 1.74 REQUIRED COMPONENTS stacktrace_backtrace)
    target_link_libraries(ispa Boost::stacktrace_backtrace)
endif()

add_compile_definitions(__SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}")
add_compile_definitions(PROGRAM_VERSION="0.1.0 beta")
add_compile_definitions(O_LEVEL=${O_LEVEL})
include_directories(mod/parser/include)
include_directories(include stdlibs)
target_include_directories(ispa PRIVATE include external parser/mod/include)
set_target_properties(ispa PROPERTIES OUTPUT_NAME ispa)
target_link_libraries(ispa parser parser_stdlib)
#set_target_properties(isc PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable GNU extensions
set_target_properties(ispa PROPERTIES CXX_STANDARD_REQUIRED 17)
set_target_properties(ispa PROPERTIES CXX_STANDARD 17)
set_target_properties(ispa PROPERTIES CXX_EXTENSIONS ON)

add_test(
    NAME mainTest
    COMMAND ${CMAKE_BINARY_DIR} ispa --dir mod/parser/parser
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)