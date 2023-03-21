#ifndef _LEVEL_H
#define _LEVEL_H

#include "Pickable.h"
#include "Player.h"
#include "Block.h"
#include "Cable.h"
#include "Entity.h"
#include <vector>
#include "Receptacle.h"
#include "Gate.h"
#include "Door.h"

class Level
{
    private :
        /**
         * @brief The player 0
         * 
         */
        Player * p0;

        /**
         * @brief The player 1
         * 
         */
        Player * p1;

        /**
         * @brief The final door of the level
         * 
         */
        Door * door;

        /**
         * @brief The list of the block of the level
         * 
         */
        std::vector<Block*> tabBlock;

        /**
         * @brief The list of the gate of the level
         * 
         */
        std::vector<Gate*> tabGate;

        /**
         * @brief The list of the cable of the level
         * 
         */
        std::vector<Cable*> tabCable;

        /**
         * @brief The list of the pickable of the level
         * 
         */
        std::vector<Pickable*> tabPickable;

        /**
         * @brief The number of the level
         * 
         */
        int levelNumber;

        /**
         * @brief The height of the level
         * 
         */
        int height;

        /**
         * @brief The width of the level
         * 
         */
        int width;

        /**
         * @brief If the level is won or not
         * 
         */
        bool isWon;

    public :
        /**
         * @brief Construct a new Level object
         * 
         * @param levelNumber 
         */
        Level(int levelNumber);

        /**
         * @brief Destroy the Level object
         * 
         */
        ~Level();

        /**
         * @brief Get the height of the level
         * 
         * @return int The height of the level
         */
        int getHeight() const;

        /**
         * @brief Get the width of the level
         * 
         * @return int The width of the level
         */
        int getWidth() const;

        /**
         * @brief Load the level from a txt file
         * 
         */
        void loadLevel();

        /**
         * @brief Reset the level
         * 
         */
        void resetLevel();

        /**
         * @brief Function called when the level is update
         * 
         */
        void update();

        /**
         * @brief Function called when the level is won
         * 
         */
        void win();

        /**
         * @brief Get if the level is won or not
         * 
         * @return true If the level is won
         * @return false If the level is not won
         */
        bool getWin() const;

        /**
         * @brief Get the list of the Gate of the level
         * 
         * @return std::vector<Gate*> The list of the Gate of the level
         */
        std::vector<Gate*> getGate() const;

        /**
         * @brief Get the list of the Pickable of the level
         * 
         * @return std::vector<Pickable*> The list of the Pickable of the level
         */
        std::vector<Pickable*> getPickable() const;

        /**
         * @brief Get the Block object at the position (x,y)
         * 
         * @param x The x position of the Block
         * @param y The y position of the Block
         * @return Block* The Block at the position (x,y)
         */
        Block * getBlock(int x, int y) const;

        /**
         * @brief Get the Cable object at the position (x,y)
         * 
         * @param x 
         * @param y 
         * @return Cable* The Cable at the position (x,y)
         */
        Cable * getCable(int x, int y) const;

        /**
         * @brief Get the Player 0 object
         * 
         * @return Player* The Player 0 object
         */
        Player * getPlayer0() const;

        /**
         * @brief Get the Player 1 object
         * 
         * @return Player* The Player 1 object
         */
        Player * getPlayer1() const;

        /**
         * @brief Get the final Door object
         * 
         * @return Door* The final Door object
         */
        Door * getDoor() const;
}; 


#endif
