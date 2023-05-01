#ifndef _MENU_H
#define _MENU_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Manual.h"

class Menu 
{
    private :
        std::string menuTitle;
        sf::RenderWindow * m_window;
        std::vector<Button*> buttons;
        std::vector<Button*> selectLevelButtons;
        bool selectLevelMenuActive = false;
        bool manualMenuActive = false;
        sf::RectangleShape rectangleMenu;
        sf::Font font;
        bool quit = false;
        bool play = true;
        int currentLevel = 0;
        Manual * manual;

    public :
        Menu(int windowWidth, int windowHeight, sf::RenderWindow * m_window);
        ~Menu();

        void draw(sf::RenderWindow *window);
        void click(int x, int y);
        void addButton (Button* button);
        void addOptionButton (Button* button);
        void addSelectLevelButton (Button* button);
        bool getQuit();
        bool getPlay();
        void pause();
        int getCurrentLevel();
        void setLevel(int level);
        sf::Keyboard::Key getKeybind() const;
};

#endif 