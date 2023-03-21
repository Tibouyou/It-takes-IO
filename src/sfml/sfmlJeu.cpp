#include <SFML/Window/WindowStyle.hpp>
#include <cassert>
#include <time.h>
#include "sfmlJeu.h"
#include <stdlib.h>

using namespace sf;

#include <iostream>
using namespace std;

sfmlJeu::sfmlJeu () {
    level = new Level(1);
    int dimx = level->getWidth()*50;
    int dimy = level->getHeight()*50;
    m_window = new RenderWindow(VideoMode(dimx,dimy), "It-Takes-IO", sf::Style::Fullscreen);
}

void sfmlJeu::sfmlInit() {

}


sfmlJeu::~sfmlJeu () {
    if (m_window != NULL) delete m_window;
}

void sfmlJeu::sfmlAff() {
    m_window->clear(Color(230, 240, 255, 255));


    // Afficher les blocs
    for(int y=0;y<level->getHeight();y++){
		for(int x=0;x<level->getWidth();x++){
			char blockC = level->getBlock(x,y)->getType();
			switch (blockC) {
				case AIR:
					break;
				case PLATFORM:{
                    sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
                    rectangle.setPosition(x*50, y*50);
                    rectangle.setFillColor(sf::Color::Black);
                    m_window->draw(rectangle);
                    }
					break;
				case SENSOR:{
					sf::RectangleShape rectangle(sf::Vector2f(50.f, 10.f));
                    rectangle.setPosition(x*50, y*50+40);
                    rectangle.setFillColor(sf::Color::Red);
                    m_window->draw(rectangle);
                    }
					break;
				case TRAP:{
					sf::RectangleShape rectangle(sf::Vector2f(50.f, 10.f));
                    rectangle.setPosition(x*50, y*50+20);
                    rectangle.setFillColor(sf::Color::Cyan);
                    m_window->draw(rectangle);
                    }
					break;
				case RECEPTACLE:
					break;
				case GATE:
					break;
				case DOOR:{
					sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
                    rectangle.setPosition(x*50, y*50);
                    rectangle.setFillColor(sf::Color::Green);
                    m_window->draw(rectangle);
                    }
					break;	
			}
		}
	}

    for(int y=0;y<level->getHeight();y++){
		for(int x=0;x<level->getWidth();x++){
			int blockC = level->getCable(x,y)->getPowerType();
			switch (blockC) {
				case EMPTY:
					if (level->getCable(x,y)->getDirectionMask() == NONE) break;
					else {
            
                        if (level->getCable(x,y)->getDirectionMask() &PowerDirection::UP) {
                            sf::RectangleShape lineUp(sf::Vector2f(6, 25));
                            lineUp.setPosition(x*50+22, y*50);
                            lineUp.setFillColor(sf::Color(250, 150, 100));
                            m_window->draw(lineUp);
                        }
                        if (level->getCable(x,y)->getDirectionMask() & PowerDirection::DOWN) {
                            sf::RectangleShape lineDown(sf::Vector2f(6, 25));
                            lineDown.setPosition(x*50+22, y*50+25);
                            lineDown.setFillColor(sf::Color(250, 150, 100));
                            m_window->draw(lineDown);
                        }
                        
                        if (level->getCable(x,y)->getDirectionMask() & PowerDirection::LEFT) {
                            sf::RectangleShape lineLeft(sf::Vector2f(25, 6));
                            lineLeft.setPosition(x*50, y*50+22);
                            lineLeft.setFillColor(sf::Color(250, 150, 100));
                            m_window->draw(lineLeft);
                        }
                        if (level->getCable(x,y)->getDirectionMask() & PowerDirection::RIGHT) {
                            sf::RectangleShape lineRight(sf::Vector2f(25, 6));
                            lineRight.setPosition(x*50+25, y*50+22);
                            lineRight.setFillColor(sf::Color(250, 150, 100));
                            m_window->draw(lineRight);
                        }
                        sf::RectangleShape center(sf::Vector2f(6, 6));
                            center.setPosition(x*50+22, y*50+22);
                            center.setFillColor(sf::Color(250, 150, 100));
                            m_window->draw(center);
                    }
					break;
				case ZERO:
					blockC = '0';
					break;
				case ONE:
					blockC = '1';
					break;
			}
		}
	}

    for (Pickable* pickable : level->getPickable()) {
		int pickableC = pickable->getType();
		switch (pickableC) {
			case NON:
				if (!pickable->getHeld()) {
					sf::RectangleShape rectangle(sf::Vector2f(50.f, 40.f));
                    rectangle.setPosition(pickable->getTileX()*50, pickable->getTileY()*50+10);
                    rectangle.setFillColor(sf::Color::Red);
                    m_window->draw(rectangle);
                }
				break;
		}
    }

    for (Gate* gates : level->getGate()) {
		GateType gateC = gates->getGateType();
		switch (gateC) {
			case AND:{
				sf::RectangleShape rectangle(sf::Vector2f(150.f, 150.f));
                rectangle.setPosition(gates->getX()*50-50, gates->getY()*50-50);
                rectangle.setFillColor(sf::Color::Green);
                m_window->draw(rectangle);
                }
				break;
		}
	}


    m_window->display();
}

void sfmlJeu::sfmlBoucle () {

    Clock clock;

    while (m_window->isOpen())
    {
        float elapsed = clock.getElapsedTime().asSeconds();
        if (elapsed > 0.5) {
            // mouvement fantomes
            level->update();
            clock.restart();
        }

        Event event;

        while (m_window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                m_window->close();

            if (event.type == Event::KeyPressed) {
                switch (event.key.code) {
                case Keyboard::P : m_window->close();
					break;
                default : break;
                }
            }
        }

        sfmlAff();
    }

}
