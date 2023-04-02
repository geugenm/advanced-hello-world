#include <iostream>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#endif

bool has_color_support() {
#ifdef _WIN32
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (handle == INVALID_HANDLE_VALUE) {
        return false;
    }

    DWORD mode = 0;
    if (!GetConsoleMode(handle, &mode)) {
        return false;
    }

    return (mode & ENABLE_VIRTUAL_TERMINAL_PROCESSING) != 0;
#else
    const char *term = std::getenv("COLORTERM");
    return term != nullptr;
#endif
}

int main() {
    if (has_color_support()) {
        std::cout << "\033[1;32mHello, world!\033[0m" << std::endl;
    } else {
        std::cout << "Hello, world!" << std::endl;
    }

    return std::cout.good() ? EXIT_SUCCESS : EXIT_FAILURE;
}
