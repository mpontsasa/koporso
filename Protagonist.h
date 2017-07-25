#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include "Creature.h"
#include <SFML/System/Vector2.hpp>

class Protagonist : public ScreenObject
{
public:
    Protagonist(const char *img, int x, int y, int z, int height_, int width_);
    void getEvent(sf::Event event);
    bool hit(sf::Vector2i point){return false;}
    void drawThis();
private:

    sf::Texture *texture;
    sf::Sprite *sprite;

    int height;
    int width;
    bool directio; //0 right, 1 left

    bool walking_right; // if right arrow is pressed
    bool walking_left; // if left arrow is pressed
};

#endif // PROTAGONIST_H
