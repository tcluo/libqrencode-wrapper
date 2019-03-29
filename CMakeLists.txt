cmake_minimum_required(VERSION 2.6)
project(libqrencode-wrapper)

# CXX
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE Debug)


# third party
add_subdirectory(third_party/libqrencode)
add_subdirectory(third_party/CLI11)
add_subdirectory(third_party/Catch2)

# example
include_directories(src third_party/libqrencode third_party/CLI11/include third_party/Catch2/single_include)
set(example_sources example/example.cpp src/qrencode_wrapper.cpp)
add_executable(example ${example_sources})
target_link_libraries(example qrencode)

# unit test
set(ut_sources unit/ut.cpp src/qrencode_wrapper.cpp)
add_executable(ut ${ut_sources})
target_link_libraries(ut qrencode)
