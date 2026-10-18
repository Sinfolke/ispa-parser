set(VCPKG_TARGET_ARCHITECTURE x64)
set(VCPKG_CRT_LINKAGE dynamic)
set(VCPKG_LIBRARY_LINKAGE dynamic)
set(VCPKG_CMAKE_SYSTEM_NAME Linux)

# CMake flags
set(VCPKG_CXX_FLAGS "-stdlib=libc++")
set(VCPKG_LINKER_FLAGS "-stdlib=libc++")

# Force Autotools / Environment variables for non-CMake ports (ICU, OpenSSL, etc.)
set(ENV{CXXFLAGS} "$ENV{CXXFLAGS} -stdlib=libc++")
set(ENV{LDFLAGS} "$ENV{LDFLAGS} -stdlib=libc++")

# Ensure these variables pass through vcpkg's clean environment wrapper
list(APPEND VCPKG_ENV_PASSTHROUGH CXXFLAGS LDFLAGS)