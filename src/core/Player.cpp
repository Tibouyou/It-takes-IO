#include <iostream>
#include "Player.h"
#include "Level.h"
#include <math.h>

Player::Player(bool playerType, int x, int y, int height, int width) : Entity( x, y, height, width)
{
    this->playerType = playerType;
    heldItem = nullptr;
    gravity = 0;
    isFalling = false;
    isJumping = false;
    direction = false;
    isAlive = true;;
}

Player::~Player()
{
    delete heldItem;
}

void Player::jump()
{
    if (!isJumping) {
    gravity = 10;
    isJumping = true;
    }
}

void Player::update(const Level& currentLevel)
{
    if (gravity <= 0) {
        isJumping = false;
    }
    if (gravity > 0) {
        gravity -= 0.5;
    }
    y += gravity;
    y-=5;
    std::cout << "Player X: " << getTileX() << " Player Y: " << getTileY() << std::endl;
    std::cout << "Collidable ? " << currentLevel.getBlock(getTileX(),getTileY()).isSolid() << std::endl;
    if (currentLevel.getBlock(getTileX(),getTileY()).isSolid()) {
        y += 5;
    }
}

void Player::setDead()
{
    isAlive = !isAlive;
}

float Player::getGravity()
{
    return gravity;
}

int Player::getTileX()
{
    return floor(x/50);
}

int Player::getTileY()
{
    return floor(y/50);
}

