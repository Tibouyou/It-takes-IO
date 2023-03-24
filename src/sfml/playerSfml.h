#ifndef _PLAYERSFML_H
#define _PLAYERSFML_H

#include "../core/Player.h"
#include <SFML/Graphics.hpp>

class PlayerSfml
{
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        int animationFrame;
        Player * player;

    public:
        PlayerSfml(Player * player);
        ~PlayerSfml();
        sf::Sprite getSprite();
        void update();

};

#endif