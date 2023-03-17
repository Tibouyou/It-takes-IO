#include <iostream>
#include <string>
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
	for(int y=0;y<level.getHeight();y++){
		for(int x=0;x<level.getWidth();x++){
			char blockC = level.getBlock(x,y)->getType();
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
	win.print( level.getPlayer0()->getTileX(), level.getPlayer0()->getTileY(), '0');
	win.print( level.getPlayer1()->getTileX(), level.getPlayer1()->getTileY(), '1');
	win.print( 0, level.getHeight(), "Player 0: ");
	win.print( 0, level.getHeight()+1, "x : "+std::to_string(level.getPlayer1()->getX()));
	win.print( 0, level.getHeight()+2, "y : "+std::to_string(level.getPlayer1()->getY()));
	win.draw();

}

void txtBoucle (Level & level) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (level.getWidth(),level.getHeight()+10);

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
		level.update();

	} while (ok);

}
