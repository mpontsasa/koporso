#ifndef ANIMATION_H

#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>

class Animation
{
    public:
        Animation(const std::string p, int frame_nr, float length);

    private:
        std::string name;
        int f_nr;
        float length;
        sf::Sprite *frames;

};

#endif // ANIMATION_H
