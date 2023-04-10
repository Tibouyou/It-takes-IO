#include <iostream>
#include "Enum.h"
#include "Player.h"
#include "Level.h"
#include <math.h>
#include "Receptacle.h"

Player::Player(bool playerType, float x, float y, int height, int width) : Entity( x, y, height, width)
{
    this->playerType = playerType;
    heldItem = nullptr;
    gravity = 0.0f;
    isOnGround = true;
    isMoving = false;
    direction = false;
    isAlive = true;

}

Player::~Player()
{
    //delete heldItem;
}


void Player::update(const Level& currentLevel, float elapsed)
{
    gravity += 9.81f * elapsed;
    y += gravity*100*elapsed;


    if (currentLevel.getBlock(getTileX(1),getTileY(50))->isSolid() || currentLevel.getBlock(getTileX(35),getTileY(50))->isSolid()) {
        y = getTileY()*50;
        gravity = 0;
        isOnGround = true;
    } else isOnGround = false;
    if (currentLevel.getBlock(getTileX(1),getTileY(-50))->isSolid() || currentLevel.getBlock(getTileX(35),getTileY(-50))->isSolid()) {
        y = y+1;
        gravity = 0;
    } 
    
    if (isMoving) {
        if (direction) {
            if (!getCollisionX(currentLevel, -elapsed*300)) x -= elapsed*300;
        } else {
            if (!getCollisionX(currentLevel, elapsed*300+35)) x += elapsed*300;
        }
    }
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
        if (pickable->getTileX() == getTileX(15) && pickable->getTileY() == getTileY()) {
            heldItem = pickable;
            heldItem->toggleHeld();
            if (currentLevel.getBlock(getTileX(15),getTileY())->getType() == RECEPTACLE) dynamic_cast<Receptacle*>(currentLevel.getBlock(getTileX(),getTileY()))->setHeldItem(nullptr);
        }
    }
}

void Player::drop(const Level& currentLevel)
{
    if (isOnGround) {
    Block* block = currentLevel.getBlock(getTileX(),getTileY());
    if (block->getType() == RECEPTACLE) {
        if (dynamic_cast<Receptacle*>(block)->getHeldItem() == nullptr) dynamic_cast<Receptacle*>(block)->setHeldItem(heldItem);
    } 
        
    heldItem->setPosition(getTileX(15)*50,getTileY()*50);
    heldItem->toggleHeld();
    heldItem = nullptr;
    }
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

void Player::jump()
{
    if (isOnGround) gravity = -std::sqrt(2.0f * 9.81f * 2.5f);
}

bool Player::getDirection()
{
    return direction;
}

bool Player::getCollisionX(const Level &currentLevel, float moveX) {
    bool collision = false;
    for (int i = 0; i < height; i++) {
        if (currentLevel.getBlock(getTileX(moveX),getTileY(i-50))->isSolid()) {
            collision = true;
        }
    }
    return collision;
}

bool Player::getMoving()
{
    return isMoving;
}

bool Player::getOnGround()
{
    return isOnGround;
}