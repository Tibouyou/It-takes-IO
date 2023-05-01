#ifndef _BUTTON_H
#define _BUTTON_H

#include <string>
#include <functional>
#include <SFML/Graphics.hpp>

class Button 
{
    private : 
        std::wstring buttonTitle;
        int x; 
        int y;
        sf::Font *font;
        sf::Text text;
        std::function<void()> onClick;
        sf::Texture* texture = nullptr;
        sf::Sprite* sprite = nullptr;
    
    public :
        Button(std::wstring buttonTitle, int x, int y, int fontSize, float scale, sf::Font *font, std::function<void()> onClick,int levelNumber=-1);  
        void draw(sf::RenderWindow *window);
        void handleEvent(int x, int y);
};

#endif