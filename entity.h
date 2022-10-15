#pragma once
#include "point.h"
#include "block.h"

class Entity : public Block{
    public:
        Entity(int row, int col, std::string path, sf::RenderWindow* window) : Block(row, col, path, window){
        }

        void moveUp(){
            this->setPosition(this->getRow() - 1, this->getCol());
        }

        void moveDown(){
            this->setPosition(this->getRow() + 1, this->getCol());
        }
        void moveLeft(){
            this->setPosition(this->getRow(), this->getCol() - 1);
        }
        void moveRight(){
            this->setPosition(this->getRow(), this->getCol() + 1);
        }
};