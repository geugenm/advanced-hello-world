#include <iostream>

int main() {
    std::cout << "\033[1;32mHello, world!\033[0m" << std::endl;

    return std::cout.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}


