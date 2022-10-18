#pragma once
#include "point.h"
#include "block.h"
#include "maze.h"
#include <iostream>

class Entity : public Block{
    int speed = 5;
    int x;
    int y;
    Maze *maze;
    bool changed_row;
    bool changed_col;
    public:
        Entity(int row, int col, std::string path, sf::RenderWindow* window, Maze *maze) : Block(row, col, path, window){
            this->x = col * 20;
            this->y = row * 20;
            this->maze = maze;
            this->changed_row = false;
            this->changed_col = false;
        }

        bool canMoveUp(){
            if (this->changed_col){
                return false;
            }
            if (maze->isWall(this->getRow() - 1, this->getCol())){
                return false;
            }
            return true; 
        }

        bool canMoveDown(){
            if (this->changed_col){
                return false;
            }
            if (maze->isWall(this->getRow() + 1, this->getCol())){
                return false;
            }
            return true;
        }

        bool canMoveLeft(){
            if (this->changed_row){
                return false;
            }
            if (maze->isWall(this->getRow(), this->getCol() - 1)){
                return false;
            }
            return true;
        }

        bool canMoveRight(){
            if (this->changed_row){
                return false;
            }
            if (maze->isWall(this->getRow(), this->getCol() + 1)){
                return false;
            }
            return true;
        }

        void moveUp(){
            this->y -= speed;
            if (this->y == (this->location.getRow() - 1) * 20){
                this->setPosition(this->getRow() - 1, this->getCol());
                this->changed_row = false;
            }
            else{
                this->sprite.setPosition(this->getCol() * 20, this->y);
                this->changed_row = true;
            }
        }

        void moveDown(){
            this->y += speed;
            if (this->y == (this->location.getRow() + 1) * 20){
                this->setPosition(this->getRow() + 1, this->getCol());
                this->changed_row = false;
            }
            else{
                this->changed_row = true;
                this->sprite.setPosition(this->getCol() * 20, this->y);
            }
        }

        void moveLeft(){
            this->x -= speed;
            if (this->x == (this->location.getCol() - 1) * 20){
                this->setPosition(this->getRow(), this->getCol() - 1);
                this->changed_col = false;
            }
            else{
                this->changed_col = true;
                this->sprite.setPosition(this->x, this->getRow() * 20);
            }
        }

        void moveRight(){
            this->x += speed;
            if (this->x == (this->location.getCol() + 1) * 20){
                this->setPosition(this->getRow(), this->getCol() + 1);
                this->changed_col = false;
            }
            else{
                this->changed_col = true;
                this->sprite.setPosition(this->x, this->getRow() * 20);
            }
        }
};