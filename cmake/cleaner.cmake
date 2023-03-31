# Add custom targets for formatting, linting, and other checks
find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
    add_custom_target(format
            COMMAND ${CLANG_FORMAT} -i ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/include/*.hpp ${PROJECT_SOURCE_DIR}/test/*.cpp
            COMMENT "Formatting code..."
            )
endif ()

find_program(CPPLINT "cpplint")
if (CPPLINT)
    add_custom_target(lint
            COMMAND ${CPPLINT} --recursive ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/include/*.hpp ${PROJECT_SOURCE_DIR}/test/*.cpp
            COMMENT "Linting code..."
            )
endif ()

find_program(CLANG_TIDY "clang-tidy")
if (CLANG_TIDY)
    add_custom_target(tidy
            COMMAND ${CLANG_TIDY} ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/include/*.hpp ${PROJECT_SOURCE_DIR}/test/*.cpp -- -std=c++17
            COMMENT "Checking code with clang-tidy..."
            )
endif ()
