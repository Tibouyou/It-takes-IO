#ifndef _ENUM_H
#define _ENUM_H

enum PowerType{EMPTY, ZERO, ONE};

enum PowerDirection {
    UP = 1<<0,
    DOWN = 1<<1,
    LEFT = 1<<2,
    RIGHT = 1<<3
};

enum BlockType{AIR, PLATFORM, SENSOR, TRAP, RECEPTACLE};

#endif