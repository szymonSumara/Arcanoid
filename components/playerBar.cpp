#include "../components/playerBar.hpp"

void PlayerBar::checkPlayersKeys( ){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
           moveVector = sf::Vector2f{15,0};
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
             moveVector = sf::Vector2f{-15,0};
        }else {
            moveVector = sf::Vector2f{0,0};
        }

    }

    void PlayerBar::move(sf::Vector2<float> moveVector){
        position += moveVector;
        updateSpraitPosition(moveVector);
    }