#ifndef _SENSORSFML_H
#define _SENSORSFML_H

#include "../core/Sensor.h"
#include "../core/Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

class SensorSfml
{
    private:
        /**
         * @brief The sensor wrapped by the sfml sensor
         * 
         */
        Sensor * sensor;

        /**
         * @brief The sprite of the sensor
         * 
         */
        sf::Sprite sprite;

        /**
         * @brief The texture of the sensor
         * 
         */
        sf::Texture texture;

        /**
         * @brief The size of the sprite
         * 
         */
        int spriteSize;

    public:

        /**
         * @brief Construct a new SensorSfml object
         * 
         * @param sensor The sensor to wrap
         * @param spriteSize The size of the sprite
         */
        SensorSfml(Block * sensor, int spriteSize);

        /**
         * @brief Destroy the SensorSfml object
         * 
         */
        ~SensorSfml();

        /**
         * @brief Get the Sprite object
         * 
         * @return sf::Sprite The sprite of the sensor
         */
        sf::Sprite getSprite();

        /**
         * @brief Update the visual of the sensor
         * 
         * @param p0 player 0
         * @param p1 player 1
         * @param elapsed time elapsed since the last update
         */
        void update(Player* p0, Player* p1, float elapsed);
};

#endif