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
    this->sprite.setTextureRect(sf::IntRect(0, 0, 125, 400));
    this->sprite.setPosition(player->getX(), player->getY()+50);
    this->sprite.setOrigin(0, 400);
    this->sprite.setScale((float)player->getHeight()/400, (float)player->getHeight()/400);
}

void PlayerSfml::update(float elapsed)
{
    this->sprite.setPosition(player->getX(), player->getY()+50);
}

PlayerSfml::~PlayerSfml()
{
}

sf::Sprite PlayerSfml::getSprite()
{
    return this->sprite;
}

