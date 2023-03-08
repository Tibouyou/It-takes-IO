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
        int getX();
        int getY();
        void setPosition(int x, int y);
        void update(const Level &currentLevel);
      

}; 

#endif