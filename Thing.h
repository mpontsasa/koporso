#ifndef THING_H

#define THING_H

#include <SFML/Graphics.hpp>
#include "ScreenObject.h"
#include "StandardSO.h"


class Thing : public StandardSO
{
public:
    Thing(const char *img, int x, int y, int depth); //constructor: x and y for topleft corner
    ~Thing(){}

    void set_intro(){};   // Sets the object for drawing if intro
    void set_outro(){};   // Sets the object for drawing if outro
    bool set_lie(){return false;};   // Sets the object for drawing if lie
    void set_stand(){};
    void getEvent(sf::Event event_){};
};


#endif // THING_H
