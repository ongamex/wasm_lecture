add_executable(_06_fs _06_fs.cpp)
chaos_addSourceMapForDebugging(_06_fs)

target_link_libraries(_06_fs PRIVATE embind)

if (EMSCRIPTEN)
	set(PRELOADFILE " ${PRELOADFILE} --preload-file ${CMAKE_CURRENT_LIST_DIR}/dir_to_preload/@/home/chaos_preloaded_files/")
	message(${PRELOADFILE})
	set_target_properties(_06_fs PROPERTIES LINK_FLAGS "${PRELOADFILE}")
endif()

add_custom_target(_06_fs_CopyFiles ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/index.html $<TARGET_FILE_DIR:_06_fs>
)