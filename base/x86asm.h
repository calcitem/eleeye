#pragma once
#include "base.h"

#ifdef _MSC_VER
#include <intrin.h>
#endif

inline uint32_t LOW_LONG(uint64_t Operand)
{
    return (uint32_t)Operand;
}

inline uint32_t HIGH_LONG(uint64_t Operand)
{
    return (uint32_t)(Operand >> 32);
}

inline uint64_t MAKE_LONG_LONG(uint32_t LowLong, uint32_t HighLong)
{
    return (uint64_t)LowLong | ((uint64_t)HighLong << 32);
}

inline int Bsf(uint32_t Operand)
{
    assert(Operand);
    //Bsf(12) = 2  1100
#ifdef _MSC_VER
    //https://docs.microsoft.com/zh-cn/cpp/intrinsics/bitscanforward-bitscanforward64?view=vs-2019
    //Search the mask data from least significant bit (LSB) to the most significant bit (MSB) for a set bit (1).
    //Index [out] Loaded with the bit position of the first set bit (1) found
    unsigned long index = 0;
    _BitScanForward(&index, Operand);
    return index;
#elif __GNUC__
    //Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.
    return __builtin_ctz(Operand);
#else
#error "Not implemented"
    assert(false);
#endif
}

inline int Bsr(uint32_t Operand)
{
    //Bsr(12) = 3  1100
#ifdef _MSC_VER
    //https://docs.microsoft.com/zh-cn/cpp/intrinsics/bitscanreverse-bitscanreverse64?view=vs-2019
    //Search the mask data from most significant bit (MSB) to least significant bit (LSB) for a set bit (1).
    //Index [out] Loaded with the bit position of the first set bit (1) found.
    unsigned long index = 0;
    _BitScanReverse(&index, Operand);
    return index;
#elif __GNUC__
    //Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined.
    return 31 - __builtin_clz(Operand);
#else
#error "Not implemented"
    assert(false);
#endif
}

inline uint64_t TimeStampCounter()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}
