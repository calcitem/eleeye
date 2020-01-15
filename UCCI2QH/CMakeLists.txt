# solution name
project(ucci2qh)

set (eleeye_sources
    ../eleeye/pregen.cpp
    ../eleeye/position.cpp
    ../eleeye/genmoves.cpp
)

set(RESOURCES "")
if (WIN32)
list(APPEND RESOURCES ${RES}/UCCI2QH.RC)
endif()

add_executable(ucci2qh
    ucci2qh.cpp
    ${eleeye_sources}
    ${RESOURCES}
)

# link libs
target_link_libraries(ucci2qh
    base
)

source_group("" FILES ${SRCS} ${INCS})
source_group("eleeye" FILES ${eleeye_sources})
source_group("res" FILES ${RESOURCES})
