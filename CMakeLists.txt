cmake_minimum_required(VERSION 3.12)

# Get the version from git tags
execute_process(
        COMMAND git describe --tags --abbrev=0
        OUTPUT_VARIABLE GIT_TAG_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Parse the version number
string(REGEX MATCH "([0-9]+)\\.([0-9]+)\\.([0-9]+)" GIT_TAG_VERSION "${GIT_TAG_VERSION}")
set(PROJECT_VERSION_MAJOR "${CMAKE_MATCH_1}")
set(PROJECT_VERSION_MINOR "${CMAKE_MATCH_2}")
set(PROJECT_VERSION_PATCH "${CMAKE_MATCH_3}")

set(GITHUB_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

if(${GITHUB_VERSION} STREQUAL "..")
    set(GITHUB_VERSION "0.0.0")
endif()


# Set the project version
project(advanced VERSION ${GITHUB_VERSION} LANGUAGES CXX)

# Set the C++ standard and other compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set build type to Release if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

# Set additional compiler flags for different configurations
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native")

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories for each component of the project
add_subdirectory(src)
add_subdirectory(test)

# Check for C++17 support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORTS_CXX17)
if (COMPILER_SUPPORTS_CXX17)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
else ()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++17 support. Please use a different C++ compiler.")
endif ()

# Add custom targets for formatting, linting, and other checks
find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
    add_custom_target(format
            COMMAND ${CLANG_FORMAT} -i ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/include/*.hpp ${PROJECT_SOURCE_DIR}/test/*.cpp
            COMMENT "Formatting code..."
            )
endif ()

find_program(CPPLINT "cpplint")
if (CPPLINT)
    add_custom_target(lint
            COMMAND ${CPPLINT} --recursive ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/include/*.hpp ${PROJECT_SOURCE_DIR}/test/*.cpp
            COMMENT "Linting code..."
            )
endif ()

find_program(CLANG_TIDY "clang-tidy")
if (CLANG_TIDY)
    add_custom_target(tidy
            COMMAND ${CLANG_TIDY} ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/include/*.hpp ${PROJECT_SOURCE_DIR}/test/*.cpp -- -std=c++17
            COMMENT "Checking code with clang-tidy..."
            )
endif ()
