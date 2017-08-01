#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <string>
#include "utility.h"
#include "SimpleImage.h"

std::string digits[10]={"0","1","2","3","4","5","6","7","8","9"};

std::string conv(int x)
{
    if(x)
        return conv(x/10) + digits[x%10];
    else
        return "";

}

Animation::Animation(const std::string p, int frame_nr, float length, int depth):length(length)
{
    name=p;
    f_nr=frame_nr;
    frames = new sf::Sprite[f_nr];

    sf::Texture *t=new sf::Texture;
    //current_frame->set_sprite(frames);

    for(int i=1; i<=f_nr; i++)
    {
        t ->loadFromFile(name + conv(i) + ".png");
        (frames + i) ->setTexture(*t);
    }
}

SimpleImage *Animation::get_current_frame()
    {return current_frame;
    }

void Animation::play_animation (sf::Sprite *frames, int nr_f, float interval)
    {sf::Time init=gameClock.getElapsedTime();

    int current_frame_index=0;

    if((gameClock.getElapsedTime()-init).asMilliseconds() > interval)
        {current_frame_index = (int)((gameClock.getElapsedTime()-init).asMilliseconds()/interval)%nr_f;

        current_frame->set_sprite(frames+current_frame_index);
        }
    }

