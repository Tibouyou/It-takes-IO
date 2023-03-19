#include "winTxt.h"
#include "txtJeu.h"

int main ( int argc, char** argv ) {
    termClear();
	Level level(1);
	txtBoucle(level);
    //termClear();
	return 0;
}
