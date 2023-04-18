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
        Font *font;
        //Texture textureMenu;
        //Texture textureOption;
        //Texture textureSelectLevel;

    public :
        Menu(int windowWidth, int windowHeight, int fontSize, Font font);
        ~Menu();

        void draw(RenderWindow *window);
        void update();
        void handleEvent(Event event);
        void addButton (Button* button);
        void addOptionButton (Button* button);
        void addSelectLevelButton (Button* button);
};

#endif 