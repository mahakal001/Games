#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <unistd.h>
#include "grid.h"
#include "player.h"
#include "game.h"

Game::Game():m_grid(),m_player(),m_window(sf::VideoMode(32*32 , 32*20), "The 8 Puzzle",sf::Style::Default) {
    m_player.get_reference_to_grid(&m_grid);     // sending grid environment to player
}

void Game::run()
{
    while (m_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;

    while(m_window.pollEvent(event)) // extract event from the event queue
    {
        if (event.type == sf::Event::Closed)
            m_window.close();
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
                m_window.close();
            m_player.processEvents(); // process player events
        }
    }
}

void Game::update()
{
    m_player.update();  //update player
    m_grid.update();    // update grid

    /* if grid has changed then test for win */
    if(m_grid.has_gridChange())
        if( m_grid.test_for_win() )
        {
            std::cout << " Congo, the grid got its final state " << std::endl ;
            std::cout << " total move taken " << m_grid.ret_totalMoveByPlayer() << std::endl;
            exit(EXIT_SUCCESS);
        }
}

void Game::render() {
    m_window.clear(sf::Color(76,69,50,255)); //clear window with specified color
    m_window.draw(m_grid); // draw grid
    m_window.display();  // display grid
}

