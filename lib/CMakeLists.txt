# Set minimum CMake version required
cmake_minimum_required(VERSION 3.5.0)

# Set project name and language
project(advanced.library LANGUAGES CXX)

# Define static library target
set(STATIC_NAME ${PROJECT_NAME}.static)
add_library(${STATIC_NAME} STATIC
        src/hello.cxx
        )
target_include_directories(${STATIC_NAME}
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include
        )

# Define dynamic library target
set(DYNAMIC_NAME ${PROJECT_NAME}.dynamic)
add_library(${DYNAMIC_NAME} SHARED
        src/hello.cxx
        )
target_include_directories(${DYNAMIC_NAME}
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include
        )

# Install libraries and headers
install(TARGETS ${STATIC_NAME} ${DYNAMIC_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
install(DIRECTORY include/
        DESTINATION include
        )