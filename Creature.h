#ifndef CREATURE_H
#define CREATURE_H

#include <SFML/Graphics.hpp>
#include "StandardSO.h"

class Creature : public StandardSO  // Living stuff(animals, characters)
{
public:
    Creature(const char *img, int x, int y, int depth);

    void getEvent(sf::Event event_){}

    void set_intro();   // Sets the object for drawing if intro
    void set_outro(){};   // Sets the object for drawing if outro
    void set_lie(){};   // Sets the object for drawing if lie
    void set_stand(){};   // Sets the object for drawing if outro

};

#endif  //CREATURE_H

