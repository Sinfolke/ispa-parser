#pragma once
// get relative path from full path ommitting source code location differences
static constexpr const char* getRelativePath(const char* full) {
    const char* root = __SOURCE_ROOT__;

    // Skip the common prefix between root and full
    while (*root && *full && (*root == *full)) {
        root++;
        full++;
    }

    // If we've reached a separator after the root path in full path, skip it
    if ((*full == '/' || *full == '\\') && (*root == '\0')) {
        full++;
    }

    return full;
}