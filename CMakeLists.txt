cmake_minimum_required(VERSION 3.0)

project(julvm VERSION 0.1 LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)

file(GLOB SOURCES sources/*.cpp)

add_executable(julvm ${SOURCES})

