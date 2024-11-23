cmake_minimum_required(VERSION 3.28.3)
project(ISC)

include(cmake/conf)

add_executable(ISC ${SOURCES})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
else()
    # RELEASE
    # -fno-semantic-interposition
    add_compile_options(-fomit-frame-pointer -ffast-math -fno-protect-parens)
endif()

if (NOT DEFINED ${DISABLE_TRACER})
    # enable call tracer 
    add_compile_definitions(ENABLE_TRACER)
    add_compile_options("-g -finstrument-functions")
endif()

add_compile_definitions(__SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(isc PRIVATE include external)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
include_directories(include stdlibs)
set_target_properties(isc PROPERTIES OUTPUT_NAME isc)
#set_target_properties(isc PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set_target_properties(isc PROPERTIES CXX_STANDARD_REQUIRED 17)
set_target_properties(isc PROPERTIES CXX_STANDARD 17)