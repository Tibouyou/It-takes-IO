#ifndef _TRAP_H
#define _TRAP_H

#include "Block.h"
#include "Player.h"

class Level;

class Trap : public Block
{
    public :
        /**
         * @brief Construct a new Trap object
         * 
         * @param x x coordinate
         * @param y y coordinate
         * @param type type of the block
         */

        Trap(int x, int y, BlockType type = TRAP);
        /**
         * @brief Get the solidity of the trap
         * 
         * @return false
         */
        bool isSolid();

        /**
         * @brief Update of the trap
         * 
         * @param p0 player 0
         * @param p1 player 1
         * @param currentLevel current level
         */
        void update(Player& p0, Player& p1, Level& currentLevel);
}; 

#endif