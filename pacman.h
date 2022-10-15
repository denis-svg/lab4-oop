#pragma once
#include "entity.h"

class PacMan : public Entity{
    public:
        std::string *paths;
        std::string *paths1;
        bool initial_state;
        PacMan(int row, int col, std::string paths[4], std::string paths1[4], sf::RenderWindow* window) : Entity(row, col, paths[1], window){
            this->paths = paths;
            this->paths1 = paths1;
            this->initial_state = true;
        }

        // create the animation when moving
        void movedLeft(){
            if (initial_state){
                this->texture.loadFromFile(paths[0]);
                this->initial_state = false;
            }else{
                this->texture.loadFromFile(paths1[0]);
                this->initial_state = true;
            }
        }
        void movedRight(){
            if (initial_state){
                this->texture.loadFromFile(paths[1]);
                this->initial_state = false;
            }else{
                this->texture.loadFromFile(paths1[1]);
                this->initial_state = true;
            }
        }
        void movedUp(){
            if (initial_state){
                this->texture.loadFromFile(paths[2]);
                this->initial_state = false;
            }else{
                this->texture.loadFromFile(paths1[2]);
                this->initial_state = true;
            }
        }
        void movedDown(){
            if (initial_state){
                this->texture.loadFromFile(paths[3]);
                this->initial_state = false;
            }else{
                this->texture.loadFromFile(paths1[3]);
                this->initial_state = true;
            }
        }
};