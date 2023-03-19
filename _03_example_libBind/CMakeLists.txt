
add_executable(_03_example_libBind example_libBind.cpp)

chaos_addSourceMapForDebugging(_03_example_libBind)

#target_link_options(_03_example_libBind PRIVATE "-s EXPORT_NAME=\"'create_exampleLibBind\"'")
#target_link_options(_03_example_libBind PRIVATE "-s MODULARIZE=1")

target_link_libraries(_03_example_libBind PRIVATE embind)



add_custom_target(_03_example_libBind_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:_03_example_libBind>
)