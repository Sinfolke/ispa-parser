cmake_minimum_required(VERSION 3.22)
project(ispa_parser LANGUAGES CXX)

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

set(STDLIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../stdlibs/new")
add_subdirectory("${STDLIB_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/ispastdlib_build")

# Build one parser from <directory>/output/incremental and <directory>/main.cpp.
# Each invocation owns separate object libraries, PCH and a static library.
function(add_ispa_generated_parser parser_name directory executable_name)
    set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${directory}")
    set(OUTPUT_DIR "${ROOT_DIR}/output")
    set(INCREMENTAL_DIR "${OUTPUT_DIR}/incremental")

    file(GLOB_RECURSE ALL_INCREMENTAL_SOURCES CONFIGURE_DEPENDS
        "${INCREMENTAL_DIR}/*.cpp"
    )
    if(NOT ALL_INCREMENTAL_SOURCES)
        message(FATAL_ERROR "No incremental .cpp files found in ${INCREMENTAL_DIR}")
    endif()

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
        list(APPEND OBJECT_TARGETS ${target})
        target_compile_features(${target} PRIVATE cxx_std_20)
        target_include_directories(${target} PRIVATE
            "${OUTPUT_DIR}"
            "${ROOT_DIR}"
            "${CMAKE_CURRENT_SOURCE_DIR}"
        )
        target_link_libraries(${target} PRIVATE ispastdlib::ispastdlib)
        if(MSVC)
            target_compile_options(${target} PRIVATE /MP)
        endif()

        if(kind STREQUAL "parser_impl")
            set(PARSER_PCH "${INCREMENTAL_DIR}/Parser/Parser/def.h")
            if(EXISTS "${PARSER_PCH}")
                target_precompile_headers(${target} PRIVATE
                    <ispastdlib.hpp>
                    "${PARSER_PCH}"
                )
            else()
                target_precompile_headers(${target} PRIVATE <ispastdlib.hpp>)
            endif()
        else()
            target_precompile_headers(${target} PRIVATE <ispastdlib.hpp>)
        endif()
    endforeach()

    add_library(${parser_name}_lib STATIC)
    foreach(target IN LISTS OBJECT_TARGETS)
        target_sources(${parser_name}_lib PRIVATE $<TARGET_OBJECTS:${target}>)
    endforeach()
    target_compile_features(${parser_name}_lib PUBLIC cxx_std_20)
    target_include_directories(${parser_name}_lib PUBLIC
        "${OUTPUT_DIR}"
        "${ROOT_DIR}"
        "${CMAKE_CURRENT_SOURCE_DIR}"
    )
    target_link_libraries(${parser_name}_lib PUBLIC ispastdlib::ispastdlib)

    add_executable(${executable_name} "${ROOT_DIR}/main.cpp")
    target_link_libraries(${executable_name} PRIVATE ${parser_name}_lib)
endfunction()

add_ispa_generated_parser(ispa   ispa   isparun)
add_ispa_generated_parser(python python pyrun)

message(STATUS "ISPA compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "ISPA stdlib directory: ${STDLIB_DIR}")
