all: character.o boundry.o enemy.o  main.o player.o game.o main 

main.o: main.cpp player.cpp players.h game.h game.cpp
	gcc -c main.cpp

character.o: character.h character.cpp
	gcc -c character.cpp

player.o: player.cpp players.h character.h character.cpp
	gcc -c player.cpp

game.o: game.cpp game.h player.cpp players.h
	gcc -c game.cpp

enemy.o: enemy.cpp  players.h character.h character.cpp  
	gcc -c enemy.cpp

boundry.o: boundry.cpp boundry.h
	gcc -c boundry.cpp


main: *h *cpp
	g++ -O3 -Wall -g -o main *o -lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window -lm
