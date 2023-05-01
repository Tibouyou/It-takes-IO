#ifndef _PLAYERSFML_H
#define _PLAYERSFML_H

#include "../core/Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>

class PlayerSfml
{
    private:
        /**
         * @brief The sprite of the player
         * 
         */
        sf::Sprite sprite;

        /**
         * @brief The texture of the player
         * 
         */
        sf::Texture texture;

        /**
         * @brief The current animation frame of the player
         * 
         */
        int animationFrame;

        /**
         * @brief The player wrapped by the sfml player
         * 
         */
        Player * player;

        /**
         * @brief The clock of the walking animation
         * 
         */
        sf::Clock WalkingClock;

        /**
         * @brief The clock of the jumping animation
         * 
         */
        sf::Clock JumpingClock;

        /**
         * @brief The clock of the death animation
         * 
         */
        sf::Clock deathClock;

        /**
         * @brief The size of the sprite
         * 
         */
        int spriteSize;

        /**
         * @brief Is the death animation done
         * 
         */
        bool deathAnimationDone = false;

        /**
         * @brief The current death animation frame
         * 
         */
        int deathAnimationFrame = 0;

    public:

        /**
         * @brief Construct a new PlayerSfml object
         * 
         * @param player The player to wrap
         * @param spriteSize The size of the sprite
         */
        PlayerSfml(Player * player, int spriteSize);

        /**
         * @brief Destroy the PlayerSfml object
         * 
         */
        ~PlayerSfml();

        /**
         * @brief Get the Sprite object
         * 
         * @return sf::Sprite The sprite of the player
         */
        sf::Sprite getSprite();

        /**
         * @brief Update the visual of the player
         * 
         * @param elapsed The elapsed time since the last update
         */
        void update(float elapsed);

        /**
         * @brief Get if the Death Animation is done
         * 
         * @return true if the death animation is done, false otherwise
         */
        bool getDeathAnimationDone();
};
#endif