#pragma once

#include "base.h"
#include <filesystem>

inline const int PATH_MAX_CHAR = 1024;

inline void Idle(void)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

inline bool AbsolutePath(const char* sz)
{
    return std::filesystem::path(sz).is_absolute();
}

inline void LocatePath(char* szDst, const char* szSrc)
{
    if (AbsolutePath(szSrc)) {
        strcpy(szDst, szSrc);
    } else {
        auto current_path = std::filesystem::current_path();
        current_path.append(szSrc);
        strcpy(szDst, current_path.string().c_str());
    }
}
