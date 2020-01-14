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
#ifdef _MSC_VER
    unsigned long index = 0;
    _BitScanForward(&index, Operand);
    return index;
#else
    assert(false);
#endif
}

inline int Bsr(uint32_t Operand)
{
#ifdef _MSC_VER
    unsigned long index = 0;
    _BitScanReverse(&index, Operand);
    return index;
#else
    assert(false);
#endif
}

inline uint64_t TimeStampCounter()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}
