cmake_minimum_required(VERSION 3.8)
project(Othello)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)



set(SOURCE_TEST_FILES src/client/gtest_src/main_test.cpp src/client/gtest_src/Test_board.cpp
        src/client/gtest_src/Test_board.h src/client/gtest_src/Test_classicRules.cpp src/client/gtest_src/Test_classicRules.h
        src/client/gtest_src/Test_AIPlayer.cpp src/client/gtest_src/Test_AIPlayer.h)

set(OTHELLO_MAIN src/client/src/main )
set(SOURCE_FILES src/client/src/Board.cpp src/client/src/Board.h
        src/client/src/ReversiClient.cpp src/client/src/ReversiClient.h
        src/client/src/RemotePlayer.cpp src/client/src/RemotePlayer.h
        src/client/src/Cell.h src/client/src/ClassicRules.cpp src/client/src/ClassicRules.h
        src/client/src/ConsoleBoard.cpp src/client/src/ConsoleBoard.h src/client/src/ConsoleToken.cpp
        src/client/src/ConsoleToken.h src/client/src/ConsoleTokenFactory.cpp
        src/client/src/ConsoleTokenFactory.h src/client/src/GameFlow.cpp src/client/src/GameFlow.h
        src/client/src/GameRules.h src/client/src/Player.h src/client/src/RealPlayer.cpp src/client/src/RealPlayer.h
        src/client/src/Token.cpp src/client/src/Token.h src/client/src/TokenFactory.h src/client/src/Tools.h src/client/src/BoardGraphic.h
        src/client/src/Player.cpp src/client/src/AIPlayer.cpp src/client/src/AIPlayer.h src/client/src/BoardGraphic.cpp
        src/client/src/Menu.cpp src/client/src/Menu.h src/client/src/ConsoleMenu.cpp src/client/src/ConsoleMenu.h)

set(SERVER src/server/ReversiServer.cpp src/server/ReversiServer.h src/server/main.cpp)
add_test(runTests runTests)
add_test(Server Server)
add_executable(Server ${OTHELLO_FILES} ${SERVER})
add_executable(Othello ${SOURCE_FILES} ${OTHELLO_MAIN})
add_executable(runTests ${SOURCE_TEST_FILES} ${SOURCE_FILES})
target_link_libraries(runTests gtest gtest_main pthread)
