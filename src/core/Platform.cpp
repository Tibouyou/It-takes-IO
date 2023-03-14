#include "Platform.h"
#include "Block.h"

Platform::Platform(int x, int y) : Block( x, y)
{
}

bool Platform::isSolid()
{
    return true;
}