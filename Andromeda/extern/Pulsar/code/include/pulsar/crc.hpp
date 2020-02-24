#pragma once

#include <cstring>
#include <cstdint>
#include <iostream>

namespace Pulsar
{

    // Generate CRC lookup table
    template <unsigned c, int k = 8>
    struct intern_crc32_f : intern_crc32_f<((c & 1) ? 0xedb88320 : 0) ^ (c >> 1), k - 1> {};
    template <unsigned c> struct intern_crc32_f<c, 0> { enum { value = c }; };

#define INTERN_PULSAR_CRC32_A(x) INTERN_PULSAR_CRC32_B(x) INTERN_PULSAR_CRC32_B(x + 128)
#define INTERN_PULSAR_CRC32_B(x) INTERN_PULSAR_CRC32_C(x) INTERN_PULSAR_CRC32_C(x +  64)
#define INTERN_PULSAR_CRC32_C(x) INTERN_PULSAR_CRC32_D(x) INTERN_PULSAR_CRC32_D(x +  32)
#define INTERN_PULSAR_CRC32_D(x) INTERN_PULSAR_CRC32_E(x) INTERN_PULSAR_CRC32_E(x +  16)
#define INTERN_PULSAR_CRC32_E(x) INTERN_PULSAR_CRC32_F(x) INTERN_PULSAR_CRC32_F(x +   8)
#define INTERN_PULSAR_CRC32_F(x) INTERN_PULSAR_CRC32_G(x) INTERN_PULSAR_CRC32_G(x +   4)
#define INTERN_PULSAR_CRC32_G(x) INTERN_PULSAR_CRC32_H(x) INTERN_PULSAR_CRC32_H(x +   2)
#define INTERN_PULSAR_CRC32_H(x) INTERN_PULSAR_CRC32_I(x) INTERN_PULSAR_CRC32_I(x +   1)
#define INTERN_PULSAR_CRC32_I(x) intern_crc32_f<x>::value ,

    constexpr unsigned intern_crc_table[] = { INTERN_PULSAR_CRC32_A(0) };

    // Constexpr implementation and helpers
    constexpr uint32_t crc32_impl(const uint8_t* p, size_t len, uint32_t crc) {
        return len ?
            crc32_impl(p + 1, len - 1, (crc >> 8) ^ intern_crc_table[(crc & 0xFF) ^ *p])
            : crc;
    }

    constexpr uint32_t crc32(const uint8_t* data, size_t length, uint32_t seed = ~0) {
        return ~crc32_impl(data, length, seed);
    }

#define PULSAR_CRC32(key, size) Pulsar::crc32((uint8_t*)key, size)
#define PULSAR_SEDDED_CRC32(key, size, seed) Pulsar::crc32((uint8_t*)key, size, seed)
}