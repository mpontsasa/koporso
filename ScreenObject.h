#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class ScreenObject  // Everything in the screen
{
public:
    virtual void GetEvent(sf::Event event_) = 0;    //Handles the event
    virtual bool Hit(sf::Vector2i point) = 0;         //true if the object contains (x,y) point
    virtual void Draw(sf::Vector2i pos) = 0;        //Draws the object
};

class ScreenRoot    // SINGLESTONE! Controls the screen output and mouse input
{
public:
    static ScreenRoot& access();    //returns the root object

private:
    ScreenRoot(){};
};
