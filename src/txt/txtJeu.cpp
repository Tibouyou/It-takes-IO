#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "../core/Level.h"

void txtAff(WinTXT & win, const Level & level) {

	win.clear();

    // Affichage des murs et des pastilles
	for(int x=0;x<level.getHeight();++x){
		for(int y=0;y<level.getWidth();++y){
			char blockC = level.getBlock(x,y).getType();
			switch (blockC) {
				case AIR:
					blockC = ' ';
					break;
				case PLATFORM:
					blockC = '#';
					break;
				case SENSOR:
					blockC = '_';
					break;
				case TRAP:
					blockC = '+';
					break;
				case RECEPTACLE:
					blockC = 'R';
					break;
			}
			win.print( x, y, blockC);
		}
	}	
	win.draw();
}

void txtBoucle (Level & level) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (level.getHeight(),level.getWidth());

	bool ok = true;
	int c;

	do {
	    txtAff(win,level);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32


		c = win.getCh();
		switch (c) {
			case 'z':
				level.getPlayer0()->jump();
				break;
			case 'p':
				ok = false;
				break;
		}

	} while (ok);

}
