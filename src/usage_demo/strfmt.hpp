#pragma once

#include <iostream>
#include "common.hpp"
#include "common_util/strfmt.h"

void TestStrfmt()
{
    PrintTitle("strfmt");
    std::cout << "fmt_uint: " << cutl::fmt_uint(12, 5) << std::endl;
    // 180100345), "2d:2h:1m:40s:345ms"
    std::cout << "duration1: " << cutl::fmt_timeduration_s(180100) << std::endl;
    std::cout << "duration2: " << cutl::fmt_timeduration_ms(180100345) << std::endl;
    std::cout << "duration3: " << cutl::fmt_timeduration_us(180100345678) << std::endl;

    // timestamp
    auto curTime = cutl::timestamp(cutl::timeunit::ms);
    std::cout << "current datetime: " << cutl::fmt_timestamp_ms(curTime) << std::endl;

    // format string
    uint8_t a = 0x0f;
    std::cout << "uint8:" << cutl::to_hex(a) << std::endl;
    uint16_t b = 0xfc;
    std::cout << "uint16:" << cutl::to_hex(b) << std::endl;
    uint32_t c = 0x1b02aefc;
    std::cout << "uint32:" << cutl::to_hex(c) << std::endl;
    uint64_t d = 0xabcdef0123456789;
    std::cout << "uint64:" << cutl::to_hex(d) << std::endl;
    uint8_t bytes[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10};
    std::cout << "bytes:" << cutl::to_hex(static_cast<const uint8_t *>(bytes), 16) << std::endl;
}