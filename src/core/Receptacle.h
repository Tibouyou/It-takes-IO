#ifndef _RECEPTACLE_H
#define _RECEPTACLE_H

#include "Enum.h"
#include "Pickable.h"
#include "Block.h"

class Level;

class Receptacle : public Block
{
    private :
        /**
         * @brief item held by the receptacle
         * 
         */
        Pickable * heldItem;

    public :
        /**
         * @brief Construct a new Receptacle object
         * 
         * @param x x coordinate
         * @param y y coordinate
         * @param type type of the block
         */
        Receptacle(int x, int y, BlockType type = RECEPTACLE);

        /**
         * @brief Get the solidity of the receptacle
         * 
         * @return false
         */
        bool isSolid();

        /**
         * @brief Get the held item by the receptacle
         * 
         * @return Pickable*
         */        
        Pickable * getHeldItem();

        /**
         * @brief Set the held item by the receptacle
         * 
         * @param item pickable to set
         */
        void setHeldItem(Pickable * item);

        /**
         * @brief Function called when the receptacle is powered
         * 
         * @param type type of the power
         * @param currentLevel current level
         */
        void power(PowerType type, const Level& currentLevel, unsigned char directionMask);

        /**
         * @brief Function called when the receptacle is reset
         */
        void reset();
}; 


#endif