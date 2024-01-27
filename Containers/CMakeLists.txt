cmake_minimum_required(VERSION 3.12)

project("Benchmark Containers" VERSION 1.0)

# add include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# set the compiling standards
set(CXX_STANDARD_REQUIRED on)
set(CXX_STANDARD 20)

# Compiler optimization
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# message(STATUS "Build Type: " ${CMAKE_BUILD_TYPE})

# set(CMAKE_CXX_FLAGS "-Wall -Wextra")
# set(CMAKE_CXX_FLAGS_DEBUG "-g")
# set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# build executable
add_executable(main src/main.cpp)

# add library
target_include_directories(main PRIVATE include)
target_include_directories(main PRIVATE include/pt1)
target_link_libraries(main ${CMAKE_CURRENT_SOURCE_DIR}/lib/libpt1.a)