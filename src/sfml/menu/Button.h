#ifndef _BUTTON_H
#define _BUTTON_H

#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
using namespace sf;

class Button 
{
    private : 
        std::wstring buttonTitle;
        int x; 
        int y;
        Font *font;
        sf::Text text;
        std::function<void()> onClick;
        sf::Texture* texture = nullptr;
        sf::Sprite* sprite = nullptr;
    
    public :
        Button(std::wstring buttonTitle, int x, int y, int fontSize, float scale, Font *font,std::function<void()> onClick,int levelNumber=-1);  
        void draw(RenderWindow *window);
        void handleEvent(int x, int y);
};

#endif