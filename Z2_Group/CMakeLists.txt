cmake_minimum_required(VERSION 3.12)

project("Z2 Group")

set(CXX_STANDARD_REQUIRED ON)
set(CXX_STANDARD 20)

add_executable(Z2.exe z2_group.cpp)

set_target_properties(Z2.exe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)