#include "Level.h"
#include "Pickable.h"
#include "Platform.h"
#include "Sensor.h"
#include "Receptacle.h"
#include "Trap.h"
#include <cassert>
#include <iostream>
#include <fstream>

Level::Level(int levelNumber)
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
    char type;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            fichierLevel >> type;
            switch (type)
            {
                case '.': 
                    tabBlock.push_back(new Block(x,y));
                    break;
                case '#':
                    tabBlock.push_back(new Platform(x,y));
                    break;
                case '_':
                    tabBlock.push_back(new Sensor(x,y));
                    break;
                case '0':
                    p0->setPosition(x*50,y*50);
                    tabBlock.push_back(new Block(x,y));
                    break;
                case '1':
                    p1->setPosition(x*50,y*50);
                    tabBlock.push_back(new Block(x,y));
                    break;
                case 'R':
                    tabBlock.push_back(new Receptacle(x,y));
                    break;   
                case '+':
                    tabBlock.push_back(new Trap(x,y));
                    break;
                case 'N':
                    tabBlock.push_back(new Block(x,y));
                    tabEntity.push_back(new Pickable(NON ,x,y,50,50));
                    break;           
                default:
                    tabBlock.push_back(new Block(x,y));
                    break;
            }
        }
    }

    int cableType;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            fichierLevel >> cableType;
            tabCable.push_back(new Cable(x,y,cableType));
        }
    }
    fichierLevel.close();
}

void Level::update()
{
    p0->update(*this);
    p1->update(*this);
    for (int i = 0; i < tabCable.size(); i++)
    {
        tabCable[i]->reset();
    }
    for (int i = 0; i < tabBlock.size(); i++)
    {
        tabBlock[i]->update(*p0,*p1,*this);
    }

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

Block * Level::getBlock(int x, int y) const
{
    assert((y < height) && (x < width) && (y >= 0) && (x >= 0));
    return tabBlock.at(y*width+x);
}

Cable * Level::getCable(int x, int y) const
{
    assert((y < height) && (x < width) && (y >= 0) && (x >= 0));
    return tabCable[y*width+x];
}

Player * Level::getPlayer0() const
{
    return p0;
}

Player * Level::getPlayer1() const
{
    return p1;
}

