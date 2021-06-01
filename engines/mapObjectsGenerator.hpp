#ifndef MAP_OBJECT_GENERATOR
#define MAP_OBJECT_GENERATOR


#include "../components/ball.hpp"
#include "../components/brick.hpp"
#include "../components/playerBar.hpp"

class MapObjectGenerator{
    MapObjectGenerator(){}
    public:
    
    static std::list<Brick*> getBricks(int bricksInRow,int bricksInColumn ,int mapWidth);

    static std::list<Ball*> getBalls(int ballsNumber );

    static PlayerBar getPlayerBar();
};


#endif