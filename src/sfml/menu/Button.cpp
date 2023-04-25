#include "Button.h"
#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>

Button::Button(std::string buttonTitle, int x, int y, int width, int height, int fontSize, sf::Font *font, std::function<void()> onClick)
{
    this->buttonTitle = buttonTitle;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->font = font;
    this->onClick = onClick;
    this->text.setFont(*font);
    this->text.setString(buttonTitle);
    this->text.setCharacterSize(100);
    this->text.setFillColor(sf::Color(255,0,0,255));

    FloatRect textBounds = this->text.getGlobalBounds();
    this->text.setPosition(x + width/2.0 - (textBounds.width /2), y + height/2.0 -(textBounds.height /2));

    this->rectangle.setSize(sf::Vector2f(width, height));
    this->rectangle.setPosition(x, y);
    this->rectangle.setFillColor(sf::Color(84,62,48,200));
}

void Button::draw(sf::RenderWindow *window)
{
    window->draw(rectangle);
    window->draw(text);
}


void Button::handleEvent(int x, int y)
{
    if (rectangle.getGlobalBounds().contains(sf::Vector2f(x, y))) {
        onClick();
    }
}



