#pragma once
#include <SFML/Graphics.hpp>
#include "point.h"
#include "block.h"

class Wall: public Block{
    public:
        Wall(int row, int col, std::string path, sf::RenderWindow* window) : Block(row, col, path, window){
        }

};