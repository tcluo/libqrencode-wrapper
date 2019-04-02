
set(QRENCODE_WRAPPER_SRCS  qrencode_wrapper.cpp)

set(QRENCODE_WRAPPER_HDRS  qrencode_wrapper.h)

add_library(qrencode_wrapper OBJECT ${QRENCODE_WRAPPER_SRCS} ${QRENCODE_WRAPPER_HDRS})

target_link_libraries(qrencode_wrapper qrencode)

target_include_directories(qrencode_wrapper PUBLIC .)

