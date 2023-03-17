add_executable(_02_example_libStructs example_libStructs.cpp)

kostaki_addSourceMapForDebugging(_02_example_libStructs)

add_custom_target(_02_example_libStructs_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:_02_example_libStructs>
)
