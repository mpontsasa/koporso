#include "../koporso/StandardSO.h"

void StandardSO::drawThis()
{
    switch (AnimationState)
    {
    case lie:
        set_lie();
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

    ScreenRoot::access().window->draw(sprite);
}

