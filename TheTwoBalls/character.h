class Character : public sf::Drawable
{
public:
    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;
    Character();
    template<typename ... Args>
    void setPosition(Args&& ... args){
        _shape.setPosition(std::forward<Args>(args) ...);
    }

    float getXpos();
    float getYpos();
    float setAngle(float );
    float retRadius();
    void collision(int,int);
    void reset_pos_and_angle(float new_angle,float newXpos,float newYpos);
    void setMusic(const std::string musicFilePath);
    void ballWorld();
    void registerWindowSize(unsigned int window_width,unsigned int window_height);


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    bool hasCollide;
    unsigned int window_width;
    unsigned int window_height;

    float min_allowed_x ;
    float min_allowed_y ;
    float max_allowed_x ;
    float max_allowed_y ;
    float col_speed;
    float angle;
    float m_radius;

    float boundry_size ;
    float apparent_boundry;


    sf::CircleShape _shape;
    sf::Vector2f _velocity;
    sf::SoundBuffer  bw_col_sound_buf;
    sf::Sound 	 bw_col_sound;
};
