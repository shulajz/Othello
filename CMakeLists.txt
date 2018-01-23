cmake_minimum_required(VERSION 3.8)
project(Othello)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)



set(SOURCE_TEST_FILES ex4/src/client/gtest_src/main_test.cpp
        ex4/src/client/gtest_src/Test_board.cpp
        ex4/src/client/gtest_src/Test_board.h
        ex4/src/client/gtest_src/Test_classicRules.cpp
        ex4/src/client/gtest_src/Test_classicRules.h
        ex4/src/client/gtest_src/Test_AIPlayer.cpp
        ex4/src/client/gtest_src/Test_AIPlayer.h)

set(OTHELLO_MAIN ex4/src/client/src/main )
set(SOURCE_FILES ex4/src/client/src/GameFlow.cpp
        ex4/src/client/src/GameRules.h
        ex4/src/client/src/GameFlow.h
        ex4/src/client/src/Board.cpp
        ex4/src/client/src/Board.h
        ex4/src/client/src/ReversiClient.cpp
        ex4/src/client/src/ReversiClient.h
        ex4/src/client/src/RemotePlayer.cpp
        ex4/src/client/src/RemotePlayer.h
        ex4/src/client/src/Cell.h
        ex4/src/client/src/ClassicRules.cpp
        ex4/src/client/src/ClassicRules.h
        ex4/src/client/src/ConsoleBoard.cpp
        ex4/src/client/src/ConsoleBoard.h
        ex4/src/client/src/ConsoleToken.cpp
        ex4/src/client/src/ConsoleToken.h
        ex4/src/client/src/ConsoleTokenFactory.cpp
        ex4/src/client/src/ConsoleTokenFactory.h
        ex4/src/client/src/Player.h
        ex4/src/client/src/RealPlayer.cpp
        ex4/src/client/src/RealPlayer.h
        ex4/src/client/src/Token.cpp
        ex4/src/client/src/Token.h
        ex4/src/client/src/TokenFactory.h
        ex4/src/client/src/Tools.h
        ex4/src/client/src/BoardGraphic.h
        ex4/src/client/src/Player.cpp
        ex4/src/client/src/AIPlayer.cpp
        ex4/src/client/src/AIPlayer.h
        ex4/src/client/src/BoardGraphic.cpp
        ex4/src/client/src/Menu.cpp
        ex4/src/client/src/Menu.h
        ex4/src/client/src/ConsoleMenu.cpp
        ex4/src/client/src/ConsoleMenu.h)

set(SERVER ex4/src/server/src/ReversiServer.cpp
        ex4/src/server/src/ReversiServer.h
        ex4/src/server/src/main.cpp
        ex4/src/server/src/Command.h
        ex4/src/server/src/CommandsManager.cpp
        ex4/src/server/src/CommandsManager.h
        ex4/src/server/src/CommandStart.cpp
        ex4/src/server/src/CommandStart.h
        ex4/src/server/src/CommandJoin.cpp
        ex4/src/server/src/CommandJoin.h
        ex4/src/server/src/CommandGetList.cpp
        ex4/src/server/src/CommandGetList.h
        ex4/src/server/src/CommandClose.cpp
        ex4/src/server/src/CommandClose.h
        ex4/src/server/src/CommandPlay.cpp
        ex4/src/server/src/CommandPlay.h
        ex4/src/server/src/HandleClientReversi.cpp
        ex4/src/server/src/HandleClientReversi.h
        ex4/src/server/src/GameManager.cpp
        ex4/src/server/src/GameManager.h
        ex4/src/server/src/CommandKillAll.cpp
        ex4/src/server/src/CommandKillAll.h
        ex4/src/server/src/HandleClient.h
        ex4/src/server/src/Task.cpp
        ex4/src/server/src/Task.h
        ex4/src/server/src/ThreadPool.cpp
        ex4/src/server/src/ThreadPool.h)
add_test(runTests runTests)
add_test(Server Server)
add_executable(Server ${OTHELLO_FILES} ${SERVER})
add_executable(Othello ${SOURCE_FILES} ${OTHELLO_MAIN})
add_executable(runTests ${SOURCE_TEST_FILES} ${SOURCE_FILES})
target_link_libraries(runTests gtest gtest_main pthread)
set(CMAKE_CXX_FLAGS -pthread)