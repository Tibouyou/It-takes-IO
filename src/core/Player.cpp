#include <iostream>
#include "Player.h"

Player::Player(bool playerType, int x, int y, int height, int width) : Entity( x, y, height, width)
{
    this->playerType = playerType;
    heldItem = NULL;
    velocity = 0;
    isFalling = false;
    isJumping = false;
    direction = false;
    isAlive = true;
}

Player::~Player()
{
    delete heldItem;
}

void Player::jump()
{
    if (!isJumping)
    {
        velocity = 10;
        isJumping = true;
    }
}

void Player::update(const Level& currentLevel)
{
    /// oui
}

void Player::setDead()
{
    isAlive = !isAlive;
}

