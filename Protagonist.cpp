#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "Protagonist.h"


Protagonist::Protagonist(const char *img, int x, int y, int z, int height_, int width_)
{
    texture = new sf::Texture;
    sprite = new sf::Sprite;
    texture ->loadFromFile(img);
    sprite ->setTexture(*texture);

    height = height_;
    width = width_;

    xValue = x;
    yValue = y;
    zValue = z;

    walking_right = 0;
    walking_left = 0;

    sprite ->setPosition(xValue,yValue);
    sprite ->scale(0.3,0.3);
}

void Protagonist::drawThis()
{
    if(walking_left)
    {
        xValue -= (gameClock.getElapsedTime() - lastUpdate).asMilliseconds() * protagonistSpeed;
        sprite ->setPosition(xValue, yValue);
    }
    else if(walking_right)
    {
        xValue += (gameClock.getElapsedTime() - lastUpdate).asMilliseconds() * protagonistSpeed;
        sprite ->setPosition(xValue, yValue);
    }

    ScreenRoot::access().window->draw(*sprite);
}

void Protagonist::getEvent(sf::Event event)
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Left:

            walking_left = 1;
            walking_right = 0;
            directio = 1;
            break;
        case sf::Keyboard::Right:
            walking_left = 0;
            walking_right = 1;
            directio = 0;
            break;
        case sf::Keyboard::Up:
            ///Who knows
            break;
        case sf::Keyboard::Down:
            ///Jump
            break;
        default:
            break;
        }
        break;
    }
    case sf::Event::KeyReleased:
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Left:
            walking_left = 0;
            break;
        case sf::Keyboard::Right:
            walking_right = 0;
            break;
        case sf::Keyboard::Up:
            break;
        case sf::Keyboard::Down:
            break;
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}
