class Grid : public sf::Drawable
{
    unsigned int    m_tile_width;
    unsigned int    m_tile_height;
    unsigned int    cur_grid[9];
    unsigned int    m_target_grid[9];
    unsigned int    m_total_exchange_made ;
    unsigned int    m_zeroTilePos;
    bool            m_has_gridChange;

    sf::Sprite*     m_spriteArray[9] ;
    sf::Sprite      m_gameTitleSprite;
    sf::Texture     m_tileTexture;

    Grid(const Grid&) = delete;
    Grid& operator=(const Grid &) = delete;

public:
    Grid();
    void init_grid();
    void update();
    void exchange(unsigned int tilePos);
    bool has_gridChange();
    bool test_for_win();
    unsigned int ret_totalMoveByPlayer();
    int ret_zeroTilePos() ;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
