#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "Protagonist.h"
#include "utility.h"


Protagonist::Protagonist(const char *img, int x, int y, int z, FixedGround *fg): fixedground(fg)
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
    walking_back = 0;
    walking_forth = 0;

    sprite ->setPosition(xValue,yValue);
    sprite ->scale(0.3,0.3);

    height = sprite ->getGlobalBounds().height;
    width = sprite ->getGlobalBounds().width;

}

void Protagonist::drawThis()
{
    if(walking_left)
    {
        int movement = (gameClock.getElapsedTime() - lastUpdate).asMilliseconds() * protagonistSpeed;
        xValue -= movement;
        if(!(fixedground ->onTheGround(*this))) //if moves out of the fixed ground
        {
            xValue = fixedground -> getXValue() - width / 2;    //move it to the edge of the fixed ground
        }
        sprite ->setPosition(xValue, yValue);
        gameView.followProtagonist(*this);
    }
    else if(walking_right)
    {
        int movement = (gameClock.getElapsedTime() - lastUpdate).asMilliseconds() * protagonistSpeed;
        xValue += movement;
        if(!(fixedground ->onTheGround(*this))) //if moves out of the fixed ground
        {
            xValue = fixedground ->getXValue() + fixedground ->getWidth() + width / 2;    //move it to the edge of the fixed ground
        }
        sprite ->setPosition(xValue, yValue);
        gameView.followProtagonist(*this);
    }
    else if(walking_back)
    {
        int movement = (gameClock.getElapsedTime() - lastUpdate).asMilliseconds() * protagonistSpeed;
        yValue -= movement;
        if(!(fixedground ->onTheGround(*this))) //if moves out of the fixed ground
        {
            yValue = fixedground ->getYValue() - height;    //move it to the edge of the fixed ground
        }
        sprite ->setPosition(xValue, yValue);
        gameView.followProtagonist(*this);
    }
    else if(walking_forth)
    {
        int movement = (gameClock.getElapsedTime() - lastUpdate).asMilliseconds() * protagonistSpeed;
        yValue += movement;
        if(!(fixedground ->onTheGround(*this))) //if moves out of the fixed ground
        {
            yValue = fixedground ->getYValue() + fixedground ->getHeight();    //move it to the edge of the fixed ground
        }
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
            walking_back = 0;
            walking_forth = 0;
            directio = 1;
            break;
        case sf::Keyboard::Right:
            walking_left = 0;
            walking_right = 1;
            walking_back = 0;
            walking_forth = 0;
            directio = 0;
            break;
        case sf::Keyboard::Up:
            walking_left = 0;
            walking_right = 0;
            walking_back = 1;
            walking_forth = 0;
            break;
        case sf::Keyboard::Down:
            walking_left = 0;
            walking_right = 0;
            walking_back = 0;
            walking_forth = 1;
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
            walking_back = 0;
            break;
        case sf::Keyboard::Down:
            walking_forth = 0;
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
