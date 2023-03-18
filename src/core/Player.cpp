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
    if (!isJumping && !isFalling) {
    gravity = 15;
    isJumping = true;
    }
}

void::Player::moveLeft()
{
    x -= 5;
    direction = false;
}

void Player::moveRight()
{
    x += 5;
    direction = true;
}

void Player::update(const Level& currentLevel)
{
    if (gravity <= 0) {
        isJumping = false;
    }
    if (gravity > 0) {
        gravity -= 0.5;
    }
    y -= gravity;
    if (!isJumping && !currentLevel.getBlock(getTileX(),getTileY())->isSolid()) {
        isFalling = true;
    }
    if (isFalling){y+=5;}
    
    if (currentLevel.getBlock(getTileX(),getTileY())->isSolid()) {
        y = getTileY()*50-1;
        isFalling = false;
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

