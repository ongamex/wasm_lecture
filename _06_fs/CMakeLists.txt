add_executable(_06_fs _06_fs.cpp)
chaos_addSourceMapForDebugging(_06_fs)

target_link_libraries(_06_fs PRIVATE embind)

add_custom_target(_06_fs_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:_06_fs>
)