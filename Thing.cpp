#include <SFML/Graphics.hpp>
#include "Thing.h"

Thing::Thing(const char *img, int x, int y, int depth)
{texture = new sf::Texture;
    sprite = new sf::Sprite;

    texture ->loadFromFile(img);
    sprite ->setTexture(*texture);
    sprite ->setPosition(x,y);

    xValue=x;
    yValue=y;
    zValue=depth;
}
