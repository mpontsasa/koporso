#include "fixedground.h"
#include <iostream>

FixedGround::FixedGround(int x, int y, int z, int width, int height, int depth): ScreenObject(x,y,z,width,height), depth(depth)
{}

bool FixedGround::onTheGround (ScreenObject &so)   // so: the screen object, width: the width of the screen object
{
    int xMiddle = so.getXValue() + so.getWidth() / 2;
    int yBottom = so.getYValue() + so.getHeight();

    return xMiddle >= xValue && xMiddle <= xValue + width &&
        yBottom >= yValue && yBottom <= yValue + height &&
        so.getZValue() >= zValue && so.getZValue() <= zValue + depth;  // if the ScreenObject is in the Fixed Ground
}
