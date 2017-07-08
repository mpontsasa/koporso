#include "ScreenObject.h"

void ScreenObject::draw()
{
    drawThis();
    auto dinIter = dinamicObjectList.begin();
    auto statIter = staticObjectList.begin();
}

ScreenRoot& ScreenRoot::access()
{
    static ScreenRoot root;
    return root;
}
