class Player
{
public:
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;
    Player();
    void processEvents();
    void update();
    void get_reference_to_grid(Grid* );
private:
    Grid* m_grid_reference;
    bool m_upKey,m_leftKey,m_rightKey,m_downKey,m_spaceKey;
};
