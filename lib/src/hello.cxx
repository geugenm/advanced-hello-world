#include <cstdlib>
#include "hello.hxx"

void HelloWorld::print_hello_world() {
    std::size_t written = std::fwrite(kHelloWorld, sizeof(char), kHelloWorldLen, stdout);
    if (written != kHelloWorldLen) {
        std::perror("Error: Failed to write to stdout.");
        std::exit(EXIT_FAILURE);
    }
}
