# solution name
project(eleeye)

file(GLOB SRCS "./*.cpp")
file(GLOB INCS "./*.h")

set(RESOURCES "")
if (WIN32)
list(APPEND RESOURCES ${RES}/ELEEYE.RC)
endif()

add_executable(eleeye
    ${SRCS} ${INCS}
    ${RESOURCES}
)

# link libs
target_link_libraries(eleeye
    base
)

source_group("" FILES ${SRCS} ${INCS})
source_group("res" FILES ${RESOURCES})
