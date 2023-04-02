cmake_minimum_required(VERSION 3.15)

include(cmake/get_github_release_version.cmake)
include(cmake/check_platform.cmake)

# Set the project version
project(advanced VERSION ${GITHUB_VERSION} LANGUAGES CXX)

include(cmake/configure_compiler.cmake)
include(cmake/code_quality.cmake)

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

add_custom_target(build-all
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
        )

