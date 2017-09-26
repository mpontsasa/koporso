#include "Background.h"
#include "ScreenRoot.h"
#include <iostream>

Background::Background(const char *img, int x, int y, int z, float ratio_x): ratio_x(ratio_x)
{
    texture.loadFromFile(img);
    sprite.setTexture(texture);
    sprite.setPosition(x,y);

    xValue=x;
    yValue=y;
    zValue=z;

    sprite.scale(10,10);
}

void Background::followScreen(int moved)
{
    xValue += moved*ratio_x;
    sprite.setPosition(xValue,yValue);
}

void Background::drawThis()
{
    ScreenRoot::access().window->draw(sprite);
}
