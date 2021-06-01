#include "brick.hpp"
  
    std::list<sf::Vector2<float>> Brick::getCornersList(){
        return std::list<sf::Vector2<float>>{
            position,
            position + sf::Vector2f(0,height/2),
            position + sf::Vector2f(0,height),
            position + sf::Vector2f(width,height),
            position + sf::Vector2f(width,0),
            position + sf::Vector2f(width/2,0),
            position + sf::Vector2f(width/2,height),
            position + sf::Vector2f(0,0)
            
        };
    }