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
         * @brief is the player falling
         * 
         */
        bool isFalling;

        /**
         * @brief is the player jumping
         * 
         */
        bool isJumping;

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
        Player(bool playerType, int x, int y, int height, int width);

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
         * @brief Make the player move left
         */
        void moveLeft();

        /**
         * @brief Make the player move right
         */
        void moveRight();

        /**
         * @brief Update of the player
         * 
         * @param currentLevel current level
         */
        void update(const Level& currentLevel);

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
};

#endif