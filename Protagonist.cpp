#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "Protagonist.h"
#include "utility.h"



Protagonist::Protagonist(const char *img, int x, int y, int z, FixedGround *fg):
fixedground(fg), walk_horizontal("../koporso/Resources/protagonist_walk_horizontal", &sprite, 2, sf::milliseconds(700), 611, 300),
walk_forth("../koporso/Resources/Stickman", &sprite, 2, sf::milliseconds(700), 208,298),
walk_back("../koporso/Resources/Stickman", &sprite, 2, sf::milliseconds(700), 208,298),
stand_anim("../koporso/Resources/protagonist_stand", &sprite, 1, sf::seconds(10000))
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
    depth = 0;
}

void Protagonist::drawThis()
{
    if(walking_left)
    {
        int movement = (gameClock.getElapsedTime() - lastUpdate).asMilliseconds() * protagonistSpeed;
        xValue -= movement;
        if(!(fixedground ->onTheGround(*this))) //if moves out of the fixed ground
        {
            xValue = fixedground -> getXValue() - width / 2 + 1;    //move it to the edge of the fixed ground
        }
        walk_horizontal.update_animation();
        sprite ->setPosition(xValue, yValue);
        gameView.followProtagonist(*this);
    }
    else if(walking_right)
    {
        int movement = (gameClock.getElapsedTime() - lastUpdate).asMilliseconds() * protagonistSpeed;
        xValue += movement;
        if(!(fixedground ->onTheGround(*this))) //if moves out of the fixed ground
        {
            xValue = fixedground ->getXValue() + fixedground ->getWidth() - width / 2 - 1;    //move it to the edge of the fixed ground
        }
        walk_horizontal.update_animation();
        sprite ->setPosition(xValue, yValue);
        gameView.followProtagonist(*this);
    }
    else if(walking_back)
    {
        int movement = (gameClock.getElapsedTime() - lastUpdate).asMilliseconds() * protagonistSpeed / depthPerHeight;
        yValue -= movement/ depthPerHeight;
        zValue -= movement;
        if(!(fixedground ->onTheGround(*this))) //if moves out of the fixed ground
        {
            yValue = fixedground ->getYValue() - height + 1;    //move it to the edge of the fixed ground
            zValue = fixedground ->getZValue();
        }
        ScreenRoot::access().oneElementSort_din();
        walk_back.update_animation();
        sprite ->setPosition(xValue, yValue);
        gameView.followProtagonist(*this);
    }
    else if(walking_forth)
    {
        int movement = (gameClock.getElapsedTime() - lastUpdate).asMilliseconds() * protagonistSpeed;
        yValue += movement / depthPerHeight;
        zValue += movement;
        if(!(fixedground ->onTheGround(*this))) //if moves out of the fixed ground
        {
            yValue = fixedground ->getYValue() + fixedground ->getHeight() - height - 1;    //move it to the edge of the fixed ground
            zValue = fixedground ->getZValue() + fixedground ->getDepth();
        }
        ScreenRoot::access().oneElementSort_din();
        walk_forth.update_animation();
        sprite ->setPosition(xValue, yValue);
        gameView.followProtagonist(*this);
    }
    else    //standing
    {
        stand_anim.update_animation();
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
            if (!walking_left)
            {
                walk_horizontal.flip(left);
                walk_horizontal.play_animation();
            }
            walking_left = 1;
            walking_right = 0;
            walking_back = 0;
            walking_forth = 0;
            directio = 1;
            break;
        case sf::Keyboard::Right:
            if (!walking_right)
            {
                walk_horizontal.flip(right);
                walk_horizontal.play_animation();
            }
            walking_left = 0;
            walking_right = 1;
            walking_back = 0;
            walking_forth = 0;
            directio = 0;
            break;
        case sf::Keyboard::Up:
            if(!walking_back)
                walk_back.play_animation();

            walking_left = 0;
            walking_right = 0;
            walking_back = 1;
            walking_forth = 0;
            break;
        case sf::Keyboard::Down:
            if(!walking_forth)
                walk_forth.play_animation();

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
            stand_anim.play_animation();
            break;
        case sf::Keyboard::Right:
            walking_right = 0;
            stand_anim.play_animation();
            break;
        case sf::Keyboard::Up:
            walking_back = 0;
            stand_anim.play_animation();
            break;
        case sf::Keyboard::Down:
            walking_forth = 0;
            stand_anim.play_animation();
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

void Protagonist::startJump()
{
    jumpStart = gameClock.getElapsedTime();
    ///not finished yet
}
