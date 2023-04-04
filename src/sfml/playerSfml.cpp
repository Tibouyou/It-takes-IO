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
    this->sprite.setScale((float)player->getHeight()/400, (float)player->getHeight()/400);

}

void PlayerSfml::update(float elapsed)
{
    std::cout << player->getGravity() << std::endl;
    this->sprite.setPosition(player->getX(), player->getY()+50);
    if (player->getIsJumping()) {
        player->addGravity(elapsed);
    } else if (player->getIsFalling()) {
        player->addGravity(-elapsed);
    }
    if (player->getMoving()) {
        if (player->getDirection()) {
            player->moveLeft(elapsed);
        } else {
            player->moveRight(elapsed);
        }
    }
}

PlayerSfml::~PlayerSfml()
{
}

sf::Sprite PlayerSfml::getSprite()
{
    return this->sprite;
}