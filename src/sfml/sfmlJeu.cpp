#include <SFML/Graphics/Color.hpp>
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
    level = new Level(1);
    int dimx = level->getWidth()*50;
    int dimy = level->getHeight()*50;
    m_window = new RenderWindow(VideoMode(dimx,dimy), "It-Takes-IO", sf::Style::Fullscreen);
    m_window->setFramerateLimit(120);
    playerSfml0 = new PlayerSfml(level->getPlayer0(), 0);
    playerSfml1 = new PlayerSfml(level->getPlayer1(), 1);
    doorTexture.loadFromFile("data/object/door.png");
    door.setTexture(doorTexture);
    door.setTextureRect(sf::IntRect(0, 0, 100, 200));
    door.setScale(0.5, 0.5);
    frameDoor = 0;
    backgroundTexture.loadFromFile("data/background.jpg");
    background.setTexture(backgroundTexture);
    background.setTextureRect(sf::IntRect(0, 0, dimx, dimy));
    background.setPosition(0, 0);

    for(int y=0;y<level->getHeight();y++){
		for(int x=0;x<level->getWidth();x++){
			char blockC = level->getBlock(x,y)->getType();
			if (blockC == SENSOR) {
				sensorsSfml.push_back(new SensorSfml(level->getBlock(x,y)));
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
                    sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
                    rectangle.setPosition(x*50, y*50);
                    rectangle.setFillColor(sf::Color::Black);
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
                    door.setPosition(x*50, y*50-50);
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
                            sf::RectangleShape lineUp(sf::Vector2f(6, 25));
                            lineUp.setPosition(x*50+22, y*50);
                            lineUp.setFillColor(colorCable);
                            m_window->draw(lineUp);
                        }
                        if (level->getCable(x,y)->getDirectionMask() & PowerDirection::DOWN) {
                            sf::RectangleShape lineDown(sf::Vector2f(6, 25));
                            lineDown.setPosition(x*50+22, y*50+25);
                            lineDown.setFillColor(colorCable);
                            m_window->draw(lineDown);
                        }
                        
                        if (level->getCable(x,y)->getDirectionMask() & PowerDirection::LEFT) {
                            sf::RectangleShape lineLeft(sf::Vector2f(25, 6));
                            lineLeft.setPosition(x*50, y*50+22);
                            lineLeft.setFillColor(colorCable);
                            m_window->draw(lineLeft);
                        }
                        if (level->getCable(x,y)->getDirectionMask() & PowerDirection::RIGHT) {
                            sf::RectangleShape lineRight(sf::Vector2f(25, 6));
                            lineRight.setPosition(x*50+25, y*50+22);
                            lineRight.setFillColor(colorCable);
                            m_window->draw(lineRight);
                        }
                        sf::RectangleShape center(sf::Vector2f(6, 6));
                            center.setPosition(x*50+22, y*50+22);
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
    
    m_window->draw(playerSfml0->getSprite());
    m_window->draw(playerSfml1->getSprite());
    if (level->getPlayer0()->getHeldItem() != nullptr) {
        sf::RectangleShape rectangle(sf::Vector2f(50.f, 40.f));
                    rectangle.setPosition(level->getPlayer0()->getX()-8, level->getPlayer0()->getY()-level->getPlayer0()->getHeight()+10);
                    rectangle.setFillColor(sf::Color::Red);
                    m_window->draw(rectangle);
    }
    if (level->getPlayer1()->getHeldItem() != nullptr) {
        sf::RectangleShape rectangle(sf::Vector2f(50.f, 40.f));
                    rectangle.setPosition(level->getPlayer1()->getX()-8, level->getPlayer1()->getY()-level->getPlayer1()->getHeight()+10);
                    rectangle.setFillColor(sf::Color::Red);
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