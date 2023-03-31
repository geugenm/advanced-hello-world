#pragma once

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
    [[nodiscard]] bool containsExpected() const {
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