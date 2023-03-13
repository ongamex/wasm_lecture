add_executable(example_libStructs example_libStructs.cpp)


target_link_options(example_libStructs PRIVATE "--source-map-base=http://127.0.0.1:8000/cmake_bin/example_libStructs/")
target_link_options(example_libStructs PRIVATE "-gsource-map")


add_custom_target(example_libStructs_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:example_libStructs>
)
