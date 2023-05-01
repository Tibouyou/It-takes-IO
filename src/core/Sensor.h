#ifndef _SENSOR_H
#define _SENSOR_H

#include "Block.h"
#include "Player.h"

class Level;

class Sensor : public Block
{
    private :
        /**
         * @brief The state of the sensor
         * 
         */
        bool activated;
        /**
         * @brief The size of the sprite
         * 
         */
        int spriteSize;
    public :
        /**
         * @brief Construct a new Sensor object
         * 
         * @param x x coordinate
         * @param y y coordinate
         * @param type type of the block
         */
        Sensor(int x, int y, int spriteSize, BlockType type = SENSOR);

        /**
         * @brief Get the solidity of the sensor
         * 
         * @return false
         */
        bool isSolid();

        /**
         * @brief Update of the sensor
         * 
         * @param p0 player 0
         * @param p1 player 1
         * @param currentLevel current level
         */
        void update(Player& p0, Player& p1, Level& currentLevel);

        /**
         * @brief Get the state of the sensor
         * 
         * @return true if the sensor is activated, false otherwise
         */
        bool isActivated();
}; 
#endif