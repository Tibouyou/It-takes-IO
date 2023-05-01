#ifndef WINTXT_H
#define WINTXT_H
#include <string>

class WinTXT
{
private:

    /**
     * @brief The width of the window
     * 
     */
    int dimx; 

    /**
     * @brief The height of the window
     * 
     */      
    int dimy;

    /**
     * @brief The list of the characters of the window
     * 
     */       
    char* win;      

public:

    /**
     * @brief Construct a new WinTXT object
     * 
     * @param dx The width of the window
     * @param dy The height of the window
     */
    WinTXT (int dx, int dy);

    /**
     * @brief Destroy the WinTXT object
     * 
     */
    ~WinTXT ();

    /**
     * @brief Set all the characters of the window to c
     * 
     * @param c 
     */
    void clear (char c=' ');

    /**
     * @brief Print a character at the position (x,y)
     * 
     * @param x The position x of the character
     * @param y The position y of the character
     * @param c The character to print
     */
    void print (int x, int y, char c);

    /**
     * @brief Print a string at the position (x,y)
     * 
     * @param x The position x of the string
     * @param y The position y of the string
     * @param c The string to print
     */
    void print (int x, int y, char* c);

    /**
     * @brief Print a std::string at the position (x,y)
     * 
     * @param x The position x of the std::string
     * @param y The position y of the std::string
     * @param c The std::string to print
     */
    void print (int x, int y, std::string c);

    /**
     * @brief Draw the window
     * 
     * @param x The position x of the window
     * @param y The position y of the window
     */
    void draw (int x=0, int y=0);

    /**
     * @brief Get the input character
     * 
     * @return char 
     */
    char getCh();

};

void termClear ();

#endif
