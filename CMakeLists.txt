cmake_minimum_required(VERSION 3.30 FATAL_ERROR)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")
project(ISPA LANGUAGES CXX)
set(CMAKE_CXX_MODULE_STD 1) # this is important
# =============================================
# FUNCTIONS
# =============================================
function(get_file_range output_var)
    set(result "")
    foreach(path IN LISTS ARGN)
        file(GLOB_RECURSE temp CONFIGURE_DEPENDS ${path})
        list(APPEND result ${temp})
    endforeach()
    list(REMOVE_DUPLICATES result)
    set(${output_var} ${result} PARENT_SCOPE)
endfunction()
function(add_raw_module target source_target)
    # Ensure that source_target builds before this one

    foreach(module IN LISTS ARGN)
        target_compile_options(${target} PRIVATE
                "-fmodule-file=${module}=${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${source_target}.dir/${module}.pcm"
        )
    endforeach()
endfunction()
function(collect_filenames out_var extension)
    set(cppm_files "")
    foreach(path IN LISTS ARGN)
        file(GLOB_RECURSE temp RELATIVE "${path}" "${path}/*.${extension}")
        list(APPEND cppm_files ${temp})
    endforeach()

    list(REMOVE_DUPLICATES cppm_files)

    set(result "")
    foreach(file ${cppm_files})
        get_filename_component(name "${file}" NAME_WE)
        list(APPEND result "${name}")
    endforeach()

    set(${out_var} "${result}" PARENT_SCOPE)
endfunction()
function(precompile_std target)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        message(STATUS "Searching std module")

        file(GLOB_RECURSE STDCXX_MODULE_LIST
                "/lib/**/std.cppm"
                "/usr/**/std.cppm"
        )

        if(STDCXX_MODULE_LIST)
            list(GET STDCXX_MODULE_LIST 0 STDCXX_MODULE)
            message(STATUS "Using std module at: ${STDCXX_MODULE}")
        else()
            message(FATAL_ERROR "std.cppm module not found in system directories")
        endif()
        # copy module into current directory to avoid cmake conflicts
        file(COPY ${STDCXX_MODULE} DESTINATION ${CMAKE_BINARY_DIR}/prebuilt_std)
        set(STDCXX_MODULE_CMAKE_PATH ${CMAKE_BINARY_DIR}/prebuilt_std/std.cppm)
        # Add compile command to precompile std module
        target_compile_options(${target} PRIVATE
                -stdlib=libc++
                -Wno-reserved-identifier
                -Wno-reserved-module-identifier
        )
        get_filename_component(STDCXX_MODULE_DIR ${STDCXX_MODULE} DIRECTORY)
        target_include_directories(${target} PRIVATE ${STDCXX_MODULE_DIR})
        target_sources(${target}
                PUBLIC
                FILE_SET cxx_modules TYPE CXX_MODULES FILES
                ${STDCXX_MODULE_CMAKE_PATH}
        )
endif()
endfunction()

# =============================================
# Fetch libraries
# =============================================

include(FetchContent)

# Try to find system-installed fmt
#find_package(fmt QUIET)
# If not found, fetch it
message(STATUS "fmt not found, using FetchContent to download it")
FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

# =============================================
# Global Configuration
# =============================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
# =============================================
# Project Structure
# =============================================
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CONVERTERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/converters)
set(PARSER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/parser)
set(INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/parser
        ${CMAKE_CURRENT_SOURCE_DIR}/parser/stdlibs
        ${CMAKE_CURRENT_SOURCE_DIR}/external
        ${CMAKE_CURRENT_SOURCE_DIR}/converters
        ${CMAKE_CURRENT_SOURCE_DIR}/external/fmt/include
)
# =============================================
# Add CXX20 std module
# =============================================
add_library(cxx_std_module STATIC)
precompile_std(cxx_std_module)
# =============================================
# Compiler Configuration
# =============================================
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "TRUE") # required for modules
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP "TRUE")    # enables BMI dependencies
if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
else()
    add_link_options(-rdynamic)
endif()
set(CLANG_MODULE_CACHE_DIR "${CMAKE_BINARY_DIR}/clang-modules")
set(MODULE_COMPILATION
        -fmodules-cache-path=${CLANG_MODULE_CACHE_DIR}
)
add_compile_options(-stdlib=libc++)
add_link_options(-stdlib=libc++)
# =============================================
# Project Definitions
# =============================================
add_compile_definitions(
        __SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}"
        PROGRAM_VERSION="0.1.0 beta"
        O_LEVEL=${O_LEVEL}
)
get_file_range(FMT_MODULES ${fmt_SOURCE_DIR}/src/fmt.cc)
add_library(fmt_m STATIC)
target_sources(fmt_m
    PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
    ${FMT_MODULES}
)
target_sources(fmt_m PRIVATE ${ISPA_SOURCES})
target_include_directories(fmt_m PRIVATE ${fmt_SOURCE_DIR}/include)
# =============================================
# ISPA MAIN EXECUTABLE MODULES
# =============================================
add_library(ispa_modules STATIC)
get_file_range(ISPA_MODULES
        ${SRC_DIR}/*.cppm
        ${PARSER_DIR}/*.cppm
        ${INCLUDE_DIR}/*.cppm
)
target_sources(ispa_modules
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        ${ISPA_MODULES}
)
target_include_directories(ispa_modules PRIVATE ${INCLUDE_DIRS})
target_link_libraries(ispa_modules PRIVATE cxx_std_module)
# =============================================
# Main Executable
# =============================================

add_executable(ispa)
#target_compile_options(ispa PRIVATE -fmodules)
get_file_range(ISPA_SOURCES
        ${PARSER_DIR}/*.cpp
        ${SRC_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/external/color.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/external/*.cc
)
target_sources(ispa PRIVATE ${ISPA_SOURCES})
target_include_directories(ispa PRIVATE ${INCLUDE_DIRS})
#target_compile_options(ispa PRIVATE ${MODULE_COMPILATION})
target_link_libraries(ispa
        PRIVATE
            ispa_modules
            cxx_std_module
)
# =============================================
# Converter Configuration
# =============================================
add_library(ispa-converter INTERFACE)
target_include_directories(ispa-converter INTERFACE ${INCLUDE_DIRS})
#
#if(WIN32)
#    file(GLOB_RECURSE CONVERTER_SRC ${SRC_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/external/cpuf/*.cpp)
#endif()
get_file_range(CPP_CONVERTER_SOURCES
        ${CONVERTERS_DIR}/C++/*.cpp
)
add_library(ispa-converter-cpp SHARED
        ${CPP_CONVERTER_SOURCES}
)
target_link_libraries(ispa-converter-cpp PRIVATE
        ispa-converter
)
target_include_directories(ispa-converter-cpp PRIVATE converters/C++)
get_file_range(CPP_CONVERTER_MODULES
        ${CONVERTERS_DIR}/C++/*.cppm
)
target_sources(ispa-converter-cpp
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        ${CPP_CONVERTER_MODULES}
        ${CONVERTERS_DIR}/Converter.cppm
)
#target_compile_options(ispa-converter-cpp PRIVATE ${MODULE_COMPILATION})
# =============================================
# Link Dependencies
# =============================================
add_dependencies(ispa_modules cxx_std_module)
add_dependencies(ispa ispa_modules cxx_std_module)
add_dependencies(ispa-converter-cpp ispa_modules cxx_std_module)
target_link_libraries(ispa-converter-cpp
        PRIVATE
            ispa_modules
)
target_link_libraries(ispa_modules PRIVATE fmt_m fmt::fmt)
target_link_libraries(ispa PRIVATE
    ispa-converter-cpp
    fmt::fmt
    fmt_m
)
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