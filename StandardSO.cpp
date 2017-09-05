#include "../koporso/StandardSO.h"

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
    if ((xValue + introTriggerDistance < gameView.view.getCenter().x + gameView.view.getSize().x / 2 && xValue + introTriggerDistance > gameView.view.getCenter().x - gameView.view.getSize().x / 2)    //on the screen from right
        || (xValue + width - introTriggerDistance < gameView.view.getCenter().x + gameView.view.getSize().x / 2 && xValue + width - introTriggerDistance > gameView.view.getCenter().x - gameView.view.getSize().x / 2))    //on the screen from left
    {
        in_out_start = gameClock.getElapsedTime();    // start the animation timer for intro
        AnimationState = intr;  //  start the intro
        return 0;   //not lying anymore
    }
    return 1;   //still lying
}

void StandardSO::set_stand()
{
    if (xValue + width - outroTriggerDistance < gameView.view.getCenter().x - gameView.view.getSize().x / 2 || xValue + introTriggerDistance > gameView.view.getCenter().x + gameView.view.getSize().x / 2)   //out of the screen
    {
        in_out_start = gameClock.getElapsedTime();    // start the animation timer for outro
        AnimationState = outr;  //  start the outro
    }
}

