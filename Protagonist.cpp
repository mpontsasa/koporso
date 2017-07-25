#include <SFML/System/Vector2.hpp>
#include "Protagonist.h"
#include "utility.h"


Protagonist::Protagonist(const char *img, int x, int y, int z)
{
    texture = new sf::Texture;
    sprite = new sf::Sprite;
    texture ->loadFromFile(img);
    sprite ->setTexture(*texture);

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
        int movement = (gameClock.getElapsedTime() - lastUpdate).asMilliseconds() * protagonistSpeed;
        xValue -= movement;
        sprite ->setPosition(xValue, yValue);
        gameView.followProtagonist(*this);
    }
    else if(walking_right)
    {
        int movement = (gameClock.getElapsedTime() - lastUpdate).asMilliseconds() * protagonistSpeed;
        xValue += movement;
        sprite ->setPosition(xValue, yValue);
        gameView.followProtagonist(*this);
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
