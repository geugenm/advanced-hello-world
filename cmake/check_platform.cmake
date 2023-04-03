# Check if we're running on a Linux or Android platform
if (NOT UNIX AND NOT ANDROID)
    message(FATAL_ERROR "Platform is not supported!")
else ()
    message(STATUS "Platform is compatible!")
endif ()
