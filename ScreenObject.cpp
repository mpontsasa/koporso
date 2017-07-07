#include "ScreenObject.h"

ScreenRoot& ScreenRoot::access()
{
    static ScreenRoot root;
    return root;
}
