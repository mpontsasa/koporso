#include "Animation.h"

class TestAnimation : public Thing
{

public:
    Animation *a;
    TestAnimation();
};

TestAnimation::TestAnimation() : Thing("../koporso/Resources/Stickman1.png",100,100,20)
    {a=new Animation("../koporso/Resources/Stickman",&sprite,2,1000,10);
    }
