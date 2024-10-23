
set (download_link_base https://raw.githubusercontent.com/Sinfolke/cpuf/main)
function(check_cpuf_module module_name cpuf_dir)
    if (EXISTS(${cpuf_dir}/${module_name}))
        message(STATUS "${module_name} exists")
    else()
        download_file(${link}/${module_name} ${module_name} ${cpuf_dir})
    endif()
endfunction()