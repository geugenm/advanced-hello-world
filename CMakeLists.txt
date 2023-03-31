# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.5)

# Set the project name and version
project(advanced VERSION 1.0.0 LANGUAGES CXX)

# Set the C++ standard and other compiler flags
set(CMAKE_CXX_STANDARD 17)

enable_testing()

# Add subdirectories for each component of the project
add_subdirectory(src)
add_subdirectory(test)