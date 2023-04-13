#ifndef _DOOR_H
#define _DOOR_H

#include "Enum.h"
#include "Block.h"
#include "Player.h"

class Level;

class Door : public Block
{
    private :

        /**
         * @brief if the door is open or not
         * 
         */
        bool open;

        /**
         * @brief if the level is won or not
         * 
         */
        bool win;

    public :

        /**
         * @brief Construct a new Door object
         * 
         * @param x The position x of the door in the level
         * @param y The position y of the door in the level
         * @param type The type of the door
         */
        Door(int x, int y, BlockType type = DOOR);

        /**
         * @brief Get the solidity of the door
         * 
         * @return bool True if the door is solid, false otherwise
         */
        bool isSolid();

        /**
         * @brief Get the open state of the door
         * 
         * @return bool True if the door is open, false otherwise
         */
        bool isOpened();

        /**
         * @brief Set the open state of the door
         */
        void setOpen();

        /**
         * @brief Function called when the door is update
         */
        void update(Player& p0, Player& p1, Level& currentLevel);

};

#endif