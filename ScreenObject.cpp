#include "ScreenObject.h"

void ScreenObject::draw()
{
    drawThis();
    auto dinIter = dinamicObjectList.begin();
    auto statIter = staticObjectList.begin();

    while(dinIter != dinamicObjectList.end() && statIter != staticObjectList.end())
    {
        if ((*dinIter) -> zValue < (*statIter) -> zValue)
        {
            (*dinIter) -> draw();
            dinIter ++;
        }
        else
        {
            (*statIter) -> draw();
            statIter ++;
        }
    }

}

ScreenRoot& ScreenRoot::access()
{
    static ScreenRoot root;
    return root;
}
