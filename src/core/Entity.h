#ifndef _ENTITY_H
#define _ENTITY_H

class Level;

class Entity 
{
    protected:
        int x;
        int y; 
        int height;
        int width;

    public:
        Entity(int x, int y, int height, int width);
        virtual ~Entity();
        int getX() const;
        int getY() const;
        void setPosition(int x, int y);
        virtual void update(const Level &currentLevel) = 0;
        int getTileX(int offset = 0);
        int getTileY(int offset = 0);
}; 

#endif