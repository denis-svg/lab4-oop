#pragma once
#include <SFML/Graphics.hpp>
#include "point.h"
#include "block.h"

class Dot: public Block{
    private:
        bool is_eaten;
        std::string path2;
    public:
        Dot(float row, float col, std::string path1, std::string path2, sf::RenderWindow* window) : Block(row, col, path1, window){
            is_eaten = false;
            this->path2 = path2;
        }
        void setEaten(){
            is_eaten = true;
            this->texture.loadFromFile(path2);
        }
        bool isEaten(){
            return this->is_eaten;
        }
};