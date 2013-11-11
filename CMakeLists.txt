# The name of our project is "HELLO". CMakeLists files in this project can 
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and 
# to the root binary directory of the project as ${HELLO_BINARY_DIR}. 
cmake_minimum_required (VERSION 2.4) 
project (AA-Work2) 

## Compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
set(CMAKE_CXX_FLAGS "-O2")        ## Optimize
set(CMAKE_EXE_LINKER_FLAGS "-s")  ## Strip binary
endif()
# Add executable called "helloDemo" that is built from the source files 
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found. 
add_executable (aa2  dtw.cpp main.cpp) 

# Link the executable to the Hello library. 
#target_link_libraries (helloDemo Hello) 
