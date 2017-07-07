#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <list>

class ScreenObject  // Everything in the screen
{
public:
    virtual void getEvent(sf::Event event_) = 0;    //Handles the event
    virtual bool hit(sf::Vector2i point) = 0;         //true if the object contains (x,y) point
    virtual void draw(sf::Vector2i pos) = 0;        //Draws the object
    int getZValue() const {return zValue;}
    void setZValue(int zv_){zValue = zv_;}
private:
    int zValue; //The value of depth (z coordinate) !Compared to parent! Only interesting if the object may move

    std::list<ScreenObject> *dinamicObjectList;   //Sub-objects that may move in depth on the stage
    std::list<ScreenObject> *staticObjectList;    //Sub-objects that don't move in depth on the stage
};


class ScreenRoot : ScreenObject // SINGLESTONE!
{
public:
    static ScreenRoot& access();    // Return the root object
    void getEvent(sf::Event event_){}   // Don't do anything with event
    virtual bool hit(sf::Vector2i point){return 1;} // Always hit
    virtual void draw(sf::Vector2i pos){}   //No need to draw anything

private:
    ScreenRoot(){}
};
