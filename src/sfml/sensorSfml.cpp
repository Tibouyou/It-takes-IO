#include "sensorSfml.h"
#include <math.h>
#include <iostream>

SensorSfml::SensorSfml(Block * sensor)
{

    this->texture.loadFromFile("data/object/sensor.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
    this->sprite.setPosition(sensor->getX()*50, sensor->getY()*50);
    this->tileX = sensor->getX();
    this->tileY = sensor->getY();
}

void SensorSfml::update(Player* p0, Player* p1,float elapsed)
{
    bool p0OnSensor = (floor(p0->getX()/50) == tileX && floor(p0->getY()/50) == tileY);
    bool p1OnSensor = (floor(p1->getX()/50) == tileX && floor(p1->getY()/50) == tileY);
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
}

sf::Sprite SensorSfml::getSprite()
{
    return this->sprite;
}

