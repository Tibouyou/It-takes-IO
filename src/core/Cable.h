#ifndef _CABLE_H
#define _CABLE_H 

#include "Entity.h" 
#include "Enum.h"

class Level;

class Cable 
{
    private : 

        /**
         * @brief The position x of the cable in the level
         * 
         */
        int tileX; 

        /**
         * @brief The position y of the cable in the level
         * 
         */
        int tileY;

        /**
         * @brief The powerType of the cable
         * 
         */
        PowerType cablePower;

        /**
         * @brief The directionMask of the cable
         * 
         */
        unsigned char directionMaskCable;

    public :

        /**
         * @brief Construct a new Cable object
         * 
         * @param tileX The position x of the cable in the level
         * @param tileY The position y of the cable in the level
         * @param directionMaskCable The directionMask of the cable
         * @param power The powerType of the cable
         */
        Cable(int tileX = 0, int tileY = 0, unsigned char directionMaskCable = PowerDirection::NONE,PowerType power = EMPTY);

        /**
         * @brief Function called when the cable is powered
         * 
         * @param power The powerType of the cable
         * @param directionMask The direction where the power come from
         * @param currentLevel The actual level
         */
        void power(PowerType power, unsigned char directionMask, const Level& currentLevel);

        /**
         * @brief Reset the power of the Cable
         */
        void reset();

        /**
         * @brief Get the directionMask of the cable
         * 
         * @return unsigned char The directionMask of the cable
         */
        unsigned char getDirectionMask();

        /**
         * @brief Get the powerType of the cable
         * 
         * @return PowerType The powerType of the cable
         */
        PowerType getPowerType();
};

#endif