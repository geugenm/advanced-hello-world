#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::ostringstream output;
    std::cout.rdbuf(output.rdbuf());

    // Replace this with the code you want to test
    std::cout << "Hello, world!" << std::endl;

    constexpr std::string_view expected_output = "Hello, world!\n";
    std::string_view actual_output = output.str();

    if (actual_output != expected_output) {
        std::cerr << "Test failed: expected \"" << expected_output
                  << "\", but got \"" << actual_output << "\"" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Test passed!" << std::endl;
    return EXIT_SUCCESS;
}

