#include "ball.hpp"

    void Ball::move(sf::Vector2<float> moveVector){
        center = center + moveVector;
        updateSpraitPosition(moveVector);
    }

    bool Ball::isPointInside(sf::Vector2<float> point){
        if((point.x - center.x)*(point.x - center.x) 
         + (point.y - center.y)*(point.y - center.y) < r*r)
         return true;
        else
        return false;
    }