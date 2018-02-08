all:  main.o grid.o  player.o game.o  main

main.o: main.cpp  game.h game.cpp
	gcc -c main.cpp

player.o: player.cpp player.h grid.cpp grid.h
	gcc -c player.cpp

game.o: game.cpp game.h
	gcc -c game.cpp

grid.o: grid.cpp grid.h
	gcc -c grid.cpp

main: *h *cpp
	g++ -Wall -g -o main *o -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window
