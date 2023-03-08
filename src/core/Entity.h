#ifndef ENTITY_H
#define ENTITY_H

#include "Level.h"

class Entity 
{
    private:
        int x;
        int y; 
        int height;
        int width;

    public:
        Entity(int x, int y, int height, int width);
        int getX();
        int getY();
        void setPosition(int x, int y);
        void update(const Level& currentLevel);
      

}; 

#endif ENTITY_H