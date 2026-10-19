cmake_minimum_required(VERSION 3.16)
project(ispa_benchmark CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ------------------------------------------------------------------------------
# 1. ANTLR4 C++ Runtime Integration
# ------------------------------------------------------------------------------
set(ANTLR4_RUNTIME_DIR "/home/ura/Downloads/antlr4-cpp-runtime-4.13.2-source")

if(NOT EXISTS "${ANTLR4_RUNTIME_DIR}/CMakeLists.txt")
    message(FATAL_ERROR "ANTLR4 source directory not found at: ${ANTLR4_RUNTIME_DIR}")
endif()

set(ANTLR4_INSTALL OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(ANTLR_BUILD_CPP_TESTS OFF CACHE BOOL "" FORCE)

add_subdirectory("${ANTLR4_RUNTIME_DIR}" antlr4_runtime_build EXCLUDE_FROM_ALL)

# ------------------------------------------------------------------------------
# 2. ANTLR4 Code Generation
# ------------------------------------------------------------------------------
find_package(Java REQUIRED COMPONENTS Runtime)

set(ANTLR_JAR "${CMAKE_CURRENT_SOURCE_DIR}/antlr-4.13.2-complete.jar")
set(GRAMMAR_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ISPA.g4")
set(GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")

# Fixed: Removed the space in "ISPABaseVisitor.cpp"
set(GENERATED_SOURCES
        "${GENERATED_DIR}/ISPALexer.cpp"
        "${GENERATED_DIR}/ISPAParser.cpp"
        "${GENERATED_DIR}/ISPAVisitor.cpp"
        "${GENERATED_DIR}/ISPABaseVisitor.cpp"
)

add_custom_command(
        OUTPUT ${GENERATED_SOURCES}
        COMMAND ${CMAKE_COMMAND} -E make_directory "${GENERATED_DIR}"
        COMMAND ${Java_JAVA_EXECUTABLE} -jar "${ANTLR_JAR}"
        -Dlanguage=Cpp
        -no-listener
        -visitor
        -o "${GENERATED_DIR}"
        "${GRAMMAR_FILE}"
        DEPENDS "${GRAMMAR_FILE}"
        COMMENT "Generating C++ lexer/parser from ISPA.g4"
        VERBATIM
)

# ------------------------------------------------------------------------------
# 3. Target Executable
# ------------------------------------------------------------------------------
add_executable(benchmark
        main.cpp
        ${GENERATED_SOURCES}
)

target_include_directories(benchmark PRIVATE
        "${GENERATED_DIR}"
        "${ANTLR4_RUNTIME_DIR}/runtime/src"
)

target_link_libraries(benchmark PRIVATE antlr4_static)