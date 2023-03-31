if (NOT WIN32 AND NOT UNIX AND NOT APPLE)
    message(FATAL_ERROR "Platform not supported")
endif()