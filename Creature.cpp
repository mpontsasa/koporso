#include "Creature.h"
#include "utility.h"

Creature::Creature(const char *img, int x, int y, int depth, int height_, int width_)
{
    texture = new sf::Texture;
    sprite = new sf::Sprite;
    texture ->loadFromFile(img);
    sprite ->setTexture(*texture);

    height = height_;
    width = width_;

    xValue = desktop.height + height/2 + 1;
    yValue = y;

    xStand = x;

    sprite ->setPosition(xValue,y);

}

void Creature::set_intro()
{

}
