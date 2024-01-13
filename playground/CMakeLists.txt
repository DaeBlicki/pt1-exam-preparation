cmake_minimum_required(VERSION 3.12)

project("Playground for testing")

# set standards
set(CXX_STANDARD_REQUIRED on)
set(CXX_STANDARD 20)    

add_executable(main main.cpp Timer.cpp)
