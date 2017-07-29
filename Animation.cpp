#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <string>
#include "utility.h"

std::string digits[10]={"0","1","2","3","4","5","6","7","8","9"};

std::string conv(int x)
{
    if(x)
        return conv(x/10) + digits[x%10];
    else
        return "";

}

Animation::Animation(const std::string p, int frame_nr, float length):length(length)
{
    name=p;
    f_nr=frame_nr;
    frames = new sf::Sprite[f_nr];

    sf::Texture *t=new sf::Texture;

    char x[21];

    for(int i=0; i<f_nr; i++)
    {
        t ->loadFromFile(name + conv(i) + ".png");
        (frames + i) ->setTexture(*t);
    }
}
