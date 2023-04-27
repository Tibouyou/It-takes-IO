#include <iostream>
#include "Entity.h"
#include "Level.h"
#include <math.h>

Entity::Entity(float x, float y, int height, int width, int spriteSize, float originX, float originY)
{
    this->x = x;
    this->y = y;
    this->originX = originX;
    this->originY = originY;
    this->height = height;
    this->width = width;
    this->spriteSize = spriteSize;
}

Entity::~Entity()
{
}

int Entity::getX() const
{
    return x;
}

int Entity::getY() const
{
    return y;
}

int Entity::getTileX(int offset)
{
    return floor((x+offset)/spriteSize);
}

int Entity::getTileY(int offset)
{
    return floor((y+offset)/spriteSize);
}

void Entity::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Entity::getHeight() const
{
    return height;
}

int Entity::getWidth() const
{
    return width;
}

