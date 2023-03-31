cmake_minimum_required(VERSION 3.12)

# Set the project name and version
project(advanced.source VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Add options for build type-specific flags
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Enable warnings and treat them as errors
add_compile_options(-Wall -Wextra -pedantic -Werror)

include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/)

# Add the executable
add_executable(${PROJECT_NAME} main.cxx)
