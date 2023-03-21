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
        /**
         * @brief List of the input of the gate
         * 
         */
        std::vector<Vector2D*> input;

        /**
         * @brief List of the output of the gate
         * 
         */
        std::vector<Vector2D*> output;

        /**
         * @brief The type of the gate
         * 
         */ 
        GateType gateType;
    public :

        /**
         * @brief Construct a new Gate object
         * 
         * @param x The position x of the gate in the level
         * @param y The position y of the gate in the level
         * @param gateType The type of the gate
         * @param type The type of the block
         */
        Gate(int x, int y,GateType gateType, BlockType type = GATE);

        /**
         * @brief Destroy the Gate object
         * 
         */
        ~Gate();

        /**
         * @brief Add an input to the gate
         * 
         *@param v the coordinate of the input
         */
        void addInput(Vector2D * v);

        /**
         * @brief Add an output to the gate
         * 
         *@param v the coordinate of the output
         */
        void addOutput(Vector2D * v);

        /**
         * @brief Get the position x of the gate
         * 
         * @return int the position x of the gate
         */
        int getX();

        /**
         * @brief Get the position y of the gate
         * 
         * @return int the position y of the gate
         */
        int getY();

        /**
         * @brief Get the type of the gate
         * 
         * @return GateType the type of the gate
         */
        GateType getGateType();

        /**
         * @brief Get the solidity of the gate
         * 
         * @return bool False
         */
        bool isSolid();

        /**
         * @brief Function called when the gate is update
         */
        void update(Level& currentLevel);
}; 


#endif