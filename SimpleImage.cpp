#include <SFML/Graphics.hpp>
#include "ScreenObject.h"
#include "SimpleImage.h"

void SimpleImage::drawThis()
{
ScreenRoot::access().window->draw(s);
}

SimpleImage::SimpleImage(char *img, int x, int y, int depth)
    {
    t.loadFromFile(img);
    s.setTexture(t);
    s.setPosition(x,y);

    xValue=x;
    yValue=y;
    zValue=depth;
    }













