cmake_minimum_required(VERSION 3.15)

include(cmake/get_github_release_version.cmake)
include(cmake/check_platform.cmake)

# Set the project version
project(advanced VERSION ${GITHUB_VERSION} LANGUAGES CXX)

include(cmake/configure.cmake)
include(cmake/cleaner.cmake)

# Set build type to Release if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

enable_testing()
add_subdirectory(test)

# Add subdirectories for each component of the project
add_subdirectory(src)
add_subdirectory(lib)

add_custom_target(build-all
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR}
        )

