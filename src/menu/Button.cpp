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
    
    this->rectangle = sf::RectangleShape(sf::Vector2f(width, height));
    this->rectangle.setPosition(x, y);
    this->rectangle.setFillColor(sf::Color::White);
    
}

void Button::draw(sf::RenderWindow *window)
{
    window->draw(rectangle);
}

void Button::update()
{
    if (click)
    {
        this->onClick();
        click = false;
    }
}

void Button::handleEvent(sf::Event event)
{
    if (event.type == sf::Event::MouseMoved) {
        if (rectangle.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y))) {
            hover = true;
        } else {
            hover = false;
        }
        } else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (rectangle.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    active = true;
                } else {
                    active = false;
                }
            }
        } else if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (rectangle.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    active = false;
                    hover = false;
                    click = true;
                } else {
                    active = false;
                }
            }
    }
}



