#ifndef _SFMLJEU_H
#define _SFMLJEU_H

#include "../core/Level.h"
#include "blockSfml.h"
#include "playerSfml.h"
#include "sensorSfml.h"
#include "../sfml/menu/Menu.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>

/**
    La classe g�rant le jeu avec un affichage SFML
*/

class sfmlJeu {

private :

    /**
     * @brief The size of the sprite
     * 
     */
    int spriteSize;

    /**
     * @brief The level to display
     * 
     */
	Level * level = nullptr;

    /**
     * @brief The window of the game
     * 
     */
	sf::RenderWindow * m_window = nullptr;

    /**
     * @brief The visual wrapper of the player 0
     * 
     */
    PlayerSfml * playerSfml0 = nullptr;

    /**
     * @brief The visual wrapper of the player 1
     * 
     */
    PlayerSfml * playerSfml1 = nullptr;

    /**
     * @brief The main menu of the game
     * 
     */
    Menu * menu = nullptr;

    /**
     * @brief List of the wrappers of the sensors of the level
     * 
     */
    std::vector<SensorSfml*> sensorsSfml;

    /**
     * @brief List of the wrappers of the blocks of the level
     * 
     */
    std::vector<BlockSfml*> blocksSfml;

    /**
     * @brief The sprite of the background of the level
     * 
     */
    sf::Sprite background;

    /**
     * @brief The sprite of the door of the level
     * 
     */
    sf::Sprite door;

    /**
     * @brief The clock of the door animation
     * 
     */
    sf::Clock doorClock;

    /**
     * @brief The texture of the door of the level
     * 
     */
    sf::Texture doorTexture;

    /**
     * @brief The texture of the background of the level
     * 
     */
    sf::Texture backgroundTexture;

    /**
     * @brief The texture of the inactive cable
     */
    sf::Texture elec;

    /**
     * @brief The texture of the active cable
     */
    sf::Texture elecAct;

    /**
     * @brief The texture of the and gate 
     */
    sf::Texture gateAnd;

    /**
     * @brief The texture of the pickable no
     */
    sf::Texture pickN;

    /**
     * @brief The texture of the generator 0
     */
    sf::Texture generator0;

    /**
     * @brief The texture of the generator 1
     */
    sf::Texture generator1;

    /**
     * @brief The music of the game
     */
    sf::Music music;

    /**
     * @brief The buffer of the sound of the electricity
     */
    sf::SoundBuffer buffer;

    /**
     * @brief The sound of the electricity
     */
    sf::Sound sound;

    /**
     * @brief The number of the current level
     */
    int levelNumber;

    /**
     * @brief The number of the maximum level
     */
    int levelMax;

    /**
     * @brief The current frame of the door animation
     */
    int frameDoor;

public :

    /**
     * @brief Construct a new sfmlJeu object
     * 
     */
    sfmlJeu ();

    /**
     * @brief Destroy the sfmlJeu object
     * 
     */
    ~sfmlJeu ();

    /**
     * @brief Initialize the game
     * 
     */
    void sfmlInit();

    /**
     * @brief Helper method to reset the level before switching to another
     * 
     */
    void freeAndClearWrappers();

    /**
     * @brief The main loop of the game
     * 
     */
    void sfmlBoucle();

    /**
     * @brief Display the game
     * 
     */
    void sfmlAff();

    /**
     * @brief Display the animation of the door
     * 
     */
    void animDoor();

    /**
     * @brief Load the curent level
     * 
     */
    void loadLevel();

    /**
     * @brief Display the menu
     * 
     */
    void sfmlMenu();
};

#endif
