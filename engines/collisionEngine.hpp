#ifndef COLISION_ENGINE
#define COLISION_ENGINE

#include "../components/ball.hpp"
#include "../components/brick.hpp"
#include "../components/playerBar.hpp"
#include <math.h>
#include <SFML/Graphics.hpp>


class CollisionEngine{
    std::list<Ball *> * balls;
    std::list<Brick*> * bricks;
    PlayerBar * playerBar;
public:
    CollisionEngine(PlayerBar * playerBar,std::list<Ball *> * balls, std::list<Brick*> * bricks):
    playerBar(playerBar), balls(balls),bricks(bricks)
    {

    }

    void detectAndHandleColisions();

private:
    void borderBounce(Ball * ball);
    void playerBarBounce(Ball *ball);
    bool isBallTouchBrick(Ball ball, Brick brick);
    sf::Vector2f calculateNewVector(sf::Vector2f firstVector, sf::Vector2f secondVector, float scalar);
};

#endif