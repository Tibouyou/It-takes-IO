#include "Level.h"
#include "Platform.h"
#include <cassert>

Level::Level(int levelNumber, int height, int width)
{
    this->levelNumber = levelNumber;
    this->p0 = new Player(0,0,50,100,50);
    this->p1 = new Player(1,0,50,100,50);
    this->tabBlock = new Block[height*width];
    this->tabCable = new Cable[height*width];
    this->height = height;
    this->width = width;
    loadLevel();
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
    tabBlock[0] = Platform(0,0);
}

void Level::resetLevel()
{
}

int Level::getHeight() const
{
    return height;
}

int Level::getWidth() const
{
    return width;
}

Block & Level::getBlock(int x, int y) const
{
    assert((x <= height) && (y <= width));
    return tabBlock[y*height+x];
}

Cable & Level::getCable(int x, int y) const
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

