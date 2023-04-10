#ifndef _SENSOR_H
#define _SENSOR_H

#include "Block.h"
#include "Player.h"

class Level;

class Sensor : public Block
{
    private :
        bool activated;
    public :
        /**
         * @brief Construct a new Sensor object
         * 
         * @param x x coordinate
         * @param y y coordinate
         * @param type type of the block
         */
        Sensor(int x, int y, BlockType type = SENSOR);

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

        bool isActivated();
}; 


#endif