class Game
{
public:
    Game(const Game&) = delete ;
    Game& operator=(const Game&) = delete ;
    Game();

    void run();
    void processEvents();
    void update();
    void render();

private:
    sf::RenderWindow m_window;
    Player  m_player;
    Grid   m_grid;
};
