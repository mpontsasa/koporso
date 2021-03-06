#include "fixedground.h"
#include "utility.h"
#include <iostream>
#include "ScreenRoot.h"

FixedGround::FixedGround(const char *img, int x, int y, int z, int width, int height): ScreenObject(x,y,z,width,height, height * depthPerHeight)
{
    texture = new sf::Texture;
    sprite = new sf::Sprite;

    texture ->loadFromFile(img);
    //texture ->setRepeated(true);
    //sprite ->setScale(sf::Vector2f(width, height));

    sprite ->setTexture(*texture);

    sprite ->setPosition(xValue,yValue);
}

bool FixedGround::onTheGround (ScreenObject &so)   // so: the screen object, width: the width of the screen object
{
    int xMiddle = so.getXValue() + so.getWidth() / 2;
    int yBottom = so.getYValue() + so.getHeight();

    return xMiddle >= xValue && xMiddle <= xValue + width &&
        yBottom >= yValue && yBottom <= yValue + height &&
        so.getZValue() >= zValue && so.getZValue() <= zValue + depth;  // if the ScreenObject is in the Fixed Ground
}

void FixedGround::drawThis()
{
    ScreenRoot::access().window->draw(*sprite);
}
