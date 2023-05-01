#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Sensor.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cassert>
#include <time.h>
#include "playerSfml.h"
#include "sensorSfml.h"
#include "sfmlJeu.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>


sfmlJeu::sfmlJeu () {
    m_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "It-Takes-IO", sf::Style::Fullscreen);
    doorTexture.loadFromFile("data/object/door.png");
    door.setTexture(doorTexture);
    door.setTextureRect(sf::IntRect(0, 0, 100, 200));
    elec.loadFromFile("data/blocks/elec.png");
    elecAct.loadFromFile("data/blocks/elec2.png");
    gateAnd.loadFromFile("data/object/&.png");
    pickN.loadFromFile("data/object/non.png");
    generator0.loadFromFile("data/object/generator0.png");
    generator1.loadFromFile("data/object/generator1.png");
    menu = new Menu(m_window->getSize().x, m_window->getSize().y, m_window);
    music.openFromFile("data/music.ogg");
    buffer.loadFromFile("data/bruitages/electricite.ogg");
    sound.setBuffer(buffer);
    sound.setLoop(true);
}

void sfmlJeu::sfmlInit() {
    this->levelNumber = 0;
    loadLevel();
}

void sfmlJeu::loadLevel() {
    int dimx = m_window->getSize().x;
    int dimy = m_window->getSize().y;
    
    freeAndClearWrappers();

    level = new Level(this->levelNumber, dimx, dimy);
    spriteSize = std::min(dimx/level->getWidth(), dimy/level->getHeight());
    m_window->setFramerateLimit(120);
    playerSfml0 = new PlayerSfml(level->getPlayer0(), spriteSize);
    playerSfml1 = new PlayerSfml(level->getPlayer1(), spriteSize);
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

    for(int y=0;y<level->getHeight();y++){
        for(int x=0;x<level->getWidth();x++){
            char blockC = level->getBlock(x,y)->getType();
            if (blockC == PLATFORM) {
                blocksSfml.push_back(new BlockSfml(level,spriteSize,x,y));
            }
        }
    }    
}

void sfmlJeu::freeAndClearWrappers() {
    if (level != nullptr) {
        delete level;
        level = nullptr;
    }
    
    if (playerSfml0 != nullptr) {
        delete playerSfml0;
        playerSfml0 = nullptr;
    }

    if (playerSfml1 != nullptr) {
        delete playerSfml1;
        playerSfml1 = nullptr;
    }

    for (BlockSfml* block : blocksSfml) {
        delete block;
    }
    blocksSfml.clear();
    
    for (SensorSfml* sensor : sensorsSfml) {
        delete sensor;
    }
    
    sensorsSfml.clear();
}

sfmlJeu::~sfmlJeu () {
    if (m_window != nullptr) {
        delete m_window;
        m_window = nullptr;
    }

    if (menu != nullptr) {
        delete menu;
        menu = nullptr;
    }

    sound.resetBuffer();

    freeAndClearWrappers();
}

void sfmlJeu::sfmlAff() {
    m_window->draw(background);


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
            if (!(level->getCable(x,y)->getDirectionMask() == NONE) && level->getBlock(x,y)->getType() != TRAP){
                if (level->getCable(x,y)->getDirectionMask() &PowerDirection::UP) {
                    sf::RectangleShape lineUp(sf::Vector2f(spriteSize/8.0, spriteSize/2.0));
                    lineUp.setPosition(x*spriteSize+spriteSize/2.3, y*spriteSize);
                    lineUp.setFillColor(colorCable);
                    m_window->draw(lineUp);
                }
                if (level->getCable(x,y)->getDirectionMask() & PowerDirection::DOWN && (level->getBlock(x,y)->getType() != SENSOR || level->getCable(x,y)->getDirectionMask() & PowerDirection::UP)) {
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
                if (level->getBlock(x,y)->getType() != SENSOR) {
                sf::RectangleShape center(sf::Vector2f(spriteSize/8.0, spriteSize/8.0));
                    center.setPosition(x*spriteSize+spriteSize/2.3, y*spriteSize+spriteSize/2.3);
                    center.setFillColor(colorCable);
                    m_window->draw(center);
                }   
            }
        }
	}

    bool elec = false;
    // Afficher les blocs
    for(int y=0;y<level->getHeight();y++){
		for(int x=0;x<level->getWidth();x++){
			char blockC = level->getBlock(x,y)->getType();
			switch (blockC) {
				case AIR:
					break;
				case PLATFORM:
					break;
				case TRAP:{
                    sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize));
                    if (level->getCable(x, y)->getPowerType()==ONE) {
                        rectangle.setTexture(&this->elecAct);
                        elec = true;
                    } else {
                        rectangle.setTexture(&this->elec);
                    }
                    if(level->getBlock(x, y+1)->getType()==TRAP || level->getBlock(x, y-1)->getType()==TRAP) {
                        rectangle.rotate(90);
                        rectangle.setPosition(x*spriteSize+spriteSize, y*spriteSize);
                    } else rectangle.setPosition(x*spriteSize, y*spriteSize);
                    m_window->draw(rectangle);
                    } 
					break;
                case GENERATOR:{
                    sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize));
                    rectangle.setPosition(x*spriteSize, y*spriteSize);
                    if (dynamic_cast<Generator*>(level->getBlock(x, y))->getPowerType()==ONE) {
                        rectangle.setTexture(&this->generator1);
                    } else {
                        rectangle.setTexture(&this->generator0);
                    }
                    m_window->draw(rectangle);
                    }
                    break;
				case RECEPTACLE:{
                    sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize));
                    rectangle.setPosition(x*spriteSize, y*spriteSize);
                    rectangle.setFillColor(sf::Color(250, 150, 100,80));
                    m_window->draw(rectangle);
                    }
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
    if (elec) {
        if (sound.getStatus()==sf::Sound::Stopped) sound.play();
    } else {
        if (sound.getStatus()==sf::Sound::Playing) sound.stop();
    }
    
    for (SensorSfml* sensor : sensorsSfml) {
		m_window->draw(sensor->getSprite());
    }

    for (BlockSfml* block : blocksSfml) {
        m_window->draw(block->getSprite());
    }

    for (Pickable* pickable : level->getPickable()) {
		int pickableC = pickable->getType();
		switch (pickableC) {
			case NON:
				if (!pickable->getHeld()) {
					sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize));
                    rectangle.setPosition(pickable->getTileX()*spriteSize, pickable->getTileY()*spriteSize);
                    rectangle.setTexture(&pickN);
                    if (pickable->getDirection()) {
                        rectangle.setTextureRect(sf::IntRect(0, 0, 100, 100));
                    } else {
                        rectangle.setTextureRect(sf::IntRect(100, 0, 100, 100));
                    }
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
                rectangle.setTexture(&gateAnd);
                m_window->draw(rectangle);
                for (Vector2D* coord : gates->getInput()) {
                    sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize));
                    rectangle.setPosition(coord->x*spriteSize, coord->y*spriteSize);
                    rectangle.setFillColor(sf::Color(0,255,0,80));
                    m_window->draw(rectangle);
                }
                for (Vector2D* coord : gates->getOutput()) {
                    sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize));
                    rectangle.setPosition(coord->x*spriteSize, coord->y*spriteSize);
                    rectangle.setFillColor(sf::Color(255,0,0,80));
                    m_window->draw(rectangle);
                }
            }
			break;
		}
	}
    
    m_window->draw(playerSfml0->getSprite());
    m_window->draw(playerSfml1->getSprite());


    if (level->getPlayer0()->getHeldItem() != nullptr) {
        sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize));
        if (level->getPlayer0()->getHeldItem()->getDirection()) {
            rectangle.setTextureRect(sf::IntRect(0, 0, 100, 100));
        } else {
            rectangle.setTextureRect(sf::IntRect(100, 0, 100, 100));
        }
        if(level->getPlayer0()->getOnGround()) {
            rectangle.setPosition(level->getPlayer0()->getX()+level->getPlayer0()->getWidth()/2.0-spriteSize/2.0, level->getPlayer0()->getY()-level->getPlayer0()->getHeight());
            rectangle.setTexture(&pickN);
        } else {
            rectangle.setPosition(level->getPlayer0()->getX()+level->getPlayer0()->getWidth()/2.0-spriteSize/2.0, level->getPlayer0()->getY()-level->getPlayer0()->getHeight()*0.8125);
            rectangle.setTexture(&pickN);
        }    
        m_window->draw(rectangle);
    }
    if (level->getPlayer1()->getHeldItem() != nullptr) {
        sf::RectangleShape rectangle(sf::Vector2f(spriteSize, spriteSize));
        if (level->getPlayer1()->getHeldItem()->getDirection()) {
            rectangle.setTextureRect(sf::IntRect(0, 0, 100, 100));
        } else {
            rectangle.setTextureRect(sf::IntRect(100, 0, 100, 100));
        }
        if (level->getPlayer1()->getOnGround()){
            rectangle.setPosition(level->getPlayer1()->getX()+level->getPlayer1()->getWidth()/2.0-spriteSize/2.0, level->getPlayer1()->getY()-level->getPlayer1()->getHeight());
            rectangle.setTexture(&pickN);
        } else {
            rectangle.setPosition(level->getPlayer1()->getX()+level->getPlayer1()->getWidth()/2.0-spriteSize/2.0, level->getPlayer1()->getY()-level->getPlayer1()->getHeight()*0.8125);
            rectangle.setTexture(&pickN);
        }    
        m_window->draw(rectangle);
    }
}

void sfmlJeu::sfmlBoucle () {
    music.setLoop(true);
    music.play();

    sf::Clock clock;

    while (m_window->isOpen()) {
        float elapsed = clock.restart().asSeconds();
        if (elapsed > 0.3) // FIX : valgrind makes the game crash without this
            continue;

        if (menu->getPlay()) {
            if (level->getPlayer0()->getAlive() && level->getPlayer1()->getAlive()) {
                level->update(elapsed);
            }
            if (level->getPlayer0()->getAlive()) {
                if (level->getPlayer1()->getAlive()) {
                    playerSfml0->update(elapsed);
                } else {
                    playerSfml1->update(elapsed);
                }
            }
            if (level->getPlayer1()->getAlive()) {
                if (level->getPlayer0()->getAlive()) {
                    playerSfml1->update(elapsed);
                } else {
                    playerSfml0->update(elapsed);
                }
            }
            for (SensorSfml* sensor : sensorsSfml) {
                sensor->update(level->getPlayer0(), level->getPlayer1(), elapsed);
            }
        }

        //Ouverture de la porte 
        if(level->getDoor()->isOpened() && frameDoor != 6) {
            float elapsedDoor = doorClock.getElapsedTime().asSeconds();
            if(elapsedDoor > 0.4) {
                frameDoor++;
                doorClock.restart();
            }
        }

        if(menu->getCurrentLevel()!=this->levelNumber) {
            this->levelNumber = menu->getCurrentLevel();
            this->loadLevel();
        }

        //Passage au niveau suivant lorque le joueur O est sur la porte
        if(level->getDoor()->isOpened() && level->getDoor()->getX()==level->getPlayer0()->getTileX() && level->getDoor()->getY()==level->getPlayer0()->getTileY()) {
            this->levelNumber++;
            if(levelNumber>3)levelNumber=0;
            this->menu->setLevel(this->levelNumber);
            this->loadLevel();
        }

        //Passage au niveau suivant lorque le joueur 1 est sur la porte
        if(level->getDoor()->isOpened() && level->getDoor()->getX()==level->getPlayer1()->getTileX() && level->getDoor()->getY()==level->getPlayer1()->getTileY()) {
            this->levelNumber++;
            if(levelNumber>3)levelNumber=0;
            this->menu->setLevel(this->levelNumber);
            this->loadLevel();
        }

        //Reinitialisation du niveau si un des joueurs est mort
        if(playerSfml0->getDeathAnimationDone()) {
            this->level->resetLevel();
            frameDoor = 0;
        }
        if(playerSfml1->getDeathAnimationDone()) {
            this->level->resetLevel();
            frameDoor = 0;
        }

        if(this->menu->getQuit()) m_window->close();

        sf::Event event;

        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
            if (!menu->getPlay()) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        this->menu->click(event.mouseButton.x, event.mouseButton.y);
                    }
                }
                if (event.type == sf::Event::KeyPressed) {
                    switch (event.key.code) {
                    case sf::Keyboard::Escape : {
                        this->menu->pause();
                    }
                    break;
                    default : break;
                    }
                }
            } else {
                if (event.type == sf::Event::KeyPressed) {
                    switch (event.key.code) {
                    case sf::Keyboard::Escape : this->menu->pause();
                        break;
                    case sf::Keyboard::Z : level->getPlayer0()->jump();
                        break;
                    case sf::Keyboard::Q : level->getPlayer0()->setMoving(true);
                        level->getPlayer0()->setDirection(true);
                        break;
                    case sf::Keyboard::D : level->getPlayer0()->setMoving(true);
                        level->getPlayer0()->setDirection(false);
                        break; 
                    case sf::Keyboard::S : level->getPlayer0()->use(*level);
                        break;   
                    case sf::Keyboard::Up : level->getPlayer1()->jump();
                        break;
                    case sf::Keyboard::Left : level->getPlayer1()->setMoving(true);
                        level->getPlayer1()->setDirection(true);
                        break;
                    case sf::Keyboard::Right : level->getPlayer1()->setMoving(true);
                        level->getPlayer1()->setDirection(false);
                        break;
                    case sf::Keyboard::Down : level->getPlayer1()->use(*level);
                        break;
                    default : break;
                    }
                }
                if (event.type == sf::Event::KeyReleased) {
                    switch (event.key.code) {
                    case sf::Keyboard::Q : if (level->getPlayer0()->getDirection()) level->getPlayer0()->setMoving(false);
                        break;
                    case sf::Keyboard::D : if (!level->getPlayer0()->getDirection()) level->getPlayer0()->setMoving(false);
                        break;    
                    case sf::Keyboard::Left : if (level->getPlayer1()->getDirection()) level->getPlayer1()->setMoving(false);
                        break;
                    case sf::Keyboard::Right : if (!level->getPlayer1()->getDirection()) level->getPlayer1()->setMoving(false);
                        break;
                    default : break;
                    }
                }
            }
        }

        if (!menu->getPlay()) {
            m_window->clear(sf::Color(230, 240, 255, 255));
            sfmlAff();
            sfmlMenu();
        } else {
            m_window->clear(sf::Color(230, 240, 255, 255));
            sfmlAff();
        }    
        m_window->display();    
    }

}

void sfmlJeu::sfmlMenu () {
    menu->draw(m_window);
}

