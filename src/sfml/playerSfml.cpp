#include "playerSfml.h"
#include <cmath>
#include <iostream>
#include <string>

PlayerSfml::PlayerSfml(Player * player, bool playerType)
{
    this->player = player;
    this->animationFrame = 0;
    if (playerType) {
        this->texture.loadFromFile("data/player/sp_1.png");
    } else {
        this->texture.loadFromFile("data/player/sp_0.png");
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(animationFrame, 0, 150, 400));
    this->sprite.setPosition(player->getX(), player->getY()+50);
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
    if (player->getMoving()) {
        if (this->WalkingClock.getElapsedTime().asSeconds() > 0.1) {
            this->animationFrame = (this->animationFrame + 1) % 4;
            this->WalkingClock.restart();
        }
    } else {
        this->animationFrame = 0;
    }

    if (player->getHeldItem() != nullptr) {
        this->sprite.setTextureRect(sf::IntRect(animationFrame*150, 400, 150, 400));
    } else {
        this->sprite.setTextureRect(sf::IntRect(animationFrame*150, 0, 150, 400));
    }

    if (player->getOnGround() && !player->getMoving()) {
        if (player->getHeldItem() != nullptr)
            this->sprite.setTextureRect(sf::IntRect(0, 1200, 150, 400));
        else
            this->sprite.setTextureRect(sf::IntRect(0, 800, 150, 400));
    }

    if (player->getDirection()) {
        this->sprite.setPosition(player->getX(), player->getY()+50);
    } else {
        this->sprite.setPosition(player->getX()+35, player->getY()+50);
    }
    
}

PlayerSfml::~PlayerSfml()
{
}

sf::Sprite PlayerSfml::getSprite()
{
    return this->sprite;
}

