#include "Animation.h"

class TestAnimation
{
    TestAnimation();

public:
    Animation *a;
};

TestAnimation::TestAnimation()
    {a=new Animation("Stickman",2,2,10);
    }
