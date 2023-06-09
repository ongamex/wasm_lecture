cmake_minimum_required(VERSION 3.15)

project(WASM_Lectures)


# Source maps are needed to debug C++ code in the browser. The browser will request these files via the HTTP server.
macro(chaos_addSourceMapForDebugging target_name)
	target_link_options(${target_name} PRIVATE "--source-map-base=http://127.0.0.1:8000/cmake_bin/${target_name}/")
	target_link_options(${target_name} PRIVATE "-gsource-map")
endmacro()

if(EMSCRIPTEN)
	# -O0 is need for the DWARF debugging to persever variables.
	# Otherwise we won't see them in the browser.
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
endif()

add_subdirectory(_01_example_cmd_types)
add_subdirectory(_02_example_libStructs)
add_subdirectory(_04_call_js)
add_subdirectory(_05_01_webworker)
add_subdirectory(_05_threads)
add_subdirectory(_06_fs)
add_subdirectory(_07_sdl)
