#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    std::string message = "Hello, world!\n";
    std::cout << message; // print the message to the console

    pid_t pid = fork(); // create a child process
    if (pid == -1) { // check if fork() failed
        std::cerr << "fork() failed!\n";
        return EXIT_FAILURE;
    } else if (pid == 0) { // child process
        long result = syscall(SYS_write, 1, message.c_str(), message.length()); // check if the message was printed
        if (result == -1) { // check if syscall() failed
            std::cerr << "syscall() failed!\n";
            return EXIT_FAILURE;
        } else {
            return EXIT_SUCCESS;
        }
    } else { // parent process
        int status;
        waitpid(pid, &status, 0); // wait for the child process to finish
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            std::cout << "Message was printed to the console!\n";
        } else {
            std::cerr << "Message was not printed to the console!\n";
        }
    }

    return 0;
}
