class Boundry : public sf::Drawable
{
public:
    Boundry(){};
    Boundry(int width,int height,int x_position,int y_position);
    template<typename ... Args>
    void setPosition(Args&& ... args){
        m_boundry.setPosition(std::forward<Args>(args) ...);
    }
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::RectangleShape m_boundry;
};


