@echo off
rem This script creates a cmake_bin directory inside the repo dir. 
rem This is needed so that the HTTP servers can access the source files so that the Web Browser can access the C++ source files for debugging.
rem We could use symlinks, but on Windows they require administrative rights, which is thedious to do.

rem Replace "D:\work\emsdk" below with the path to your instance of emsdk. This thing tells cmake where are the emscripten compiler, linker, stdlibs and so on.
rem After configuring it is safe to use CMake GUI.
@echo on
mkdir cmake_bin
cd cmake_bin
cmake .. -G Ninja -DCMAKE_TOOLCHAIN_FILE="D:\work\emsdk\upstream\emscripten\cmake\Modules\Platform\Emscripten.cmake" -DCMAKE_BUILD_TYPE="Debug"