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
        Block(float row, float col, std::string path, sf::RenderWindow* window){
            this->texture.loadFromFile(path);
            this->window = window;
            this->sprite.setTexture(this->texture);
            this->setPosition(row, col);
        }
        void draw(){
            this->window->draw(this->sprite);
        }
        void setPosition(float row, float col){
            this->location = Point(col, row);
            this->sprite.setPosition(col * 20, row * 20);
        }
};