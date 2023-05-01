#ifndef _MANUAL_H
#define _MANUAL_H

#include "Button.h"

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Manual 
{
    private :
        /**
         * @brief The title of the manual
         * 
         */
        std::string menuTitle;

        /**
         * @brief The main window
         * 
         */
        sf::RenderWindow * m_window;

        /**
         * @brief The list of the buttons of the manual
         * 
         */
        std::vector<Button*> buttons;

        /**
         * @brief The button to return to the main menu
         * 
         */
        Button * buttonReturn;

        /**
         * @brief If the manual is quit
         * 
         */
        bool quit = false;

        /**
         * @brief The current page of the manual
         * 
         */
        int currentPage = 0;

        /**
         * @brief The font of the manual
         * 
         */
        sf::Font font;

        /**
         * @brief The sprite of the manual
         * 
         */
        sf::Sprite sprite;

        /**
         * @brief The texture of the manual's background
         * 
         */
        sf::Texture background;

        /**
         * @brief The texture of the button manual
         * 
         */
        sf::Texture button;

        /**
         * @brief The texture of the pickable manual
         * 
         */
        sf::Texture pickable;

        /**
         * @brief The texture of the receptacle manual
         * 
         */
        sf::Texture receptacle;

        /**
         * @brief The texture of the gates manual
         * 
         */
        sf::Texture gates;

    public :
        /**
         * @brief Construct a new Manual object
         * 
         * @param windowWidth The width of the window
         * @param windowHeight The height of the window
         * @param m_window The main window
         */
        Manual(int windowWidth, int windowHeight, sf::RenderWindow * m_window);

        /**
         * @brief Destroy the Manual object
         * 
         */
        ~Manual();

        /**
         * @brief Draw the manual
         * 
         * @param window The main window
         */
        void draw(sf::RenderWindow *window);

        /**
         * @brief Fonction call when there is a click on the manual
         * 
         * @param x The x position of the click
         * @param y The y position of the click
         */
        void click(int x, int y);

        /**
         * @brief Add a button to the manual
         * 
         * @param button The button to add
         */
        void addButton (Button* button);

        /**
         * @brief Get if the manual is quit
         * 
         * @return true If the manual is quit
         * @return false If the manual is not quit
         */
        bool getQuit();

        /**
         * @brief Open the manual
         * 
         */
        void Open();
};

#endif 