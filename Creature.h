#ifndef CREATURE_H
#define CREATURE_H

#include <SFML/Graphics.hpp>
#include "StandardSO.h"

class Creature : public StandardSO  // Living stuff(animals, characters)
{
public:
    Creature(char *img, int x, int y, int depth); //constructor: x and y for topleft corner

    void getEvent(sf::Event event_){}
    void set_intro();

};

#endif  //CREATURE_H

