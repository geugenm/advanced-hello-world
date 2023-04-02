# Add custom targets for formatting, linting, and other checks
include(cmake/code-quality-tools/enable-clang-format.cmake)
include(cmake/code-quality-tools/enable-clang-tidy.cmake)
include(cmake/code-quality-tools/enable-linter.cmake)