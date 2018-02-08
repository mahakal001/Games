#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <unistd.h>
#include <iostream>
#include <math.h>
#include "players.h"

Player::Player()
{
    appearance();
    setMusic("resources/ball.wav");

    hasCollide  = false;
}

void Player::appearance()
{
    _shape.setRadius(15.f);
    m_radius = _shape.getRadius();
    _shape.setPosition(350,350);
    _shape.setFillColor(sf::Color::White);
    _shape.setOrigin(m_radius,m_radius);
}


void Player::set_trajectory (float angleToSet,float acc)
{
    angle = angleToSet;
    float r_angle = (angleToSet  * M_PI) / 180 ;
    _velocity = sf::Vector2f(std::cos(r_angle),std::sin(r_angle)) * acc ;
}

void Player::responde_to_player_input(float acc)
{
    if(rightKey)
        set_trajectory(0,acc);
    else if(downKey)
        set_trajectory(90,acc);
    else if(leftKey)
        set_trajectory(180,acc);
    else if(upKey)
        set_trajectory(270,acc);

    return;
}

void Player::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    float acc = 50000*seconds ;

    if(hasCollide)
    {
        bw_col_sound.play();
        set_trajectory(angle,acc);
    }
    else
        responde_to_player_input(acc);

    _shape.move(seconds * _velocity);

    return;
}

void Player::processEvents()
{
    downKey =  sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    upKey    = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    leftKey  = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

