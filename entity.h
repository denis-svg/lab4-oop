#pragma once
#include "point.h"
#include "block.h"
#include "maze.h"

class Entity : public Block{
    int speed = 5;
    int x;
    int y;
    Maze *maze;
    public:
        Entity(int row, int col, std::string path, sf::RenderWindow* window, Maze *maze) : Block(row, col, path, window){
            this->x = col * 20;
            this->y = row * 20;
            this->maze = maze;
        }

        void moveUp(){
            if (!maze->isWall(this->getRow() - 1, this->getCol())){
            this->y -= speed;
            if (this->y == (this->location.getRow() - 1) * 20)
                this->setPosition(this->getRow() - 1, this->getCol());
            else
                this->sprite.setPosition(this->getCol() * 20, this->y);
            }
        }

        void moveDown(){
            if (!maze->isWall(this->getRow() + 1, this->getCol())){
                this->y += speed;
                if (this->y == (this->location.getRow() + 1) * 20)
                    this->setPosition(this->getRow() + 1, this->getCol());
                else
                    this->sprite.setPosition(this->getCol() * 20, this->y);
            }
        }
        void moveLeft(){
            if (!maze->isWall(this->getRow(), this->getCol() - 1)){
                this->x -= speed;
                if (this->x == (this->location.getCol() - 1) * 20)
                    this->setPosition(this->getRow(), this->getCol() - 1);
                else
                    this->sprite.setPosition(this->x, this->getRow() * 20);
            }
        }
        void moveRight(){
            if (!maze->isWall(this->getRow(), this->getCol() + 1)){
                this->x += speed;
                if (this->x == (this->location.getCol() + 1) * 20)
                    this->setPosition(this->getRow(), this->getCol() + 1);
                else
                    this->sprite.setPosition(this->x, this->getRow() * 20);
            }
        }
};