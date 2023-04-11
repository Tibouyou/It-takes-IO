#ifndef _SFMLJEU_H
#define _SFMLJEU_H

#include "../core/Level.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#include "playerSfml.h"
#include "sensorSfml.h"

/**
    La classe g�rant le jeu avec un affichage SFML
*/

class sfmlJeu {

private :

    int spriteSize;
	Level * level;
	sf::RenderWindow * m_window;
    PlayerSfml * playerSfml0;
    PlayerSfml * playerSfml1;
    sf::Sprite door;
    sf::Texture doorTexture;
    int frameDoor;
    sf::Clock doorClock;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    std::vector<SensorSfml*> sensorsSfml;

public :

    sfmlJeu ();
    ~sfmlJeu ();

    void sfmlInit();
    void sfmlBoucle();
    void sfmlAff();
    void animDoor();
};

#endif
