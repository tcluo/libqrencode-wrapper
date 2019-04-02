#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "qrencode_wrapper.h"

TEST_CASE("Display by ASCII", "[qrcode]")
{
    QRcodeWrapper qw("123");
    CHECK_NOTHROW(qw.display_by_ansi());
}

TEST_CASE("Display by Unicode", "[qrcode]")
{
    QRcodeWrapper qw("abc");
    CHECK_NOTHROW(qw.display_by_unicode());
}


