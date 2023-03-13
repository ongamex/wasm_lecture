add_executable(example_lib example_lib.cpp)

# A command on build that copies the index.html.
#add_custom_command(
#    TARGET example_lib POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:example_lib>/
#)

add_custom_target(example_lib_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:example_lib>
)