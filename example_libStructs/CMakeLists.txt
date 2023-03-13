add_executable(example_libStructs example_libStructs.cpp)

target_link_options(example_libStructs PRIVATE "--source-map-base \"${CMAKE_SOURCE_DIR}\"")
#target_link_options(example_libStructs PRIVATE "--source-map-base http://localhost:8000/")

#target_link_options(example_libStructs PRIVATE "-fdebug-compilation-dir=\"..\"")
target_compile_options(example_libStructs PRIVATE "-gsource-map")
target_compile_options(example_libStructs PRIVATE "-g")

add_custom_target(example_libStructs_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:example_libStructs>
)
