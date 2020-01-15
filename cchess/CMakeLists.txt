# solution name
project(book)

file(GLOB SRCS "./*.cpp")
file(GLOB INCS "./*.h")

set (eleeye_sources
    ../eleeye/pregen.cpp
    ../eleeye/position.cpp
    ../eleeye/genmoves.cpp
)

set (cchess_sources
    cchess.cpp
    cchess.h
    pgnfile.cpp
    pgnfile.h
)

set(RESOURCES "")
list(APPEND RESOURCES ${RES}/CCHESS.RC)

add_executable(addecco WIN32
    ${SRCS} ${INCS}
    ${eleeye_sources}
    ${cchess_sources}
    ${RESOURCES}
)

source_group("" FILES ${SRCS} ${INCS})
source_group("eleeye" FILES ${eleeye_sources})
source_group("cchess" FILES ${cchess_sources})
source_group("res" FILES ${RESOURCES})
