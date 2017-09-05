#ifndef ANIMATION_H

#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>
//#include "SimpleImage.h"

class Animation
{
    public:
        Animation(const std::string p, sf::Sprite **spr, int frame_nr, float length, int depth);
        void play_animation();
        void update_animation(sf::Time interval);
        void stop_animation();
        int zValue;
        sf::Texture *textures;
        sf::Sprite *frames;

    private:
        std::string name;
        int f_nr;
        float length;
        //sf::Sprite *frames;
        bool run_animation;
        sf::Sprite **spr;
        sf::Time init;
//        SimpleImage *current_frame;



};

#endif // ANIMATION_H
