# solution name
project(base)

file(GLOB SRCS "./*.cpp")
file(GLOB INCS "./*.h")

add_library(base STATIC ${SRCS} ${INCS})

source_group("" FILES ${SRCS} ${INCS})
