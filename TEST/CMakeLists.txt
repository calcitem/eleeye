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
