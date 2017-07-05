#include "ScreenObject.h"

ScreenRoot& ScreenRoot::access()
{
    static ScreenRoot *sr = new ScreenRoot;
    return *sr;
}
