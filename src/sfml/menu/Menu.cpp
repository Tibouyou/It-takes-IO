#include "Menu.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"
using namespace sf;
using namespace std;

Menu::Menu (int windowWidth, int windowHeight, sf::RenderWindow * m_window)
{
    this->manual = new Manual(windowWidth, windowHeight, m_window);
    this->menuTitle = "Menu principal";
    this->m_window = m_window;
    this->rectangleMenu = RectangleShape(Vector2f(windowWidth, windowHeight));
    this->font.loadFromFile("data/Holidays Homework.ttf");
    float scale;
    if (windowHeight/172 > windowWidth/640) {
        scale = windowHeight/5.0/172.0;
    } else {
        scale = windowWidth/2.0/640.0;
    }
    
    addButton (new Button(L"Play", windowWidth/2.0, windowHeight/8.0, 100*scale,scale, &font, [this]() 
    {
        play = true;
    }));

     addButton (new Button(L"Select Level", windowWidth/2.0, 1*windowHeight/4.0+windowHeight/8.0, 100*scale/1.4, scale, &font, [this]() 
    {
        this->selectLevelMenuActive = true;
    }));

    addButton (new Button(L"Quit", windowWidth/2.0, 2*windowHeight/4.0+windowHeight/8.0, 100*scale, scale, &font, [this]() 
    {
        quit = true;
    }));

    addButton (new Button(L"Manuel", windowWidth/2.0, 3*windowHeight/4.0+windowHeight/8.0, 100*scale, scale, &font, [this]() 
    {
        this->manualMenuActive = true;
        this->manual->Open();
    }));

    int col = 0;
    int row = -1;
    for (int i = 0; i <= 3; i++) {
        if (i%3==0){
            col = 0;
            row++;
        } else {
            col++;
        }
        addSelectLevelButton(new Button(L"Level " + to_string(i), col*windowWidth/3.0+windowWidth/6.0, row*windowHeight/3.0+windowHeight/6.0, 100*scale/1.4, scale, &font,[this,i]() 
        {
            this->currentLevel = i;
            this->selectLevelMenuActive = false;
            play = true;
        },i));
    }
}

Menu::~Menu()
{
    for (Button *button : buttons)
    {
        delete button;
    }
    buttons.clear();

    for (Button *button : selectLevelButtons)
    {
        delete button;
    } 
    selectLevelButtons.clear();

    if (manual != nullptr) {
        delete manual;
        manual = nullptr;
    }
}

void Menu::draw(RenderWindow *window)
{
    //window->draw(rectangleMenu);

    if (selectLevelMenuActive) {
        for (Button *button : selectLevelButtons)
        {
            button->draw(window);
        }
    } else if (manualMenuActive) {
        manual->draw(window);
    } else {
        for (Button *button : buttons)
        {
            button->draw(window);
        }
    }
}


void Menu::click(int x, int y)
{
    if (selectLevelMenuActive) {
        for (Button *button : selectLevelButtons)
        {
            button->handleEvent(x,y);
        }
    } else if (manualMenuActive) {
        manual->click(x,y);
        if (manual->getQuit()) {
            manualMenuActive = false;
        }
    }
    else {
        for (Button *button : buttons)
        {
            button->handleEvent(x,y);
        }
    }
}

void Menu::addButton (Button* button)
{
    buttons.push_back(button);
}


void Menu::addSelectLevelButton (Button* button)
{
    selectLevelButtons.push_back(button);
}

bool Menu::getQuit() {
    return quit;
}

bool Menu::getPlay() {
    return play;
}

void Menu::pause()
{
    play = !play;
}

int Menu::getCurrentLevel()
{
    return currentLevel;
}

void Menu::setLevel(int level)
{
    this->currentLevel = level;
}