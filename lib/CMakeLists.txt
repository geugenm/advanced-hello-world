cmake_minimum_required(VERSION 3.5.0)

project(advanced.library LANGUAGES CXX)


set(STATIC_NAME ${PROJECT_NAME}.static)

add_library(${STATIC_NAME} STATIC)

target_sources(${STATIC_NAME}
        PRIVATE
        src/hello.cpp)

target_include_directories(${STATIC_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)


set(DYNAMIC_NAME ${PROJECT_NAME}.dynamic)

add_library(${DYNAMIC_NAME} SHARED)

target_sources(${DYNAMIC_NAME}
        PRIVATE
        src/hello.cpp)

target_include_directories(${DYNAMIC_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
