#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "qrencode_wrapper.h"

TEST_CASE("Display by ansi", "[qrcode]")
{
    QRcodeWrapper qw("123");
    CHECK_NOTHROW(qw.display_by_ansi());
    CHECK_NOTHROW(qw.display_by_unicode());
}



