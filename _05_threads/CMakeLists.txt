add_executable(_05_threads example_threads.cpp)
chaos_addSourceMapForDebugging(_05_threads)

target_link_libraries(_05_threads PRIVATE embind)

add_custom_target(_05_threads_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:_05_threads>
)