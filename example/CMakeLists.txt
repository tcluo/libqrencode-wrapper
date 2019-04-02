
set(EXAMPLE_SRCS example.cpp)

add_executable(example ${EXAMPLE_SRCS})

target_link_libraries(example qrencode_wrapper)

target_link_libraries(example CLI11::CLI11)
