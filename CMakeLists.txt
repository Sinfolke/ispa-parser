cmake_minimum_required(VERSION 3.28.3)
project(ISPA LANGUAGES CXX)
# =============================================
# FUNCTIONS
# =============================================
function(get_file_range output_var)
    set(result "")
    foreach(path IN LISTS ARGN)
        file(GLOB_RECURSE temp CONFIGURE_DEPENDS ${path})
        list(APPEND result ${temp})
    endforeach()
    set(${output_var} ${result} PARENT_SCOPE)
endfunction()


# =============================================
# Global Configuration
# =============================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
# =============================================
# Project Structure
# =============================================
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PARSER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/parser)
set(INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/parser
        ${CMAKE_CURRENT_SOURCE_DIR}/parser/stdlibs
        ${CMAKE_CURRENT_SOURCE_DIR}/external
        ${CMAKE_CURRENT_SOURCE_DIR}/converters
)


# =============================================
# Compiler Configuration
# =============================================

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
else()
    add_link_options(-rdynamic)
endif()

# =============================================
# Dependencies
# =============================================
if(NOT DISABLE_TRACER)
    add_compile_definitions(ENABLE_TRACER)
    if(WIN32)
        find_package(Boost REQUIRED COMPONENTS stacktrace_noop)
    else()
        find_package(Boost 1.74 REQUIRED COMPONENTS stacktrace_backtrace)
    endif()
endif()

# =============================================
# Project Definitions
# =============================================
add_compile_definitions(
        __SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}"
        PROGRAM_VERSION="0.1.0 beta"
        O_LEVEL=${O_LEVEL}
)

# =============================================
# Main Executable
# =============================================
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "TRUE") # required for modules
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP "TRUE")    # enables BMI dependencies

add_executable(ispa)
#target_compile_options(ispa PRIVATE -fmodules)
get_file_range(ISPA_SOURCES
        ${PARSER_DIR}/*.cpp
        ${SRC_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/external/cpuf/*.cpp
)
get_file_range(ISPA_MODULE_INTERFACES
        ${SRC_DIR}/*.cppm
)
target_sources(ispa PRIVATE ${ISPA_SOURCES})
target_sources(ispa
        PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        ${ISPA_MODULE_INTERFACES}
)

target_include_directories(ispa PRIVATE ${INCLUDE_DIRS})
set_target_properties(ispa PROPERTIES
        OUTPUT_NAME ispa
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        HEADER_FILE_ONLY FALSE
        SKIP_PRECOMPILE_HEADERS TRUE
)

# =============================================
# Converter Configuration
# =============================================
add_library(ispa-converter INTERFACE)
target_include_directories(ispa-converter INTERFACE ${INCLUDE_DIRS})

if(WIN32)
    file(GLOB_RECURSE CONVERTER_SRC ${SRC_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/external/cpuf/*.cpp)
endif()

file(GLOB_RECURSE CPP_CONVERTER_SOURCES converters/C++/*.cpp)
add_library(ispa-converter-cpp SHARED
        ${CPP_CONVERTER_SOURCES}
        ${CONVERTER_SRC}
        ${SRC_DIR}/tree.cpp
)

target_link_libraries(ispa-converter-cpp PRIVATE
        ispa-converter
)
target_include_directories(ispa-converter-cpp PRIVATE converters/C++)

# =============================================
# Link Dependencies
# =============================================
target_link_libraries(ispa PRIVATE
    ispa-converter-cpp
)

if(NOT DISABLE_TRACER)
    target_link_libraries(ispa PRIVATE Boost::stacktrace_backtrace)
endif()

# =============================================
# Testing Configuration
# =============================================
#add_library(tests INTERFACE)
#target_compile_definitions(tests INTERFACE
#        __ROOT_DIR__="${CMAKE_CURRENT_SOURCE_DIR}/tests"
#)
#target_include_directories(tests INTERFACE
#        parser/include
#        parser/stdlibs/old
#)

# Uncomment and modify as needed for test executables
# function(add_ispa_test test_name)
#     add_executable(${test_name} tests/tester.cpp)
#     target_link_libraries(${test_name} PRIVATE tests)
#     target_compile_definitions(${test_name} PRIVATE
#         __PROCESS_FILE__="${test_name}.isc"
#     )
# endfunction()
#
# add_ispa_test(IR-convertion-group)
# add_ispa_test(IR-skip-spaces)
# add_ispa_test(hex-bin)
# add_ispa_test(group-variable-type)
# add_ispa_test(accessor)
# add_ispa_test(inline-accessor-if-test)
# add_ispa_test(inline-test)
# add_ispa_test(insideLoop-test)

# =============================================
# Testing
# =============================================
#add_test(
#        NAME mainTest
#        COMMAND ${CMAKE_BINARY_DIR}/ispa --dir parser/parser --lang cpp -a LL
#        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#)