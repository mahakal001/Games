#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "players.h"
#include <time.h>
#include "boundry.h"
#include "game.h"

static int col_count=0;

void Game::init_players()
{
    _player.registerWindowSize(window_width,window_height);
    _player.ballWorld();
    _enemy.registerWindowSize(window_width,window_height);
    _enemy.ballWorld();
}

void Game::init_boudry()
{
    b1 =  Boundry(window_width,5,0,0);
    b2 =  Boundry(5,window_height,0,0);
    b3 =  Boundry(window_width,5,0,window_height-5);
    b4 =  Boundry(5,window_height,window_width-5,0);
}

void Game::init_bool_vars()
{
    vsync = true;
    isPause = false;
}

void Game::init_bb_col_music()
{

    using String = std::basic_string<char>;
    String bb_col_music_file{"resources/explos.wav"};
    bb_col_sound_buf.loadFromFile(bb_col_music_file);
    bb_col_sound.setBuffer(bb_col_sound_buf);
}

void Game::init_bg_music()
{
    bg_music.openFromFile("resources/Mean.wav");
    bg_music.setPitch(2);
    bg_music.setVolume(50);
    bg_music.setLoop(true);
    bg_music.play();
}

void Game::init_text()
{

    if(!font.loadFromFile("resources/NES-Chimera.ttf"))
        std::cout<<"error while loading font" << std::endl;
    text.setFont(font);
    text.setString("Collision Count : 0");
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setPosition(window_width-500,20);
}

Game::Game() : _window{sf::VideoMode(500,500),"TheTwoBalls"},_player(),_enemy()
{
    window_width =  _window.getSize().x;
    window_height =  _window.getSize().y;

    init_players();
    init_boudry();
    init_bool_vars();
    init_bb_col_music();
    init_bg_music();
    init_text();

    _window.setVerticalSyncEnabled(true);
}

void Game::run(int minimum_frame_per_seconds) {

    while (_window.isOpen()) {
        processEvents();
        if(isPause){
            std::string tempStr = text.getString();
            text.setString(tempStr + "\n\n\n\n\n\n\nGAME PAUSE\n\nPress Space to Continue");
            render();
            gamePause();
            text.setString(tempStr);
        }

        update(clock.restart());
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while(_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            isPause = false;
            _window.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                isPause = false;
                _window.close();
            }
            if(isPause && (event.key.code == sf::Keyboard::Space))
                isPause = false;
            else if(event.key.code == sf::Keyboard::Space)
                isPause = true ;
        }
        _player.processEvents();
    }
}

void Game::gamePause(){
    bg_music.stop();
    while(isPause){
        processEvents();
    }
    bg_music.play();
    clock.restart();
    return;
}

bool Game::bb_collision()
{
    float dist = sqrt(pow(_player.getXpos() - _enemy.getXpos() ,2) + pow(_player.getYpos() - _enemy.getYpos(),2));
    if( dist < _player.retRadius() + _enemy.retRadius() )
    {
        srand((_player.getXpos()));
        bb_col_sound.play();
        col_count++;
        std:: string myStr = "Collision Count : " + std::to_string(col_count);

        text.setString(myStr);
        srand(((_player.getXpos()* (time(NULL)/50))/1));

        _player.setPosition(rand()%600+20,rand()%500+20);
        _enemy.setPosition(rand()%600+30,rand()%600+60);

        srand(((_player.getXpos()* (time(NULL)/50))/1));

        _enemy.setAngle((rand() % 40)+20);
        _player.setAngle((rand()%360)+1);
        _enemy.setVelocity();

        return true;
    }
    else
        return false;
}

void Game::update(sf::Time TimePerFrame)
{
    _player.collision(window_width,window_height);
    _player.update(TimePerFrame);

    _enemy.collision(window_width,window_height);
    _enemy.update(TimePerFrame);

    if(bb_collision())
        isPause = true;
}

void Game::render() {

    using namespace std;
    _window.clear();
    _window.draw(b1);
    _window.draw(b2);
    _window.draw(b3);
    _window.draw(b4);
    _window.draw(_player);
    _window.draw(_enemy);
    _window.draw(text);

    _window.display();
}

