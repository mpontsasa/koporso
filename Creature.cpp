#include "Creature.h"
#include "utility.h"
#include <iostream>

Creature::Creature(const char *img, int x, int y, int depth, int height_, int width_)
{
    texture = new sf::Texture;
    sprite = new sf::Sprite;
    texture ->loadFromFile(img);
    sprite ->setTexture(*texture);

    height = height_;
    width = width_;

    xValue = x;
    yValue = desktop.height;

    yStand = y;

    sprite ->setPosition(xValue,yValue);

    AnimationState = intr;
}

void Creature::set_intro()
{
    yValue -=2;
    sprite ->setPosition(xValue, yValue);
}
