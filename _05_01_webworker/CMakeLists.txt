
add_custom_target(_05_01_webworkers_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html ${CMAKE_BINARY_DIR}/_05_01_webworker
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/my_worker.js ${CMAKE_BINARY_DIR}/_05_01_webworker
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/main.js ${CMAKE_BINARY_DIR}/_05_01_webworker
)
