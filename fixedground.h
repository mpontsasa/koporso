#ifndef FIXEDGROUND_H
#define FIXEDGROUND_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "ScreenObject.h"



class FixedGround : public ScreenObject
{
public:

    FixedGround(const char *img,int x, int y, int z, int width, int height);
    ~FixedGround(){}


    bool onTheGround(ScreenObject &so);

    void getEvent(sf::Event event){}
    void drawThis();
    bool hit(sf::Vector2i){return false;}

    int getDepth() const {return depth;}
protected:

    std::vector<FixedGround> relatedGrounds;

    sf::Texture *texture;
    sf::Sprite *sprite;

};

#endif // FIXEDGROUND_H
