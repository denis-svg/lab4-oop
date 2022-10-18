#pragma once
#include "entity.h"
#include "maze.h"

class PacMan : public Entity{
    public:
        std::string *paths;
        std::string *paths1;
        bool initial_state;
        PacMan(int row, int col, sf::RenderWindow* window, Maze *maze) : Entity(row, col, std::string("images/right.png"), window, maze){
            // initializing paths
            this->paths =  new std::string[4];
            this->paths[0] = std::string("images/left.jpg");
            this->paths[1] = std::string("images/right.png");
            this->paths[2] = std::string("images/up.png");
            this->paths[3] = std::string("images/down.png");

            this->paths1 =  new std::string[4];
            this->paths1[0] = std::string("images/left1.jpg");
            this->paths1[1] = std::string("images/right1.png");
            this->paths1[2] = std::string("images/up1.png");
            this->paths1[3] = std::string("images/down1.png");
            this->initial_state = true;
        }

        // create the animation when moving
        void setLeft(){
            if (initial_state){
                this->texture.loadFromFile(paths[0]);
                this->initial_state = false;
            }else{
                this->texture.loadFromFile(paths1[0]);
                this->initial_state = true;
            }
        }
        void setRight(){
            if (initial_state){
                this->texture.loadFromFile(paths[1]);
                this->initial_state = false;
            }else{
                this->texture.loadFromFile(paths1[1]);
                this->initial_state = true;
            }
        }
        void setUp(){
            if (initial_state){
                this->texture.loadFromFile(paths[2]);
                this->initial_state = false;
            }else{
                this->texture.loadFromFile(paths1[2]);
                this->initial_state = true;
            }
        }
        void setDown(){
            if (initial_state){
                this->texture.loadFromFile(paths[3]);
                this->initial_state = false;
            }else{
                this->texture.loadFromFile(paths1[3]);
                this->initial_state = true;
            }
        }
};