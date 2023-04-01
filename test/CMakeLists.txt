# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.5.0)


# Use CTest to run the tests
enable_testing()

# Define the test executable and list all the source files with main functions
add_executable(test.cout
        test-cout.cxx
        )

add_executable(test.cout.ostringstream
        test-cout-system.cxx
        )


# Add all the source files with main functions as tests
add_test(NAME CoutTest COMMAND test.cout coutTest)

add_test(NAME CoutRedirectionTest COMMAND test.cout.ostringstream coutRedirectionTest)
