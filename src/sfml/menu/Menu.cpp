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
    
    addButton (new Button("Play", windowWidth/2.0, windowHeight/8.0, 100*scale,scale, &font, [this]() 
    {
        play = true;
    }));

     addButton (new Button("Select Level", windowWidth/2.0, 1*windowHeight/4.0+windowHeight/8.0, 100*scale/1.4, scale, &font, [this]() 
    {
        this->selectLevelMenuActive = true;
    }));

    addButton (new Button("Quit", windowWidth/2.0, 2*windowHeight/4.0+windowHeight/8.0, 100*scale, scale, &font, [this]() 
    {
        quit = true;
    }));

    addButton (new Button("Manuel", windowWidth/2.0, 3*windowHeight/4.0+windowHeight/8.0, 100*scale, scale, &font, [this]() 
    {
        cout << "Manuel" << endl;
        this->optionMenuActive = false;
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
        addSelectLevelButton(new Button("Level " + to_string(i), col*windowWidth/3.0+windowWidth/6.0, row*windowHeight/3.0+windowHeight/6.0, 100*scale/1.4, scale, &font,[this,i]() 
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
    for (Button *button : optionsButtons)
    {
        delete button;
    }
    for (Button *button : selectLevelButtons)
    {
        delete button;
    } 
}

void Menu::draw(RenderWindow *window)
{
    //window->draw(rectangleMenu);

    if (optionMenuActive)
    {
        for (Button *button : optionsButtons)
        {
            button->draw(window);
        }
    }
    else if (selectLevelMenuActive)
    {
        for (Button *button : selectLevelButtons)
        {
            button->draw(window);
        }
    }
    else 
    {
        for (Button *button : buttons)
        {
            button->draw(window);
        }
    }
}


void Menu::click(int x, int y)
{
    if (optionMenuActive)
    {
        for (Button *button : optionsButtons)
        {
            button->handleEvent(x,y);
        }
    }
    else if (selectLevelMenuActive)
    {
        for (Button *button : selectLevelButtons)
        {
            button->handleEvent(x,y);
        }
    }
    else 
    {
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

void Menu::addOptionButton (Button* button)
{
    optionsButtons.push_back(button);
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
    play = false;
}

int Menu::getCurrentLevel()
{
    return currentLevel;
}

sf::Keyboard::Key Menu::getKeybind() const {
    while (m_window->isOpen())
    {
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window->close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                std::cout<<event.key.code<<std::endl;
                return event.key.code;
            }
        }
    }
}

void Menu::setLevel(int level)
{
    this->currentLevel = level;
}