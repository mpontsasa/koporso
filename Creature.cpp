#include "Creature.h"
#include "utility.h"

Creature::Creature(const char *img, int x, int y, int depth)
{
    texture = new sf::Texture;
    sprite = new sf::Sprite;
    texture ->loadFromFile(img);
    sprite ->setTexture(*texture);
    sprite ->setPosition(x,y);

    xValue=x;
    yValue=y;
    zValue=depth;
}

void Creature::set_intro()
{

}
