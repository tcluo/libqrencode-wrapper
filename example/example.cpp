#include "qrencode_wrapper.h"
#include "CLI/CLI.hpp"
#include <iostream>
#include <set>

int main(int argc, const char **argv)
{
    std::string str;
    std::string qr_mode;
    CLI::App app("Example program of libqrencode wrapper");

    try
    {
        // Parse arguments
        app.add_option("-s,--string", str, "String to encode")->required();
        app.add_set("-m,--mode", qr_mode, {"ansi", "utf8"}, "QRcode mode", true);
        app.parse(argc, argv);

        // Convert string to QRcode
        QRcodeWrapper qrcode(str);

        // Display QR code
        if (qr_mode == "utf8")
            qrcode.display_by_unicode();
        else
            qrcode.display_by_ansi();
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }
	
	return 0;
}
