cmake_minimum_required(VERSION 3.20)

project(PasswordManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenSSL REQUIRED)

add_executable(PasswordManager
    src/main.cpp
    src/password_manager.cpp
    src/tools.cpp
    src/verification.cpp
)

target_link_libraries(PasswordManager PRIVATE OpenSSL::Crypto)
target_include_directories(PasswordManager PRIVATE include)