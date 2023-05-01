#ifndef _PICKABLE_H
#define _PICKABLE_H

#include "Entity.h"

enum PickableType { NON };

class Pickable : public Entity
{
    private:
        /**
         * @brief The type of the pickable
         * 
         */
        PickableType type;

        /**
         * @brief The state of the pickable
         * 
         */
        bool isHeld;

        /**
         * @brief The direction of the pickable
         * 
         */
        bool direction = false;
    
    public:

        /**
         * @brief Construct a new Pickable object
         * 
         * @param type The type of the pickable
         * @param x The position x of the pickable in the level
         * @param y The position y of the pickable in the level
         * @param height The height of the pickable
         * @param width The width of the pickable
         */
        Pickable(PickableType type, int x, int y, int height, int width, int spriteSize, int originX, int originY);

        /**
         * @brief Destroy the Pickable object
         * 
         */
        ~Pickable();

        /**
         * @brief Function called when the pickable is updated
         * 
         */
        void update(const Level& currentLevel, float elapsed = 1.0f);

        /**
         * @brief Get the type of the pickable
         * 
         * @return PickableType The type of the pickable
         */
        PickableType getType();

        /**
         * @brief Toggle the state of the pickable
         * 
         */
        void toggleHeld();

        /**
         * @brief Get the state of the pickable
         * 
         * @return true The pickable is held
         * @return false The pickable is not held
         */
        bool getHeld();

        /**
         * @brief Get the direction of the pickable
         * 
         * @return true The pickable is facing right
         * @return false The pickable is facing left
         */
        bool getDirection();

        /**
         * @brief Set the direction of the pickable
         * 
         * @param direction The direction of the pickable
         */
        void setDirection(bool direction);

        /**
         * @brief Reset the pickable
         * 
         */
        void reset();
};

#endif