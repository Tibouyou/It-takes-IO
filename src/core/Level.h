#ifndef _LEVEL_H
#define _LEVEL_H


class Level
{
    private :
        Player p0;
        Player p1;
        Block tabBlock[20][20];
        Cable tabCable[20][20];
        vector<Entity> tabEntity;
        int levelNumber;

    public :
        Level(int levelNumber);
        ~Level();
        void loadLevel();
        void resetLevel();
        Block * getBlock(int x, int y);
        Cable * getCable(int x, int y);
        Player * getPlayer0();
        Player * getPlayer1();
}; 


#endif
