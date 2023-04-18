#ifndef _BUTTON_H
#define _BUTTON_H

#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
using namespace sf;

class Button 
{
    private : 
        std::string buttonTitle;
        int x; 
        int y;
        int width;
        int height;
        bool click = false;
        bool hover = false;
        bool active = false;
        RectangleShape rectangle;
        Font *font;
        std::function<void()> onClick;
    
    public :
        Button(std::string buttonTitle, int x, int y, int width, int height, int fontSize, Font *font, std::function<void()> onClick);  
        void draw(RenderWindow *window);
        void update();
        void handleEvent(Event event);
};

#endif