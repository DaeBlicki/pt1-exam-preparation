#======================================================#
# CMakeLists.txt for the pt1 library                   
# created   :   18/12/2023
# author    :   DaeBlicki
# 
# updated   :   06/01/2024
# message   :   Add Complex class
# VERSION 2.00 (C) Copyright Free to use
#======================================================#

cmake_minimum_required(VERSION 3.12)

project("pt1 Library" VERSION 1.1)

# add include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# set C++ 20 standard
set(CXX_STANDARD_REQUIRED on)
set(CXX_STANDARD 20)

# list of pt1 source
set(pt1_source
    src/Timer.cpp
    src/Complex.cpp
    src/Random.cpp
)

# list of pt1 headers
set(pt1_headers
    include/Timer.hpp
    include/Random.hpp
    include/Complex.hpp
)

# build a static library
add_library(pt1 STATIC ${pt1_source})

# add testing
enable_testing()

# list of all the tests
set(tests
    test_complex
    test_timer
    test_random
)

# build tests from test list and link with library
foreach(test ${tests})
    add_executable(${test} test/${test}.cpp)
    target_link_libraries(${test} pt1)
    add_test(NAME ${test} COMMAND ${test})
endforeach()

# save the archive file in the bin subdirectory
set_target_properties(pt1 PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)