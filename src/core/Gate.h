#ifndef _GATE_H
#define _GATE_H

#include "Block.h"
#include "Enum.h"
#include "Player.h"
#include <vector>
#include "Cable.h"
#include "Vector2D.h"

class Level;

class Gate : public Block
{
    private : 
        std::vector<Vector2D*> input;
        std::vector<Vector2D*> output;
        GateType gateType;
    public :
        Gate(int x, int y,GateType gateType, BlockType type = GATE);
        std::vector<Vector2D*> getInput();
        std::vector<Vector2D*> getOutput();
        bool isSolid();
        void update(Player& p0,Player& p1, Level& currentLevel);
}; 


#endif