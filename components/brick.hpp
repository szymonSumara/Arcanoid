#ifndef BRICK
#define BRICK

#include "mapObject.hpp"
#include <list>
class Brick: public MapObject{
    
    public:

    bool isReadyToRemove = false;

    sf::Vector2f position;
    Brick(int width,int height,sf::Vector2f position , std::string spritePath):MapObject(width,height,spritePath),position(position){}
    Brick(sf::Vector2f position): MapObject(54 ,20,"brick.jpg"),position(position){
        updateSpraitPosition(position);
    }
    
    void onPunchEvent(){
        isReadyToRemove = true;
    }

    sf::Vector2f getMassCenter(){
        return  sf::Vector2f(position.x + width/2 , position.y + height/2);
    }

    void move(sf::Vector2f moveVector){

    }

    std::list<sf::Vector2<float>> getCornersList();
};


#endif