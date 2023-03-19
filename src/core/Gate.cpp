#include "Gate.h"
#include "Enum.h"
#include "Vector2D.h"
#include <math.h>

Gate::Gate(int x, int y, GateType gateType, BlockType type) : Block( x, y, type)
{
    this->gateType = gateType;

}

std::vector<Vector2D*> Gate::getInput()
{
    return input;
}

std::vector<Vector2D*> Gate::getOutput()
{
    return output;
}

bool Gate::isSolid()
{
    return false;
}


void Gate::update(Player& p0,Player& p1, Level& currentLevel)
{
        
}