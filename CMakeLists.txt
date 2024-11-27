cmake_minimum_required(VERSION 3.28.3)
project(ISC)

include(cmake/conf)
add_subdirectory(mod/parser)    # include parser

add_executable(isc ${SOURCES})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
    if (NOT O_LEVEL)
        set(O_LEVEL g)
    endif()
else()
    # RELEASE
    # -fno-semantic-interposition
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        add_compile_options(-ffast-math -fno-protect-parens)
    else()
        message(STATUS "Found compiler not support direct optimization control")
    endif()
    if (NOT O_LEVEL)
        set(O_LEVEL, 2)
    endif()
endif()

if (NOT DISABLE_TRACER)
    # Enable call tracer
    add_compile_definitions(ENABLE_TRACER)
    add_compile_options(-g -finstrument-functions)
endif()

add_compile_options("-O${O_LEVEL}")
add_compile_definitions("O_LEVEL=${O_LEVEL}")
add_compile_definitions("__USE_TIME64")
add_compile_definitions(__SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(isc PRIVATE include external parser/mod/include)

include_directories(include stdlibs)
set_target_properties(isc PROPERTIES OUTPUT_NAME isc)
#set_target_properties(isc PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable GNU extensions
set_target_properties(isc PROPERTIES CXX_STANDARD_REQUIRED 17)
set_target_properties(isc PROPERTIES CXX_STANDARD 17)
set_target_properties(isc PROPERTIES CXX_EXTENSIONS ON)