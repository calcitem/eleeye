cmake_minimum_required(VERSION 3.12)

set(ROOT ${CMAKE_CURRENT_SOURCE_DIR})

#MESSAGE("ROOT ${ROOT}")

#buid type
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Setting build type to 'Debug' as none was specified.")
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

#output dirs
#MESSAGE("CMAKE_CONFIGURATION_TYPES ${CMAKE_CONFIGURATION_TYPES}")
#MESSAGE("CMAKE_GENERATOR_PLATFORM ${CMAKE_GENERATOR_PLATFORM}")
#MESSAGE("CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE}")
if(WIN32)
    if("${CMAKE_GENERATOR_PLATFORM}" STREQUAL "x64")
        MESSAGE("64 bits compiler detected")
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT}/\@bin)
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT}/\@lib)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ROOT}/\@lib)
    else()
        MESSAGE("32 bits compiler detected")
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT}/\@bin_x86)
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT}/\@lib_x86)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ROOT}/\@lib_x86)
    endif()
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT}/\@bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT}/\@lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ROOT}/\@lib)
endif()


if(APPLE)

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
   string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
   set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${ROOT}/\@bin)
   set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${ROOT}/\@lib)
   set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${ROOT}/\@lib)
endforeach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})

set(CMAKE_XCODE_ATTRIBUTE_WARNING_CFLAGS "-Wno-int-conversion")

endif()


# include dirs
include_directories(
    ${ROOT}
    ${ROOT}/3rd/include
)

# lib dirs
link_directories(
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)

add_definitions(
    -DLARGEBOARDS
    -DPRECOMPUTED_MAGICS
)


if(WIN32)

SET(CMAKE_STATIC_LINKER_FLAGS "/ignore:4221")
SET(CMAKE_CXX_FLAGS_DEBUG "/std:c++17 /Zc:__cplusplus /MTd /Zi /Od /D \"DEBUG\" /D \"_DEBUG\" /WX")
SET(CMAKE_CXX_FLAGS_RELEASE "/std:c++17 /Zc:__cplusplus /MT /O2 /D \"NDEBUG\"")
set(_WIN32_WINNT 0x0502 CACHE STRING "Define Windows API version to use.")

add_definitions(
    /D_CRT_SECURE_NO_WARNINGS
    /wd4251 # 'identifier' : class 'type' needs to have dll-interface to be used by clients of class 'type2'
    /wd4819 # code page
    /wd4267 # 'var' : conversion from 'size_t' to 'type', possible loss of data
    /wd4244 # 'conversion' conversion from 'type1' to 'type2', possible loss of data
)

else()

SET(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG -D_DEBUG")
SET(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

add_definitions(
    -std=c++17
)

endif()

# solution name
project(xq)

add_subdirectory(3rd)
add_subdirectory(base)
add_subdirectory(eleeye)
add_subdirectory(TEST)
