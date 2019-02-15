#pragma once

#include "qrencode.h"
#include <memory>
#include <string>

class QRcodeWrapper
{
public:
    QRcodeWrapper(const std::string &str);
    ~QRcodeWrapper();

    void display_by_ansi();
    void display_by_unicode();

private:
    std::unique_ptr<QRcode, void(*)(QRcode *)> qrcode_;
};
