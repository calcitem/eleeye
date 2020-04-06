# solution name
project(TEST)

set (eleeye_sources
    ../eleeye/pregen.cpp
    ../eleeye/position.cpp
    ../eleeye/genmoves.cpp
)

set (cchess_sources
    ../cchess/cchess.cpp
    ../cchess/pgnfile.cpp
)

add_executable(unittest
    ${eleeye_sources}
    unittest.cpp
)

add_executable(maketest
    ${eleeye_sources}
    ${cchess_sources}
    maketest.cpp
)

add_executable(uccitest
    ${eleeye_sources}
    uccitest.cpp
)
target_link_libraries(uccitest
    base
)


file(GLOB tests_SRCS "./tests/*.cpp")
file(GLOB tests_INCS "./tests/*.h")

add_executable(run_tests
    run_tests.cpp
    ${eleeye_sources}
    ${tests_SRCS} ${tests_INCS}
)
target_link_libraries(run_tests
    base
    gtest
)
source_group("" FILES run_tests.cpp)
source_group("eleeye" FILES ${eleeye_sources})
source_group("tests" FILES ${tests_SRCS} ${tests_INCS})

