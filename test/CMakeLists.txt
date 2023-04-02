# Set the minimum required version of CMake and project name
cmake_minimum_required(VERSION 3.5.0)
project(MyProject VERSION 1.0.0 LANGUAGES CXX)

# Enable CTest to run tests
include(CTest)
enable_testing()

# Set the directory for the project source files
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Define the directories to search for source files
set(SOURCE_DIRS
        src
        )

foreach(dir ${SOURCE_DIRS})
    # Define the test executables and their source files for each directory
    set(TESTS
            cout-redirection
            cout-system
            main
            )

    foreach(test ${TESTS})
        # Check if source file exists in the tests directory
        set(test_source ${CMAKE_CURRENT_SOURCE_DIR}/${test}.cxx)
        if(NOT EXISTS ${test_source})
            # If source file doesn't exist in tests directory, search the directory
            set(test_source ${PROJECT_DIR}/${dir}/${test}.cxx)
            if(NOT EXISTS ${test_source})
                message(FATAL_ERROR "Could not find source file for ${test} test in directory ${dir}")
            else()
                # If source file is in directory, add directory name to test executable and test name
                set(test "${dir}_${test}")
            endif()
        endif()

        # Add the test executable
        add_executable(${test} ${test_source})

        # Set C++ standard and compiler options for the test executable
        set_target_properties(${test} PROPERTIES
                CXX_STANDARD 17
                CXX_STANDARD_REQUIRED YES
                CXX_EXTENSIONS NO
                )

        # Add test
        add_test(NAME ${test}Test COMMAND ${test})
    endforeach()
endforeach()
