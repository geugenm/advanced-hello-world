# CMakeLists.txt file for the test directory

# Define the test executable and list all the source files with main functions
add_executable(MyTests wow.cpp test_cout.cxx)

# Use CTest to run the tests
enable_testing()

# Add all the source files with main functions as tests
add_test(NAME Test1 COMMAND MyTests test1)
add_test(NAME Test2 COMMAND MyTests test2)
