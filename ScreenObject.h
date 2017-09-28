#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <list>
#include "Animation.h"


class ScreenObject  // Everything in the screen
{
public:
    ScreenObject(int x, int y, int z, int width, int height, int depth = 0):xValue(x), yValue(y), zValue(z),height(height),width(width), depth(depth){}
    ScreenObject(){}


    virtual void getEvent(sf::Event event_) = 0;    //Handles the event
    virtual bool hit(sf::Vector2i point) = 0;         //true if the object contains (x,y) point
    virtual void drawThis() = 0;    // Draws This Object
    virtual void draw();        //Draws the object and sub-objects

    void addStaticSo(ScreenObject *so_);
    void addDinamicSo(ScreenObject *so_);
    void addGroundSo(ScreenObject *so_);

    int getXValue() const {return xValue;}
    void setXValue(int xv_){xValue = xv_;}

    int getYValue() const {return yValue;}
    void setYValue(int yv_){yValue = yv_;}

    int getZValue() const {return zValue;}
    void setZValue(int zv_){zValue = zv_;}

    int getWidth() const {return width;}
    int getHeight() const {return height;}

    int getBottom() const {return yValue + height;}
    int getTop() const {return yValue;}
    int getFront() const {return zValue + depth;}
    int getBack() const {return zValue;}
    int getRight() const {return xValue + width;}
    int getLeft() const {return xValue;}

protected:
    int xValue; //x coordinate
    int yValue; //y coordinate
    int zValue; //The value of depth (z coordinate)

    int height;
    int width;
    int depth;

    std::list<ScreenObject*> dinamicObjectList;   //Sub-objects that may move in depth on the stage
    std::list<ScreenObject*> staticObjectList;    //Sub-objects that don't move in depth on the stage
};

#endif //SCREENOBJECT_H
