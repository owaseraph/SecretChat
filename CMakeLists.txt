cmake_minimum_required(VERSION 3.10)

# Project Name
project(SecureChat)

# Use C++17 (Standard for modern C++ features)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(include)

file(GLOB SOURCES "src/*.cpp")


add_executable(SecureChat ${SOURCES})