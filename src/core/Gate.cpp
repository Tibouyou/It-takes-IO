#include "Gate.h"
#include "Enum.h"
#include "Vector2D.h"
#include <math.h>
#include "Level.h"

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


void Gate::update(Level& currentLevel)
{
    PowerType outputPower = EMPTY;
    switch (gateType)
    {
        case AND:
            for (Vector2D* input : input)
            {
                if (currentLevel.getCable(input->x, input->y)->getPowerType() != ONE) {
                    outputPower = EMPTY;
                    break;
                }
                outputPower = ONE;
            }
            
            for (Vector2D* output : output)
            {
                currentLevel.getCable(output->x, output->y)->power(outputPower, PowerDirection::NONE, currentLevel);
            }
            break;
    }
}

int Gate::getX()
{
    return tileX;
}

int Gate::getY()
{
    return tileY;
}