cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(AmberFoxProject VERSION 0.1 LANGUAGES CXX)

add_executable(${PROJECT_NAME})

add_subdirectory(Source)
