# solution name
project(eleeye)

file(GLOB SRCS "./*.cpp")
file(GLOB INCS "./*.h")

add_executable(eleeye
    ${SRCS} ${INCS}
)

# link libs
target_link_libraries(eleeye
    base
)

source_group("" FILES ${SRCS} ${INCS})
