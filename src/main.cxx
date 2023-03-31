#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class OutputChecker {
public:
    OutputChecker() = default;

    ~OutputChecker() = default;

    void expect(const std::string& expected) {
        expected_messages_.push_back(expected);
    }

    // Check if the console output contains all expected messages
    [[nodiscard]] bool check() const {
        std::string console_output = get_console_output();
        bool result = true;
        for (const auto& expected : expected_messages_) {
            if (console_output.find(expected) == std::string::npos) {
                result = false;
                std::cerr << "Expected message not found: " << expected << std::endl;
            }
        }
        return result;
    }

private:
    // Get the console output as a string
    [[nodiscard]] static std::string get_console_output() {
        std::string result;
        std::getline(std::cin, result);
        return result;
    }

    std::vector<std::string> expected_messages_;
};

int main() {
    // Initialize the output checker
    OutputChecker checker;

    // Print a colorful message
    std::cout << "\033[1;32mHello, world!\033[0m" << std::endl;

    // Add the expected message to the output checker
    checker.expect("Hello, world!");

    // Check if the console output contains the expected message
    if (checker.check()) {
        std::cout << "Output is correct!" << std::endl;
    } else {
        std::cerr << "Output is incorrect!" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
