#include "Level.h"
#include "Platform.h"
#include "Sensor.h"
#include "Receptacle.h"
#include "Trap.h"
#include "Generator.h"

#include <iostream>
#include <fstream>
#include <math.h>
#include <cassert>

Level::Level(int levelNumber, int dimWindowX, int dimWindowY)
{
    this->levelNumber = levelNumber;
    this->isWon = false;
    loadLevel(dimWindowX, dimWindowY);
    this->p0->setSpriteSize(spriteSize);
    this->p1->setSpriteSize(spriteSize);
}

Level::~Level()
{
    delete p0;
    delete p1;

    p0 = nullptr;
    p1 = nullptr;

    for (Block* block: tabBlock)
    {
        delete block;
    }
    tabBlock.clear();

    for (Gate* gate: tabGate)
    {
        delete gate;
    }
    tabGate.clear();

    for (Cable* cable: tabCable)
    {
        delete cable;
    }
    tabCable.clear();

    for (Pickable* pickable: tabPickable)
    {
        delete pickable;
    }
    tabPickable.clear();
}

void Level::loadLevel(int dimWindowX, int dimWindowY)
{
    std::vector<Vector2D*> input;
    std::vector<Vector2D*> output;
    int width, height;
    std::ifstream fichierLevel("data/levels/level"+std::to_string(levelNumber)+".txt");
    if (!fichierLevel.is_open()) {
    std::cout << "Erreur dans l'ouverture en lecture du fichier : " << "level1.txt" << std::endl;
    return;
    }
    fichierLevel >> width >> height;
    this->width = width;
    this->height = height;
    if (dimWindowX/width < dimWindowY/height)
    {
        this->spriteSize = dimWindowX/width;
    }
    else
    {
        this->spriteSize = dimWindowY/height;
    }
    #ifdef TXT
    this->spriteSize = 50;
    #endif // TXT
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
                    tabBlock.push_back(new Sensor(x,y,spriteSize));
                    break;
                case '0':
                    this->p0 = new Player(0,x*spriteSize,y*spriteSize,100,50,0,x*spriteSize,y*spriteSize);
                    tabBlock.push_back(new Block(x,y));
                    break;
                case '1':
                    this->p1 = new Player(1,x*spriteSize,y*spriteSize,100,50,0,x*spriteSize,y*spriteSize);
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
                    tabPickable.push_back(new Pickable(NON ,x*spriteSize,y*spriteSize, spriteSize, spriteSize, spriteSize,x*spriteSize,y*spriteSize));
                    break; 
                case 'I':
                    tabBlock.push_back(new Block(x,y));
                    input.push_back(new Vector2D(x,y));
                    break;
                case 'O':
                    tabBlock.push_back(new Block(x,y));
                    output.push_back(new Vector2D(x,y));
                    break;    
                case '&':
                    tabGate.push_back(new Gate(x,y, AND));
                    tabBlock.push_back(new Block(x,y));
                    break;  
                case 'D':
                    door = new Door(x,y);
                    tabBlock.push_back(door);
                    break;  
                case 'g':
                    tabBlock.push_back(new Generator(x,y,ZERO));
                    break;
                case 'G':
                    tabBlock.push_back(new Generator(x,y,ONE));
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

    for (Gate* gateCore: tabGate)
    {
        for (Vector2D* input : input)
        {
            if (input->x - gateCore->getX() <= 1 && input->x - gateCore->getX() >= -1 && input->y - gateCore->getY() <= 1 && input->y - gateCore->getY() >= -1)
            {
                gateCore->addInput(input);
            }
        }
        for (Vector2D* output : output)
        {
            if (output->x - gateCore->getX() <= 1 && output->x - gateCore->getX() >= -1 && output->y - gateCore->getY() <= 1 && output->y - gateCore->getY() >= -1)
            {
                gateCore->addOutput(output);
            }
        }
    }
}

void Level::update(float elapsed)
{
    p0->update(*this,elapsed);
    p1->update(*this,elapsed);

    if (!door->isOpened())
    {
        for (unsigned int i = 0; i < tabCable.size(); i++)
        {
            tabCable[i]->reset();
        }

        for (unsigned int i = 0; i < tabBlock.size(); i++)
        {
            if (tabBlock[i]->getType() == GENERATOR)
            {
                tabBlock[i]->update(*p0,*p1,*this);
            }
        }

        for (unsigned int i = 0; i < tabBlock.size(); i++)
        {
            if (tabBlock[i]->getType() == SENSOR)
            {
                tabBlock[i]->update(*p0,*p1,*this);
            }
        }

        for (unsigned int i = 0; i < tabGate.size(); i++)
        {
            tabGate[i]->update(*this);
        }
    }
    

    for (unsigned int i = 0; i < tabBlock.size(); i++)
    {
        if (tabBlock[i]->getType() == TRAP)
        {
            tabBlock[i]->update(*p0,*p1,*this);
        }
    }

    for (unsigned int i = 0; i < tabBlock.size(); i++)
    {
        if (tabBlock[i]->getType() == DOOR)
        {
            tabBlock[i]->update(*p0,*p1,*this);
        }
    }
}

void Level::resetLevel()
{
    this->isWon = false;
    p0->reset();
    p1->reset();
    for (Pickable* pickable: tabPickable)
    {
        pickable->reset();
    }
    for(Block* block: tabBlock)
    {
        if (block->getType() == RECEPTACLE)
        {
            dynamic_cast<Receptacle*>(block)->reset();
        }
    }
    getDoor()->reset();
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

Door * Level::getDoor() const
{
    return door;
}

std::vector<Pickable*> Level::getPickable() const
{
    return tabPickable;
}

std::vector<Gate*> Level::getGate() const
{
    return tabGate;
}

void Level::win()
{
    this->isWon = true;
}

bool Level::getWin() const
{
    return isWon;
}
