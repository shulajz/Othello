cmake_minimum_required(VERSION 3.8)
project(Othello)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)



set(SOURCE_TEST_FILES gtest_src/main_test.cpp gtest_src/test_Borad.cpp)

set(SOURCE_FILES src/main.cpp src/Board.cpp
        src/ClassicRules.cpp
        src/ConsoleBoard.cpp src/ConsoleToken.cpp
        src/ConsoleTokenFactory.cpp
        src/GameFlow.cpp
        src/RealPlayer.cpp
        src/Token.cpp
        src/Player.cpp src/AIPlayer.cpp src/BoardGraphic.cpp
        src/Menu.cpp src/ConsoleMenu.cpp src/Cell.h src/TokenFactory.h)


add_executable(Othello ${SOURCE_FILES})
add_executable(runTests ${SOURCE_TEST_FILES})