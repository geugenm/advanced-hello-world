#include <iostream>
#include <fstream>

int main() {
    const std::string fileName = "output.txt";

    // Try to open the file for writing
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing!\n";
        return EXIT_FAILURE;
    }

    // Save the original streambuf and redirect the output to the file
    std::streambuf *originalStreambuf = std::cout.rdbuf();
    std::cout.rdbuf(file.rdbuf());

    // Write to std::cout, which will now write to the file
    std::cout << "Hello, world!\n";

    // Restore the original streambuf and close the file
    std::cout.rdbuf(originalStreambuf);
    file.close();

    // Try to read from the file to make sure it was redirected properly
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading!\n";
        return EXIT_FAILURE;
    }

    std::string line;
    std::getline(inFile, line);
    if (line != "Hello, world!") {
        std::cerr << "Error: output was not redirected to file properly!\n";
        return EXIT_FAILURE;
    }

    // Delete the file and exit successfully
    inFile.close();
    if (remove(fileName.c_str()) != EXIT_SUCCESS) {
        std::cerr << "Error deleting file!\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
