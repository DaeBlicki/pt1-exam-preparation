# CMakeLists.txt for the Penna Simulation
# inspired by T.J.P. Penna - A Bit-String Model for Biological Aging

cmake_minimum_required(VERSION 3.12)

project("Penna Simulation" VERSION 1.0)

# Standard Requirement C++ 20
set(CXX_STANDARD_REQUIRED on)
set(CXX_STANDARD 20)

# find matplotplusplus package
# set(Matplot++_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/matplotplusplus/)
# find_package(Matplot++ REQUIRED)

# Add matplotplusplus subdirectory
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/matplotplusplus)

# Set Penna Simulation sources
set(PENNA_SOURCES
    src/Penna/animal.cpp
    src/Penna/genome.cpp
    src/Penna/population.cpp
    )

# Set Penna Simulation headers
set(PENNA_HEADERS
    include/Penna/animal.hpp
    include/Penna/genome.hpp
    include/Penna/population.hpp
    include/Penna/simulation.hpp
    )

# Build the executable
add_executable(Penna_Simulation src/main.cpp src/Penna/simulation.cpp ${PENNA_SOURCES})

# Link libraries with executable
set(PT1_LIBRARY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(Penna_Simulation PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib/libpt1.a)
target_link_libraries(Penna_Simulation PUBLIC matplot)

# Include the used headers in the library
target_include_directories(Penna_Simulation PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/Penna)
target_include_directories(Penna_Simulation PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pt1)

# Include subdirectory to save the result file
target_include_directories(Penna_Simulation PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/doc/Simulation_results)

# Ensure that the 'results' subdirectory is created during the build process
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/doc/Simulation_results)

# adding test
enable_testing()

# Genome - default ctor testing
add_executable(genome_test_default_constructor test/genome_test_default_constructor.cpp ${PENNA_SOURCES})
target_link_libraries(genome_test_default_constructor PRIVATE ${PT1_LIBRARY_PATH}/libpt1.a)
target_include_directories(genome_test_default_constructor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/Penna)
target_include_directories(genome_test_default_constructor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pt1)

add_test(NAME genome_test_default_constructor COMMAND genome_test_default_constructor)

# Genome - copy ctor testing
add_executable(genome_test_copy_constructor test/genome_test_copy_constructor.cpp ${PENNA_SOURCES})
target_link_libraries(genome_test_copy_constructor PRIVATE ${PT1_LIBRARY_PATH}/libpt1.a)
target_include_directories(genome_test_copy_constructor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/Penna)
target_include_directories(genome_test_copy_constructor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pt1)

add_test(NAME genome_test_copy_constructor COMMAND genome_test_copy_constructor)

# Animal - default ctor testing
add_executable(animal_test_default_constructor test/animal_test_default_constructor.cpp ${PENNA_SOURCES})
target_link_libraries(animal_test_default_constructor PRIVATE ${PT1_LIBRARY_PATH}/libpt1.a)
target_include_directories(animal_test_default_constructor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/Penna)
target_include_directories(animal_test_default_constructor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pt1)

add_test(NAME animal_test_default_constructor COMMAND animal_test_default_constructor)

# Animal - copy ctor testing
add_executable(animal_test_copy_constructor test/animal_test_copy_constructor.cpp ${PENNA_SOURCES})
target_link_libraries(animal_test_copy_constructor PRIVATE ${PT1_LIBRARY_PATH}/libpt1.a)
target_include_directories(animal_test_copy_constructor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/Penna)
target_include_directories(animal_test_copy_constructor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pt1)

add_test(NAME animal_test_copy_constructor COMMAND animal_test_copy_constructor)

# Animal - basic initialization testing
add_executable(animal_test_basic_initialization test/animal_test_basic_initialization.cpp ${PENNA_SOURCES})
target_link_libraries(animal_test_basic_initialization PRIVATE ${PT1_LIBRARY_PATH}/libpt1.a)
target_include_directories(animal_test_basic_initialization PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/Penna)
target_include_directories(animal_test_basic_initialization PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pt1)

add_test(NAME animal_test_basic_initialization COMMAND animal_test_basic_initialization)

# Animal - advanced initialization testing
add_executable(animal_test_advanced_initialization test/animal_test_advanced_initialization.cpp ${PENNA_SOURCES})
target_link_libraries(animal_test_advanced_initialization PRIVATE ${PT1_LIBRARY_PATH}/libpt1.a)
target_include_directories(animal_test_advanced_initialization PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/Penna)
target_include_directories(animal_test_advanced_initialization PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pt1)

add_test(NAME animal_test_advanced_initialization COMMAND animal_test_advanced_initialization)

# Population - default constructor testing
add_executable(population_test_default_constructor test/population_test_default_constructor.cpp ${PENNA_SOURCES})
target_link_libraries(population_test_default_constructor PRIVATE ${PT1_LIBRARY_PATH}/libpt1.a)
target_include_directories(population_test_default_constructor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/Penna)
target_include_directories(population_test_default_constructor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pt1)

add_test(NAME population_test_default_constructor COMMAND population_test_default_constructor)

# Population - functionality testing
add_executable(population_test_functionality test/population_test_functionality.cpp ${PENNA_SOURCES})
target_link_libraries(population_test_functionality PRIVATE ${PT1_LIBRARY_PATH}/libpt1.a)
target_include_directories(population_test_functionality PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/Penna)
target_include_directories(population_test_functionality PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/pt1)

add_test(NAME population_test_functionality COMMAND population_test_functionality)

# Store the executable in the bin directory
set_target_properties(Penna_Simulation PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)