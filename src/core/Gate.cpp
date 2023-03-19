#include "Gate.h"
#include "Enum.h"
#include "Vector2D.h"
#include <math.h>

Gate::Gate(int x, int y, GateType gateType, BlockType type) : Block( x, y, type)
{
    this->gateType = gateType;

}

void Gate::addInput(Vector2D * v)
{
    input.push_back(v);
}

void Gate::addOutput(Vector2D * v)
{
    output.push_back(v);
}

bool Gate::isSolid()
{
    return false;
}


void Gate::update(Player& p0,Player& p1, Level& currentLevel)
{
        
}

int Gate::getX()
{
    return tileX;
}

int Gate::getY()
{
    return tileY;
}