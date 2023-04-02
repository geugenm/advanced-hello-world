#include <iostream>
#include <string>

#if defined(_WIN32)
#include <windows.h>
#else

#include <unistd.h>
#include <sys/wait.h>

#endif

int main() {
    constexpr std::string_view testMessage = "Hello, world!\n";

    // Create a child process
#if defined(_WIN32)
    STARTUPINFO startupInfo = {0};
    PROCESS_INFORMATION processInfo = {0};
    if (!CreateProcess(nullptr, const_cast<char*>(testMessage.data()), nullptr, nullptr, FALSE, 0, nullptr, nullptr, &startupInfo, &processInfo)) {
        std::cerr << "CreateProcess() failed!\n";
        return EXIT_FAILURE;
    }
    WaitForSingleObject(processInfo.hProcess, INFINITE);
#else
    pid_t pid = fork();

    // Check if fork() failed
    if (pid == EXIT_FAILURE) {
        std::cerr << "fork() failed!\n";
        return EXIT_FAILURE;
    }

    // Child process
    if (pid == EXIT_SUCCESS) {
        // Print the testMessage using a system call
        const ssize_t result = write(STDOUT_FILENO, testMessage.data(), testMessage.length());

        // Check if the testMessage was printed
        if (result == EXIT_FAILURE) {
            std::cerr << "write() failed!\n";
            return EXIT_FAILURE;
        }
    } else {
        int status;

        // Wait for the child process to finish
        if (waitpid(pid, &status, 0) == EXIT_FAILURE) {
            std::cerr << "waitpid() failed!\n";
            return EXIT_FAILURE;
        }

        // Check if the child process terminated normally
        if (WIFEXITED(status)) {
            // Get the exit status of the child process
            const int exitStatus = WEXITSTATUS(status);

            if (exitStatus == EXIT_SUCCESS) {
                std::cout << "Message was printed to the console!\n";
            } else {
                std::cerr << "Child process exited with status " << exitStatus << '\n';
                return EXIT_FAILURE;
            }
        } else {
            std::cerr << "Child process did not terminate normally!\n";
            return EXIT_FAILURE;
        }
    }
#endif

    return EXIT_SUCCESS;
}
