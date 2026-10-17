cmake_minimum_required(VERSION 3.22)
project(ispa_parser LANGUAGES CXX)

# Do not change the global C++ standard when embedded as a subproject.
option(ISPA_BUILD_EXECUTABLES "Build the ISPA and Python parser runners" ${PROJECT_IS_TOP_LEVEL})
option(ISPA_BUILD_SELF_PARSER "Build the ISPA grammar parser" ON)
option(ISPA_BUILD_PYTHON_PARSER "Build the Python grammar parser" ${PROJECT_IS_TOP_LEVEL})
option(ISPA_ENABLE_PCH "Enable precompiled headers for parsers" ON)

set(ISPA_PARSER_MODE "AUTO" CACHE STRING "Parser sources: AUTO, INCREMENTAL, or BOOTSTRAPPED")
set_property(CACHE ISPA_PARSER_MODE PROPERTY STRINGS AUTO INCREMENTAL BOOTSTRAPPED)
if(NOT ISPA_PARSER_MODE MATCHES "^(AUTO|INCREMENTAL|BOOTSTRAPPED)$")
    message(FATAL_ERROR "Invalid ISPA_PARSER_MODE='${ISPA_PARSER_MODE}' (expected AUTO, INCREMENTAL or BOOTSTRAPPED)")
endif()

function(ispa_apply_compile_options target)
    target_compile_features(${target} PRIVATE cxx_std_20)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /MP)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra)
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

set(STDLIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../stdlibs/new")
if(NOT TARGET ispastdlib::ispastdlib)
    add_subdirectory("${STDLIB_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/ispastdlib_build")
endif()

function(add_ispa_generated_parser parser_name directory executable_name)
    set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${directory}")
    set(OUTPUT_DIR "${ROOT_DIR}/output")
    set(INCREMENTAL_DIR "${OUTPUT_DIR}/incremental")
    set(BOOTSTRAPPED_DIR "${ROOT_DIR}/bootstrapped")

    file(GLOB_RECURSE ALL_INCREMENTAL_SOURCES CONFIGURE_DEPENDS
        "${INCREMENTAL_DIR}/*.cpp"
    )

    set(HAVE_INCREMENTAL FALSE)
    if(EXISTS "${OUTPUT_DIR}/Parser.h" AND ALL_INCREMENTAL_SOURCES)
        set(HAVE_INCREMENTAL TRUE)
    endif()

    set(HAVE_BOOTSTRAPPED FALSE)
    if(EXISTS "${BOOTSTRAPPED_DIR}/Parser.h" AND EXISTS "${BOOTSTRAPPED_DIR}/Parser.cpp")
        set(HAVE_BOOTSTRAPPED TRUE)
    endif()

    if(ISPA_PARSER_MODE STREQUAL "INCREMENTAL")
        if(NOT HAVE_INCREMENTAL)
            message(FATAL_ERROR "${parser_name}: incremental parser requested, but output/Parser.h or incremental sources are missing")
        endif()
        set(PARSER_SOURCE_MODE "INCREMENTAL")
    elseif(ISPA_PARSER_MODE STREQUAL "BOOTSTRAPPED")
        if(NOT HAVE_BOOTSTRAPPED)
            message(FATAL_ERROR "${parser_name}: bootstrapped parser requested, but bootstrapped/Parser.h or Parser.cpp is missing")
        endif()
        set(PARSER_SOURCE_MODE "BOOTSTRAPPED")
    elseif(HAVE_INCREMENTAL)
        set(PARSER_SOURCE_MODE "INCREMENTAL")
    elseif(HAVE_BOOTSTRAPPED)
        set(PARSER_SOURCE_MODE "BOOTSTRAPPED")
    else()
        message(FATAL_ERROR
            "${parser_name}: no complete parser sources found. Expected either "
            "${OUTPUT_DIR}/Parser.h + incremental/*.cpp, or "
            "${BOOTSTRAPPED_DIR}/Parser.h + Parser.cpp"
        )
    endif()

    message(STATUS "${parser_name}: using ${PARSER_SOURCE_MODE} parser")

    if(PARSER_SOURCE_MODE STREQUAL "INCREMENTAL")
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
        message(STATUS "${parser_name}: AST=${AST_COUNT}, parser=${PARSER_COUNT}, support=${OTHER_COUNT}")

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
            target_link_libraries(${target} PRIVATE ispastdlib::ispastdlib)

            if(ISPA_ENABLE_PCH)
                if(kind STREQUAL "parser_impl" AND EXISTS "${INCREMENTAL_DIR}/Parser/Parser/def.h")
                    target_precompile_headers(${target} PRIVATE
                        <ispastdlib.hpp>
                        "${INCREMENTAL_DIR}/Parser/Parser/def.h"
                    )
                else()
                    target_precompile_headers(${target} PRIVATE <ispastdlib.hpp>)
                endif()
            endif()
        endforeach()

        # The object libraries own compilation of individual generated units.
        # Rebuild the static archive from their object files.
        add_library(${parser_name}_lib STATIC)
        foreach(target IN LISTS OBJECT_TARGETS)
            target_sources(${parser_name}_lib PRIVATE "$<TARGET_OBJECTS:${target}>")
        endforeach()

        target_include_directories(${parser_name}_lib PUBLIC
            "${OUTPUT_DIR}"
            "${ROOT_DIR}"
            "${CMAKE_CURRENT_SOURCE_DIR}"
        )

    else()
        # Public headers in existing clients may use either <Parser.h> or
        # <output/Parser.h>. Stage a compatibility layout in the build tree.
        # This never writes into the source tree or into generated output/.
        set(BOOTSTRAP_INCLUDE_ROOT "${CMAKE_CURRENT_BINARY_DIR}/${parser_name}_bootstrap_include")
        file(MAKE_DIRECTORY "${BOOTSTRAP_INCLUDE_ROOT}/output")
        configure_file("${BOOTSTRAPPED_DIR}/Parser.h"
            "${BOOTSTRAP_INCLUDE_ROOT}/output/Parser.h" COPYONLY)

        add_library(${parser_name}_lib STATIC "${BOOTSTRAPPED_DIR}/Parser.cpp")
        ispa_apply_compile_options(${parser_name}_lib)
        target_include_directories(${parser_name}_lib PUBLIC
            "${BOOTSTRAP_INCLUDE_ROOT}"
            "${BOOTSTRAPPED_DIR}"
            "${ROOT_DIR}"
            "${CMAKE_CURRENT_SOURCE_DIR}"
        )
        if(ISPA_ENABLE_PCH)
            target_precompile_headers(${parser_name}_lib PRIVATE <ispastdlib.hpp>)
        endif()
    endif()

    target_compile_features(${parser_name}_lib PUBLIC cxx_std_20)
    target_link_libraries(${parser_name}_lib PUBLIC ispastdlib::ispastdlib)

    if(ISPA_BUILD_EXECUTABLES)
        if(NOT EXISTS "${ROOT_DIR}/main.cpp")
            message(FATAL_ERROR "${parser_name}: Missing main.cpp: ${ROOT_DIR}/main.cpp")
        endif()
        add_executable(${executable_name} "${ROOT_DIR}/main.cpp")
        ispa_apply_compile_options(${executable_name})
        target_link_libraries(${executable_name} PRIVATE ${parser_name}_lib)
    endif()
endfunction()

if(ISPA_BUILD_SELF_PARSER)
    add_ispa_generated_parser(ispa ispa isparun)
    add_library(ISPA::Parser ALIAS ispa_lib)
endif()

if(ISPA_BUILD_PYTHON_PARSER)
    add_ispa_generated_parser(python python pyrun)
    add_library(ISPA::PythonParser ALIAS python_lib)
endif()

message(STATUS "--------------------------------------")
message(STATUS "ISPA generated parsers")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "C++ standard: C++20")
message(STATUS "Build executables: ${ISPA_BUILD_EXECUTABLES}")
message(STATUS "Build ISPA parser: ${ISPA_BUILD_SELF_PARSER}")
message(STATUS "Build Python parser: ${ISPA_BUILD_PYTHON_PARSER}")
message(STATUS "Parser selection: ${ISPA_PARSER_MODE}")
message(STATUS "Precompiled headers: ${ISPA_ENABLE_PCH}")
message(STATUS "Stdlib directory: ${STDLIB_DIR}")
message(STATUS "--------------------------------------")
