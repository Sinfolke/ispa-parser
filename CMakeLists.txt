cmake_minimum_required(VERSION 3.28.3)
project(ISC)

include(cmake/fn)
include(cmake/conf)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (CMAKE_BUILD_TYPE STREQUAL "DEBUG")
    add_compile_definitions(DEBUG)
else()
    # RELEASE
    # -fno-semantic-interposition
    add_compile_options("-fomit-frame-pointer -ffast-math -fno-protect-parens -fstack-arrays")
endif()

add_compile_definitions(BUILD_V="${build_v}")
add_compile_definitions(__SOURCE_ROOT__="${CMAKE_CURRENT_SOURCE_DIR}")
add_executable(main ${SOURCES})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
set_target_properties(main PROPERTIES OUTPUT_NAME isc)
#set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set_target_properties(main PROPERTIES CXX_STANDARD_REQUIRED 20)
set_target_properties(main PROPERTIES CXX_STANDARD 20)