#ifndef _PLAYERSFML_H
#define _PLAYERSFML_H

#include "../core/Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>

class PlayerSfml
{
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        int animationFrame;
        Player * player;
        sf::Clock WalkingClock;
        sf::Clock JumpingClock;

    public:
        PlayerSfml(Player * player, bool playerType);
        ~PlayerSfml();
        sf::Sprite getSprite();
        void update(float elapsed);
};

#endif