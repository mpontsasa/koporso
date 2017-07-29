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
    yValue = gameView.view.getSize().y;
    zValue = depth;
    yStand = y;

    sprite ->setPosition(xValue,yValue);

    AnimationState = intr;

    in_out_start = gameClock.getElapsedTime();
}

void Creature::set_intro()
{
    if (gameClock.getElapsedTime() - in_out_start >= introTime)
    {
        yValue = yStand;
        AnimationState = outr;
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
        yValue = yStand;
        AnimationState = intr;
        sprite ->setPosition(xValue, yValue);
    }
    else
    {
        yValue = gameView.view.getSize().y + ((gameClock.getElapsedTime() - in_out_start).asMilliseconds() * (gameView.view.getSize().y - yStand) / introTime.asMilliseconds());
        sprite ->setPosition(xValue, yValue);
    }
}
