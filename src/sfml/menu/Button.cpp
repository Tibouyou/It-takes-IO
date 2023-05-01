#include "Button.h"
#include <functional>

Button::Button(std::wstring buttonTitle, int x, int y, int fontSize,float scale, sf::Font *font ,std::function<void()> onClick, int levelNumber)
{
    this->buttonTitle = buttonTitle;
    this->x = x;
    this->y = y;
    this->font = font;
    this->onClick = onClick;
    this->text.setFont(*font);
    if (buttonTitle!=L"Return") {
        this->text.setString(buttonTitle);
    }
    this->text.setCharacterSize(fontSize);
    this->text.setOrigin(this->text.getGlobalBounds().width/2.0, this->text.getGlobalBounds().height/2.0);
    this->text.setFillColor(sf::Color(0,0,0,255));
    this->texture = new sf::Texture();
    if (levelNumber != -1) {
        this->texture->loadFromFile("data/preview/lvl"+std::to_string(levelNumber)+".png");
    } else {
        if (buttonTitle==L"Return") {
            this->texture->loadFromFile("data/return.png");
        } else {
            this->texture->loadFromFile("data/button.png");
        }
    }
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*this->texture);
    this->sprite->setOrigin(this->texture->getSize().x/2.0, this->texture->getSize().y/2.0);
    this->sprite->setPosition(x, y);
    this->sprite->setScale(scale, scale);
    this->text.setPosition(x, y);
}

void Button::draw(sf::RenderWindow *window)
{
    window->draw(*sprite);
    window->draw(text);
}


void Button::handleEvent(int x, int y)
{
    if (sprite->getGlobalBounds().contains(sf::Vector2f(x, y))) {
        onClick();
    }
}



