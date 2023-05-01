#include "Gate.h"
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

GateType Gate::getGateType()
{
    return gateType;
}

Gate::~Gate()
{
    for (Vector2D* input : input)
    {
        delete input;
    }
    input.clear();

    for (Vector2D* output : output)
    {
        delete output;
    }
    output.clear();
}

std::vector<Vector2D*> Gate::getInput()
{
    return input;
}

std::vector<Vector2D*> Gate::getOutput()
{
    return output;
}