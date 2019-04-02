cmake_minimum_required(VERSION 3.12)
project(libqrencode-wrapper)

# CXX
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE Debug)

# Component
add_subdirectory(src)
add_subdirectory(example)
add_subdirectory(ut)

# Third party
add_subdirectory(third_party/libqrencode)
add_subdirectory(third_party/CLI11)
add_subdirectory(third_party/Catch2)

