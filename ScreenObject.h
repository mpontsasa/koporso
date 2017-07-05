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
    int zValue; //The value of depth (z coordinate)
};


class ScreenRoot    // SINGLESTONE! Controls the screen output and mouse input
{
public:
    static ScreenRoot& access();    //returns the root object

private:
    ScreenRoot(){};


    class Stage  // All the object on one stage
    {
    public:
        Stage(){};



    private:
        std::list<ScreenObject> *dinamicObjectList;   //Objects that may move in depth on the stage
        std::list<ScreenObject> *staticObjectList;    //Objects that don't move in depth on the stage
    };


    std::list<Stage> stageList;  //List of stages on screen
};
