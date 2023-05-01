#ifndef _ENTITY_H
#define _ENTITY_H

class Level;

class Entity 
{
    protected:
        /**
         * @brief The position x of the entity in the level
         * 
         */
        float x;

        /**
         * @brief The position y of the entity in the level
         * 
         */
        float y; 

        /**
         * @brief The origin x of the entity
         * 
         */
        float originX;

        /**
         * @brief The origin y of the entity
         * 
         */
        float originY;

        /**
         * @brief The height of the entity
         * 
         */
        int height;

        /**
         * @brief The width of the entity
         * 
         */
        int width;

        /**
         * @brief The size of the sprite
         * 
         */
        int spriteSize;

    public:

        /**
         * @brief Construct a new Entity object
         * 
         * @param x The position x of the entity in the level
         * @param y The position y of the entity in the level
         * @param height The height of the entity
         * @param width The width of the entity
         */
        Entity(float x, float y, int height, int width, int spriteSize, float originX, float originY);

        /**
         * @brief Destroy the Entity object
         * 
         */
        virtual ~Entity();

        /**
         * @brief Get the position x of the entity in the level
         * 
         * @return int The position x of the entity in the level
         */
        int getX() const;

        /**
         * @brief Get the position y of the entity in the level
         * 
         * @return int The position y of the entity in the level
         */
        int getY() const;

        /**
         * @brief Set the position of the entity in the level
         *
         * @param x The position x in the level
         * @param y The position y in the level
         */
        void setPosition(int x, int y);

        /**
         * @brief Overridable function called when the entity is update
         * 
         * @param currentLevel The current level
         */
        virtual void update(const Level &currentLevel, float elapsed = 1.0f) = 0;

        /**
         * @brief Get the tile x of the entity
         *         
         * @return int The tile x of the entity
         */
        int getTileX(int offset = 0);

        /**
         * @brief Get the tile y of the entity
         *         
         * @return int The tile y of the entity
         */
        int getTileY(int offset = 0);

        /**
         * @brief Get the width of the entity
         * 
         * @return int The width of the entity
         */
        int getWidth() const;

        /**
         * @brief Get the height of the entity
         * 
         * @return int The height of the entity
         */
        int getHeight() const;

        /**
         * @brief Overridable function called when the entity is reset
         * 
         */
        void reset();

}; 

#endif