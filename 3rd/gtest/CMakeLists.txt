project(gtest)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(gtest STATIC ./src/gtest-all.cc)

source_group("" FILES ./src/gtest-all.cc)
