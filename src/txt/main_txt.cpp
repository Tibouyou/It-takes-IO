#include "winTxt.h"
#include "txtJeu.h"
#include <iostream>


int main ( int argc, char** argv ) {
    termClear();
	Level level(1,1920,1080);
	txtBoucle(level);
    termClear();
	return 0;
}
