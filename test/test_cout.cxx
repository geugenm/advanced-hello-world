#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    constexpr std::string_view testMessage = "Hello, world!\n";

    // Create a child process
    pid_t pid = fork();

    // Check if fork() failed
    if (pid == EXIT_FAILURE) {
        std::cerr << "fork() failed!\n";
        return EXIT_FAILURE;
    }

    // Child process
    if (pid == EXIT_SUCCESS) {
        // Print the testMessage using a system call
        long result = syscall(SYS_write, 1, testMessage.data(), testMessage.length());

        // Check if the testMessage was printed
        if (result == EXIT_FAILURE) {
            std::cerr << "syscall() failed!\n";
            return EXIT_FAILURE;
        }
    }
        // Parent process
    else {
        int status;

        // Wait for the child process to finish
        waitpid(pid, &status, 0);

        // Check if the testMessage was printed
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            std::cout << "Message was printed to the console!\n";
        } else {
            std::cerr << "Message was not printed to the console!\n";
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
