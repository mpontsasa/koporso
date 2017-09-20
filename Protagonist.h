#ifndef PROTAGONIST_H
#define PROTAGONIST_H

#include <SFML/System/Vector2.hpp>
#include "ScreenObject.h"
#include "fixedground.h"
#include "FlippableAnimation.h"

class Protagonist : public ScreenObject
{
public:
    Protagonist(const char *img, int x, int y, int z, FixedGround *fg);
    void getEvent(sf::Event event);
    bool hit(sf::Vector2i point){return false;}
    void drawThis();

    void startJump();

private:

    sf::Texture *texture;
    sf::Sprite *sprite;

    bool directio; //0 right, 1 left

    bool walking_right; // if right arrow is pressed
    bool walking_left; // if left arrow is pressed
    bool walking_back; // if up arrow is pressed
    bool walking_forth; // if down arrow is pressed

    FixedGround *fixedground;


    sf::Time jumpStart;
    float jumpVelocity;

    FlippableAnimation walk_horizontal;
    Animation stand_anim;

};

#endif // PROTAGONIST_H
