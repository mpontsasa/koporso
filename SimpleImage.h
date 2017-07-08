#ifndef SIMPLEIMAGE_H

#define SIMPLEIMAGE_H

#include <SFML/Graphics.hpp>
#include "ScreenObject.h"

class SimpleImage : public ScreenObject
{
public:
    SimpleImage(char *img, int x, int y); //constructor: x and y for topleft corner
    void getEvent(sf::Event event_){}
    bool hit(sf::Vector2i point){return false;}
    void drawThis();
    sf::Texture t;
    sf::Sprite s;
};

#endif
