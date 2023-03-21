#ifndef _SFMLJEU_H
#define _SFMLJEU_H

#include "../core/Level.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

/**
    La classe g�rant le jeu avec un affichage SFML
*/

class sfmlJeu {

private :

	Level * level;
	sf::RenderWindow * m_window;

public :

    sfmlJeu ();
    ~sfmlJeu ();

    void sfmlInit();
    void sfmlBoucle();
    void sfmlAff();

};

#endif
