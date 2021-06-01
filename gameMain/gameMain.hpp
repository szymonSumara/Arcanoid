#ifndef GAME_MAIN
#define GAME_MAIN

#include "../engines/gameEngine.hpp"
#include "../engines/collisionEngine.hpp"
#include "../engines/visualizationEngine.hpp"
#include "../engines/mapObjectsGenerator.hpp"

#include "../components/ball.hpp"
#include "../components/playerBar.hpp"
#include "../components/brick.hpp"
#define MAP_WIDTH 1376
#define MAP_HEIGHT 900
class Game{

    GameEngine gameEngine;
    VisualisationEngine visualisationEngine;
    CollisionEngine collisionEngine;
    std::list<Ball*> balls;
    std::list<Brick*> bricks;
    PlayerBar playerBar;
    public:
    
    Game(int startBallsNumber, int bricksInRow, int bricksInColumn):
        balls(MapObjectGenerator::getBalls(startBallsNumber)),
        bricks( MapObjectGenerator::getBricks(bricksInRow,bricksInColumn,MAP_WIDTH)),
        visualisationEngine( 1376,900),
        playerBar(MapObjectGenerator::getPlayerBar()),
        collisionEngine(&playerBar,&balls,&bricks),
        gameEngine(1376,900,collisionEngine,bricks,balls,visualisationEngine,playerBar)
        
    {
    }

    void start(){
        gameEngine.startGame();
    }

};


#endif