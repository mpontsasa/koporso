#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <list>

class ScreenObject  // Everything in the screen
{
public:
    virtual void getEvent(sf::Event event_) = 0;    //Handles the event
    virtual bool hit(sf::Vector2i point) = 0;         //true if the object contains (x,y) point
    virtual void drawThis() = 0;    // Draws This Object
    virtual void draw();        //Draws the object and sub-objects

    void addStaticSo(ScreenObject *so_);
    void addDinamicSo(ScreenObject *so_);
    int getZValue() const {return zValue;}
    void setZValue(int zv_){zValue = zv_;}

protected:
    int xValue; //x coordinate !Compared to screen!
    int yValue; //y coordinate !Compared to screen!
    int zValue; //The value of depth (z coordinate) !Compared to parent! Only interesting if the object may move

    std::list<ScreenObject*> dinamicObjectList;   //Sub-objects that may move in depth on the stage
    std::list<ScreenObject*> staticObjectList;    //Sub-objects that don't move in depth on the stage
};


class ScreenRoot : public ScreenObject // SINGLESTONE!
{
public:
    void getEvent(sf::Event event_){}   // Don't do anything with event
    virtual bool hit(sf::Vector2i point){return 1;} // Always hit
    virtual void drawThis(){}   //No need to draw anything

    static ScreenRoot& access();    // Return the root object++

    sf::RenderWindow *window;

private:
 //   ScreenRoot(){}

};

class FixedGround : public ScreenObject
{
public:
    void getEvent(sf::Event event_);    //Handles the event
    bool hit(sf::Vector2i point);         //true if the object contains (x,y) point
    void drawThis() const;
};

#endif //SCREENOBJECT_H
