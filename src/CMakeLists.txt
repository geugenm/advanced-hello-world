# Set the source files for the library or executable target
set(SOURCES
        main.cpp
        )


# Define a library target using the source files
add_library(MyLibrary ${SOURCES})

# Set the include directories for the library target
target_include_directories(MyLibrary PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        # Add any additional include directories here as needed
        )

# Set any compile definitions for the library target
target_compile_definitions(MyLibrary PRIVATE
        MY_DEFINE_1
        MY_DEFINE_2
        # Add any additional compile definitions here as needed
        )

# Set any compile options for the library target
target_compile_options(MyLibrary PRIVATE
        -Wall
        -Wextra
        # Add any additional compile options here as needed
        )



# Define an executable target using the source files
add_executable(MyExecutable main.cpp ${SOURCES})

# Set the include directories for the executable target
target_include_directories(MyExecutable PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        # Add any additional include directories here as needed
        )

# Set any compile definitions for the executable target
target_compile_definitions(MyExecutable PRIVATE
        MY_DEFINE_1
        MY_DEFINE_2
        # Add any additional compile definitions here as needed
        )

# Set any compile options for the executable target
target_compile_options(MyExecutable PRIVATE
        -Wall
        -Wextra
        # Add any additional compile options here as needed
        )
