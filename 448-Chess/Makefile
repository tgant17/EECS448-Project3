chess: main.o king.o pawn.o queen.o rook.o knight.o bishop.o board.o game.o
	g++ -std=c++11 -g -Wall main.o king.o pawn.o queen.o rook.o knight.o bishop.o board.o game.o -o chess

main.o: main.cpp chessPieceInterface.h king.h pawn.h queen.h rook.h knight.h bishop.h game.h
	g++ -std=c++11 -g -Wall -c main.cpp

game.o: game.h game.cpp
		g++ -std=c++11 -g -Wall -c game.cpp 

king.o: king.h king.cpp
		g++ -std=c++11 -g -Wall -c king.cpp 

pawn.o: pawn.h pawn.cpp
		g++ -std=c++11 -g -Wall -c pawn.cpp 

queen.o: queen.h queen.cpp
		g++ -std=c++11 -g -Wall -c queen.cpp 

rook.o: rook.h rook.cpp
		g++ -std=c++11 -g -Wall -c rook.cpp 

knight.o: knight.h knight.cpp
		g++ -std=c++11 -g -Wall -c knight.cpp 

bishop.o: bishop.h bishop.cpp
		g++ -std=c++11 -g -Wall -c bishop.cpp

board.o: board.h board.cpp
	g++ -std=c++11 -g -Wall -c board.cpp

clean:
	rm *.o chess