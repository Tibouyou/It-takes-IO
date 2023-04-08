#include <iostream>
#include "Entity.h"
#include "Level.h"
#include <math.h>

Entity::Entity(float x, float y, int height, int width)
{
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
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
    return floor((x+offset)/50);
}

int Entity::getTileY(int offset)
{
    return floor((y+offset)/50);
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
