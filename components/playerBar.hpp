#ifndef PLAYER_BAR
#define PLAYER_BAR


#include "mapObject.hpp"


class PlayerBar : public MapObject{
 
    sf::Vector2f position;
    sf::Vector2f moveVector;

    public:
    PlayerBar(int width,int height,sf::Vector2f startPosition , std::string spritePath):MapObject(width,height,spritePath),
    position(0,0),moveVector(0,0){
        move(startPosition);
    }
    //PlayerBar(): MapObject(240,39,"bar.jpg"){}
    PlayerBar( PlayerBar && ) = default;
    PlayerBar( PlayerBar & ) = default;
    void doRutine( ){
        checkPlayersKeys();
        move(moveVector);
    }
    
    void checkPlayersKeys( );

    void move(sf::Vector2<float> moveVector);

    sf::Vector2f getPosition() const {
        return position ;
    }

    sf::Vector2f getMassCenter() const {
        return sf::Vector2f(position.x + width/2 , position.y + height/2);
    }

};

#endif