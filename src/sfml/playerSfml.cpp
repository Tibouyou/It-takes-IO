#include "playerSfml.h"
#include <cmath>
#include <iostream>
#include <string>

PlayerSfml::PlayerSfml(Player * player, int spriteSize)
{
    this->spriteSize = spriteSize;
    this->player = player;
    this->animationFrame = 0;
    if (player->getPlayerType()) {
        this->texture.loadFromFile("data/player/sp_1.png");
        player->setHeight(spriteSize*1.5);
        player->setWidth(player->getHeight()*150/400);
    } else {
        this->texture.loadFromFile("data/player/sp_0.png");
        player->setHeight(spriteSize);
        player->setWidth(player->getHeight()*150/400);
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(animationFrame, 0, 150, 400));
    this->sprite.setPosition(player->getX(), player->getY()+spriteSize);
    this->sprite.setOrigin(0, 400);
    this->sprite.setScale((float)player->getHeight()/400, (float)player->getHeight()/400);
}

void PlayerSfml::update(float elapsed)
{
    if (player->getDirection()) {
        this->sprite.setScale((float)player->getHeight()/400, (float)player->getHeight()/400);
    } else {
        this->sprite.setScale(-(float)player->getHeight()/400, (float)player->getHeight()/400);
    }
    if (!player->getOnGround()) {
        animationFrame = 1;
    } else if (player->getMoving()) {
        if (this->WalkingClock.getElapsedTime().asSeconds() > 0.1) {
            this->animationFrame = (this->animationFrame + 1) % 4;
            this->WalkingClock.restart();
        }
    } else {
        this->animationFrame = 0;
    }

    if (player->getHeldItem() != nullptr) {
        if (player->getOnGround()) {
            this->sprite.setTextureRect(sf::IntRect(animationFrame*150, 400, 150, 400));
        }  else {
            this->sprite.setTextureRect(sf::IntRect(animationFrame*150, 1200, 150, 400));
        }
    } else {
        if (player->getOnGround()) {
            this->sprite.setTextureRect(sf::IntRect(animationFrame*150, 0, 150, 400));
        } else {
            this->sprite.setTextureRect(sf::IntRect(animationFrame*150, 800, 150, 400));
        }
    }

    if (player->getOnGround() && !player->getMoving()) {
        if (player->getHeldItem() != nullptr)
            this->sprite.setTextureRect(sf::IntRect(0, 1200, 150, 400));
        else
            this->sprite.setTextureRect(sf::IntRect(0, 800, 150, 400));
    }

    if (player->getDirection()) {
        this->sprite.setPosition(player->getX(), player->getY()+spriteSize);
    } else {
        this->sprite.setPosition(player->getX()+player->getWidth(), player->getY()+spriteSize);
    }
    
}

PlayerSfml::~PlayerSfml()
{
    delete player;
}

sf::Sprite PlayerSfml::getSprite()
{
    return this->sprite;
}

