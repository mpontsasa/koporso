#ifndef ANIMATION_H

#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>
//#include "SimpleImage.h"

class Animation
{
    public:
        Animation(const std::string p, int frame_nr, float length, int depth);
        void play_animation(int nr_f, float interval);
        void stop_animation();
        int zValue;

    private:
        std::string name;
        int f_nr;
        float length;
        sf::Texture *frames;
        bool run_animation;
//        SimpleImage *current_frame;



};

#endif // ANIMATION_H
