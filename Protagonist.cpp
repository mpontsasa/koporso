#include "Protagonist.h"
#include <SFML/System/Vector2.hpp>

Protagonist::Protagonist(const char *img, int x, int y, int depth, int height_, int width_)
{
    texture = new sf::Texture;
    sprite = new sf::Sprite;
    texture ->loadFromFile(img);
    sprite ->setTexture(*texture);

    height = height_;
    width = width_;

    xValue = x;
    yValue = y;

    sprite ->setPosition(xValue,yValue);
    sprite ->scale(0.3,0.3);
}

void Protagonist::drawThis()
{
    ScreenRoot::access().window->draw(*sprite);
}

void Protagonist::getEvent(sf::Event event)
{
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        switch (event.key.code)
        {
        case sf::Keyboard::Left:
            break;
        case sf::Keyboard::Right:
            break;
        case sf::Keyboard::Up:
            break;
        case sf::Keyboard::Down:
            break;
        default:
            break;
        }
        break;
    case sf::Event::KeyReleased:
        switch (event.key.code)
        {
        case sf::Keyboard::Left:
            break;
        case sf::Keyboard::Right:
            break;
        case sf::Keyboard::Up:
            break;
        case sf::Keyboard::Down:
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
