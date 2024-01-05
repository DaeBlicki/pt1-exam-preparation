cmake_minimum_required(VERSION 3.12)

project("Complex Number Class" VERSION 1.0)

set(CXX_STANDARD_REQUIRED on)
set(CXX_STANDARD 20)

add_executable(main.exe main.cpp complex.cpp)

# set_target_properties(main.exe PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
# )