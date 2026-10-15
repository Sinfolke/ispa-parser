cmake_minimum_required(VERSION 3.22)
project(ispa_parser LANGUAGES CXX)

# ------------------------------------------------------------
# C++ configuration
# ------------------------------------------------------------

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/O1 /W4)
else()
    add_compile_options(-Og -Wall -Wextra)

    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        add_compile_options(
                -Wno-switch
                -Wno-self-assign-overloaded
                -Wno-unused-but-set-variable
                -Wno-unused-lambda-capture
                -Wno-deprecated-copy
        )
    endif()
endif()

# ------------------------------------------------------------
# Directories
# ------------------------------------------------------------

set(OUTPUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/output")
set(INCREMENTAL_DIR "${OUTPUT_DIR}/incremental")
set(STDLIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../stdlibs/new")

# ------------------------------------------------------------
# Include ISPA standard library target
# ------------------------------------------------------------

add_subdirectory("${STDLIB_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/ispastdlib_build")

# ------------------------------------------------------------
# Discover incremental implementation files
# ------------------------------------------------------------

file(GLOB_RECURSE ALL_INCREMENTAL_SOURCES
        CONFIGURE_DEPENDS
        "${INCREMENTAL_DIR}/*.cpp"
)

set(AST_SOURCES)
set(PARSER_SOURCES)
set(OTHER_SOURCES)

foreach(src IN LISTS ALL_INCREMENTAL_SOURCES)
    if(src MATCHES "/Parser/FlatTypes/")
        list(APPEND AST_SOURCES "${src}")

    elseif(src MATCHES "/Parser/Parser/")
        list(APPEND PARSER_SOURCES "${src}")

    else()
        list(APPEND OTHER_SOURCES "${src}")
    endif()
endforeach()

list(LENGTH AST_SOURCES AST_COUNT)
list(LENGTH PARSER_SOURCES PARSER_COUNT)
list(LENGTH OTHER_SOURCES OTHER_COUNT)

message(STATUS "ISPA AST sources: ${AST_COUNT}")
message(STATUS "ISPA parser sources: ${PARSER_COUNT}")
message(STATUS "ISPA support sources: ${OTHER_COUNT}")

# ------------------------------------------------------------
# Object libraries
# ------------------------------------------------------------

if(AST_SOURCES)
    add_library(ispa_ast OBJECT ${AST_SOURCES})
endif()

if(PARSER_SOURCES)
    add_library(ispa_parser_impl OBJECT ${PARSER_SOURCES})
endif()

if(OTHER_SOURCES)
    add_library(ispa_support OBJECT ${OTHER_SOURCES})
endif()

set(ISPA_OBJECT_TARGETS)

foreach(target IN ITEMS ispa_ast ispa_parser_impl ispa_support)
    if(NOT TARGET ${target})
        continue()
    endif()

    list(APPEND ISPA_OBJECT_TARGETS ${target})

    target_compile_features(${target} PRIVATE cxx_std_20)

    target_include_directories(${target} PRIVATE
            "${OUTPUT_DIR}"
            "${CMAKE_CURRENT_SOURCE_DIR}"
    )

    # Link against the target provided by stdlibs/new
    target_link_libraries(${target} PRIVATE ispastdlib::ispastdlib)

    if(MSVC)
        target_compile_options(${target} PRIVATE /MP)
    endif()
endforeach()

# ------------------------------------------------------------
# Precompiled headers for Object Targets
# ------------------------------------------------------------

if(TARGET ispa_ast)
    target_precompile_headers(ispa_ast PRIVATE
            <ispastdlib.hpp>
    )
endif()

if(TARGET ispa_parser_impl)
    target_precompile_headers(ispa_parser_impl PRIVATE
            <ispastdlib.hpp>
            "${OUTPUT_DIR}/incremental/Parser/Parser/def.h"
    )
endif()

if(TARGET ispa_support)
    target_precompile_headers(ispa_support PRIVATE
            <ispastdlib.hpp>
    )
endif()

# ------------------------------------------------------------
# Combined static library
# ------------------------------------------------------------

if(NOT ISPA_OBJECT_TARGETS)
    message(FATAL_ERROR
            "No generated incremental .cpp files found in ${INCREMENTAL_DIR}"
    )
endif()

add_library(ispa_parser_lib STATIC)

foreach(target IN LISTS ISPA_OBJECT_TARGETS)
    target_sources(ispa_parser_lib PRIVATE
            $<TARGET_OBJECTS:${target}>
    )
endforeach()

target_include_directories(ispa_parser_lib PUBLIC
        "${OUTPUT_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(ispa_parser_lib PUBLIC ispastdlib::ispastdlib)
target_compile_features(ispa_parser_lib PUBLIC cxx_std_20)

# ------------------------------------------------------------
# Executable
# ------------------------------------------------------------

add_executable(run main.cpp)

target_link_libraries(run PRIVATE
        ispa_parser_lib
        ispastdlib::ispastdlib
)

# ------------------------------------------------------------
# Build information
# ------------------------------------------------------------

message(STATUS "ISPA compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "ISPA incremental sources: ${INCREMENTAL_DIR}")
message(STATUS "ISPA stdlib directory: ${STDLIB_DIR}")