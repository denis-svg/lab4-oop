#pragma once
#include "point.h"
#include <SFML/Graphics.hpp>

class Block{
    public:
        Point location;
        sf::Sprite sprite;
        sf::Texture texture;
        sf::RenderWindow *window;
    public:
        Block(int row, int col, std::string path, sf::RenderWindow* window){
            this->texture.loadFromFile(path);
            this->window = window;
            this->sprite.setTexture(this->texture);
            this->location = Point(col, row);
            this->setPosition(row, col);
        }


        void draw(){
            this->window->draw(this->sprite);
        }

        void setPosition(int row, int col){
            this->sprite.setPosition(col * 20, row * 20);
            this->location.setCol(col);
            this->location.setRow(row);
        }

        int getRow(){
            return this->location.getRow();
        }

        int getCol(){
            return this->location.getCol();
        }
};