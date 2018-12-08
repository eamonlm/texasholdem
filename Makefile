#Makefile for the Texas Hold Em program

runHoldEm: holdem.o table.o player.o
	g++ -c -std=c++11 holdem.o table.o player.o -o runHoldEm

holdEm.o: holdme.cpp
	g++ -c -std=c++11 holdem.cpp -o holdem.o

table.o: table.cpp table.h
	g++ -c -std=c++11 table.cpp -o table.o

player.o: player.cpp player.h
	g++ -c -std=c++11 player.cpp -o player.o
