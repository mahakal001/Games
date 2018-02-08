#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "grid.h"
#include "player.h"

Player::Player()
{
    //initalize variable
    m_upKey = m_leftKey = m_downKey = m_rightKey = false;
    m_spaceKey = false;
}

void Player::get_reference_to_grid(Grid* grid)
{
    m_grid_reference = grid;

}

void Player::processEvents()
{
    // get the key pressed by player
    m_downKey =  sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    m_upKey    = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    m_leftKey  = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    m_rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

    m_spaceKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void Player::update()
{
    /*
     * Here first we check if the move is valid or not.
     * if move is valid ,then  take action
     * else skip
     */

    if (m_leftKey)
    {
        if(m_grid_reference->ret_zeroTilePos() % 3 != 2)
            m_grid_reference->exchange(m_grid_reference->ret_zeroTilePos()+1);

        m_leftKey = false;
    }
    else if (m_rightKey)
    {
        if(m_grid_reference->ret_zeroTilePos() % 3 != 0)
            m_grid_reference->exchange(m_grid_reference->ret_zeroTilePos()-1);

        m_rightKey = false;
    }
    else if (m_upKey)
    {
        int zeroTilePos = m_grid_reference->ret_zeroTilePos() ;

        if( zeroTilePos != 6 && zeroTilePos != 7 && zeroTilePos != 8 )
            m_grid_reference->exchange(zeroTilePos+3);

        m_upKey = false;
    }
    else if (m_downKey)
    {
        int zeroTilePos = m_grid_reference->ret_zeroTilePos() ;

        if(zeroTilePos != 0 && zeroTilePos != 1 && zeroTilePos != 2 )
            m_grid_reference->exchange(zeroTilePos-3);

        m_downKey = false;
    }
}
