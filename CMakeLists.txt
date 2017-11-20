cmake_minimum_required(VERSION 3.8)
project(Othello)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.cpp Board.h Cell.h ClassicRules.cpp ClassicRules.h ConsoleBoard.cpp ConsoleBoard.h ConsoleToken.cpp ConsoleToken.h ConsoleTokenFactory.cpp ConsoleTokenFactory.h GameFlow.cpp GameFlow.h GameRules.h Player.h RealPlayer.cpp RealPlayer.h Token.cpp Token.h TokenFactory.h Tools.h BoardGraphic.h Player.cpp AIPlayer.cpp AIPlayer.h BoardGraphic.cpp)
add_executable(Othello ${SOURCE_FILES})