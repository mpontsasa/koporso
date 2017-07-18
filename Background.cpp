#include "Background.h"

Background::Background(char *img, int x, int y, int depth, float ratio_x): ratio_x(ratio_x)
    {
    t.loadFromFile(img);
    s.setTexture(t);
    s.setPosition(x,y);

    xValue=x;
    yValue=y;
    zValue=depth;
    }

void Background::followScreen(int moved)
{
    s.setPosition(xValue+moved/ratio_x,yValue);
}
