add_executable(example_simple example_simple.cpp)

# When compiling directly with emcc the docs says that we need to specifiy "-o index.html"
# to get the default shell wrapper (the auto gemerated HTML that looks like a console),
# however in order to make this work in CMake we need to specify it like below.
# Note that the needed *.wasm file would still be generated.
set_target_properties(example_simple PROPERTIES SUFFIX ".html")