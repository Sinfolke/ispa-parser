
cmake_minimum_required(VERSION 3.22)

project(ispa_parser LANGUAGES CXX)

# ------------------------------------------------------------
# Configuration
# ------------------------------------------------------------

# Do not modify CMAKE_CXX_STANDARD globally when embedded.
# All generated targets request C++20 individually.

option(ISPA_BUILD_EXECUTABLES
        "Build the ISPA and Python parser runners"
        ${PROJECT_IS_TOP_LEVEL}
)

option(ISPA_BUILD_SELF_PARSER
        "Build the generated ISPA grammar parser"
        ON
)

option(ISPA_BUILD_PYTHON_PARSER
        "Build the generated Python parser"
        ${PROJECT_IS_TOP_LEVEL}
)

option(ISPA_ENABLE_PCH
        "Enable precompiled headers for generated parsers"
        ON
)

# ------------------------------------------------------------
# Compiler configuration
# ------------------------------------------------------------

function(ispa_apply_compile_options target)
    target_compile_features(${target} PRIVATE cxx_std_20)

    if(MSVC)
        target_compile_options(${target} PRIVATE
                /W4
                /MP
        )
    else()
        target_compile_options(${target} PRIVATE
                -Wall
                -Wextra
        )

        if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
            target_compile_options(${target} PRIVATE
                    -Wno-switch
                    -Wno-self-assign-overloaded
                    -Wno-unused-but-set-variable
                    -Wno-unused-lambda-capture
                    -Wno-deprecated-copy
            )
        endif()
    endif()
endfunction()

# ------------------------------------------------------------
# ISPA standard library
# ------------------------------------------------------------

set(STDLIB_DIR
        "${CMAKE_CURRENT_SOURCE_DIR}/../stdlibs/new"
)

if(NOT TARGET ispastdlib::ispastdlib)
    add_subdirectory(
            "${STDLIB_DIR}"
            "${CMAKE_CURRENT_BINARY_DIR}/ispastdlib_build"
    )
endif()

# ------------------------------------------------------------
# Generated parser
# ------------------------------------------------------------

# Directory layout:
#
# <directory>/
#   main.cpp
#   output/
#     Parser.h
#     incremental/
#       Parser/
#         FlatTypes/
#         Parser/
#         ...
#
# Each parser uses separate object libraries, PCH and a
# final static library.
#
function(add_ispa_generated_parser
        parser_name
        directory
        executable_name
)

    set(ROOT_DIR
            "${CMAKE_CURRENT_SOURCE_DIR}/${directory}"
    )

    set(OUTPUT_DIR
            "${ROOT_DIR}/output"
    )

    set(INCREMENTAL_DIR
            "${OUTPUT_DIR}/incremental"
    )

    if(NOT EXISTS "${OUTPUT_DIR}/Parser.h")
        message(FATAL_ERROR
                "${parser_name}: Missing generated Parser.h: "
                "${OUTPUT_DIR}/Parser.h"
        )
    endif()

    file(GLOB_RECURSE ALL_INCREMENTAL_SOURCES
            CONFIGURE_DEPENDS
            "${INCREMENTAL_DIR}/*.cpp"
    )

    if(NOT ALL_INCREMENTAL_SOURCES)
        message(FATAL_ERROR
                "${parser_name}: No incremental .cpp files found in "
                "${INCREMENTAL_DIR}"
        )
    endif()

    # --------------------------------------------------------
    # Separate compilation groups
    # --------------------------------------------------------

    set(AST_SOURCES)
    set(PARSER_SOURCES)
    set(OTHER_SOURCES)

    foreach(src IN LISTS ALL_INCREMENTAL_SOURCES)

        if(src MATCHES "[/\\\\]Parser[/\\\\]FlatTypes[/\\\\]")
            list(APPEND AST_SOURCES "${src}")

        elseif(src MATCHES "[/\\\\]Parser[/\\\\]Parser[/\\\\]")
            list(APPEND PARSER_SOURCES "${src}")

        else()
            list(APPEND OTHER_SOURCES "${src}")
        endif()

    endforeach()

    list(LENGTH AST_SOURCES AST_COUNT)
    list(LENGTH PARSER_SOURCES PARSER_COUNT)
    list(LENGTH OTHER_SOURCES OTHER_COUNT)

    message(STATUS
            "${parser_name}: "
            "AST=${AST_COUNT}, "
            "parser=${PARSER_COUNT}, "
            "support=${OTHER_COUNT}"
    )

    # --------------------------------------------------------
    # Object libraries
    # --------------------------------------------------------

    set(OBJECT_TARGETS)

    foreach(kind IN ITEMS ast parser_impl support)

        if(kind STREQUAL "ast")
            set(SOURCES ${AST_SOURCES})

        elseif(kind STREQUAL "parser_impl")
            set(SOURCES ${PARSER_SOURCES})

        else()
            set(SOURCES ${OTHER_SOURCES})
        endif()

        if(NOT SOURCES)
            continue()
        endif()

        set(target "${parser_name}_${kind}")

        add_library(${target} OBJECT ${SOURCES})

        list(APPEND OBJECT_TARGETS "${target}")

        ispa_apply_compile_options(${target})

        target_include_directories(${target} PRIVATE
                "${OUTPUT_DIR}"
                "${ROOT_DIR}"
                "${CMAKE_CURRENT_SOURCE_DIR}"
        )

        target_link_libraries(${target} PRIVATE
                ispastdlib::ispastdlib
        )

        # ----------------------------------------------------
        # Precompiled headers
        # ----------------------------------------------------

        if(ISPA_ENABLE_PCH)

            if(kind STREQUAL "parser_impl")

                set(PARSER_PCH
                        "${INCREMENTAL_DIR}/Parser/Parser/def.h"
                )

                if(EXISTS "${PARSER_PCH}")
                    target_precompile_headers(${target} PRIVATE
                            <ispastdlib.hpp>
                            "${PARSER_PCH}"
                    )
                else()
                    target_precompile_headers(${target} PRIVATE
                            <ispastdlib.hpp>
                    )
                endif()

            else()

                target_precompile_headers(${target} PRIVATE
                        <ispastdlib.hpp>
                )

            endif()

        endif()

    endforeach()

    # --------------------------------------------------------
    # Static library
    # --------------------------------------------------------

    add_library(${parser_name}_lib STATIC)

    foreach(target IN LISTS OBJECT_TARGETS)
        target_sources(${parser_name}_lib PRIVATE
                $<TARGET_OBJECTS:${target}>
        )
    endforeach()

    target_compile_features(${parser_name}_lib
            PUBLIC cxx_std_20
    )

    target_include_directories(${parser_name}_lib PUBLIC
            "${OUTPUT_DIR}"
            "${ROOT_DIR}"
            "${CMAKE_CURRENT_SOURCE_DIR}"
    )

    target_link_libraries(${parser_name}_lib PUBLIC
            ispastdlib::ispastdlib
    )

    # --------------------------------------------------------
    # Optional executable
    # --------------------------------------------------------

    if(ISPA_BUILD_EXECUTABLES)

        if(NOT EXISTS "${ROOT_DIR}/main.cpp")
            message(FATAL_ERROR
                    "${parser_name}: Missing main.cpp: "
                    "${ROOT_DIR}/main.cpp"
            )
        endif()

        add_executable(${executable_name}
                "${ROOT_DIR}/main.cpp"
        )

        ispa_apply_compile_options(${executable_name})

        target_link_libraries(${executable_name} PRIVATE
                ${parser_name}_lib
        )

    endif()

endfunction()

# ------------------------------------------------------------
# ISPA grammar parser
# ------------------------------------------------------------

if(ISPA_BUILD_SELF_PARSER)

    add_ispa_generated_parser(
            ispa
            ispa
            isparun
    )

    add_library(ISPA::Parser ALIAS ispa_lib)

endif()

# ------------------------------------------------------------
# Python parser
# ------------------------------------------------------------

if(ISPA_BUILD_PYTHON_PARSER)

    add_ispa_generated_parser(
            python
            python
            pyrun
    )

    add_library(ISPA::PythonParser ALIAS python_lib)

endif()

# ------------------------------------------------------------
# Configuration summary
# ------------------------------------------------------------

message(STATUS "--------------------------------------")
message(STATUS "ISPA generated parsers")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "C++ standard: C++20")
message(STATUS "Build executables: ${ISPA_BUILD_EXECUTABLES}")
message(STATUS "Build ISPA parser: ${ISPA_BUILD_SELF_PARSER}")
message(STATUS "Build Python parser: ${ISPA_BUILD_PYTHON_PARSER}")
message(STATUS "Precompiled headers: ${ISPA_ENABLE_PCH}")
message(STATUS "Stdlib directory: ${STDLIB_DIR}")
message(STATUS "--------------------------------------")