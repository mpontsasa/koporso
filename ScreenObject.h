#include <SFML/Graphics.hpp>

class ScreenObject
{
public:
    virtual void GetEvent(sf::Event event_) = 0;    //Handels the event
    virtual bool Hit(float x, float y) = 0;         //true if the object contains (x,y) point
    virtual void Draw(float x, float y) = 0;        //Draws the object
};
