#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>

class Animation
{
public:
    Animation(const std::string name_, sf::Sprite **spr, int frame_nr, sf::Time length, int x = 100, int y = 100, bool flippable = 0);
    ~Animation();

    void play_animation();  //animation starter
    void update_animation();    //must be called in every frame while the animation is running(to refresh), before setting the position of the sprite
    void update_animation(bool direction);

private:
    std::string name;   //general name of the frames with access path

    int f_nr;   //number of frames
    bool *flipped;  //0=non-flippable, 1=flippable

    sf::Time length;   //the time it takes to play an entire animation

    sf::Time interval;  //time interval between changing frames
    sf::Time init;  //time when the animation started

    sf::Sprite **spr;   //points on the sprite of the current frame
    sf::Texture *textures;
    sf::Sprite *frames;

};

#endif // ANIMATION_H
