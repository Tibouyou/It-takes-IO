#include <iostream>
#include "Pickable.h"

Pickable::Pickable(PickableType type, int x, int y, int height, int width, int spriteSize, int originX, int originY) : Entity(x, y, height, width, spriteSize, originX, originY)
{
    this->type = type;
    this->isHeld = false;
}

Pickable::~Pickable()
{
}

void Pickable::update(const Level& currentLevel, float elapsed)
{
}

PickableType Pickable::getType()
{
    return type;
}

void Pickable::toggleHeld()
{
    isHeld = !isHeld;
}

bool Pickable::getHeld()
{
    return isHeld;
}

bool Pickable::getDirection()
{
    return direction;
}

void Pickable::setDirection(bool direction)
{
    this->direction = direction;
}

void Pickable::reset()
{
    isHeld = false;
    direction = false;
    x = originX;
    y = originY;
}
