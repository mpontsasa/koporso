#ifndef FIXEDGROUND_H
#define FIXEDGROUND_H

#include <vector>
#include "ScreenObject.h"
#include <SFML/Graphics.hpp>


class FixedGround : public ScreenObject
{
public:
    FixedGround(int x, int y, int z, int width, int height, const char img[]);

    bool onTheGround(ScreenObject &so);

    void getEvent(sf::Event event){}
    void drawThis(){ScreenRoot::access().window->draw(*sprite);}
    bool hit(sf::Vector2i){return false;}
protected:

    std::vector<FixedGround> relatedGrounds;

    int depth;  // Depth of the ground
    sf::Texture *texture;
    sf::Sprite *sprite;

};

#endif // FIXEDGROUND_H
