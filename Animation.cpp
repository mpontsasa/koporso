#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <string>
#include "utility.h"
#include "SimpleImage.h"
#include <iostream>

std::string digits[10]= {"0","1","2","3","4","5","6","7","8","9"};

std::string conv(int x)
{
    if(x)
        return conv(x/10) + digits[x%10];
    else
        return "";

}

Animation::Animation(const std::string name_, sf::Sprite **spr, int frame_nr, sf::Time length, int x, int y):length(length), spr(spr)
{
    name=name_;
    f_nr=frame_nr;
    frames = new sf::Sprite[f_nr];
    textures = new sf::Texture[f_nr];
    interval = length/static_cast<float>(frame_nr);

    for(int i=0; i<f_nr; i++)
    {
        (textures + i) ->loadFromFile(name + conv(i+1) + ".png");
        (frames + i ) -> setTexture(textures[i]);
        (frames + i ) ->setPosition(x, y);
    }
}

Animation::~Animation()
{
    delete[] frames;
    delete[] textures;
}

void Animation::play_animation ()
{
    init=gameClock.getElapsedTime();
}

void Animation::update_animation()
{
    *spr = frames + ((gameClock.getElapsedTime()-init).asMilliseconds()/interval.asMilliseconds())%f_nr;
}

void Animation::update_animation(bool direction)    //direction: 0=right, 1=left
{
    int current_frame_index=((gameClock.getElapsedTime()-init).asMilliseconds()/interval.asMilliseconds())%f_nr;

    *spr = frames + current_frame_index;

    /*if(direction != flipped[current_frame_index])
        (*spr)->setTextureRect(sf::IntRect(width, 0, -width, height))*/
}
