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
    isMoving = false;
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
    isMoving = true;
    direction = false;
}

void Player::moveRight()
{
    isMoving = true;
    direction = true;
}

void Player::update(const Level& currentLevel)
{
    if (isMoving) {
        if (direction && !currentLevel.getBlock(getTileX(50),getTileY())->isSolid()) {
            x += 50;
        }
        else if(!direction && !currentLevel.getBlock(getTileX(-50),getTileY())->isSolid()) {
            x -= 50;
        }
    }
    if (gravity <= 0) {
        isJumping = false;
    }
    if (gravity > 0) {
        gravity -= 0.5;
    }
    if (currentLevel.getBlock(getTileX(),getTileY(-gravity))->isSolid()) {
        gravity = 0;
        isFalling = true;
    }
    y -= gravity;
    if (!isJumping && !currentLevel.getBlock(getTileX(),getTileY())->isSolid()) {
        isFalling = true;
    }
    if (isFalling){y+=10;}
    
    if (currentLevel.getBlock(getTileX(),getTileY())->isSolid()) {
        y = getTileY()*50-1;
        isFalling = false;
    }
    isMoving = false;
}

void Player::setDead()
{
    isAlive = !isAlive;
}

float Player::getGravity()
{
    return gravity;
}

void Player::pickUp(const Level& currentLevel)
{
    if (heldItem == nullptr) {
        for (Pickable* pickable : currentLevel.getPickable()) {
            if (pickable->getTileX() == getTileX() && pickable->getTileY() == getTileY()) {
                heldItem = pickable;
                heldItem->setHeld();
                break;
            }
        }
    }
}

void Player::drop()
{
    if (heldItem != nullptr) {
        heldItem->setPosition(getTileX()*50,getTileY()*50);
        heldItem->setHeld();
        heldItem = nullptr;
    }
}

Pickable* Player::getHeldItem()
{
    return heldItem;
}

