
#include "base/base2.h"
#include "base/x86asm.h"
#include "gtest/gtest.h"

TEST(base, bits)
{
    //0000 0000 0000 0000 0000 0000 0000 1100
    ASSERT_EQ(2, Bsf(12));
    ASSERT_EQ(3, Bsr(12));
    ASSERT_EQ(2, PopCnt(12));
    ASSERT_EQ(17, PopCnt(0x4000033333333));
}
