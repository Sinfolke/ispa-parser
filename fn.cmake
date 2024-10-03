cmake_minimum_required(VERSION 3.0)

set(NO_EXIT_MES_INCL 1)

# Create a folder
function(mkdir path)
    if (NOT EXISTS ${path})
        file(MAKE_DIRECTORY ${path})
    endif()
endfunction()

# Unzips file
function(unzip path output)
    if (UNIX)
        execute_process(
            COMMAND ${CMAKE_COMMAND} -E tar xf ${path}
            WORKING_DIRECTORY ${output}
            RESULT_VARIABLE UNZIP_RESULT
        )
    else() # Windows
        execute_process(
            COMMAND ${CMAKE_COMMAND} -E tar xzf ${path}
            WORKING_DIRECTORY ${output}
            RESULT_VARIABLE UNZIP_RESULT
        )
    endif()

    if(NOT UNZIP_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to unzip the file: ${path}")
    endif()
endfunction()

# Downloads file by a specific link
function(download_file link name output)
    if (NO_EXIT_MES_INCL)
        set(NO_EXIT_MES_INCL 0 PARENT_SCOPE)
        message("Some libraries are going to be downloaded.")
    endif()
    message("Downloading ${name} library by the link: ${link}")
    if (UNIX)
        execute_process(
            COMMAND curl -LJO ${link}
            WORKING_DIRECTORY ${output}
            RESULT_VARIABLE DOWNLOAD_RESULT
        )
    else()
        execute_process(
            COMMAND powershell -Command "Invoke-WebRequest -Uri '${link}' -OutFile '${output}'"
            RESULT_VARIABLE DOWNLOAD_RESULT
        )
    endif()

    if(NOT DOWNLOAD_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to download file from ${link}")
    endif()
endfunction()

# Download a .zip file by link and unzip
# Used for a git full repository download
function(download_repository link name branch output)
    if (NO_EXIT_MES_INCL)
        set(NO_EXIT_MES_INCL 0 PARENT_SCOPE)
        message("Some libraries are going to be downloaded. If you want to exit you may use CTRL+C or close the terminal.")
    endif()
    message("Downloading ${name} library by the link: ${link}")
    set(archive "${CMAKE_CURRENT_SOURCE_DIR}/download.zip")

    if (UNIX)
        execute_process(
            COMMAND curl -LJO ${link}/archive/${branch}.zip
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE DOWNLOAD_RESULT
        )
    else()
        execute_process(
            COMMAND powershell -Command "Invoke-WebRequest -Uri '${link}/archive/${branch}.zip' -OutFile '${archive}'"
            RESULT_VARIABLE DOWNLOAD_RESULT
        )
    endif()

    if(NOT DOWNLOAD_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to download repository from ${link}/archive/${branch}.zip")
    endif()

    # Unzip the downloaded file
    unzip(${archive} ${output})

    # Rename the extracted folder
    file(RENAME ${output}/${name}-${branch} ${output}/${name})
    file(REMOVE ${archive})
endfunction()

function(parseString str start length result_handler)
    set(escaptions 0)
    foreach(i RANGE 0 ${length})
        # Extract the character at the current position
        string(SUBSTRING "${str}" ${i} 1 c)
        if (${c} STREQUAL "\\")
            math(EXPR escaptions "${escaptions} + 1")
        elseif (${c} STREQUAL "\"")
            # String end
            math(EXPR odd "${escaptions} % 2")
            if (NOT odd)
                math(EXPR end_pos "i - 1")
                set(${result_handler} ${end_pos} PARENT_SCOPE)  # Use PARENT_SCOPE to modify outside variable
                return()
            endif()
        endif()
    endforeach()
    set(${result_handler} -1 PARENT_SCOPE)  # Ensure to set the result correctly in the parent scope
endfunction()

function(parseUntilSpace str start length result_handler)
    # Iterate through each character
    foreach(i RANGE 0 ${length})
        # Extract the character at the current position
        string(SUBSTRING "${str}" ${i} 1 c)
        if (${c} STREQUAL " ")
            math(EXPR end_pos "i - 1")
            set(${result_handler} ${end_pos} PARENT_SCOPE)
            return()
        endif()
    endforeach()
    set(${result_handler} -1 PARENT_SCOPE)
endfunction()

# Function to check if a specific include path is present
function(get_include_paths result_handler)
    # Get the CFLAGS and CXXFLAGS environment variables
    get_environment_variable(CFLAGS "CFLAGS")
    get_environment_variable(CXXFLAGS "CXXFLAGS")

    # Combine CFLAGS and CXXFLAGS into a single string
    set(flags "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS} ${CFLAGS} ${CXXFLAGS}")
    set(arg 0)
    set(INCL_FLAGS "")
    string(LENGTH ${flags} len)
    foreach(i RANGE 0 ${len})
        # Extract the character at the current position
        string(SUBSTRING "${flags}" ${i} 1 c)
        if (${c} STREQUAL "-" OR ${c} STREQUAL "/")
            set(arg 1)
        elseif (${c} STREQUAL "I" AND ${arg})
            math(EXPR i "i + 1")
            if (${c} STREQUAL "\"")
                # Extract string
                math(EXPR i "${i} + 1")
                parseString(${flags} ${i} ${len} end_pos)
            else()
                parseUntilSpace(${flags} ${i} ${len} end_pos)
            endif()
            if(${end_pos} EQUAL -1)
                message("Failed to parse your custom arguments at pos ${i}")
                # Handle the error as needed
            endif()
            string(SUBSTRING ${flags} ${i} ${end_pos} str)
            list(APPEND INCL_FLAGS ${str})
            math(EXPR i "i + ${end_pos} + 2") # Go ahead of parse result
        endif()
    endforeach()
    set(${result_handler} ${INCL_FLAGS} PARENT_SCOPE)  # Ensure to set the result correctly in the parent scope
endfunction()

function(find_file include_paths file result_handler)
    foreach(sub_dir IN LISTS include_paths)
        # Check if the specific file exists in the subdirectory
        if(IS_FILE("${sub_dir}/${file}"))
            set(${result_handler} ${sub_dir} PARENT_SCOPE)  # Use PARENT_SCOPE to modify outside variable
            return()
        endif()
    endforeach()
    set(${result_handler} "" PARENT_SCOPE)
endfunction()

function(find_dir include_paths dir result_handler)
    foreach(sub_dir IN LISTS include_paths)
        # Check if the specific directory exists in the subdirectory
        if(IS_DIRECTORY("${sub_dir}/${dir}"))
            set(${result_handler} ${sub_dir} PARENT_SCOPE)  # Use PARENT_SCOPE to modify outside variable
            return()
        endif()
    endforeach()
    set(${result_handler} "" PARENT_SCOPE)
endfunction()

# Does not matter whether it is a file or dir
function(find_in_fs include_paths unit result_handler)
    foreach(sub_dir IN LISTS include_paths)
        # Check if the specific file or directory exists in the subdirectory
        if(EXISTS "${sub_dir}/${unit}")
            set(${result_handler} ${sub_dir} PARENT_SCOPE)  # Use PARENT_SCOPE to modify outside variable
            return()
        endif()
    endforeach()
    set(${result_handler} "" PARENT_SCOPE)
endfunction()
