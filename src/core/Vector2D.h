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
     * @brief id of the vector
     * 
     */
    int id;

    /**
     * @brief Construct a new Vector2D object
     * 
     * @param x x coordinate
     * @param y y coordinate
     * @param id id of the vector
     */
    Vector2D(int x, int y, int id=0);
};
#endif