#include "Menu.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"
using namespace sf;
using namespace std;

Menu::Menu (int windowWidth, int windowHeight, int fontSize, sf::RenderWindow * m_window)
{
    this->menuTitle = "Menu principal";
    this->m_window = m_window;
    this->rectangleMenu = RectangleShape(Vector2f(windowWidth, windowHeight));
    this->rectangleMenu.setFillColor(Color::White);
    this->font.loadFromFile("data/Holidays Homework.ttf");
    //this->textureMenu.loadFromFile("assets/menu.png");
    //this->textureOption.loadFromFile("assets/option.png");
    //this->textureSelectLevel.loadFromFile("assets/selectLevel.png");
    int buttonheight = windowHeight/5;
    
    addButton (new Button("Play", windowWidth/4.0, buttonheight/100*10, windowWidth/2.0, buttonheight-buttonheight/100*20, fontSize, &font, [this]() 
    {
        play = true;
    }));

    addButton (new Button("Options", windowWidth/4.0, buttonheight*1+buttonheight/100*10, windowWidth/2.0, buttonheight-buttonheight/100*20, fontSize, &font, [this]() 
    {
        cout << "Options" << endl;
        this->optionMenuActive = true;
    }));

     addButton (new Button("Select Level", windowWidth/4.0, buttonheight*2+buttonheight/100*10, windowWidth/2.0, buttonheight-buttonheight/100*20, fontSize, &font, [this]() 
    {
        this->selectLevelMenuActive = true;
    }));

    addButton (new Button("Quit", windowWidth/4.0, buttonheight*3+buttonheight/100*10, windowWidth/2.0, buttonheight-buttonheight/100*20, fontSize, &font, [this]() 
    {
        quit = true;
    }));

    addButton (new Button("Emmanuel", windowWidth/4.0, buttonheight*4+buttonheight/100*10, windowWidth/2.0, buttonheight-buttonheight/100*20, fontSize, &font, [this]() 
    {
        cout << "Emmanuel" << endl;
        this->optionMenuActive = false;
    }));

    for (int i = 1; i <= 2; i++) {
        addSelectLevelButton(new Button("Level " + to_string(i), windowWidth/4.0, buttonheight*i+buttonheight/100*10, windowWidth/2.0, buttonheight-buttonheight/100*20, fontSize, &font, [this,i]() 
        {
            this->currentLevel = i;
            this->selectLevelMenuActive = false;
            play = true;
        }));
    }

    addOptionButton(new Button("Keybinds", windowWidth/4.0, buttonheight*1+buttonheight/100*10, windowWidth/2.0, buttonheight-buttonheight/100*20, fontSize, &font, [this]() 
    {
        std::cout<< "test : "<< this->getKeybind() << std::endl;
    }));
}

Menu::~Menu()
{
    
}

void Menu::draw(RenderWindow *window)
{
    window->draw(rectangleMenu);

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