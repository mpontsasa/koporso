#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include <SFML/System/Vector2.hpp>
#include "ScreenObject.h"

class Protagonist : public ScreenObject
{
public:
    Protagonist(const char *img, int x, int y, int z);
    void getEvent(sf::Event event);
    bool hit(sf::Vector2i point){return false;}
    void drawThis();

    int getHeight() const {return sprite ->getGlobalBounds().height;}
    int getWidth() const {return sprite ->getGlobalBounds().width;}

private:

    sf::Texture *texture;
    sf::Sprite *sprite;

    bool directio; //0 right, 1 left

    bool walking_right; // if right arrow is pressed
    bool walking_left; // if left arrow is pressed
};

#endif // PROTAGONIST_H
