#ifndef CREATURE_H
#define CREATURE_H

#include <SFML/Graphics.hpp>
#include "StandardSO.h"

class Creature : public StandardSO  // Living stuff(animals, characters)
{
public:
    Creature(const char *img, int x, int y, int depth, int height_, int width_);

    void getEvent(sf::Event event_){}

    void set_intro();   // Sets the object for drawing if intro
    void set_outro();   // Sets the object for drawing if outro
    bool set_lie(){return false;};   // Sets the object for drawing if lie
    void set_stand(){};   // Sets the object for drawing if outro
protected:
    int yStand; //x when stand
};

#endif  //CREATURE_H

