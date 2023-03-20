#include "Level.h"
#include "Enum.h"
#include "Gate.h"
#include "Pickable.h"
#include "Platform.h"
#include "Sensor.h"
#include "Receptacle.h"
#include "Trap.h"
#include "Vector2D.h"
#include "Door.h"
#include <cassert>
#include <iostream>
#include <fstream>

Level::Level(int levelNumber)
{
    this->levelNumber = levelNumber;
    this->p0 = new Player(0,0,50,100,50);
    this->p1 = new Player(1,0,50,100,50);
    this->isWon = false;
    loadLevel();
}

Level::~Level()
{
    delete p0;
    delete p1;

    for (Block* block: tabBlock)
    {
        delete block;
    }
    for (Gate* gate: tabGate)
    {
        delete gate;
    }
    for (Cable* cable: tabCable)
    {
        delete cable;
    }
    for (Pickable* pickable: tabPickable)
    {
        delete pickable;
    }
}

void Level::loadLevel()
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
                    tabPickable.push_back(new Pickable(NON ,x*50,y*50,50,50));
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

void Level::update()
{
    p0->update(*this);
    p1->update(*this);

    if (!door->isOpened())
    {
        for (unsigned int i = 0; i < tabCable.size(); i++)
        {
            tabCable[i]->reset();
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
