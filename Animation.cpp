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

Animation::Animation(const std::string p, sf::Sprite **spr, int frame_nr, float length, int depth):length(length), spr(spr)
{
    name=p;
    f_nr=frame_nr;
    frames = new sf::Sprite[f_nr];
    textures = new sf::Texture[f_nr];
    //current_frame->set_sprite(frames);

    for(int i=0; i<f_nr; i++)
    {
        (textures + i) ->loadFromFile(name + conv(i+1) + ".png");
        (frames + i ) -> setTexture(textures[i]);
    }

    //*spr=frames[1];
}

/*SimpleImage *Animation::get_current_frame()
    {return current_frame;
    }*/

void Animation::play_animation ()
{
    init=gameClock.getElapsedTime();
    run_animation=true;
}

void Animation::update_animation(sf::Time interval)
{
    int asd;

    asd=((gameClock.getElapsedTime()-init).asMilliseconds()/interval.asMilliseconds())%f_nr;

    *spr = frames + asd;

    (*spr)->setPosition(100,100);
}

void Animation::stop_animation()
{
    run_animation=false;
}
