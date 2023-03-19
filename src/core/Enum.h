#ifndef _ENUM_H
#define _ENUM_H

enum PowerType{EMPTY, ZERO, ONE};

enum PowerDirection {
    NONE = 0,
    UP = 1<<0,
    DOWN = 1<<1,
    LEFT = 1<<2,
    RIGHT = 1<<3
};

enum BlockType{AIR, PLATFORM, SENSOR, TRAP, RECEPTACLE, GATE};

enum GateType{AND};

enum Obstacle {
    nothing = '.',
    platform = '#',
    sensor = '_',
    trap = '+',
    receptacle = 'R',
    cable = 'C',
    pickableNon = 'N', 
    door = 'D',
    player0 = '0',
    player1 = '1'
};

#endif