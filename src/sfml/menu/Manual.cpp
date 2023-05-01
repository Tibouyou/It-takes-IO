#include "Manual.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"
using namespace sf;
using namespace std;

Manual::Manual (int windowWidth, int windowHeight, sf::RenderWindow * m_window)
{
    this->menuTitle = "Menu principal";
    this->m_window = m_window;
    this->rectangleMenu = RectangleShape(Vector2f(windowWidth, windowHeight));
    this->font.loadFromFile("data/Holidays Homework.ttf");
    this->background.loadFromFile("data/menu/menu_bg.png");
    this->button.loadFromFile("data/menu/menu_bouton.png");
    this->pickable.loadFromFile("data/menu/menu_pickable.png");
    this->receptacle.loadFromFile("data/menu/menu_receptacle.png");
    this->gates.loadFromFile("data/menu/menu_gates.png");
    this->sprite.setTexture(background);
    float scale = 0.8*windowHeight/1080;
    this->sprite.setScale(scale, scale);
    this->sprite.setOrigin(background.getSize().x/2.0,background.getSize().y/2.0);
    this->sprite.setPosition(windowWidth/2.0, windowHeight/2.0);
    
    buttonReturn = new Button(L"Return", 296*scale/2+windowHeight/10.0, windowHeight/2.0, 100*scale, scale, &font, [this]() 
    {
        if (this->currentPage == 0) {
            quit = true;
        } else {
            this->currentPage = 0;
            quit = false;
        }
    });

    float rectangle = windowHeight*8.0/10.0;
    addButton (new Button(L"Boutons", windowWidth*950/1642, windowHeight*2.0/10.0+rectangle/4.0*0, 100*scale, scale, &font, [this]() {
            if (this->currentPage == 0)
                this->currentPage = 1;
    }));
    
    addButton (new Button(L"Objets Déplaçables", windowWidth*950/1642, windowHeight*2.0/10.0+rectangle/4.0*1, 50*scale, scale, &font, [this]() {
            if (this->currentPage == 0)
                this->currentPage = 2;
    }));

    addButton (new Button(L"Réceptacles", windowWidth*950/1642, windowHeight*2.0/10.0+rectangle/4.0*2, 75*scale, scale, &font, [this]() {
            if (this->currentPage == 0)
                this->currentPage = 3;
    }));

    addButton (new Button(L"Portes Logiques", windowWidth*950/1642, windowHeight*2.0/10.0+rectangle/4.0*3, 60*scale, scale, &font, [this]() {
            if (this->currentPage == 0)
                this->currentPage = 4;
    }));
}

Manual::~Manual()
{
    for (Button *button : buttons)
    {
        delete button;
    }
}

void Manual::draw(RenderWindow *window)
{
    //window->draw(rectangleMenu);
    switch (currentPage) {
        case 0:
            this->sprite.setTexture(background);
            window->draw(sprite);
            for (Button *button : buttons){
                button->draw(window);
            }
            break;
        case 1:
            this->sprite.setTexture(button);
            window->draw(sprite);
            break;
        case 2:
            this->sprite.setTexture(pickable);
            window->draw(sprite);
            break;
        case 3:
            this->sprite.setTexture(receptacle);
            window->draw(sprite);
            break;
        case 4:
            this->sprite.setTexture(gates);
            window->draw(sprite);
            break;
    }
    buttonReturn->draw(window);
}


void Manual::click(int x, int y)
{
    for (Button *button : buttons){
        button->handleEvent(x,y);
    }
    buttonReturn->handleEvent(x,y);
}

void Manual::addButton (Button* button)
{
    buttons.push_back(button);
}

bool Manual::getQuit() {
    return quit;
}

bool Manual::getPlay() {
    return play;
}

void Manual::pause()
{
    play = !play;
}

int Manual::getCurrentLevel()
{
    return currentLevel;
}

void Manual::setLevel(int level)
{
    this->currentLevel = level;
}

void Manual::Open() {
    this->currentPage = 0;
    this->quit = false;
}