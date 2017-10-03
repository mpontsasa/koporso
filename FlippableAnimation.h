#ifndef FLIPPABLEANIMATION_H
#define FLIPPABLEANIMATION_H

#include "Animation.h"
#include "../koporso/utility.h"

class FlippableAnimation : public Animation
{
public:
    FlippableAnimation(const std::string name_, sf::Sprite **spr, int frame_nr, sf::Time length, int height, int width, int x = 100, int y = 100);   //dir: (starting direction) 0=left, 1=right
    void flip(Direction dir_);
protected:

    Direction direction;
    int height, width;

};

#endif // FLIPPABLEANIMATION_H
