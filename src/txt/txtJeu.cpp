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
					if (level.getCable(x,y)->getPowerType() == PowerType::ONE)
						blockC = '+';
					else blockC = 'x';
					break;
				case RECEPTACLE:
					blockC = 'R';
					break;
				case GATE:
					blockC = '&';
					break;
				case DOOR:
					if (level.getBlock(x,y)->isSolid()) blockC = 'D';
					else blockC = 'd';
					break;	
			}
			win.print( x, y, blockC);
		}
	}
	for(int y=0;y<level.getHeight();y++){
		for(int x=0;x<level.getWidth();x++){
			int blockC = level.getCable(x,y)->getPowerType();
			switch (blockC) {
				case EMPTY:
					if (level.getCable(x,y)->getDirectionMask() == NONE) blockC = ' ';
					else blockC = '.';
					break;
				case ZERO:
					blockC = '0';
					break;
				case ONE:
					blockC = '1';
					break;
			}
			win.print( x+level.getWidth()+5, y, blockC);
		}
	}
	for (Pickable* pickable : level.getPickable()) {
		int pickableC = pickable->getType();
		switch (pickableC) {
			case NON:
				pickableC = 'N';
				break;
		}
		if (!pickable->getHeld()) win.print( pickable->getTileX(), pickable->getTileY(), pickableC);
    }
	
	for (Gate* gates : level.getGate()) {
		GateType gateC = gates->getGateType();
		switch (gateC) {
			case AND:
				win.print( gates->getX(), gates->getY(), '&');
				win.print( gates->getX()+level.getWidth()+5, gates->getY(), '&');
				break;
		}
	}
	win.print( level.getPlayer0()->getTileX(), level.getPlayer0()->getTileY(), '0');
	win.print( level.getPlayer1()->getTileX(), level.getPlayer1()->getTileY(), '1');
	win.draw();

}

void txtBoucle (Level& level) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (level.getWidth()*2+5,level.getHeight()+10);

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
			case 'q':
				level.getPlayer0()->moveLeft();
				break;	
			case 'd':
				level.getPlayer0()->moveRight();
				break;
			case 's':
				level.getPlayer0()->use(level);
				break;
			case 'u':
				level.getPlayer1()->jump();
				break;
			case 'h':
				level.getPlayer1()->moveLeft();
				break;	
			case 'k':
				level.getPlayer1()->moveRight();
				break;	
			case 'j':
				level.getPlayer1()->use(level);
				break;			
			case 'p':
				ok = false;
				break;
		}
		level.update();

		if(!level.getPlayer0()->getAlive() || !level.getPlayer1()->getAlive()) ok = false;
		if(level.getWin()) ok = false;
	} while (ok);
	termClear();
	if(level.getWin()) std::cout << "Bien joué" << std::endl;
	else std::cout << "Gros nullos" << std::endl;
}
