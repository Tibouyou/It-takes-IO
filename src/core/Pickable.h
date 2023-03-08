#ifndef PICKABLE_H
#define PICKABLE_H

#include "Entity.h"
enum PickableType { NON };

class Pickable : public Entity
{
    private: 
        PickableType type;
        bool isHeld();
    
    public:
        Pickable(PickableType type, int x, int y, int height, int width);
        void update(const Level& currentLevel);
        PickableType getType();
        void setHeld();
        vool getHeld();
};

#endif PICKABLE_H