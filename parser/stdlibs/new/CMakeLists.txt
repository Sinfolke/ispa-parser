cmake_minimum_required(VERSION 3.22)
project(ispastdlib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------------------------------
# Headers and Sources
# ------------------------------------------------------------
file(GLOB_RECURSE ISPA_STDLIB_HEADERS
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/ispastdlib.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/ispastdlib/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/ispastdlib/*.h"
)

file(GLOB_RECURSE ISPA_STDLIB_SOURCES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# ------------------------------------------------------------
# Library Target
# ------------------------------------------------------------
if(ISPA_STDLIB_SOURCES)
    add_library(ispastdlib STATIC ${ISPA_STDLIB_SOURCES})
else()
    add_library(ispastdlib INTERFACE)
endif()

# Create alias
add_library(ispastdlib::ispastdlib ALIAS ispastdlib)

# ------------------------------------------------------------
# Target Configuration
# ------------------------------------------------------------
if(TARGET ispastdlib)
    target_include_directories(ispastdlib PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
            $<INSTALL_INTERFACE:include>
    )

    target_compile_features(ispastdlib PUBLIC cxx_std_20)

    target_precompile_headers(ispastdlib PUBLIC
            ${ISPA_STDLIB_HEADERS}
    )

    if(WIN32)
        target_link_libraries(ispastdlib PRIVATE dbghelp)
    endif()

    if(MSVC)
        target_compile_options(ispastdlib PRIVATE /MP)
    endif()
endif()