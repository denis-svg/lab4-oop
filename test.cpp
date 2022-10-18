#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 200), "SFML works!");
    Game g(&window);
    g.run();
    /*
    Maze m(&window);
    std::string paths[4] =  {std::string("images/left.jpg"), std::string("images/right.png"), std::string("images/up.png"), std::string("images/down.png")};
    std::string paths1[4] =  {std::string("images/left1.jpg"), std::string("images/right1.png"), std::string("images/up1.png"), std::string("images/down1.png")};
    PacMan p(4, 0, paths, paths1, &window);
    window.setFramerateLimit(30);
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    bool need_update = true;
    bool left = false;
    bool right = false;
    bool down = false;
    bool up = false;
    while (window.isOpen())
    {
        sf::Event event;
        start = std::chrono::high_resolution_clock::now();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                m.freeMemory();
                window.close();
            }
            if (event.type == sf::Event::EventType::KeyPressed){
                if (event.key.code == sf::Keyboard::A){
                    need_update = true;
                    p.moveLeft();
                    p.movedLeft();
                }
                if (event.key.code == sf::Keyboard::D){
                    need_update = true;
                    p.moveRight();
                    p.movedRight();
                }
                if (event.key.code == sf::Keyboard::W){
                    need_update = true;
                    p.moveUp();
                    p.movedUp();
                }
                if (event.key.code == sf::Keyboard::S){
                    need_update = true;
                    if (!m.isWall(p.getRow() + 1, p.getCol())){
                        p.moveDown();
                        p.movedDown();
                    }
                }
    	    }
            if (event.type == sf::Event::EventType::KeyReleased){

                if (event.key.code == sf::Keyboard::D){
                    right = false;
                }

    	    }
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    if(m.isDot(event.mouseButton.y / 20, event.mouseButton.x / 20)){
                        std::cout<<"Is dot"<<std::endl;
                    }
                    if(m.isWall(event.mouseButton.y / 20, event.mouseButton.x / 20)){
                        std::cout<<"Is Wall"<<std::endl;
                    }
                }
            }
        }

            window.clear();
            m.draw();
            p.draw();
            window.display();
        end = std::chrono::high_resolution_clock::now();
        float fps = (float)1e9/(float)std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
        //std::cout<<fps<<std::endl;
    }
   */
}

