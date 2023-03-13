add_executable(example_libStructs example_libStructs.cpp)

target_compile_options(example_libStructs PRIVATE "-g3")
target_compile_options(example_libStructs PRIVATE "--source-map-base \"cmake_bin/example_libStructs"")
target_link_options(example_libStructs PRIVATE "-gsource-map")


add_custom_target(example_libStructs_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:example_libStructs>
)
