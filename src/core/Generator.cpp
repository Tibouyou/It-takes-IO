#include "Generator.h"
#include "Level.h"

Generator::Generator(int x, int y, PowerType powerType, BlockType type) : Block(x, y, type)
{
    this->powerType = powerType;
}

bool Generator::isSolid()
{
    return false;
}

PowerType Generator::getPowerType()
{
    return powerType;
}

void Generator::update(Player &p0, Player &p1, Level &currentLevel){
    currentLevel.getCable(tileX, tileY)->power(powerType, PowerDirection::NONE, currentLevel);
}

void Generator::power(PowerType type, const Level& currentLevel, unsigned char directionMask)
{
    
}
