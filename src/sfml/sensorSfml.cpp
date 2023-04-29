#include "sensorSfml.h"
#include <math.h>
#include <iostream>

SensorSfml::SensorSfml(Block * sensor, int spriteSize)
{

    this->texture.loadFromFile("data/object/sensor.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    this->sprite.setPosition(sensor->getX()*spriteSize, sensor->getY()*spriteSize);
    this->tileX = sensor->getX();
    this->tileY = sensor->getY();
    this->spriteSize = spriteSize;
    this->sprite.setScale((float)spriteSize/50, (float)spriteSize/50);
}

void SensorSfml::update(Player* p0, Player* p1,float elapsed)
{
   bool p0OnSensor = (p0->getTileX(p0->getWidth()/2) == tileX && p0->getTileY() == tileY);
    bool p1OnSensor = (p1->getTileX(p1->getWidth()/2) == tileX && p1->getTileY() == tileY);

    if (p0OnSensor || p1OnSensor)
    {
        this->sprite.setTextureRect(sf::IntRect(50, 0, 50, 50));
    }
    else
    {
        this->sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    }
}

SensorSfml::~SensorSfml()
{
    delete this->sensor;
}

sf::Sprite SensorSfml::getSprite()
{
    return this->sprite;
}

