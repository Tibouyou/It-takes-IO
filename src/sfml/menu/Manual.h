#ifndef _MANUAL_H
#define _MANUAL_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;
using namespace std;

class Manual 
{
    private :
        string menuTitle;
        sf::RenderWindow * m_window;
        vector<Button*> buttons;
        Button * buttonReturn;
        RectangleShape rectangleMenu;
        Font font;
        bool quit = false;
        bool play = true;
        int currentLevel = 0;
        sf::Sprite sprite;
        sf::Texture background;
        sf::Texture button;
        sf::Texture pickable;
        sf::Texture receptacle;
        sf::Texture gates;
        int currentPage = 0;

    public :
        Manual(int windowWidth, int windowHeight, sf::RenderWindow * m_window);
        ~Manual();

        void draw(RenderWindow *window);
        void click(int x, int y);
        void addButton (Button* button);
        bool getQuit();
        bool getPlay();
        void pause();
        int getCurrentLevel();
        void setLevel(int level);
        sf::Keyboard::Key getKeybind() const;
        void Open();
};

#endif 