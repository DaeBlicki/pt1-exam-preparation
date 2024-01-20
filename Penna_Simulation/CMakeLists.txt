#======================================================#
# CMakeLists.txt for the Penna Simulation
# created   :   18/12/2023
# author    :   DaeBlicki
# 
# updated   :   06/01/2024
# message   :   Project structure overhaul
# VERSION 2.00 (C) Copyright Free to use
#======================================================#

cmake_minimum_required(VERSION 3.12)

project("Penna Simulation" VERSION 2.0)

# Standard Requirement C++ 20
set(CXX_STANDARD_REQUIRED on)
set(CXX_STANDARD 20)

# Compiler optimization
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

message(STATUS "Build Type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Add matplotplusplus subdirectory
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/matplotplusplus)

# Set Penna library sources
set(PENNA_SOURCES
    src/Penna/animal.cpp
    src/Penna/genome.cpp
    src/Penna/population.cpp
)

# Set Penna library headers
set(PENNA_HEADERS
    include/Penna/animal.hpp
    include/Penna/genome.hpp
    include/Penna/population.hpp
)

# adding test
enable_testing()

# set all tests
set(tests
    test_genome
    test_animal
    test_population
)

# create test case for penna library
foreach(test ${tests})
    add_executable(${test} test/${test}.cpp ${PENNA_SOURCES})
    target_link_libraries(${test} ${CMAKE_CURRENT_SOURCE_DIR}/lib/libpt1.a)
    target_include_directories(${test} PRIVATE include/Penna)
    target_include_directories(${test} PRIVATE include/pt1)
    add_test(NAME ${test} COMMAND ${test})
endforeach()

# Build the executable
add_executable(Penna_Simulation src/main.cpp src/simulation.cpp ${PENNA_SOURCES})

# Include the used headers in the library
target_include_directories(Penna_Simulation PRIVATE include/Penna)
target_include_directories(Penna_Simulation PRIVATE include/pt1)

# Link libraries with executable
target_link_libraries(Penna_Simulation ${CMAKE_CURRENT_SOURCE_DIR}/lib/libpt1.a)
target_link_libraries(Penna_Simulation matplot)

# Ensure that the 'results' subdirectory is created during the build process
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/doc/Simulation_results)

# Store the executable in the bin directory
set_target_properties(Penna_Simulation PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)