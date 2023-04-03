#include <cstdlib>
#include <iostream>
#include <string>

bool is_terminal_support_truecolor() {
    const char *term = std::getenv("TERM");
    const char *colorterm = std::getenv("COLORTERM");

    bool colored_terminal_supported =
            (term != nullptr && std::string(term) == "xterm-256color") ||
            (colorterm != nullptr && std::string(colorterm) == "truecolor");

    if (!colored_terminal_supported) {
        std::cerr << "Error: Truecolor not supported in this terminal!\n";
        std::cerr << "TERM=" << (term != nullptr ? term : "") << '\n';
        std::cerr << "COLORTERM=" << (colorterm != nullptr ? colorterm : "") << '\n';
    }

    return colored_terminal_supported;
}

bool is_terminal_support_256color() {
    const char *term = std::getenv("TERM");

    bool colored_256_supported =
            (term != nullptr && std::string(term) == "xterm-256color");

    if (!colored_256_supported) {
        const char *os_env_var = std::getenv("OS");
        if (os_env_var != nullptr && std::string(os_env_var) == "Windows_NT") {
            colored_256_supported = true;
        }
    }

    if (!colored_256_supported) {
        std::cerr << "Error: 256 color not supported in this terminal!\n";
        std::cerr << "TERM=" << (term != nullptr ? term : "") << '\n';
    }

    return colored_256_supported;
}

int main() {
    if (is_terminal_support_truecolor()) {
        std::cout << "\033[1;32mHello, world! (Truecolor)\033[0m\n";
    } else {
        std::cout << "Hello, world! (No Truecolor)\n";
    }

    if (is_terminal_support_256color()) {
        std::cout << "\033[1;34mHello, world! (256 Colors)\033[0m\n";
    } else {
        std::cout << "Hello, world! (No 256 Colors)\n";
    }

    return std::cout.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}
