cmake_minimum_required(VERSION 3.5)
project(ISC)
include(fn.cmake)
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.admin")
    set(ADMIN 1)
else()
    set(ADMIN 0)
endif()
if (ADMIN)
    include_directories("C:/cclang/cstlibs")
    add_compile_definitions("NO_HEAD")
else()
    # this is for other users who wants to build my project
    # links with libraries on the lib folder
    # if some does not exist it downloads

    mkdir(${CMAKE_CURRENT_SOURCE_DIR}/lib)               # make sure lib folder exists
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib) # add lib folder to include paths
    # fetch up cpuf
    if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/lib/cpuf")
        download_repository(https://github.com/Sinfolke/cpuf cpuf main ${CMAKE_CURRENT_SOURCE_DIR}/lib)
    endif()
    # fetch up tinyformat
    if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/lib/tinyformat.h)
        download_file("https://raw.githubusercontent.com/c42f/tinyformat/master/tinyformat.h" tinyformat "${CMAKE_CURRENT_SOURCE_DIR}/lib/tinyformat.h")
    endif()
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SOURCES src/main.cpp)

file(REMOVE_RECURSE ${CMAKE_BINARY_DIR}/bin)
if (CMAKE_BUILD_TYPE STREQUAL "DEBUG")
    add_compile_definitions(DEBUG)
endif()

if (build_ofc)
    add_compile_definitions("BUILD_OFC")
endif()

if (build_stable)
    add_compile_definitions("BUILD_STABLE")
endif()
add_compile_definitions("BUILD_V" ${build_v})
add_executable(main ${SOURCES})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set_target_properties(main PROPERTIES OUTPUT_NAME isc)
set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set_target_properties(main PROPERTIES CXX_STANDARD_REQUIRED 20)
set_target_properties(main PROPERTIES CXX_STANDARD 20)