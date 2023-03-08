#ifndef _PLAYER_H
#define _PLAYER_H

#include "Entity.h"
#include "Pickable.h"

class Player : public Entity
{
    private:
        bool playerType;
        Pickable* heldItem;
        float velocity;
        bool isFalling;
        bool isJumping;
        bool direction;
        bool isAlive;

    public:
        Player(bool playerType, int x, int y, int height, int width);
        ~Player();
        void jump();
        void update(const Level& currentLevel);
        void setDead();
};

#endif