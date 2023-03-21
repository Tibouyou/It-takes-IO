#ifndef _BLOCK_H
#define _BLOCK_H

#include "Enum.h"
#include "Player.h"

class Level;

class Block
{
    protected :
        /**
         * @brief The position x of the block in the level
         * 
         */
        int tileX;
        /**
         * @brief The position y of the block in the level
         * 
         */
        int tileY;
        /**
         * @brief The type of the block
         * 
         */
        BlockType type;

    public :

        /**
         * @brief Construct a new Block object
         * 
         * @param x The position x of the block in the level
         * @param y The position y of the block in the level
         * @param type The type of the block
         */
        Block(int x = 0, int y = 0, BlockType type = AIR);

        /**
         * @brief Destroy the Block object
         * 
         */
        virtual ~Block();

        /**
         * @brief Get the solidity of the block
         * 
         * @return bool True if the block is solid, false otherwise
         */
        virtual bool isSolid();

        /**
         * @brief Get blockType of the block
         * 
         * @return BlockType The type of the block
         */
        BlockType getType();
        /**
         * @brief Overridable function for the block to do something when it is powered
         * 
         * @param type The type of the power
         * @param currentLevel The actual level
         */
        virtual void power(PowerType type, const Level& currentLevel);

        /**
         * @brief Overridable function for the block to do something when it is updated
         * 
         * @param p0 The first player
         * @param p1 The second player
         * @param currentLevel The actual level 
         */
        virtual void update(Player& p0, Player& p1, Level& currentLevel);
}; 


#endif




