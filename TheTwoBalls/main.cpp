#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "players.h"
#include "boundry.h"
#include "game.h"

int main(int argc,char* argv[])
{
    Game game;
    game.run(60);
    return 0;
}//main
