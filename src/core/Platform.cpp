#include "Platform.h"
#include "Block.h"
#include <iostream>

Platform::Platform(int x, int y, BlockType type) : Block( x, y, type)
{
}

bool Platform::isSolid()
{
    return true;
}