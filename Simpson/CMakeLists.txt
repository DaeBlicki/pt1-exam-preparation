cmake_minimum_required(VERSION 3.12)

project("Simpson Library" VERSION 1.0)

# add include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/Simpson)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/pt1)

# set standards
set(CXX_STANDARD_REQUIRED on)
set(CXX_STANDARD 20)    

# set simpson as simpson.cpp
add_library(Simpson STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/simpson.cpp)

# testing
enable_testing()

# name the test names
set(tests
    test_polynomial
    test_sine
    test_integrate
    test_benchmark
    test_integrate2d
)

set(test_path ${CMAKE_CURRENT_SOURCE_DIR}/test/)

# building tests
foreach(test ${tests})
    add_executable(${test} test/${test}.cpp src/polynomial.cpp)
    target_link_libraries(${test} Simpson)
    target_link_libraries(${test} ${CMAKE_CURRENT_SOURCE_DIR}/lib/libpt1.a)
    add_test(NAME ${test} COMMAND ${test})
endforeach()