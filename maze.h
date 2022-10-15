#pragma once
#include "wall.h"
#include "dot.h"
#include <map>
#include <fstream>
#include <vector>

class Maze{
    private:
        // string will be stored in the format 'row col'
        // in total there will be 30 rows and 30 cols
        std::map<std::string, Wall*> walls;
        std::map<std::string, Dot*> dots;
        sf::RenderWindow *window;
    public:
        Maze(sf::RenderWindow* window){
            this->window = window;
            std::string myText;

            // Read from the walls file
            std::ifstream MyReadFile("walls.txt");

            while (!MyReadFile.eof()){
                MyReadFile>>myText;
                std::string delimiter = ";";
                std::string row = myText.substr(0, myText.find(delimiter));
                std::string col = myText.substr(myText.find(delimiter) + 1, myText.length());
                walls[myText] = new Wall(std::stoi(row), std::stoi(col), std::string("wall.png"), window);
            }
            MyReadFile.close();
            // Read from the dots file
            MyReadFile.open("dots.txt");

            while (!MyReadFile.eof()){
                MyReadFile>>myText;
                std::string delimiter = ";";
                std::string row = myText.substr(0, myText.find(delimiter));
                std::string col = myText.substr(myText.find(delimiter) + 1, myText.length());
                dots[myText] = new Dot(std::stoi(row), std::stoi(col), std::string("coin.png"), std::string("no_coin.png"), window);
            }
            MyReadFile.close();
        }

        void draw(){
            // draw walls
            for ( const auto &wall : walls ) {
                wall.second->draw();
            }

            // draw dots
            for ( const auto &dot : dots ) {
                dot.second->draw();
            }
        }

        void freeMemory(){
            // free wall
            std::vector<std::string> keys_wall;
            for ( const auto &wall : walls ) {
                    keys_wall.push_back(wall.first);
                }
            for (auto key : keys_wall){
                auto wall = walls.find(key);
                delete (wall->second);
                walls.erase(wall);
            }
            // free dots
            std::vector<std::string> keys_dot;
            for ( const auto &dot : dots ) {
                    keys_dot.push_back(dot.first);
                }
            for (auto key : keys_dot){
                auto dot = dots.find(key);
                delete (dot->second);
                dots.erase(dot);
            }
        }
};