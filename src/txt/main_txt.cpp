#include "winTxt.h"
#include "txtJeu.h"

int main ( int argc, char** argv ) {
    termClear();
	Level level(1,20,20);
	txtBoucle(level);
    termClear();
	return 0;
}
