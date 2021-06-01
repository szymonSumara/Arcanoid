#ifndef BALL
#define BALL

#include "mapObject.hpp"

class Ball : public MapObject{
    
    sf::Vector2<float> moveVector{-4,-4};
    int r;
    sf::Vector2f center;
    public:
    const float speed = 10;
    Ball( sf::Vector2f startPosition, int r):MapObject(2*r,2*r,"ball.png"),center(startPosition),r(r){
        updateSpraitPosition(center - sf::Vector2f(r,r));
          
    }

    void doRutine(){
        move( moveVector );
    }

    void updateMoveVector(sf::Vector2f newMoveVector){
        moveVector = newMoveVector;
    }

    sf::Vector2f getCenter() const{
        return center;
    }

    void move(sf::Vector2<float> moveVector);

    bool isPointInside(sf::Vector2<float> point);

    float getRadius() const{
        return r;
    }

    sf::Vector2f getMoveVector() const {
        return moveVector;
    }

};


#endif