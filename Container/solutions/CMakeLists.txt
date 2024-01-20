cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 11)

# setting warning compiler flags
if(CMAKE_CXX_COMPILER_ID MATCHES "(C|c?)lang")
  add_compile_options(-Weverything)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# add options
option(VERBOSE "Show what's happening" OFF)
if ( VERBOSE )
  add_definitions(-DVERBOSE)
endif()
option(MOVE "Enable move ctor & assignment" ON)
if ( MOVE )
  add_definitions(-DMOVE)
endif()

add_executable(main main.cpp)
