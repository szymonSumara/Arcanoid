#include "mapObjectsGenerator.hpp"

    std::list<Brick*> MapObjectGenerator::getBricks(int bricksInRow,int bricksInColumn ,int mapWidth ){
        std::list<Brick*> generatedBricks;
        int xStart = (mapWidth - bricksInRow*55)/2;
        for(int j=0;j<bricksInColumn;j++){
                 for(int i = 0;i<bricksInRow;i++){
                     generatedBricks.push_back( new Brick(sf::Vector2f(xStart + 55*i,100 + j*21)));
             }
         }

        return generatedBricks;
    }

    std::list<Ball*> MapObjectGenerator::getBalls(int ballsNumber ){
        std::list<Ball*> generatedBalls;
 
        for(int i = 0;i<ballsNumber;i++){
            generatedBalls.push_back( new Ball(sf::Vector2f(55*i,500),20));
        }
        return generatedBalls;
    }

    PlayerBar MapObjectGenerator::getPlayerBar(){
        return PlayerBar(240,39,sf::Vector2f(200,800),"bar.jpg");
    }