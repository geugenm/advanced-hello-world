#include "main.hpp"

int main() {
    // Initialize the output checker
    OutputChecker checker;

    // Print a colorful message
    std::cout << "\033[1;32mHello, world!\033[0m" << std::endl;

    // Add the expected message to the output checker
    checker.expect("Hello, world!");

    // Check if the console output contains the expected message
    if (checker.containsExpected()) {
        std::cout << "Output is correct!" << std::endl;
    } else {
        std::cerr << "Output is incorrect!" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


