#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "players.h"


static unsigned int enemy_count = 0;

void Enemy::appearance()
{
    _shape.setRadius(30.f);
    m_radius = _shape.getRadius();
    _shape.setOrigin(m_radius,m_radius);
    _shape.setPosition(m_radius+5,m_radius+5);
    _shape.setPointCount(30);
    _shape.setFillColor (sf::Color::Yellow);
}

Enemy::Enemy()
{	
    std::cout << "enemy count" << enemy_count << std::endl ;
    appearance();
    angle = 60.f ;
    enemy_count++;
    hasCollide  = false;
    setMusic("resources/ball.wav");
}

Enemy::~Enemy()
{
    std::cout << "enemy count" << enemy_count << std::endl ;
    enemy_count--;
}

void Enemy::setVelocity(){
    _velocity = sf::Vector2f(0,0);
}

void Enemy::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();
    float r_angle = ((angle * M_PI)/180);

    if (hasCollide){
        bw_col_sound.play();
        _velocity =  sf::Vector2f(std::cos(r_angle),std::sin(r_angle)) * 70000.f * seconds ;
    }
    else
        _velocity += sf::Vector2f(std::cos(r_angle),std::sin(r_angle)) * 100.f * seconds;

    _shape.move(seconds * _velocity);
}


