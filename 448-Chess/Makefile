chess: main.o king.o board.o 
	g++ -std=c++11 -g -Wall main.o king.o board.o -o chess

main.o: main.cpp chessPieceInterface.h king.h
	g++ -std=c++11 -g -Wall -c main.cpp

king.o: king.h king.cpp
		g++ -std=c++11 -g -Wall -c king.cpp 

board.o: board.h board.cpp
	g++ -std=c++11 -g -Wall -c board.cpp

clean:
	rm *.o chess