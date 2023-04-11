#ifndef _SENSORSFML_H
#define _SENSORSFML_H

#include "../core/Sensor.h"
#include "../core/Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

class SensorSfml
{
    private:
        Block * sensor;
        sf::Sprite sprite;
        sf::Texture texture;
        int tileX;
        int tileY;
        int spriteSize;

    public:
        SensorSfml(Block * sensor, int spriteSize);
        ~SensorSfml();
        sf::Sprite getSprite();
        void update(Player* p0, Player* p1, float elapsed);
};

#endif