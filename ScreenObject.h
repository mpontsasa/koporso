#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class ScreenObject
{
public:
    virtual void GetEvent(sf::Event event_) = 0;    //Handles the event
    virtual bool Hit(sf::Vector2i point) = 0;         //true if the object contains (x,y) point
    virtual void Draw(sf::Vector2i pos) = 0;        //Draws the object
};
