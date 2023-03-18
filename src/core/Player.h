#ifndef _PLAYER_H
#define _PLAYER_H

#include "Entity.h"
#include "Pickable.h"

class Player : public Entity
{
    private:
        bool playerType;
        Pickable* heldItem;
        float gravity;
        bool isFalling;
        bool isJumping;
        bool isMoving;
        bool direction;
        bool isAlive;

    public:
        Player(bool playerType, int x, int y, int height, int width);
        ~Player();
        void jump();
        void moveLeft();
        void moveRight();
        void update(const Level& currentLevel);
        void setDead();
        void pickUp(const Level& currentLevel);
        void drop();
        Pickable* getHeldItem();
        float getGravity();
};

#endif