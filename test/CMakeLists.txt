# CMakeLists.txt file for the test directory

# Define the test executable and list all the source files with main functions
add_executable(advanced.tests wow.cpp test_cout.cxx)

# Use CTest to run the tests
enable_testing()

# Add all the source files with main functions as tests
add_test(NAME CoutTest COMMAND advanced.tests coutTest)
add_test(NAME CoutRedirectionTest COMMAND advanced.tests coutRedirectionTest)
