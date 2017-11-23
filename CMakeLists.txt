cmake_minimum_required(VERSION 3.8)
project(Othello)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)



set(SOURCE_TEST_FILES gtest_src/main_test.cpp gtest_src/Test_board.cpp gtest_src/Test_board.h)


set(SOURCE_FILES src/main.cpp src/Board.cpp src/Board.h
        src/Cell.h src/ClassicRules.cpp src/ClassicRules.h
        src/ConsoleBoard.cpp src/ConsoleBoard.h src/ConsoleToken.cpp
        src/ConsoleToken.h src/ConsoleTokenFactory.cpp
        src/ConsoleTokenFactory.h src/GameFlow.cpp src/GameFlow.h
        src/GameRules.h src/Player.h src/RealPlayer.cpp src/RealPlayer.h
        src/Token.cpp src/Token.h src/TokenFactory.h src/Tools.h src/BoardGraphic.h
        src/Player.cpp src/AIPlayer.cpp src/AIPlayer.h src/BoardGraphic.cpp
        src/Menu.cpp src/Menu.h src/ConsoleMenu.cpp src/ConsoleMenu.h)


add_executable(Othello ${SOURCE_FILES})
add_executable(runTests ${SOURCE_TEST_FILES})