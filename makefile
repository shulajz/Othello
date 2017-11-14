# Shulamit Ajzner
# 313485690

a.out: Board.o BoardGraphic.h Cell.h ClassicRules.o ConsoleBoard.o ConsoleToken.o ConsoleTokenFactory.o GameFlow.o GameRules.h Player.o RealPlayer.o Token.o TokenFactory.h main.o
	g++ Board.o BoardGraphic.h Cell.h ClassicRules.o ConsoleBoard.o ConsoleToken.o ConsoleTokenFactory.o GameFlow.o GameRules.h Player.o RealPlayer.o Token.o main.o
Board.o: Board.cpp Board.h
	g++ -c Board.cpp
ClassicRules.o: ClassicRules.cpp ClassicRules.h
	g++ -c ClassicRules.cpp
ConsoleBoard.o: ConsoleBoard.cpp ConsoleBoard.h
	g++ -c ConsoleBoard.cpp
ConsoleToken.o: ConsoleToken.cpp ConsoleToken.h
	g++ -c ConsoleToken.cpp
ConsoleTokenFactory.o: ConsoleTokenFactory.cpp ConsoleTokenFactory.h
	g++ -c ConsoleTokenFactory.cpp
GameFlow.o: GameFlow.cpp GameFlow.h
	g++ -c GameFlow.cpp
Player.o: Player.cpp Player.h
	g++ -c Player.cpp
RealPlayer.o: RealPlayer.cpp RealPlayer.h
	g++ -c RealPlayer.cpp
Token.o: Token.cpp Token.h
	g++ -c Token.cpp
main.o: main.cpp 
	g++ -c main.cpp
