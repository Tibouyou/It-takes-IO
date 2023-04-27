#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace sf;
using namespace std;

class Menu 
{
    private :
        string menuTitle;
        sf::RenderWindow * m_window;
        vector<Button*> buttons;
        vector<Button*> optionsButtons;
        vector<Button*> selectLevelButtons;
        bool optionMenuActive = false;
        bool selectLevelMenuActive = false;
        RectangleShape rectangleMenu;
        Font font;
        bool quit = false;
        bool play = false;
        int currentLevel = 0;

    public :
        Menu(int windowWidth, int windowHeight, int fontSize, sf::RenderWindow * m_window);
        ~Menu();

        void draw(RenderWindow *window);
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