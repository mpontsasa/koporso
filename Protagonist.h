#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include "Creature.h"
#include <SFML/System/Vector2.hpp>

class Protagonist : public ScreenObject
{
public:
    Protagonist(const char *img, int x, int y, int depth, int height_, int width_);
    void getEvent(sf::Event event);
    bool hit(sf::Vector2i point){return false;}
    void drawThis();
private:

    sf::Texture *texture;
    sf::Sprite *sprite;

    int height;
    int width;
};

#endif // PROTAGONIST_H
