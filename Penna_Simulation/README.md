# Penna Simulation - Simulation for Biological Aging

## 1. Introduction
The Penna Simulation is a scientific application to measure the dynamic of a population. User defined parameter will calculate the course of the population size and the number of bad mutation of the genome. 

## 2. How to get started

### 2.1 Requirement
- Ubuntu 22.04+
- CMake version 3.22+
- GNU 11.4.0

Get full advantage of the matplotplusplus library with following libraries
- libTIFF 
- libPNG 
- libFFTW

```
sudo apt-get update
sudo apt-get install libtiff-dev
sudo apt-get install libpng-dev
sudo apt-get install fftw-dev
```

### 2.2 Download
Go to the desired location, where you want to download 'Penna Simulation' and enter following commands in the Terminal to
install penna_simulation.exe. 

```
git clone https://gitlab.ethz.ch/davidbl/pt1-project.git
cd pt1-project/penna_simulation/lib
git clone https://github.com/alandefreitas/matplotplusplus/
cd ..
mkdir build
cd build
cmake ..
make
```