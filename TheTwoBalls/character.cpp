#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include "character.h"

Character::Character(){}

void Character::registerWindowSize(unsigned int width,unsigned int height)
{
    using namespace std;
    window_width = width;
    window_height = height;
    cout << window_width << "   " << window_height << endl ;
}

void Character::ballWorld(){
    using namespace  std;
    boundry_size = 5.f ;
    apparent_boundry = m_radius + boundry_size;
    min_allowed_x  = apparent_boundry;
    min_allowed_y  = apparent_boundry;
    max_allowed_x  = window_width - apparent_boundry ;
    max_allowed_y  = window_height - apparent_boundry;
}

float Character::setAngle(float new_angle){
    angle = new_angle;
}

float Character::retRadius(){
    return m_radius ;
}

float Character::getXpos(){
    return _shape.getPosition().x ;
}

float Character::getYpos(){
    return _shape.getPosition().y ;
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const	{
    target.draw(_shape,states);
}

void Character::reset_pos_and_angle(float new_angle,float newXpos,float newYpos){
    hasCollide = true;
    angle = new_angle;
    _shape.setPosition(newXpos,newYpos);
}

void Character::collision (int window_width,int window_height)
{
    float x = _shape.getPosition().x ;
    float y = _shape.getPosition().y ;
    float new_angle ;

    hasCollide = false;

    if(x  < min_allowed_x)
    {
        new_angle = 180 - angle ;
        reset_pos_and_angle(new_angle,min_allowed_x,y);
    }
    else if(x > max_allowed_x)
    {
        new_angle = 180 - angle ;
        reset_pos_and_angle(new_angle,max_allowed_x,y);
    }
    else if( y < min_allowed_y )
    {
        new_angle = -angle;
        reset_pos_and_angle(new_angle,x,min_allowed_y);
    }
    else if(y   > max_allowed_y)
    {
        new_angle = -angle;
        reset_pos_and_angle(new_angle,x,max_allowed_y);
    }
}

void Character::setMusic(const std::string musicFilePath)
{
    using String = std::basic_string<char>;
    String bw_col_music_file{musicFilePath};
    bw_col_sound_buf.loadFromFile(bw_col_music_file);
    bw_col_sound.setBuffer(bw_col_sound_buf);
}
