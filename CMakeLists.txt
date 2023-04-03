cmake_minimum_required(VERSION 3.5.0)

# Include custom modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Check platform compatibility
include(check_platform)

# Set the project version
project(advanced VERSION 1.0.0 LANGUAGES CXX)

# Configure the compiler
include(configure_compiler)

# Ensure high code quality standards
include(code_quality)

# Set build type to Release if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

# Add subdirectories for each component of the project
add_subdirectory(src)
add_subdirectory(lib)

# Add tests
option(BUILD_TESTS "Build tests" ON)
if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif ()

# Custom target to build everything
add_custom_target(build-all COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR})