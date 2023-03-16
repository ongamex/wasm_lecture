add_executable(example_libStructs example_libStructs.cpp)

kostaki_addSourceMapForDebugging(example_libStructs)

add_custom_target(example_libStructs_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:example_libStructs>
)
