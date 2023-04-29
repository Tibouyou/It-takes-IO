#include "blockSfml.h"
#include <math.h>
#include <iostream>

BlockSfml::BlockSfml(Level * level, int spriteSize, int tileX, int tileY)
{
    this->spriteSize = spriteSize;
    std::string path = "0000";
    if (tileX+1>=level->getWidth()) path[0] = '0';
    else if (level->getBlock(tileX+1, tileY)->isSolid()) path[0] = '1';
    if (tileX-1<0) path[1] = '0';
    else if (level->getBlock(tileX-1, tileY)->isSolid()) path[1] = '1';
    if (tileY+1>=level->getHeight()) path[2] = '0';
    else if (level->getBlock(tileX, tileY+1)->isSolid()) path[2] = '1';
    if (tileY-1<0) path[3] = '0';
    else if (level->getBlock(tileX, tileY-1)->isSolid()) path[3] = '1';

    if (path == "0101" && !level->getBlock(tileX-1, tileY-1)->isSolid()) path += "_alt";
    else if (path == "0110" && !level->getBlock(tileX-1, tileY+1)->isSolid()) path += "_alt";
    else if (path == "1010" && !level->getBlock(tileX+1, tileY+1)->isSolid()) path += "_alt";
    else if (path == "1001" && !level->getBlock(tileX+1, tileY-1)->isSolid()) path += "_alt";
    else if (path == "0111") {
        if (!level->getBlock(tileX-1, tileY-1)->isSolid() && !level->getBlock(tileX-1, tileY+1)->isSolid()) path += "_alt_b";
        else if (!level->getBlock(tileX-1, tileY-1)->isSolid()) path += "_alt_u";
        else if (!level->getBlock(tileX-1, tileY+1)->isSolid()) path += "_alt_d";
    }
    else if (path == "1011") {
        if (!level->getBlock(tileX+1, tileY-1)->isSolid() && !level->getBlock(tileX+1, tileY+1)->isSolid()) path += "_alt_b";
        else if (!level->getBlock(tileX+1, tileY-1)->isSolid()) path += "_alt_u";
        else if (!level->getBlock(tileX+1, tileY+1)->isSolid()) path += "_alt_d";
    }
    else if (path == "1101" && tileY-1>0) {
        if (!level->getBlock(tileX-1, tileY-1)->isSolid() && !level->getBlock(tileX+1, tileY-1)->isSolid()) path += "_alt_b";
        else if (!level->getBlock(tileX-1, tileY-1)->isSolid()) path += "_alt_l";
        else if (!level->getBlock(tileX+1, tileY-1)->isSolid()) path += "_alt_r";
    }
    else if (path == "1110" && tileY+1<level->getHeight() && !level->getBlock(tileX-1, tileY+1)->isSolid() && !level->getBlock(tileX+1, tileY+1)->isSolid()) path += "_alt";

    this->texture.loadFromFile("data/blocks/"+path+".png");
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(spriteSize/100.0, spriteSize/100.0);
    this->sprite.setPosition(tileX*spriteSize, tileY*spriteSize);
}

BlockSfml::~BlockSfml()
{
}

sf::Sprite BlockSfml::getSprite()
{
    return this->sprite;
}

