class Background : public ScreenObject
{
public:
    void getEvent(sf::Event event_);    //Handles the event
    bool hit(sf::Vector2i point);         //true if the object contains (x,y) point
    void drawThis() const;
};
