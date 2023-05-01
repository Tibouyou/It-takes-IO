#ifndef _BUTTON_H
#define _BUTTON_H

#include <string>
#include <functional>
#include <SFML/Graphics.hpp>

class Button 
{
    private : 
        /**
         * @brief The title of the button
         * 
         */
        std::wstring buttonTitle;

        /**
         * @brief The x position of the button
         * 
         */
        int x;

        /**
         * @brief The y position of the button
         * 
         */ 
        int y;

        /**
         * @brief The font of the button
         * 
         */
        sf::Font *font;

        /**
         * @brief The text of the button
         * 
         */
        sf::Text text;

        /**
         * @brief The function called when the button is clicked
         * 
         */
        std::function<void()> onClick;

        /**
         * @brief The texture of the button
         * 
         */
        sf::Texture* texture = nullptr;

        /**
         * @brief The sprite of the button
         * 
         */
        sf::Sprite* sprite = nullptr;
    
    public :

        /**
         * @brief Construct a new Button object
         * 
         * @param buttonTitle The title of the button
         * @param x The x position of the button
         * @param y The y position of the button
         * @param fontSize The size of the font
         * @param scale The scale of the button
         * @param font The font of the button
         * @param onClick The function called when the button is clicked
         * @param levelNumber The number of the level
         */
        Button(std::wstring buttonTitle, int x, int y, int fontSize, float scale, sf::Font *font, std::function<void()> onClick,int levelNumber=-1);  

        /**
         * @brief Destroy the Button object
         * 
         */
        ~Button();

        /**
         * @brief Draw the button on the window
         * 
         * @param window 
         */
        void draw(sf::RenderWindow *window);

        /**
         * @brief Check if the button is clicked
         * 
         * @param x The x position of the mouse
         * @param y The y position of the mouse
         */
        void handleEvent(int x, int y);
};

#endif