#ifndef FLIPPABLEANIMATION_H
#define FLIPPABLEANIMATION_H

#include "Animation.h"

enum Direction
        {
            left=0, right=1
        };

class FlippableAnimation : public Animation
{
    public:
        FlippableAnimation(const std::string name_, sf::Sprite **spr, int frame_nr, sf::Time length, int height, int width, int x = 100, int y = 100);   //dir: (starting direction) 0=left, 1=right

    protected:

    private:

        Direction direction;
        int height, width;

        void flip(Direction dir_);

};

#endif // FLIPPABLEANIMATION_H
