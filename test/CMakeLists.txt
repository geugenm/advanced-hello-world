cmake_minimum_required(VERSION 3.5.0)

project(AdvancedTests VERSION 1.0.0 LANGUAGES CXX)

# Enable CTest to run tests
include(CTest)
enable_testing()

# Set the directory for the project source files
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Define the directories to search for source files
set(SOURCE_DIRS
        src
        )

# Define the test executables and their source files for each directory
set(TESTS
        cout_redirection
        cout_system
        main
        )

foreach (dir ${SOURCE_DIRS})
    foreach (test ${TESTS})
        # Check if source file exists in the tests directory
        set(test_source ${CMAKE_CURRENT_SOURCE_DIR}/${test}.cxx)
        if (NOT EXISTS ${test_source})
            # If source file doesn't exist in tests directory, search the directory
            set(test_source ${PROJECT_DIR}/${dir}/${test}.cxx)
            if (NOT EXISTS ${test_source})
                message(FATAL_ERROR "Could not find source file for ${test} test in directory ${dir}")
            else ()
                # If source file is in directory, add directory name to test executable and test name
                set(test "${dir}_${test}")
            endif ()
        endif ()

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
    endforeach ()
endforeach ()


# Define the libraries to test and their types (static or dynamic)
set(LIBRARIES
        advanced.library.static
        advanced.library.dynamic
        )

# Loop over the libraries and link each one
foreach (LIBRARY ${LIBRARIES})
    # Define the test target
    add_executable(${LIBRARY}Test
            library_integration.cpp
            )
    # Add the library and set its type
    target_link_libraries(${LIBRARY}Test ${LIBRARY_TYPE} ${LIBRARY})

    # Set include directories for the library
    target_include_directories(${LIBRARY_TYPE} ${LIBRARY} PUBLIC ${PROJECT_DIR}/lib/include/)

    # Add test
    add_test(NAME test_${LIBRARY} COMMAND LibraryTest)
endforeach ()

