#ifndef FIXEDGROUND_H
#define FIXEDGROUND_H

#include <vector>
#include "ScreenObject.h"


class FixedGround : public ScreenObject
{
public:
    FixedGround(int x, int y, int z, int width, int height, int depth);

    bool onTheGround(ScreenObject &so);

    void getEvent(sf::Event event){}
    void drawThis(){}
    bool hit(sf::Vector2i){return false;}
protected:

    std::vector<FixedGround> relatedGrounds;

    int depth;  // Depth of the ground
};

#endif // FIXEDGROUND_H
