cmake_minimum_required(VERSION 3.20)

project(PasswordManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(PasswordManager
    src/main.cpp
    src/password_manager.cpp
    src/file_stream.cpp
)

target_include_directories(PasswordManager PRIVATE include)