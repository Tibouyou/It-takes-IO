#ifndef _VECTOR2D_H
#define _VECTOR2D_H

struct Vector2D {
    /**
     * @brief x coordinate
     * 
     */
    int x; 

    /**
     * @brief y coordinate
     * 
     */
    int y;

    /**
     * @brief Construct a new Vector2D object
     * 
     * @param x x coordinate
     * @param y y coordinate
     */
    Vector2D(int x = 0, int y = 0);
};
#endif