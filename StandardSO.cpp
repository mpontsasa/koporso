#include "../koporso/StandardSO.h"
#include <iostream>

void StandardSO::drawThis()
{
    switch (AnimationState)
    {
    case lie:
        if (set_lie())  // if not in the screen, dont draw
            return;
        break;
    case intr:
        set_intro();
        break;
    case stand:
        set_stand();
        break;
    case outr:
        set_outro();
        break;
    }

    ScreenRoot::access().window->draw(*sprite);
}

bool StandardSO::set_lie()
{

    if ((xInView(leftTriggerPoint()) && rightTriggerPoint() > getViewLeftBorder())
        || (xInView(rightTriggerPoint()) && leftTriggerPoint() < getViewRightBorder()))
    {
        in_out_start = gameClock.getElapsedTime();    // start the animation timer for intro
        AnimationState = intr;  //  start the intro
        return 0;   //not lying anymore

    }
    return 1;   //still lying*/

}

void StandardSO::set_stand()
{

    if(rightTriggerPoint() < getViewLeftBorder() || leftTriggerPoint() > getViewRightBorder())
    {
        in_out_start = gameClock.getElapsedTime();    // start the animation timer for outro
        AnimationState = outr;  //  start the outro
    }

}

