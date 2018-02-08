#include <SFML/Graphics.hpp>
#include "boundry.h"
#include <iostream>

Boundry::Boundry(int width,int height,int x_position,int y_position)
{
    m_boundry.setSize(sf::Vector2f(width,height));
    m_boundry.setPosition(x_position,y_position);
    m_boundry.setFillColor(sf::Color::Cyan);
}

void Boundry::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_boundry,states);
}

