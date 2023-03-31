#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

namespace myapp {

    const char* const kHelloWorld = "Hello, World!\n";
    const std::size_t kHelloWorldLen = std::strlen(kHelloWorld);

    void print_hello_world() {
        std::size_t written = std::fwrite(kHelloWorld, sizeof(char), kHelloWorldLen, stdout);
        if (written != kHelloWorldLen) {
            std::perror("Error: Failed to write to stdout.");
            std::exit(EXIT_FAILURE);
        }
    }

}  // namespace myapp

int main() {
    myapp::print_hello_world();
    return EXIT_SUCCESS;
}
