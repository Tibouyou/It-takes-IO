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
        vector<Button*> buttons;
        vector<Button*> optionsButtons;
        vector<Button*> selectLevelButtons;
        bool optionMenuActive = false;
        bool selectLevelMenuActive = false;
        RectangleShape rectangleMenu;
        Font font;
        bool quit = false;
        bool play = false;

    public :
        Menu(int windowWidth, int windowHeight, int fontSize);
        ~Menu();

        void draw(RenderWindow *window);
        void click(int x, int y);
        void addButton (Button* button);
        void addOptionButton (Button* button);
        void addSelectLevelButton (Button* button);
        bool getQuit();
        bool getPlay();
        void Pause();
};

#endif 