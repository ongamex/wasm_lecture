
add_executable(example_libBind example_libBind.cpp)

#target_link_options(example_libBind PRIVATE "-s EXPORT_NAME=\"'create_exampleLibBind\"'")
#target_link_options(example_libBind PRIVATE "-s MODULARIZE=1")

target_link_libraries(example_libBind PRIVATE embind)

#target_link_options(example_libBind PRIVATE "--source-map-base \"${CMAKE_SOURCE_DIR}\"")
target_link_options(example_libBind PRIVATE "--source-map-base http://localhost:8000/")

#target_link_options(example_libBind PRIVATE "-fdebug-compilation-dir=\"..\"")
target_link_options(example_libBind PRIVATE "-gsource-map")
target_compile_options(example_libBind PRIVATE "-o example_libBind.js")
target_compile_options(example_libBind PRIVATE "-g")


add_custom_target(example_libBind_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:example_libBind>
)