add_executable(_05_threads _05_threads.cpp)
chaos_addSourceMapForDebugging(_05_threads)

target_link_options(_05_threads PRIVATE  "-sUSE_PTHREADS=1")
target_link_options(_05_threads PRIVATE  "-sPTHREAD_POOL_SIZE=3")
target_link_libraries(_05_threads PRIVATE embind)

add_custom_target(_05_threads_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:_05_threads>
)