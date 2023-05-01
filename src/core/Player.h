#ifndef _PLAYER_H
#define _PLAYER_H

#include "Entity.h"
#include "Pickable.h"

class Player : public Entity
{
    private:
        /**
         * @brief type of the player
         * 
         */
        bool playerType;

        /**
         * @brief item held by the player
         * 
         */
        Pickable* heldItem;

        /**
         * @brief gravity of the player
         * 
         */
        float gravity;

        /**
         * @brief is the player moving
         * 
         */
        bool isMoving;

        /**
         * @brief is the player looking left or right 
         * 
         */
        bool direction;

        /**
         * @brief is the player alive
         * 
         */
        bool isAlive;

        /**
         * @brief is the player on the ground
         * 
         */
        bool isOnGround;

    public:
        /**
         * @brief Construct a new Player object
         * 
         * @param playerType type of the player
         * @param x x coordinate
         * @param y y coordinate
         * @param height height of the player
         * @param width width of the player
         */
        Player(bool playerType, float x, float y, int height, int width, int spriteSize, float originX, float originY);

        /**
         * @brief Destroy the Player object
         * 
         */
        ~Player();

        /**
         * @brief Make the player jump
         */
        void jump();

        /**
         * @brief Update of the player
         * 
         * @param currentLevel current level
         */
        void update(const Level& currentLevel, float elapsed = 1.0f);

        /**
         * @brief Set the player to dead
         */
        void setDead();

        /**
         * @brief Get if the player is alive 
         * 
         * @return true if the player is alive
         * @return false if the player is dead
         */
        bool getAlive() const;

        /**
         * @brief Pick up an item if the player is on it else drop it
         */
        void use(const Level& currentLevel);

        /**
         * @brief Pick up the item held by the player
         */
        void pickUp(const Level& currentLevel);

        /**
         * @brief Drop the item held by the player
         */
        void drop(const Level& currentLevel);

        /**
         * @brief Get item held by the player
         * 
         * @return Pickable* item held by the player
         */
        Pickable* getHeldItem();

        /**
         * @brief Get the gravity of the player
         * 
         * @return float gravity of the player
         */
        float getGravity();

        /**
         * @brief Set if the player is moving
         * 
         * @param isMoving true if the player is moving false otherwise
         */
        void setMoving(bool isMoving);

        /**
         * @brief Set the direction of the player
         * 
         * @param direction direction of the player true if right false if left
         */
        void setDirection(bool direction);

        /**
         * @brief Get the direction of the player
         * 
         * @return true if the player is looking right false otherwise
         */
        bool getDirection();

        /**
         * @brief Get if the player is moving
         * 
         * @return true if the player is moving false otherwise
         */
        bool getMoving();

        /**
         * @brief Get the collision on the y axis
         * 
         * @param currentLevel current level
         * @param moveX movement on the x axis
         * @return true if there is a collision false otherwise
         */
        bool getCollisionX(const Level& currentLevel, float moveX);

        /**
         * @brief Get if the player is on the ground
         * 
         * @return true if the player is on the ground
         * @return false  if the player is not on the ground
         */
        bool getOnGround();

        /**
         * @brief Set the player height
         * 
         * @param height height of the player
         */
        void setHeight(int height);
        
        /**
         * @brief Set the player width
         * 
         * @param width width of the player
         */
        void setWidth(int width);
        
        /**
         * @brief Set the player sprite size
         * 
         * @param spriteSize sprite size of the player
         */
        void setSpriteSize(int spriteSize);

        /**
         * @brief Get the player type
         * 
         * @return false if the player is player 0 true if the player is player 1
         */
        bool getPlayerType();

        /**
         * @brief Reset the player
         * 
         */
        void reset();
};

#endif