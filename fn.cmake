set(NO_EXIT_MES_INCL 1)
function (mkdir path)
    if (NOT EXISTS ${path})
        file(MAKE_DIRECTORY ${path})
    endif()
endfunction()
function(unzip path output)
    if (UNIX)
        execute_process(
            COMMAND ${CMAKE_COMMAND} -E tar xf ${path}
            WORKING_DIRECTORY ${output}
            RESULT_VARIABLE UNZIP_RESULT
        )
    else()
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
function(download_file link name output)
    if (NO_EXIT_MES_INCL)
        set(NO_EXIT_MES_INCL 0 PARENT_SCOPE)
        message("Some libraries are going to be downloaded. If you want to exit you may use CTRL+C or close the terminal.")
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