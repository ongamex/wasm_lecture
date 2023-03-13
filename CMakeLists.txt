cmake_minimum_required(VERSION 3.15)

project(WASM_Lectures)

if(EMSCRIPTEN)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ALLOW_MEMORY_GROWTH=1") # By default Emscripten has a fixed pool size for dynamic allocations. This enables it to grow.
	#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g0") # Emscripten debug symbols take a lot of space for disable it by default. When debugging use -g3.
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3")
endif()

add_subdirectory(example_simple)
add_subdirectory(example_exe)
add_subdirectory(example_lib)
add_subdirectory(example_libStructs)
add_subdirectory(example_libBind)
