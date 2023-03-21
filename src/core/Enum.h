#ifndef _ENUM_H
#define _ENUM_H

/**
 * @brief The power type of a cable
 * 
 */
enum PowerType{EMPTY, ZERO, ONE};

/**
 * @brief The direction of the power in binary
 * 
 */
enum PowerDirection {
    NONE = 0,
    UP = 1<<0,
    DOWN = 1<<1,
    LEFT = 1<<2,
    RIGHT = 1<<3
};

/**
 * @brief The type of a block
 * 
 */
enum BlockType{AIR, PLATFORM, SENSOR, TRAP, RECEPTACLE, GATE, DOOR};

/**
 * @brief The type of a gate
 * 
 */
enum GateType{AND};

#endif