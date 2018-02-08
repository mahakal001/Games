#include "character.h"

class Player : public Character 
{
public:
    Player();
    ~Player(){};
    void processEvents();
    void  update(sf::Time deltaTime);
    void appearance();
    void responde_to_player_input(float acc);
    void set_trajectory(float,float);

private: 
    bool upKey,leftKey,rightKey,downKey;

};


class Enemy : public Character
{
public:
    ~Enemy();
    Enemy();
    void set_trajectory(float,float);
    void setVelocity();
    void  update(sf::Time deltaTime);
    void appearance();
};


