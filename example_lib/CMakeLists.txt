add_executable(example_lib example_lib.cpp)

kostaki_addSourceMapForDebugging(example_lib)

add_custom_target(example_lib_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:example_lib>
)