# solution name
project(xqftools)

file(GLOB SRCS "./*.cpp")
file(GLOB INCS "./*.h")

set (eleeye_sources
    ../eleeye/pregen.cpp
    ../eleeye/position.cpp
    ../eleeye/genmoves.cpp
)

set (cchess_sources
    ../cchess/cchess.cpp
    ../cchess/pgnfile.cpp
)

set(RESOURCES "")
if (WIN32)
list(APPEND RESOURCES ${RES}/MXQFCONV.RC)
endif()

add_definitions(-DMXQFCONV_EXE)

add_executable(mxqfconv WIN32
    ${SRCS} ${INCS}
    ${eleeye_sources}
    ${cchess_sources}
    ${RESOURCES}
)

# link libs
target_link_libraries(mxqfconv
    base
)

source_group("" FILES ${SRCS} ${INCS})
source_group("eleeye" FILES ${eleeye_sources})
source_group("cchess" FILES ${cchess_sources})
source_group("res" FILES ${RESOURCES})
