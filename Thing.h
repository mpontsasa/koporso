#ifndef THING_H

#define THING_H

#include <SFML/Graphics.hpp>
#include "ScreenObject.h"
#include "StandardSO.h"


class Thing : public StandardSO
{
public:
    Thing(const char *img, int x, int y, int depth); //constructor: x and y for topleft corner

    void set_intro(){};   // Sets the object for drawing if intro
    void set_outro(){};   // Sets the object for drawing if outro
    void set_lie(){};   // Sets the object for drawing if lie
    void set_stand(){};
    void getEvent(sf::Event event_){};
};


#endif // THING_H
