#ifndef STANDARDSO_H
#define STANDARDSO_H

#include "ScreenObject.h"
#include "utility.h"
#include <SFML/System/Vector2.hpp>

class StandardSO : public ScreenObject
{
    void drawThis();
    bool hit(sf::Vector2i point){return 1;} ///test

    int rightTriggerPoint(){return getRight() - triggerDistance;}
    int leftTriggerPoint(){return getLeft() + triggerDistance;}

protected:

    virtual void set_intro() = 0;   // Sets the object for drawing if intro
    virtual void set_outro() = 0;   // Sets the object for drawing if outro
    virtual bool set_lie();   // Sets the object for drawing if lie
    virtual void set_stand();   // Sets the object for drawing if outro

    sf::Time in_out_time;   //Time of full in/outro
    sf::Time in_out_start;   //Time of in/outro beginning

    enum enumname
    {
        lie, intr, stand, outr
    } AnimationState;

    sf::Texture *texture;
    sf::Sprite *sprite;
};

#endif //STANDARDSO_H
