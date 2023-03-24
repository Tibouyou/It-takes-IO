#include "playerSfml.h"
#include <iostream>

PlayerSfml::PlayerSfml(Player * player)
{
    this->player = player;
    this->animationFrame = 0;
    this->texture.loadFromFile("data/player/sp_0.png");
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(0, 0, 125, 400));
    this->sprite.setPosition(player->getX(), player->getY()+50);
    this->sprite.setOrigin(0, 400);
    this->sprite.setScale((float)player->getWidth()/125, (float)player->getHeight()/400);

}

void PlayerSfml::update()
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