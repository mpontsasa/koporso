#ifndef ANIMATION_H

#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>
//#include "SimpleImage.h"

class Animation
{
    public:
        Animation(const std::string p, int frame_nr, float length, int depth);
        void play_animation(sf::Sprite *frames, int nr_f, float interval);
        void stop_animation();
        int zValue;

    private:
        std::string name;
        int f_nr;
        float length;
        sf::Sprite *frames;
//        SimpleImage *current_frame;



};

#endif // ANIMATION_H
