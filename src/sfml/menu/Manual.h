#ifndef _MANUAL_H
#define _MANUAL_H

#include "Button.h"

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Manual 
{
    private :
        std::string menuTitle;
        sf::RenderWindow * m_window;
        std::vector<Button*> buttons;
        Button * buttonReturn;
        sf::RectangleShape rectangleMenu;
        sf::Font font;
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

        void draw(sf::RenderWindow *window);
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