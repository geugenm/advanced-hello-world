#include <iostream>
#include <sstream>
#include "../src/main.hpp"

int main() {
    OutputChecker checker;

    // Test 1: containsExpected that an expected message is found
    checker.expect("Hello, world!");
    std::cout << "Running Test 1: containsExpected with an expected message..." << std::endl;
    std::string input1 = "Hello, world!\n";
    std::istringstream iss1(input1);
    std::cin.rdbuf(iss1.rdbuf());
    if (checker.containsExpected()) {
        std::cout << "Test 1 passed!" << std::endl;
    } else {
        std::cerr << "Test 1 failed!" << std::endl;
        return EXIT_FAILURE;
    }

    // Test 2: containsExpected that an expected message is not found
    checker.expect("Goodbye, world!");
    std::cout << "Running Test 2: containsExpected with an unexpected message..." << std::endl;
    std::string input2 = "Hello, world!\n";
    std::istringstream iss2(input2);
    std::cin.rdbuf(iss2.rdbuf());
    if (!checker.containsExpected()) {
        std::cout << "Test 2 passed!" << std::endl;
    } else {
        std::cerr << "Test 2 failed!" << std::endl;
        return EXIT_FAILURE;
    }

    // Test 3: containsExpected with no expected messages
    std::cout << "Running Test 3: containsExpected with no expected messages..." << std::endl;
    std::string input3 = "Hello, world!\n";
    std::istringstream iss3(input3);
    std::cin.rdbuf(iss3.rdbuf());
    if (checker.containsExpected()) {
        std::cerr << "Test 3 failed!" << std::endl;
        return EXIT_FAILURE;
    } else {
        std::cout << "Test 3 passed!" << std::endl;
    }

    // Test 4: containsExpected with an empty console output
    std::cout << "Running Test 4: containsExpected with empty console output..." << std::endl;
    std::string input4 = "\n";
    std::istringstream iss4(input4);
    std::cin.rdbuf(iss4.rdbuf());
    if (!checker.containsExpected()) {
        std::cout << "Test 4 passed!" << std::endl;
    } else {
        std::cerr << "Test 4 failed!" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "All tests passed!" << std::endl;
    return EXIT_SUCCESS;
}
