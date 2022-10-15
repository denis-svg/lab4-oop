#pragma once
#include <SFML/Graphics.hpp>
#include "point.h"
#include "block.h"

class Wall: public Block{
    public:
        Wall(float row, float col, std::string path, sf::RenderWindow* window) : Block(row, col, path, window){
        }
};