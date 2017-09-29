#include "Creature.h"
#include "utility.h"
#include <iostream>

Creature::Creature(const char *img, int x, int y, int z, int height_, int width_)
{
    texture = new sf::Texture;
    sprite = new sf::Sprite;
    texture ->loadFromFile(img);
    sprite ->setTexture(*texture);

    height = height_;
    width = width_;
    depth = 0;

    xValue = x;
    yValue = gameView.view.getSize().y;
    zValue = z;
    yStand = y;
    yLie = gameView.view.getSize().y;

    sprite ->setPosition(xValue,yValue);

    AnimationState = lie;

    in_out_start = gameClock.getElapsedTime();
}

void Creature::set_intro()
{
    if (gameClock.getElapsedTime() - in_out_start >= introTime)
    {
        yValue = yStand;
        AnimationState = stand;
        sprite ->setPosition(xValue, yValue);
    }
    else
    {
        yValue = gameView.view.getSize().y - ((gameClock.getElapsedTime() - in_out_start).asMilliseconds() * (gameView.view.getSize().y - yStand) / introTime.asMilliseconds());
        sprite ->setPosition(xValue, yValue);
    }
}

void Creature::set_outro()
{
    if (gameClock.getElapsedTime() - in_out_start >= introTime)
    {
        yValue = gameView.view.getSize().y;
        AnimationState = lie;
        sprite ->setPosition(xValue, yValue);
    }
    else
    {
        yValue = yStand + ((gameClock.getElapsedTime() - in_out_start).asMilliseconds() * (gameView.view.getSize().y - yStand) / introTime.asMilliseconds());
        sprite -> setPosition(xValue, yValue);
    }
}
