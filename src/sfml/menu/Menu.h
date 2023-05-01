#ifndef _MENU_H
#define _MENU_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "Manual.h"

class Menu 
{
    private :
        /**
         * @brief The title of the menu
         * 
         */
        std::string menuTitle;

        /**
         * @brief The main window
         * 
         */
        sf::RenderWindow * m_window;

        /**
         * @brief The list of the buttons of the menu
         * 
         */
        std::vector<Button*> buttons;

        /**
         * @brief The list of the option buttons of the menu to select a level
         * 
         */
        std::vector<Button*> selectLevelButtons;

        /**
         * @brief If the select level menu is active
         * 
         */
        bool selectLevelMenuActive = false;

        /**
         * @brief If the manual is active
         * 
         */
        bool manualMenuActive = false;

        /**
         * @brief The font of the menu
         * 
         */
        sf::Font font;

        /**
         * @brief If the menu is quit
         * 
         */
        bool quit = false;

        /**
         * @brief If the game is playing
         * 
         */
        bool play = true;

        /**
         * @brief The current level
         * 
         */
        int currentLevel = 0;

        /**
         * @brief The manual of the game
         * 
         */
        Manual * manual;

    public :
        /**
         * @brief Construct a new Menu object
         * 
         * @param windowWidth The width of the window
         * @param windowHeight The height of the window
         * @param m_window The main window
         */
        Menu(int windowWidth, int windowHeight, sf::RenderWindow * m_window);

        /**
         * @brief Destroy the Menu object
         * 
         */
        ~Menu();

        /**
         * @brief Draw the menu
         * 
         * @param window The window to draw the menu
         */
        void draw(sf::RenderWindow *window);

        /**
         * @brief Fonction call when there is a click on the menu
         * 
         * @param x The x position of the click
         * @param y The y position of the click
         */
        void click(int x, int y);

        /**
         * @brief Add a button to the menu
         * 
         * @param button 
         */
        void addButton (Button* button);

        /**
         * @brief Add a button to the select level menu
         * 
         * @param button 
         */
        void addSelectLevelButton (Button* button);

        /**
         * @brief Get if the menu is quit
         * 
         * @return true If the menu is quit
         * @return false If the menu is not quit
         */
        bool getQuit();

        /**
         * @brief Get if the game is playing
         * 
         * @return true If the game is playing
         * @return false If the game is not playing
         */
        bool getPlay();

        /**
         * @brief Toggle the pause state of the game
         * 
         */
        void pause();

        /**
         * @brief Get the current level
         * 
         * @return int The current level
         */
        int getCurrentLevel();

        /**
         * @brief Set the Level object
         * 
         * @param level 
         */
        void setLevel(int level);
};

#endif 