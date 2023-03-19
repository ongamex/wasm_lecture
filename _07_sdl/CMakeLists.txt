cmake_minimum_required(VERSION 3.14)

project(_07_sdl)

FILE(GLOB EMGAME_SRC *)
add_executable(_07_sdl WIN32 ${EMGAME_SRC})

chaos_addSourceMapForDebugging(_07_sdl)

target_compile_options(_07_sdl PRIVATE  "-sUSE_SDL=2")
target_link_libraries(_07_sdl PRIVATE SDL2)

if(EMSCRIPTEN)
	set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
else()
	target_link_libraries(_07_sdl SDL2main SDL2)
endif()

set_property(TARGET _07_sdl PROPERTY VS_DEBUGGER_COMMAND "${CMAKE_INSTALL_PREFIX}/emgame_bin/_07_sdl.exe")

# Assets
set(PRELOADFILE "${CMAKE_CURRENT_LIST_DIR}/assets@assets/")
set_target_properties(_07_sdl PROPERTIES LINK_FLAGS "--preload-file ${PRELOADFILE}")
