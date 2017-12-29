# name
# id

server.out: compileAll
	g++ *.o -o ../../exe/server.out
	rm -f *.o

compileAll: src/*.h src/*.cpp
	g++ -c src/*.cpp

