#include <iostream>
#include "Enum.h"
#include "Player.h"
#include "Level.h"
#include <math.h>
#include "Receptacle.h"

Player::Player(bool playerType, int x, int y, int height, int width) : Entity( x, y, height, width)
{
    this->playerType = playerType;
    heldItem = nullptr;
    gravity = 0;
    isFalling = false;
    isJumping = false;
    isMoving = false;
    direction = false;
    isAlive = true;
}

Player::~Player()
{
    //delete heldItem;
}

void Player::jump()
{
    if (!isJumping && !isFalling) {
    gravity = 30;
    isJumping = true;
    }
}

void::Player::moveLeft(int x)
{
    this->x -= x;
}

void Player::moveRight(int x)
{
    this->x += x;
}

void Player::update(const Level& currentLevel)
{
    if (gravity >= 200) {
        gravity = 0;
        isFalling = true;
        isJumping = false;
    }
    if (currentLevel.getBlock(getTileX(),getTileY(-gravity/100))->isSolid()) {
        gravity = 0;
        isFalling = true;
        isJumping = false;
    }
    if (!isJumping && !currentLevel.getBlock(getTileX(),getTileY())->isSolid()) {
        isFalling = true;
    }
    if (currentLevel.getBlock(getTileX(),getTileY(49))->isSolid()) {
        y = getTileY()*50;
        isFalling = false;
    }
    y -= gravity/100;

}

void Player::setDead()
{
    isAlive = false;
}

bool Player::getAlive() const 
{
    return isAlive;
}

float Player::getGravity()
{
    return gravity;
}

void Player::use(const Level& currentLevel)
{
    if (!currentLevel.getDoor()->isOpened()) {
        if (heldItem == nullptr)  {
            pickUp(currentLevel);
        } else {
            drop(currentLevel);
        }
    }
}

void Player::pickUp(const Level& currentLevel)
{
    for (Pickable* pickable : currentLevel.getPickable()) {
        if (pickable->getTileX() == getTileX() && pickable->getTileY() == getTileY()) {
            heldItem = pickable;
            heldItem->toggleHeld();
            if (currentLevel.getBlock(getTileX(),getTileY())->getType() == RECEPTACLE) dynamic_cast<Receptacle*>(currentLevel.getBlock(getTileX(),getTileY()))->setHeldItem(nullptr);
        }
    }
}

void Player::drop(const Level& currentLevel)
{
    Block* block = currentLevel.getBlock(getTileX(),getTileY());
    if (block->getType() == RECEPTACLE) {
        if (dynamic_cast<Receptacle*>(block)->getHeldItem() == nullptr) dynamic_cast<Receptacle*>(block)->setHeldItem(heldItem);
    } 
        
    heldItem->setPosition(getTileX()*50,getTileY()*50);
    heldItem->toggleHeld();
    heldItem = nullptr;
}

Pickable* Player::getHeldItem()
{
    return heldItem;
}

void Player::setMoving(bool isMoving) 
{
    this->isMoving = isMoving;
}

void Player::setDirection(bool direction)
{
    this->direction = direction;
}

bool Player::getDirection()
{
    return direction;
}

bool Player::getMoving()
{
    return isMoving;
}

void Player::addGravity(int value)
{
    gravity += value;
}

bool Player::getIsJumping()
{
    return isJumping;
}

bool Player::getIsFalling()
{
    return isFalling;
}