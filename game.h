#pragma once
#include "maze.h"
#include "pacman.h"
#include <iostream>
#include "point.h"


class Game{
    Maze *maze;
    PacMan *pac_man;
    sf::RenderWindow *window;
    public:
        Game(sf::RenderWindow *window){
            this->window = window;

            this->maze = new Maze(window);
            this->pac_man = new PacMan(1, 1, window, maze);
        }

        void draw(){
            window->clear();
            maze->draw();
            pac_man->draw();
            window->display();
        }

        void checkEvents(){
            sf::Event event;
            window->pollEvent(event);
            if (event.type == sf::Event::Closed){
                window->close();
            }
            if (event.type == sf::Event::EventType::KeyPressed){
                if (event.key.code == sf::Keyboard::A){
                    if (pac_man->canMoveLeft()){
                        pac_man->moveLeft();
                        pac_man->setLeft();
                    }
                }
                if (event.key.code == sf::Keyboard::D){
                    if (pac_man->canMoveRight()){
                        pac_man->moveRight();
                        pac_man->setRight();
                    }
                }
                if (event.key.code == sf::Keyboard::W){
                    if (pac_man->canMoveUp()){
                        pac_man->moveUp();
                        pac_man->setUp();
                    }
                }
                if (event.key.code == sf::Keyboard::S){
                    if (pac_man->canMoveDown()){
                        pac_man->moveDown();
                        pac_man->setDown();
                    }
                }
            }
        }

        void run(){
            while (window->isOpen())
            {
                this->checkEvents();
                this->draw();
            }
            
        }

};