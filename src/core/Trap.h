#ifndef _TRAP_H
#define _TRAP_H

class Receptacle : public Block
{
    public :
        bool isSolid();
        void update(const player& p0,const player& p1, const Level& level);
}; 


#endif