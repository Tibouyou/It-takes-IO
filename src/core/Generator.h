#ifndef _GENERATOR_H
#define _GENERATOR_H

#include "Enum.h"
#include "Block.h"

class Level;

class Generator : public Block
{
    private :

        PowerType powerType;

    public :
        /**
         * @brief Construct a new Generator object
         * 
         * @param x x coordinate
         * @param y y coordinate
         * @param type type of the block
         */
        Generator(int x, int y, PowerType powerType, BlockType type = GENERATOR);

        /**
         * @brief Get the solidity of the generator
         * 
         * @return false
         */
        bool isSolid();

        /**
         * @brief Function called when the generator is powered
         * 
         * @param type type of the power
         * @param currentLevel current level
         */
        void power(PowerType type, const Level& currentLevel, unsigned char directionMask);

        /**
         * @brief Get the power type of the generator
         * 
         * @return PowerType 
         */
        PowerType getPowerType();

        /**
         * @brief Function called when the generator is update
         */
        void update(Player &p0, Player &p1, Level &currentLevel);
}; 


#endif