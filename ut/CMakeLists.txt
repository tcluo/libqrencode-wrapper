
set(UT_SRCS ut.cpp)

add_executable(ut ${UT_SRCS})

target_link_libraries(ut qrencode_wrapper)

target_link_libraries(ut Catch2::Catch2)

