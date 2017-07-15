#ifndef STANDARDSO_H
#define STANDARDSO_H

#include "ScreenObject.h"
#include "utility.h"


class StandardSO : public ScreenObject
{
    void drawThis();

protected:

    virtual void set_intro() = 0;   // Sets the object for drawing if intro
    virtual void set_outro() = 0;   // Sets the object for drawing if outro
    virtual void set_lie() = 0;   // Sets the object for drawing if lie
    virtual void set_stand() = 0;   // Sets the object for drawing if outro

    sf::Time in_out_time;   //Time of full in/outro
    sf::Time in_out_start;   //Time of in/outro beginning

    enum
    {
        lie, intr, stand, outr
    } AnimationState;

};

#endif //STANDARDSO_H
