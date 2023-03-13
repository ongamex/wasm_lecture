cmake_minimum_required(VERSION 3.15)

project(WASM_Lectures)

add_subdirectory(example_simple)
add_subdirectory(example_exe)
add_subdirectory(example_lib)
add_subdirectory(example_libStructs)
add_subdirectory(example_libBind)

# A command that copies the serve.py file that is a simple HTTP server to the CMake bin diretroy.
# When we launch it it will server on http://127.0.0.1:8000/ so we can test our code.
# The script runs ninja in the cmake-binary-dir each time we get a request eding with / (meaning it needs index.html)
# That way we do not need to manually recompile the C++.
add_custom_target(copy_serve_py_to_bin_dir ALL 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/serve.py ${CMAKE_BINARY_DIR}
)

# For the WASM C++ debugging to work the HTTP server needs to be able to access and respond with files
# from our source code.
add_custom_target(create_symlink_to_code ALL
	COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/ ${CMAKE_BINARY_DIR}/wasm)

add_custom_target(create_symlink_to_emsdk ALL
	COMMAND ${CMAKE_COMMAND} -E create_symlink "D:\\work/emsdk" ${CMAKE_BINARY_DIR}/emsdk/emscripten)

if(EMSCRIPTEN)
	# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os") This flag should decrease the build size, but last time I'v checked (2021) it does not in our case.
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s DISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR=1")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_SDL=2")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1") # This is the old way of telling Emscripten to use WebGL2
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s MIN_WEBGL_VERSION=2") # This is the new way of telling Emscripten to use WebGL2
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s MAX_WEBGL_VERSION=2") # This is the new way of telling Emscripten to use WebGL2

	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s ALLOW_MEMORY_GROWTH=1") # By default Emscripten has a fixed pool size for dynamic allocations. This enables it to grow.
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
	#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g0") # Emscripten debug symbols take a lot of space for disable it by default. When debugging use -g3.
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3") # Here for debbuging only, disable -g0 in that case.
endif()