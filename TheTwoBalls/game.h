
class Game
{
public:
    Game(const Game&) = delete ;
    Game& operator=(const Game&) = delete ;
    Game();
    void run(int frameRate);
    void init_players();
    void init_boudry();
    void init_bool_vars();
    void init_bb_col_music();
    void init_bg_music();
    void init_text();
    bool bb_collision();
    
private:
    void processEvents();
    void update(sf::Time TimePerFrame);
    void render();
    void gamePause();

    sf::RenderWindow _window;
    Player  _player;
    Enemy   _enemy;
    Boundry b1;
    Boundry b2;
    Boundry b3;
    Boundry b4;

    unsigned int window_width;
    unsigned int window_height;
    sf::SoundBuffer  bb_col_sound_buf;
    sf::Clock clock;
    sf::Sound bb_col_sound;
    sf::Music bg_music;
    sf::Font font;
    sf::Text text;
    bool vsync;
    bool isPause;

};
