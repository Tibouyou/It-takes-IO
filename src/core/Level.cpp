#include "Level.h"
#include "Platform.h"
#include <cassert>

Level::Level(int levelNumber)
{
    this->levelNumber = levelNumber;
    this->p0 = new Player(0,0,50,100,50);
    this->p1 = new Player(1,0,50,100,50);
    this->tabBlock = new Block[400];
    this->tabCable = new Cable[400];
}

Level::~Level()
{
    delete p0;
    delete p1;
    delete [] tabBlock;
    delete [] tabCable;
}

void Level::loadLevel()
{
}

void Level::resetLevel()
{
}

Block & Level::getBlock(int x, int y) const
{
    assert((x <= 20) && (y <= 20));
    return tabBlock[y*20+x];
}

Cable & Level::getCable(int x, int y)
{
    assert((x <= 20) && (y <= 20));
    return tabCable[y*20+x];
}

Player * Level::getPlayer0()
{
    return p0;
}

Player * Level::getPlayer1()
{
    return p1;
}

