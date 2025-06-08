cmake_minimum_required(VERSION 3.30 FATAL_ERROR)
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
    list(REMOVE_DUPLICATES result)
    set(${output_var} ${result} PARENT_SCOPE)
endfunction()
function(add_raw_module target source_target)
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
        message(STATUS "Checking cached std module location...")

        # Use cache variable if already set
        if(NOT DEFINED STDCXX_MODULE_PATH OR NOT EXISTS "${STDCXX_MODULE_PATH}")
            message(STATUS "Searching for std.cppm module...")
            file(GLOB_RECURSE STDCXX_MODULE_LIST
                    "/lib/**/std.cppm"
                    "/usr/**/std.cppm"
            )
            if(STDCXX_MODULE_LIST)
                list(GET STDCXX_MODULE_LIST 0 STDCXX_MODULE_PATH)
                set(STDCXX_MODULE_PATH "${STDCXX_MODULE_PATH}" CACHE FILEPATH "Path to std.cppm module")
            else()
                message(FATAL_ERROR "std.cppm module not found in system directories")
            endif()
            message(STATUS "Module found at ${STDCXX_MODULE_PATH}")
        else()
            message(STATUS "Using cached std module location: ${STDCXX_MODULE_PATH}")
        endif()

        # Get compat module next to it
        get_filename_component(STDCXX_MODULE_DIR ${STDCXX_MODULE_PATH} DIRECTORY)
        set(STD_COMPATCXX_MODULE_PATH "${STDCXX_MODULE_DIR}/std.compat.cppm")
        if(NOT EXISTS "${STD_COMPATCXX_MODULE_PATH}")
            message(FATAL_ERROR "std.compat.cppm not found at expected location: ${STD_COMPATCXX_MODULE_PATH}")
        endif()
        set(STDCXX_MODULE_NAME std.cppm)
        set(STDCXX_COMPAT_MODULE_NAME std.compat.cppm)
    endif()
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        if (NOT DEFINED COMPILER_INSTALL_DIR)
            get_filename_component(COMPILER_PATH "${CMAKE_CXX_COMPILER}" REALPATH)
            get_filename_component(COMPILER_BIN_DIR "${COMPILER_PATH}" DIRECTORY)
            get_filename_component(COMPILER_ROOT_DIR "${COMPILER_BIN_DIR}" DIRECTORY)
        endif()
        message(STATUS "Using gcc installation dir: ${COMPILER_ROOT_DIR}")

        # Use cache variable if already set
        if(NOT DEFINED STDCXX_MODULE_PATH OR NOT EXISTS "${STDCXX_MODULE_PATH}")
            message(STATUS "Searching for std.cc module...")
            file(GLOB_RECURSE STDCXX_MODULE_LIST
                    "${COMPILER_ROOT_DIR}/include/**/std.cc"
            )
            if(STDCXX_MODULE_LIST)
                list(GET STDCXX_MODULE_LIST 0 STDCXX_MODULE_PATH)
                set(STDCXX_MODULE_PATH "${STDCXX_MODULE_PATH}" CACHE FILEPATH "Path to std.cc module")
            else()
                message(FATAL_ERROR "std.cc module not found in gcc installation dir")
            endif()
            message(STATUS "Module found at ${STDCXX_MODULE_PATH}")
        else()
            message(STATUS "Using cached std module location: ${STDCXX_MODULE_PATH}")
        endif()

        # Get compat module next to it
        get_filename_component(STDCXX_MODULE_DIR ${STDCXX_MODULE_PATH} DIRECTORY)
        set(STD_COMPATCXX_MODULE_PATH "${STDCXX_MODULE_DIR}/std.compat.cc")
        if(NOT EXISTS "${STD_COMPATCXX_MODULE_PATH}")
            message(FATAL_ERROR "std.compat.cc not found at expected location: ${STD_COMPATCXX_MODULE_PATH}")
        endif()
        set(STDCXX_MODULE_NAME std.cc)
        set(STDCXX_COMPAT_MODULE_NAME std.compat.cc)
    endif()
    # Copy both to build dir
    file(COPY ${STDCXX_MODULE_PATH} DESTINATION ${CMAKE_BINARY_DIR}/prebuilt_std)
    file(COPY ${STD_COMPATCXX_MODULE_PATH} DESTINATION ${CMAKE_BINARY_DIR}/prebuilt_std)

    set(STDCXX_MODULE_CMAKE_PATH "${CMAKE_BINARY_DIR}/prebuilt_std/${STDCXX_MODULE_NAME}")
    set(STD_COMPATCXX_MODULE_CMAKE_PATH "${CMAKE_BINARY_DIR}/prebuilt_std/${STDCXX_COMPAT_MODULE_NAME}")

    target_compile_options(${target} PRIVATE
            -Wno-reserved-identifier
            -Wno-reserved-module-identifier
    )
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(${target} PRIVATE -stdlib=libc++)
    endif()

    target_include_directories(${target} PRIVATE ${STDCXX_MODULE_DIR})
    target_sources(${target}
            PUBLIC
            FILE_SET cxx_modules TYPE CXX_MODULES FILES
            ${STDCXX_MODULE_CMAKE_PATH}
            ${STD_COMPATCXX_MODULE_CMAKE_PATH}
    )
    set_target_properties(${target} PROPERTIES LINKER_LANGUAGE CXX)
endfunction()

# =============================================
# Fetch libraries
# =============================================

include(FetchContent)

# Try to find system-installed fmt
#find_package(fmt QUIET)
# If not found, fetch it
#message(STATUS "fmt not found, using FetchContent to download it")
#FetchContent_Declare(fmt
#        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#        GIT_TAG master
#)
#FetchContent_MakeAvailable(fmt)

# get spdlog library

#if(NOT TARGET spdlog)
#    # Stand-alone build
#    find_package(spdlog REQUIRED)
#endif()

# ---------------------------------------------------------------------------------------
# Example of using pre-compiled library
# ---------------------------------------------------------------------------------------


# =============================================
# Global Configuration
# =============================================
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
#        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-sanitize-address-use-odr-indicator")
#        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
    endif()
endif()
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
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-stdlib=libc++)
    add_link_options(-stdlib=libc++)
endif()

# =============================================
# Project Definitions
# =============================================
add_compile_definitions(
        __SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}"
        PROGRAM_VERSION="0.1.0 beta"
        O_LEVEL=${O_LEVEL}
)
#get_file_range(FMT_MODULES ${fmt_SOURCE_DIR}/src/fmt.cc)
#add_library(fmt_m STATIC)
#target_sources(fmt_m
#    PUBLIC
#    FILE_SET cxx_modules TYPE CXX_MODULES FILES
#    ${FMT_MODULES}
#)
#target_sources(fmt_m PRIVATE ${ISPA_SOURCES})
#target_include_directories(fmt_m PRIVATE ${fmt_SOURCE_DIR}/include)
# =============================================
# ISPA MAIN EXECUTABLE MODULES
# =============================================
add_library(ispa_modules STATIC)
get_file_range(ISPA_MODULES
        ${SRC_DIR}/*.cppm
        ${PARSER_DIR}/*.cppm
        ${INCLUDE_DIR}/*.cppm
        external/*.cppm
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
        external/cpuf/*.cpp
)
target_sources(ispa PRIVATE ${ISPA_SOURCES})
target_include_directories(ispa PRIVATE ${INCLUDE_DIRS})
#target_compile_options(ispa PRIVATE ${MODULE_COMPILATION})
target_link_libraries(ispa
        PRIVATE
            ispa_modules
#            cxx_std_module
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
# export modules from main executable to shared library
#add_raw_module(ispa-converter-cpp ispa_modules
#        corelib
#        hash
#        logging
#        cpuf.printf
#        cpuf.color
#        Parser
#        ispastdlibcpp
#        TreeAPI
#        AST
#        LRParser
#        ELRParser
#        LLIRBuilder
#        LLIR
#)
#add_raw_module(ispa-converter-cpp cxx_std_module
#        std
#        std.compat
#)
#target_compile_options(ispa-converter-cpp PRIVATE ${MODULE_COMPILATION})
# =============================================
# Link Dependencies
# =============================================
add_dependencies(ispa_modules cxx_std_module)
add_dependencies(ispa ispa_modules cxx_std_module)
add_dependencies(ispa-converter-cpp ispa_modules cxx_std_module)
target_link_libraries(ispa-converter-cpp PRIVATE ispa_modules)
#target_link_libraries(ispa_modules PRIVATE fmt_m fmt::fmt)
target_link_libraries(ispa PRIVATE
    ispa-converter-cpp
    #fmt::fmt
    #fmt_m
)
# =============================================
# Testing Configuration
# =============================================
add_library(tests INTERFACE)
target_compile_definitions(tests INTERFACE
        __ROOT_DIR__="${CMAKE_CURRENT_SOURCE_DIR}/tests"
)
target_include_directories(tests INTERFACE
        tests
)
function(add_ispa_test test_name test_file test_dir tester)
    if(NOT EXISTS "${tester}")
        message(FATAL_ERROR "Tester not found: ${CMAKE_CURRENT_SOURCE_DIR}/tests/${directory}/tester.cpp")
    endif()
    add_executable(${test_name} ${tester})
    target_link_libraries(${test_name} PRIVATE tests)
    target_compile_definitions(${test_name} PRIVATE
            __PROCESS_FILE__="${test_file}"
            __TEST_DIR__="${test_dir}"
    )
    add_test(NAME ${test_name} COMMAND ${test_name})
    set_tests_properties(${test_name} PROPERTIES TIMEOUT 2)
endfunction()
function(add_test_dir directory)
    get_file_range(TEST_FILES tests/${directory}/*.isc)

    foreach(TEST_FILE IN LISTS TEST_FILES)
        get_filename_component(TEST_NAME "${TEST_FILE}" NAME_WE)
        add_ispa_test(${TEST_NAME} "${TEST_FILE}" ${CMAKE_CURRENT_SOURCE_DIR}/tests/${directory} "${CMAKE_CURRENT_SOURCE_DIR}/tests/${directory}/tester.cpp")
    endforeach()
endfunction()

# =============================================
# Testing
# =============================================
enable_testing()
add_test_dir(NFA-DFA)

#add_test(
#        NAME mainTest
#        COMMAND ${CMAKE_BINARY_DIR}/ispa --dir parser/parser --lang cpp -a LL
#        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#)