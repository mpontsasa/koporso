#include "Animation.h"

class TestAnimation : public Thing
{

public:
    FlippableAnimation *a;
    TestAnimation();
};

TestAnimation::TestAnimation() : Thing("../koporso/Resources/Stickman1.png",100,100,20)
{
    a=new FlippableAnimation("../koporso/Resources/Stickman",&sprite,2,sf::milliseconds(1000),208,298);
}
