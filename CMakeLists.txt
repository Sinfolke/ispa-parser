cmake_minimum_required(VERSION 3.28.3)
project(ISPA)

#enable_testing()
add_subdirectory(parser)           # include parser
#add_subdirectory(mod/converter-cpp)    # include c++ converter
set(SRC_DIR ./src)
file(GLOB_RECURSE SOURCES ${SRC_DIR}/*.cpp external/cpuf/*.cpp)
add_executable(ispa ${SOURCES})
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
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
        set(O_LEVEL 2)
    endif()
endif()

if(MSVC)
    # Enable exporting all symbols for MSVC
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
else()
    # Enable exporting all symbols for GCC/Clang
    target_link_options(ispa PRIVATE -rdynamic)
endif()
if (NOT DISABLE_TRACER)
    # Enable call tracer
    add_compile_definitions(ENABLE_TRACER)
    if (MSVC)
        add_compile_options(/Zi)
    else()
        add_compile_options(-g)
    endif()

    if (WIN32)
       find_package(Boost REQUIRED COMPONENTS stacktrace_noop)
       target_link_libraries(ispa PRIVATE Boost::stacktrace_noop)
    else()
       find_package(Boost 1.74 REQUIRED COMPONENTS stacktrace_backtrace)
       target_link_libraries(ispa PRIVATE Boost::stacktrace_backtrace)
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
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable GNU extensions
set_target_properties(ispa PROPERTIES CXX_STANDARD_REQUIRED 17)
set_target_properties(ispa PROPERTIES CXX_STANDARD 17)
set_target_properties(ispa PROPERTIES CXX_EXTENSIONS ON)

add_compile_definitions(__SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}")
add_compile_definitions(PROGRAM_VERSION="0.1.0 beta")
add_compile_definitions(O_LEVEL=${O_LEVEL})
include_directories(parser/include)
include_directories(include parser/stdlibs/old)
target_include_directories(ispa PRIVATE include src external parser/include converters)
set_target_properties(ispa PROPERTIES OUTPUT_NAME ispa)
target_link_libraries(ispa PRIVATE parser parser_stdlib ispa-converter-cpp)
target_compile_definitions(ispa PRIVATE BUILDING_EXE)

# add converter library
add_library(ispa-converter INTERFACE)
target_include_directories(ispa-converter INTERFACE include src external parser/include parser/stdlibs/old converters)
if (WIN32)
    set(SRC_DIR ./src)
    file(GLOB_RECURSE CONVERTER_SRC ${SRC_DIR}/*.cpp external/cpuf/*.cpp)
endif()
file(GLOB_RECURSE CPP_CONVERTER_SOURCES converters/C++/*.cpp)
add_library(ispa-converter-cpp SHARED ${CPP_CONVERTER_SOURCES} ${CONVERTER_SRC} ${SRC_DIR}/tree.cpp)
target_link_libraries(ispa-converter-cpp PRIVATE ispa-converter parser parser_stdlib)
target_include_directories(ispa-converter-cpp PRIVATE converters/C++)
#create interface for tests
add_library(tests INTERFACE)
target_compile_definitions(tests INTERFACE __ROOT_DIR__="${CMAKE_CURRENT_SOURCE_DIR}/tests")
target_include_directories(tests INTERFACE parser/include parser/stdlibs/old)
#IR-convertion-group
add_executable(IR-convertion-group tests/tester.cpp)
target_link_libraries(IR-convertion-group PRIVATE tests)
target_compile_definitions(IR-convertion-group PRIVATE __PROCESS_FILE__="IR-convertion-group.isc")
#IR-skip-spaces
add_executable(IR-skip-spaces tests/tester.cpp)
target_link_libraries(IR-skip-spaces PRIVATE tests)
target_compile_definitions(IR-skip-spaces PRIVATE __PROCESS_FILE__="IR-skip-spaces.isc")
#hex-bin
add_executable(hex-bin tests/tester.cpp)
target_link_libraries(hex-bin PRIVATE tests)
target_compile_definitions(hex-bin PRIVATE __PROCESS_FILE__="hex-bin.isc")
#group-variable-type
add_executable(group-variable-type tests/tester.cpp)
target_link_libraries(group-variable-type PRIVATE tests)
target_compile_definitions(group-variable-type PRIVATE __PROCESS_FILE__="group-variable-type.isc")
#accessor
add_executable(accessor tests/tester.cpp)
target_link_libraries(accessor PRIVATE tests)
target_compile_definitions(accessor PRIVATE __PROCESS_FILE__="accessor.isc")
#inline-accessor-if-test
add_executable(inline-accessor-if-test tests/tester.cpp)
target_link_libraries(inline-accessor-if-test PRIVATE tests)
target_compile_definitions(inline-accessor-if-test PRIVATE __PROCESS_FILE__="inline-accessor-if-test.isc")
#inline-test
add_executable(inline-test tests/tester.cpp)
target_link_libraries(inline-test PRIVATE tests)
target_compile_definitions(inline-test PRIVATE __PROCESS_FILE__="inline-test.isc")
#insideLoop-test
add_executable(insideLoop-test tests/tester.cpp)
target_link_libraries(insideLoop-test PRIVATE tests)
target_compile_definitions(insideLoop-test PRIVATE __PROCESS_FILE__="insideLoop.isc")
add_test(
    NAME mainTest
    COMMAND ${CMAKE_BINARY_DIR} ispa --dir parser/parser --lang cpp
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
