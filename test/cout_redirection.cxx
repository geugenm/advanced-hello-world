#include <iostream>
#include <sstream>
#include <string>

#define HELLO_WORLD_MSG "Hello, World!"

void printHelloWorld() {
    std::cout << HELLO_WORLD_MSG << std::endl;
}

int main() {
    // Redirect cout to a string buffer
    std::stringstream buffer;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    // Call the external function to print the message
    printHelloWorld();

    if (std::cout.bad()) {
        std::cerr << "std::cout is bad";
        return EXIT_FAILURE;
    }

    // Restore cout to its original buffer
    std::cout.rdbuf(oldCoutBuffer);

    // Check if the buffer contains the expected message
    std::string consoleOutput = buffer.str();
    if (consoleOutput.find(HELLO_WORLD_MSG) == std::string::npos) {
        std::cerr << "Error: failed to print \"" << HELLO_WORLD_MSG << "\" to the console" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}