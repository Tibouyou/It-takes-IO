#include "Menu.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"
using namespace sf;
using namespace std;

Menu::Menu (int windowWidth, int windowHeight, int fontSize, Font font)
{
    this->menuTitle = "Menu principal";
    this->rectangleMenu = RectangleShape(Vector2f(windowWidth, windowHeight));
    this->rectangleMenu.setFillColor(Color::White);
    this->font = &font;
    //this->textureMenu.loadFromFile("assets/menu.png");
    //this->textureOption.loadFromFile("assets/option.png");
    //this->textureSelectLevel.loadFromFile("assets/selectLevel.png");

    addButton (new Button("Play", 0, 0, 200, 50, fontSize, &font, [this]() 
    {
        cout << "Play" << endl;
    }));

    addButton (new Button("Options", 0, 50, 200, 50, fontSize, &font, [this]() 
    {
        cout << "Options" << endl;
        this->optionMenuActive = true;
    }));

     addButton (new Button("Select Level", 0, 50, 200, 50, fontSize, &font, [this]() 
    {
        cout << "Select Level" << endl;
        this->selectLevelMenuActive = true;
    }));

    addButton (new Button("Quit", 0, 100, 200, 50, fontSize, &font, [this]() 
    {
        cout << "Quit" << endl;
    }));

    addOptionButton (new Button("Emmanuel", 0, 0, 200, 50, fontSize, &font, [this]() 
    {
        cout << "Emmanuel" << endl;
        this->optionMenuActive = false;
    }));

}

Menu::~Menu()
{
    delete this->font;
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

void Menu::update()
{
    if (optionMenuActive)
    {
        for (Button *button : optionsButtons)
        {
            button->update();
        }
    }
    else if (selectLevelMenuActive)
    {
        for (Button *button : selectLevelButtons)
        {
            button->update();
        }
    }
    else 
    {
        for (Button *button : buttons)
        {
            button->update();
        }
    }
}

void Menu::handleEvent(Event event)
{
    if (optionMenuActive)
    {
        for (Button *button : optionsButtons)
        {
            button->handleEvent(event);
        }
    }
    else if (selectLevelMenuActive)
    {
        for (Button *button : selectLevelButtons)
        {
            button->handleEvent(event);
        }
    }
    else 
    {
        for (Button *button : buttons)
        {
            button->handleEvent(event);
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

