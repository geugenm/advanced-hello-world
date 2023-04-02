# Get the version from git tags
execute_process(
        COMMAND git describe --tags --abbrev=0
        OUTPUT_VARIABLE GIT_TAG_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Parse the version number
string(REGEX MATCH "([0-9]+)\\.([0-9]+)\\.([0-9]+)" GIT_TAG_VERSION "${GIT_TAG_VERSION}")
set(PROJECT_VERSION_MAJOR "${CMAKE_MATCH_1}")
set(PROJECT_VERSION_MINOR "${CMAKE_MATCH_2}")
set(PROJECT_VERSION_PATCH "${CMAKE_MATCH_3}")

set(GITHUB_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

if (${GITHUB_VERSION} STREQUAL "..")
    message(WARNING "Cannot parse github version")
    set(GITHUB_VERSION "1.0.0")
endif ()