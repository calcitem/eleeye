# solution name
project(uccileag)

file(GLOB SRCS "./*.cpp")
file(GLOB INCS "./*.h")

set (eleeye_sources
    ../eleeye/pregen.cpp
    ../eleeye/position.cpp
    ../eleeye/genmoves.cpp
    ../eleeye/book.cpp
)

set (cchess_sources
    ../cchess/cchess.cpp
    ../cchess/pgnfile.cpp
)

set(RESOURCES "")
if (WIN32)
list(APPEND RESOURCES ${RES}/UCCILEAG.RC)
endif()

add_executable(uccileag
    ${SRCS} ${INCS}
    ${eleeye_sources}
    ${cchess_sources}
    ../codec/base64/base64.CPP
    ${RESOURCES}
)

# link libs
target_link_libraries(uccileag
    base
)

source_group("" FILES ${SRCS} ${INCS})
source_group("eleeye" FILES ${eleeye_sources})
source_group("cchess" FILES ${cchess_sources})
source_group("res" FILES ${RESOURCES})
