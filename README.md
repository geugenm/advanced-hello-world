<h1 align="center">Advanced Hello World</h1>

<div align="center" style="text-align: center;">
  <div>
    <a href="https://github.com/geugenm/advanced-hello-world/issues">
      <img src="https://img.shields.io/github/issues-raw/geugenm/advanced-hello-world?style=for-the-badge" alt="GitHub Issues">
    </a>
    <img src="https://img.shields.io/badge/platform-linux%20-informational?style=for-the-badge&amp;logo=appveyor" alt="Platforms">
    <a href="https://en.cppreference.com/w/cpp/17">
      <img src="https://img.shields.io/badge/cpp-17-informational?style=for-the-badge&amp;logo=cplusplus" alt="CPP version">
    </a>
  </div>
  <div>
    <a href="https://github.com/geugenm/advanced-hello-world/actions/workflows/ubuntu-latest.yml">
        <img src="https://img.shields.io/github/actions/workflow/status/geugenm/advanced-hello-world/ubuntu-latest.yml?logo=ubuntu&style=for-the-badge" alt="Build status on ubuntu">
    </a>
  </div>
</div>




Welcome to the Advanced Hello World repository! This is a simple project written in C++ that demonstrates the use of
CMake libraries and CTest for testing.

## What is Advanced Hello World?

Advanced Hello World is a C++ program that prints the message "Hello, world!" to the console or screen. However, this
program is not your typical "Hello, world!" program. It has been written using modern C++ features, including system
calls, and demonstrates some of the unique capabilities of the language.

## Getting Started

To run this program, you will need to have CMake installed on your system. Once you have CMake installed, navigate to
the directory of the program and run the following commands:

```bash
mkdir build
cd build
cmake ..
make
```

This will build the program and run it, printing "Hello, world!" to the console.

## Testing

This repository also includes CTest for testing the program. To run the tests, navigate to the build directory and run
the following command:

```bash 
ctest
```

This will run the tests and output the results to the console.

## Contributing

If you would like to contribute to this project, feel free to fork the repository and submit a pull request with your
changes. Contributions are always welcome, whether it's an improvement to the existing program or a new program in a
different language.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

Thanks to the developers of CMake and CTest for providing the tools necessary to build and test this program. Also,
thanks to the open-source community for providing resources and support for C++ development.