
cmake_minimum_required(VERSION 3.22)
project(Parser LANGUAGES CXX)

# ============================================================
# Configuration
# ============================================================

option(ISPA_BUILD_OLD_PARSER
        "Build the legacy ISPA parser"
        OFF
)

option(ISPA_BUILD_NEW_PARSER
        "Build the new ISPA generated parser"
        ON
)

option(ISPA_BUILD_OLD_TESTS
        "Build legacy ISPA parser tests"
        ${PROJECT_IS_TOP_LEVEL}
)

# ============================================================
# Legacy ISPA parser (C++17)
# ============================================================

if(ISPA_BUILD_OLD_PARSER)

    file(GLOB_RECURSE parser_sources
            CONFIGURE_DEPENDS
            "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    )

    add_library(parser STATIC ${parser_sources})

    target_compile_features(parser PUBLIC cxx_std_17)

    target_include_directories(parser PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}/include"
            "${CMAKE_CURRENT_SOURCE_DIR}/stdlibs/old"
    )

    set_target_properties(parser PROPERTIES
            POSITION_INDEPENDENT_CODE ON
            CXX_EXTENSIONS OFF
    )

    add_library(parser_stdlib STATIC
            "${CMAKE_CURRENT_SOURCE_DIR}/stdlibs/old/ispastdlib.hpp"
    )

    target_compile_features(parser_stdlib PUBLIC cxx_std_17)

    target_include_directories(parser_stdlib PUBLIC
            "${CMAKE_CURRENT_SOURCE_DIR}/stdlibs/old"
    )

    set_target_properties(parser_stdlib PROPERTIES
            CXX_EXTENSIONS OFF
    )

    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_definitions(parser PRIVATE __LIBC)
        target_compile_definitions(parser_stdlib PRIVATE __LIBC)
    endif()
endif()

# ============================================================
# New ISPA parser (C++20)
# ============================================================

if(ISPA_BUILD_NEW_PARSER)
    add_subdirectory(new)
endif()

# ============================================================
# Public aliases
# ============================================================

if(TARGET parser)
    add_library(ISPA::LegacyParser ALIAS parser)
endif()

if(TARGET parser_stdlib)
    add_library(ISPA::LegacyStdlib ALIAS parser_stdlib)
endif()

# The new parser defines:
#
#   ISPA::Parser
#   ISPA::PythonParser
#
# through new/CMakeLists.txt.

# ============================================================
# Diagnostics
# ============================================================

message(STATUS "ISPA configuration:")
message(STATUS "  Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "  Legacy parser: ${ISPA_BUILD_OLD_PARSER}")
message(STATUS "  New parser: ${ISPA_BUILD_NEW_PARSER}")
message(STATUS "  Legacy tests: ${ISPA_BUILD_OLD_TESTS}")
