# Use a lightweight base image
FROM ubuntu:latest

# Set the working directory to /app
WORKDIR /app

# Install necessary dependencies
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    clang \
    cmake \
    git \
    wget

# Copy the source code into the container
COPY . /app

# Set the compiler flags
ENV CXXFLAGS="-std=c++17 -Wall -Wextra -pedantic -Werror"

# Build the project
RUN mkdir build && \
    cd build && \
    cmake .. && \
    make

# Run tests
RUN cd build && \
    ctest --verbose

# Set the entrypoint to an interactive shell
CMD ["/bin/bash"]
