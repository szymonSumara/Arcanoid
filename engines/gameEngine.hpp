#ifndef GAME_ENGINE
#define GAME_ENGINE


#include "../components/mapObject.hpp"
#include "../components/playerBar.hpp"
#include "../components/brick.hpp"
#include "../components/ball.hpp"
#include "../engines/collisionEngine.hpp"
#include "../engines/visualizationEngine.hpp"
#include <chrono>
#include <time.h>  
class GameEngine{

    private:
    const int windowWidth;
    const int windowHeight;
    std::list<Brick*> & bricks;
    std::list<Ball*> & balls;
    CollisionEngine & collisionEngine;
    VisualisationEngine & visualisationEngine;
    PlayerBar & playerBar;

    public:
    GameEngine(
            int windowWidth, 
            int windowHeight,
            CollisionEngine & collisionEngine, 
            std::list<Brick*> & bricks, 
            std::list<Ball*> & balls,
            VisualisationEngine & visualisationEngine,
            PlayerBar & playerBar
         ):
            windowWidth(windowWidth),
            windowHeight(windowHeight),
            collisionEngine(collisionEngine),
            bricks(bricks),
            balls(balls),
            visualisationEngine(visualisationEngine),
            playerBar(playerBar)
        {
            srand (time(NULL));
        }


    GameEngine &  operator= (const GameEngine & gameEngine) = default;
    void startGame();


};


#endif