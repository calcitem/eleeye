#pragma once

#include <cassert>
#include <chrono>
#include <cstdint>
#include <ctime>
#include <thread>
#include <utility>

#define __ASSERT(a) assert(a)
#define __ASSERT_BOUND(a, b, c) assert((a) <= (b) && (b) <= (c))
#define __ASSERT_BOUND_2(a, b, c, d) assert((a) <= (b) && (b) <= (c) && (c) <= (d))

inline bool EQV(bool bArg1, bool bArg2)
{
    return bArg1 ? bArg2 : !bArg2;
}

inline bool XOR(bool bArg1, bool bArg2)
{
    return bArg1 ? !bArg2 : bArg2;
}

template <typename T>
inline T MIN(T Arg1, T Arg2)
{
    return Arg1 < Arg2 ? Arg1 : Arg2;
}

template <typename T>
inline T MAX(T Arg1, T Arg2)
{
    return Arg1 > Arg2 ? Arg1 : Arg2;
}

template <typename T>
inline T ABS(T Arg)
{
    return Arg < 0 ? -Arg : Arg;
}

template <typename T>
inline T SQR(T Arg)
{
    return Arg * Arg;
}

template <typename T>
inline void SWAP(T& Arg1, T& Arg2)
{
    std::swap(Arg1, Arg2);
}

inline int PopCnt8(uint8_t uc)
{
    int n;
    n = ((uc >> 1) & 0x55) + (uc & 0x55);
    n = ((n >> 2) & 0x33) + (n & 0x33);
    return (n >> 4) + (n & 0x0f);
}

inline int PopCnt16(uint16_t w)
{
    int n;
    n = ((w >> 1) & 0x5555) + (w & 0x5555);
    n = ((n >> 2) & 0x3333) + (n & 0x3333);
    n = ((n >> 4) & 0x0f0f) + (n & 0x0f0f);
    return (n >> 8) + (n & 0x00ff);
}

inline int PopCnt32(uint32_t dw)
{
    int n;
    n = ((dw >> 1) & 0x55555555) + (dw & 0x55555555);
    n = ((n >> 2) & 0x33333333) + (n & 0x33333333);
    n = ((n >> 4) & 0x0f0f0f0f) + (n & 0x0f0f0f0f);
    n = ((n >> 8) & 0x00ff00ff) + (n & 0x00ff00ff);
    return (n >> 16) + (n & 0x0000ffff);
}

inline int64_t GetTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}
