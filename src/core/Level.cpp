#include "Level.h"
#include "Platform.h"
#include "Sensor.h"
#include "Receptacle.h"
#include "Trap.h"
#include <cassert>
#include <iostream>
#include <fstream>

Level::Level(int levelNumber, int height, int width)
{
    this->levelNumber = levelNumber;
    this->p0 = new Player(0,0,50,100,50);
    this->p1 = new Player(1,0,50,100,50);
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
    int width, height;
    std::ifstream fichierLevel("data/levels/level"+std::to_string(levelNumber)+".txt");
    if (!fichierLevel.is_open()) {
    std::cout << "Erreur dans l'ouverture en lecture du fichier : " << "level1.txt" << std::endl;
    return;
    }
    fichierLevel >> width >> height;
    this->width = width;
    this->height = height;
    this->tabBlock = new Block[height*width];
    this->tabCable = new Cable[height*width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            char type;
            fichierLevel >> type;
            switch (type)
            {
                case '#':
                    tabBlock[y*width+x] = Platform(x,y);
                    break;
                case '_':
                    tabBlock[y*width+x] = Sensor(x,y);
                    break;
                case '0':
                    p0->setPosition(x*50,y*50);
                    break;
                case '1':
                    p1->setPosition(x*50,y*50);
                    break;
                case 'R':
                    tabBlock[y*width+x] = Receptacle(x,y);
                    break;   
                case '+':
                    tabBlock[y*width+x] = Trap(x,y);
                    break;     
                default:
                    break;
            }
        }
    }
    fichierLevel.close();
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
    assert((y <= height) && (x <= width));
    return tabBlock[y*width+x];
}

Cable & Level::getCable(int x, int y) const
{
    assert((x <= 20) && (y <= 20));
    return tabCable[y*20+x];
}

Player * Level::getPlayer0() const
{
    return p0;
}

Player * Level::getPlayer1() const
{
    return p1;
}

