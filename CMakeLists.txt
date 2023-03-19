cmake_minimum_required(VERSION 3.15)

project(WASM_Lectures)

macro(chaos_addSourceMapForDebugging target_name)
	target_link_options(${target_name} PRIVATE "--source-map-base=http://127.0.0.1:8000/cmake_bin/${target_name}/")
	target_link_options(${target_name} PRIVATE "-gsource-map")
endmacro()

if(EMSCRIPTEN)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
	#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ALLOW_MEMORY_GROWTH=1") # By default Emscripten has a fixed pool size for dynamic allocations. This enables it to grow.
endif()

add_subdirectory(_01_example_cmd_types)
add_subdirectory(_02_example_libStructs)
add_subdirectory(_03_example_LibBind)
add_subdirectory(_04_call_js)
add_subdirectory(_05_01_webworker)
add_subdirectory(_05_threads)
add_subdirectory(_06_fs)
