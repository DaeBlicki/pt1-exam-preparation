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
    complex_test_arithmetic
    complex_test_assignment
    complex_test_constructor
    complex_test_logical
    random_test_initialization
    timer_test_data
    timer_test_isMeasuring
    timer_test_reset
    timer_test_start_and_stop
    timer_test_precision
)

# build tests from test list and link with library
foreach(test ${tests})
    add_executable(${test} test/${test}.cpp)
    target_link_libraries(${test} pt1)
    add_test(NAME ${test} COMMAND ${test})
endforeach()

# save the archive file in the bin subdirectory
set_target_properties(pt1 PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)