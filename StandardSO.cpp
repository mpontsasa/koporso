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

