#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <algorithm>
#include <random>
#include "grid.h"

Grid::Grid()
{
    m_tile_width = m_tile_height = 64 ;
    m_total_exchange_made = 0;

    // Load texture file
    if( !m_tileTexture.loadFromFile("media/tiles.png"))
        std::cout << "unable to Download file \n" ;
    
    /* Make sprites having digits from the loaded texture.
     * such that m_spriteArray[i] will have ith digit print on it
     *
 */
    for(auto i=0;i<9;i++) {
        m_spriteArray[i] =  new sf::Sprite( m_tileTexture,
                                            sf::IntRect(i*64,0,m_tile_width,m_tile_height));
    }

    // set the desired final configuration of the grid
    for(auto i=0;i<9;i++)
        m_target_grid[i] = i;

    // set title sprite "The eight puzzle"
    m_gameTitleSprite = sf::Sprite(m_tileTexture,sf::IntRect(0,64,64*9,64));
    m_gameTitleSprite.setPosition(64*4,64*2);

    //initialize grid
    init_grid();
}

void Grid::init_grid()
{
    // create temporary grid
    int tmp[9] = { 7,2,4,5,0,6,8,3,1 };

    // shuffle tmp[] to randomize grid
    //  std:srand(std::time(0));
    //  std::random_shuffle(std::begin(tmp), std::end(tmp));

    // set current grid
    for(auto i=0;i<9;i++) {
        cur_grid[i] = tmp[i];
    }

    // get the position of tile 0
    for(auto i=0;i<9;i++) {
        if ( cur_grid[i] == 0 )
        {
            m_zeroTilePos = i;
            break;
        }
    }
}

void Grid::update(){
    /* Grid::exchange() is hadling the update too*/
}

int Grid::ret_zeroTilePos() {
    return m_zeroTilePos;
}

void Grid::exchange(unsigned int tilePos)
{
    //exchange the content at tilePos and m_zeroTilePos
    cur_grid[m_zeroTilePos] = cur_grid[tilePos] ;
    cur_grid[tilePos] = 0;

    // update m_zeroTilePos
    m_zeroTilePos = tilePos;    //get zero(empty) tile position

    m_has_gridChange = true;   // our grid has changed

    m_total_exchange_made++; // add 1 to total move.

    // print current grid
    for(auto i=0;i<9;i++)
        std::cout << cur_grid[i] << "," ;

    std::cout << "\n";
}

bool Grid::has_gridChange(){
    return m_has_gridChange;
}

unsigned int Grid::ret_totalMoveByPlayer() {
    return m_total_exchange_made ;
}

bool Grid::test_for_win(){
    m_has_gridChange = false;   // reset the m_has_gridChange to false
    for(int i=0 ;i<9;i++)
        if( cur_grid[i] != m_target_grid[i])
            return false;
    /* if we are here means the loop has match*/
    return true;
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    int shiftX = 256 + 62*3 ;
    int shiftY = 256;

    for(auto i=0;i<9;i++) {  // draw grid
        m_spriteArray[cur_grid[i]]->setPosition((i%3)*64 + shiftX,(i/3) * 64 + shiftY) ;
        target.draw(*m_spriteArray[cur_grid[i]],states);
    }
    target.draw(m_gameTitleSprite,states);
}

