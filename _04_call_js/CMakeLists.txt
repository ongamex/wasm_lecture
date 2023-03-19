
add_executable(_04_call_js call_js.cpp)
chaos_addSourceMapForDebugging(_04_call_js)

target_link_libraries(_04_call_js PRIVATE embind)

add_custom_target(_04_call_js_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:_04_call_js>
)