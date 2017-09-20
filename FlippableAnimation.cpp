#include "FlippableAnimation.h"

FlippableAnimation::FlippableAnimation(const std::string name_, sf::Sprite **spr, int frame_nr, sf::Time length, int height, int width, int x, int y):Animation(name_, spr, frame_nr, length, x, y), height(height), width(width)
{
direction=left;
}

void FlippableAnimation::flip(Direction dir_)
{
    if(direction!=dir_)
    {
        direction=dir_;

        if(direction==right)
            for(int i=0;i<f_nr;i++)
                frames[i].setTextureRect(sf::IntRect(width,0,-width,height));

        else
            for(int i=0;i<f_nr;i++)
                frames[i].setTextureRect(sf::IntRect(0,0,width,height));
    }

}
