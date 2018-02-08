#include <iostream>
#include <SFML/Graphics.hpp>

#include <unistd.h>

#include "grid.h"
#include "player.h"
#include "game.h"

int main(int argc,char** argv)
{
    Game game;

    game.run();

    return 0;
}
