#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Sensor.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cassert>
#include <time.h>
#include "sensorSfml.h"
#include "sfmlJeu.h"
#include <stdlib.h>

#include <math.h>

using namespace sf;

#include <iostream>
using namespace std;

sfmlJeu::sfmlJeu () {
    m_window = new RenderWindow(sf::VideoMode(1920, 1080), "It-Takes-IO", sf::Style::Fullscreen);
    int dimx = m_window->getSize().x;
    int dimy = m_window->getSize().y;
    level = new Level(1, dimx, dimy);
    spriteSize = min(dimx/level->getWidth(), dimy/level->getHeight());
    m_window->setFramerateLimit(120);
    playerSfml0 = new PlayerSfml(level->getPlayer0(), spriteSize);
    playerSfml1 = new PlayerSfml(level->getPlayer1(), spriteSize);
    doorTexture.loadFromFile("data/object/door.png");
    door.setTexture(doorTexture);
    door.setTextureRect(sf::IntRect(0, 0, 100, 200));
    door.setScale(spriteSize*2.0/200, spriteSize*2.0/200);
    frameDoor = 0;
    backgroundTexture.loadFromFile("data/background.png");
    background.setTexture(backgroundTexture);
    background.setScale((float)dimx/4960, (float)dimx/4960);
    background.setPosition(0, 0);

    for(int y=0;y<level->getHeight();y++){
		for(int x=0;x<level->getWidth();x++){
			char blockC = level->getBlock(x,y)->getType();
			if (blockC == SENSOR) {
				sensorsSfml.push_back(new SensorSfml(level->getBlock(x,y),spriteSize));
            }
        }
    }        
}

void sfmlJeu::sfmlInit() {

}


sfmlJeu::~sfmlJeu () {
    if (m_window != NULL) delete m_window;
}

void sfmlJeu::sfmlAff() {
    m_window->clear(Color(230, 240, 255, 255));
    m_window->draw(background);

    // Afficher les blocs
    for(int y=0;y<level->getHeight();y++){
		for(int x=0;x<level->getWidth();x++){
			char blockC = level->getBlock(x,y)->getType();
			switch (blockC) {
				case AIR:
					break;
				case PLATFORM:{
                    sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize));
                    rectangle.setPosition(x*spriteSize, y*spriteSize);
                    rectangle.setFillColor(sf::Color::Black);
                    m_window->draw(rectangle);
                    }
					break;
				case TRAP:{
					sf::RectangleShape rectangle(sf::Vector2f(spriteSize, (float)spriteSize/5));
                    rectangle.setPosition(x*spriteSize, y*spriteSize+spriteSize/2.5);
                    rectangle.setFillColor(sf::Color::Cyan);
                    m_window->draw(rectangle);
                    }
					break;
				case RECEPTACLE:
					break;
				case GATE:
					break;
				case DOOR:{
                    door.setPosition(x*spriteSize, y*spriteSize-spriteSize);
                    door.setTextureRect(sf::IntRect(frameDoor*100, 0, 100, 200));
                    m_window->draw(door);
                    }
					break;	
			}
		}
	}

    for (SensorSfml* sensor : sensorsSfml) {
		m_window->draw(sensor->getSprite());
    }

    for(int y=0;y<level->getHeight();y++){
		for(int x=0;x<level->getWidth();x++){
			int blockC = level->getCable(x,y)->getPowerType();
            sf::Color colorCable;
			switch (blockC) {
				case EMPTY:
                    colorCable = sf::Color(250, 150, 100);
					break;
				case ZERO:
					colorCable = sf::Color(255, 0, 0);
					break;
				case ONE:
					colorCable = sf::Color(0, 0, 255);
					break;
			}
            		if (!(level->getCable(x,y)->getDirectionMask() == NONE))
					{
            
                        if (level->getCable(x,y)->getDirectionMask() &PowerDirection::UP) {
                            sf::RectangleShape lineUp(sf::Vector2f(spriteSize/8.0, spriteSize/2.0));
                            lineUp.setPosition(x*spriteSize+spriteSize/2.3, y*spriteSize);
                            lineUp.setFillColor(colorCable);
                            m_window->draw(lineUp);
                        }
                        if (level->getCable(x,y)->getDirectionMask() & PowerDirection::DOWN) {
                            sf::RectangleShape lineDown(sf::Vector2f(spriteSize/8.0, spriteSize/2.0));
                            lineDown.setPosition(x*spriteSize+spriteSize/2.3, y*spriteSize+spriteSize/2.0);
                            lineDown.setFillColor(colorCable);
                            m_window->draw(lineDown);
                        }
                        
                        if (level->getCable(x,y)->getDirectionMask() & PowerDirection::LEFT) {
                            sf::RectangleShape lineLeft(sf::Vector2f(spriteSize/2.0, spriteSize/8.0));
                            lineLeft.setPosition(x*spriteSize, y*spriteSize+spriteSize/2.3);
                            lineLeft.setFillColor(colorCable);
                            m_window->draw(lineLeft);
                        }
                        if (level->getCable(x,y)->getDirectionMask() & PowerDirection::RIGHT) {
                            sf::RectangleShape lineRight(sf::Vector2f(spriteSize/2.0, spriteSize/8.0));
                            lineRight.setPosition(x*spriteSize+spriteSize/2.0, y*spriteSize+spriteSize/2.3);
                            lineRight.setFillColor(colorCable);
                            m_window->draw(lineRight);
                        }
                        sf::RectangleShape center(sf::Vector2f(spriteSize/8.0, spriteSize/8.0));
                            center.setPosition(x*spriteSize+spriteSize/2.3, y*spriteSize+spriteSize/2.3);
                            center.setFillColor(colorCable);
                            m_window->draw(center);
                    }
		}
	}

    for (Pickable* pickable : level->getPickable()) {
		int pickableC = pickable->getType();
		switch (pickableC) {
			case NON:
				if (!pickable->getHeld()) {
					sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize/1.25));
                    rectangle.setPosition(pickable->getTileX()*spriteSize, pickable->getTileY()*spriteSize+spriteSize/5.0);
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
				sf::RectangleShape rectangle(sf::Vector2f(spriteSize*3, spriteSize*3));
                rectangle.setPosition(gates->getX()*spriteSize-spriteSize, gates->getY()*spriteSize-spriteSize);
                rectangle.setFillColor(sf::Color::Green);
                m_window->draw(rectangle);
                }
				break;
		}
	}
    
    m_window->draw(playerSfml0->getSprite());
    m_window->draw(playerSfml1->getSprite());


    if (level->getPlayer0()->getHeldItem() != nullptr) {
        sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize/1.25));
        if(level->getPlayer0()->getOnGround()) {
            rectangle.setPosition(level->getPlayer0()->getX()+level->getPlayer0()->getWidth()/2.0-spriteSize/2.0, level->getPlayer0()->getY()-level->getPlayer0()->getHeight()+spriteSize*0.25/1.25);
            rectangle.setFillColor(sf::Color::Red);
        } else {
            rectangle.setPosition(level->getPlayer0()->getX()+level->getPlayer0()->getWidth()/2.0-spriteSize/2.0, level->getPlayer0()->getY()-level->getPlayer0()->getHeight()*0.8125+spriteSize*0.25/1.25);
            rectangle.setFillColor(sf::Color::Red);
        }    
        m_window->draw(rectangle);
    }
    if (level->getPlayer1()->getHeldItem() != nullptr) {
        sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize/1.25));
        if (level->getPlayer1()->getOnGround()){
            rectangle.setPosition(level->getPlayer1()->getX()+level->getPlayer1()->getWidth()/2.0-spriteSize/2.0, level->getPlayer1()->getY()-level->getPlayer1()->getHeight()+spriteSize*0.25/1.25);
            rectangle.setFillColor(sf::Color::Red);
        } else {
            rectangle.setPosition(level->getPlayer1()->getX()+level->getPlayer1()->getWidth()/2.0-spriteSize/2.0, level->getPlayer1()->getY()-level->getPlayer1()->getHeight()*0.8125+spriteSize*0.25/1.25);
            rectangle.setFillColor(sf::Color::Red);
        }    
        m_window->draw(rectangle);
    }
    m_window->display();
}

void sfmlJeu::sfmlBoucle () {

    Clock clock;

    while (m_window->isOpen())
    {
        float elapsed = clock.getElapsedTime().asSeconds();
        level->update(elapsed);
        playerSfml0->update(elapsed);
        playerSfml1->update(elapsed);
        for (SensorSfml* sensor : sensorsSfml) {
		    sensor->update(level->getPlayer0(), level->getPlayer1(), elapsed);
        }
        clock.restart();

        if(level->getDoor()->isOpened() && frameDoor != 6) {
            float elapsedDoor = doorClock.getElapsedTime().asSeconds();
            if(elapsedDoor > 0.4) {
                frameDoor++;
                doorClock.restart();
            }
        }

        if(level->getDoor()->isOpened() && level->getDoor()->getX()==level->getPlayer0()->getTileX() && level->getDoor()->getY()==level->getPlayer0()->getTileY()) {
            m_window->close();
        }
        if(level->getDoor()->isOpened() && level->getDoor()->getX()==level->getPlayer1()->getTileX() && level->getDoor()->getY()==level->getPlayer1()->getTileY()) {
            m_window->close();
        }

        if(!level->getPlayer0()->getAlive() || !level->getPlayer1()->getAlive()) m_window->close();

        Event event;

        while (m_window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                m_window->close();

            if (event.type == Event::KeyPressed) {
                switch (event.key.code) {
                case Keyboard::P : m_window->close();
					break;
                case Keyboard::Z : level->getPlayer0()->jump();
					break;
                case Keyboard::Q : level->getPlayer0()->setMoving(true);
                    level->getPlayer0()->setDirection(true);
					break;
                case Keyboard::D : level->getPlayer0()->setMoving(true);
                    level->getPlayer0()->setDirection(false);
					break; 
                case Keyboard::S : level->getPlayer0()->use(*level);
					break;   
                case Keyboard::Up : level->getPlayer1()->jump();
                    break;
                case Keyboard::Left : level->getPlayer1()->setMoving(true);
                    level->getPlayer1()->setDirection(true);
                    break;
                case Keyboard::Right : level->getPlayer1()->setMoving(true);
                    level->getPlayer1()->setDirection(false);
                    break;
                case Keyboard::Down : level->getPlayer1()->use(*level);
                    break;
                default : break;
                }
            }

            if (event.type == Event::KeyReleased) {
                switch (event.key.code) {
                case Keyboard::Q : if (level->getPlayer0()->getDirection()) level->getPlayer0()->setMoving(false);
					break;
                case Keyboard::D : if (!level->getPlayer0()->getDirection()) level->getPlayer0()->setMoving(false);
					break;    
                case Keyboard::Left : if (level->getPlayer1()->getDirection()) level->getPlayer1()->setMoving(false);
                    break;
                case Keyboard::Right : if (!level->getPlayer1()->getDirection()) level->getPlayer1()->setMoving(false);
                    break;
                default : break;
                }
            }
        }

        sfmlAff();
    }

}