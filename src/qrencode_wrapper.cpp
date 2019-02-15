#include "qrencode_wrapper.h"
#include <stdexcept>

#define ANSI_RESET       "\x1B[0m"
#define ANSI_BLACKONGREY "\x1B[30;47;27m"
#define ANSI_BLACK       "\x1B[7m"
#define ANSI_WHITE       "\x1B[27m"
#define UTF8_BOTH        "\xE2\x96\x88"
#define UTF8_TOPHALF     "\xE2\x96\x80"
#define UTF8_BOTTOMHALF  "\xE2\x96\x84"

QRcodeWrapper::QRcodeWrapper(const std::string &str)
    : qrcode_(QRcode_encodeString8bit(str.c_str(), 0, QR_ECLEVEL_M), QRcode_free)
{
    if (! qrcode_.get())
        throw std::runtime_error("Failed to generate QR code");
}

QRcodeWrapper::~QRcodeWrapper()
{

}

// [Reference] https://github.com/krayon/libpam-otp/blob/master/src/google-authenticator.c#L239
void QRcodeWrapper::display_by_ansi()
{
    const char *ptr = reinterpret_cast<const char *>(qrcode_->data);

    // Upper border
    for (int i = 0; i < 2; ++i)
    {
        printf(ANSI_BLACKONGREY);
        for (int x = 0; x < qrcode_->width + 4; ++x)
        {
            printf("  ");
        }

        puts(ANSI_RESET);
    }

    // Main body
    for (int x = 0; x < qrcode_->width; ++x)
    {
        printf(ANSI_BLACKONGREY"    ");
        int is_black = 0;
        for (int y = 0; y < qrcode_->width; ++y)
        {
            if (*ptr++ & 1)
            {
                if (! is_black)
                {
                    printf(ANSI_BLACK);
                }

                is_black = 1;
            }
            else
            {
                if (is_black)
                {
                    printf(ANSI_WHITE);
                }

                is_black = 0;
            }

            printf("  ");
        }

        if (is_black)
        {
            printf(ANSI_WHITE);
        }

        puts("    " ANSI_RESET);
    }

    // Lower border
    for (int i = 0; i < 2; ++i)
    {
        printf(ANSI_BLACKONGREY);
        for (int x = 0; x < qrcode_->width + 4; ++x)
        {
            printf("  ");
        }

        puts(ANSI_RESET);
    }
}

// [Reference] https://github.com/krayon/libpam-otp/blob/master/src/google-authenticator.c#L276
void QRcodeWrapper::display_by_unicode()
{
    // Upper border
    printf(ANSI_BLACKONGREY);
    for (int i = 0; i < qrcode_->width + 4; ++i)
    {
        printf(" ");
    }

    puts(ANSI_RESET);

    // Main body
    for (int y = 0; y < qrcode_->width; y += 2)
    {
        printf(ANSI_BLACKONGREY "  ");
        for (int x = 0; x < qrcode_->width; ++x)
        {
            const int top = qrcode_->data[y * qrcode_->width + x] & 1;
            int bottom = 0;
            if (y + 1 < qrcode_->width)
            {
                bottom = qrcode_->data[(y + 1) * qrcode_->width + x] & 1;
            }

            if (top)
            {
                if (bottom)
                {
                    printf(UTF8_BOTH);
                }
                else
                {
                    printf(UTF8_TOPHALF);
                }
            }
            else
            {
                if (bottom)
                {
                    printf(UTF8_BOTTOMHALF);
                }
                else
                {
                    printf(" ");
                }
            }
        }

        puts("  " ANSI_RESET);
    }

    // Lower border
    printf(ANSI_BLACKONGREY);
    for (int i = 0; i < qrcode_->width + 4; ++i)
    {
        printf(" ");
    }

    puts(ANSI_RESET);
}
