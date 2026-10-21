cmake_minimum_required(VERSION 4.0 FATAL_ERROR)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")
set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-stdlib=libc++)
    add_link_options(-stdlib=libc++)
endif()

project(ISPA LANGUAGES CXX)
# =============================================
# Compile Definitions
# =============================================
add_compile_definitions(
        __SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}"
        PROGRAM_VERSION="0.1.0 beta"
        O_LEVEL=${O_LEVEL}
        DSTD_NO_DEBUG=1
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        add_compile_options(-g)
    endif()
endif()

if(NOT DEFINED O_LEVEL OR "${O_LEVEL}" STREQUAL "")
    set(O_LEVEL 0)
endif()

# =============================================
# Helper Functions
# =============================================
function(get_file_range output_var)
    cmake_parse_arguments(ARG "" "EXCLUDE" "" ${ARGN})
    set(result "")
    foreach(path IN LISTS ARG_UNPARSED_ARGUMENTS)
        file(GLOB_RECURSE temp CONFIGURE_DEPENDS ${path})
        list(APPEND result ${temp})
    endforeach()
    list(REMOVE_DUPLICATES result)
    if(ARG_EXCLUDE)
        list(FILTER result EXCLUDE REGEX "${ARG_EXCLUDE}")
    endif()
    set(${output_var} ${result} PARENT_SCOPE)
endfunction()
function(get_file_range_non_recurse output_var)
    cmake_parse_arguments(ARG "" "EXCLUDE" "" ${ARGN})

    # Read existing contents from parent scope if available
    set(result "${${output_var}}")

    foreach(path IN LISTS ARG_UNPARSED_ARGUMENTS)
        # Use GLOB to match only the specified directory (non-recursive)
        file(GLOB temp CONFIGURE_DEPENDS ${path})
        list(APPEND result ${temp})
    endforeach()

    if(ARG_EXCLUDE AND result)
        list(FILTER result EXCLUDE REGEX "${ARG_EXCLUDE}")
    endif()

    if(result)
        list(REMOVE_DUPLICATES result)
    endif()

    set(${output_var} "${result}" PARENT_SCOPE)
endfunction()
# =============================================
# Fetch & Find Dependencies
# =============================================

find_package(Boost REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(ICU REQUIRED COMPONENTS uc)

add_subdirectory(parser)

# =============================================
# ISPA Modules Library
# =============================================
add_library(ispa_modules SHARED)
set_target_properties(ispa_modules PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    WINDOWS_EXPORT_ALL_SYMBOLS ON
    BUILD_RPATH "${CMAKE_CURRENT_BINARY_DIR}"
)

get_file_range(ISPA_MODULE_INTERFACES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cppm
        ${CMAKE_CURRENT_SOURCE_DIR}/src/runtime/*.cppm
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.cppm
        ${CMAKE_CURRENT_SOURCE_DIR}/external/*.cppm
)

# Collect implementation sources and exclude main entry point
get_file_range(ISPA_MODULE_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/runtime/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/external/cpuf/*.cpp
        EXCLUDE ".*/main\\.cpp$"
        EXCLUDE "parser/new/.*\\.cpp$"
)
get_file_range_non_recurse(ISPA_MODULE_INTERFACES ${CMAKE_CURRENT_SOURCE_DIR}/lib/converter/*.cppm)
get_file_range_non_recurse(ISPA_MODULE_INTERFACES ${CMAKE_CURRENT_SOURCE_DIR}/lib/algorithm/*.cppm)
list(REMOVE_ITEM ISPA_MODULE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
target_sources(ispa_modules
        PUBLIC
            FILE_SET cxx_modules TYPE CXX_MODULES FILES ${ISPA_MODULE_INTERFACES}
        PRIVATE
            ${ISPA_MODULE_SOURCES}
            ${CMAKE_CURRENT_SOURCE_DIR}/parser/python/bootstrapped/PyRawParser.cpp
)

target_include_directories(ispa_modules PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/parser/stdlibs/new
        ${CMAKE_CURRENT_SOURCE_DIR}/external
        ${CMAKE_CURRENT_SOURCE_DIR}/parser/python/bootstrapped
)

target_link_libraries(ispa_modules PUBLIC Boost::boost CLI11::CLI11 ICU::uc ISPA::Parser)
set_target_properties(ispa_modules PROPERTIES
        DISABLE_PRECOMPILE_HEADERS ON
)
# =============================================
# Main Executable
# =============================================
add_executable(ispa ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(ispa PRIVATE ispa_modules)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_link_libraries(ispa PRIVATE c++ c++abi m)
endif()
function(add_ispa_lib type lib)
    get_file_range(${type}_${lib}_SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/${type}/${lib}/*.cpp
    )
    get_file_range(${type}_${lib}_MODULES
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/${type}/${lib}/*.cppm
    )

    set(target_name "ispa-${type}-${lib}")

    add_library(${target_name} SHARED)

    target_sources(${target_name}
            PUBLIC
            FILE_SET cxx_modules TYPE CXX_MODULES FILES ${${type}_${lib}_MODULES}
            PRIVATE
            ${${type}_${lib}_SOURCES}
    )

    # Link language target to shared converter modules and ispa_modules
    target_link_libraries(${target_name}
            PRIVATE
            ispa_modules
    )

    set_target_properties(${target_name} PROPERTIES
            WINDOWS_EXPORT_ALL_SYMBOLS ON
            DISABLE_PRECOMPILE_HEADERS ON
    )

    # Algorithms are loaded through their descriptor, never linked into the host.
    if(type STREQUAL "algorithm")
        add_dependencies(ispa ${target_name})
    else()
        target_link_libraries(ispa PRIVATE ${target_name})
    endif()
endfunction()

# =============================================
# Converter Shared Library
# =============================================
function(add_converter language)
    add_ispa_lib(converter ${language})
endfunction()

add_converter(cpp)

# =============================================
# Algorithms Shared Library
# =============================================
function(add_algorithm alg)
    add_ispa_lib(algorithm ${alg})

    if(ARGN)
        foreach(dep IN LISTS ARGN)
            target_link_libraries(ispa-algorithm-${alg} PRIVATE ispa-algorithm-${dep})
        endforeach()
    endif()
endfunction()

add_algorithm(LL)
add_algorithm(LR)
add_algorithm(LALR LR)
add_algorithm(LR_STAR LR)
# =============================================
# Testing
# =============================================
enable_testing()
find_package(GTest REQUIRED)

get_file_range(TEST_SOURCE_FILES EXCLUDE "tests/compile/" "tests/*.cpp")
get_file_range(TEST_MODULE_FILES EXCLUDE "tests/compile/" "tests/*.cppm")

add_executable(tests ${TEST_SOURCE_FILES})
add_dependencies(tests ispa)
target_sources(tests
        PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
        ${TEST_MODULE_FILES}
)

target_include_directories(tests PRIVATE
        "tests/lib"
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(tests PRIVATE
        ROOT_DIR="${CMAKE_CURRENT_SOURCE_DIR}"
        TEST_ROOT_DIR="${CMAKE_CURRENT_SOURCE_DIR}/tests"
        BINARY_DIR="${CMAKE_CURRENT_BINARY_DIR}"
)

target_link_libraries(tests
        PRIVATE
        ispa_modules
        ispa-algorithm-LR
        ispa-algorithm-LALR
        GTest::gtest
        GTest::gtest_main
        yaml-cpp::yaml-cpp
)

include(GoogleTest)
gtest_discover_tests(tests)