#include "./collisionEngine.hpp"

double distanceBetweenPoints(sf::Vector2<float> a, sf::Vector2<float> b){
    return (a.x - b.x)*(a.x - b.x) +  (a.y - b.y)*(a.y - b.y);
}


 void CollisionEngine::detectAndHandleColisions(){
        for(Ball * ball:*balls){
            borderBounce(ball);
            playerBarBounce(ball);
            for(Brick * brick:*bricks){
                if(brick->isReadyToRemove)continue;
                if(distanceBetweenPoints(ball->getCenter(),brick->getMassCenter()) > (ball->getRadius()*2)*(ball->getRadius()*2))continue;
                if(isBallTouchBrick(*ball,*brick)){
                    ball->updateMoveVector(
                        calculateNewVector(ball->getCenter(),brick->getMassCenter(),ball->speed)
                    );
                    brick->isReadyToRemove = true;
                }
            }
        }
    }

    void CollisionEngine::borderBounce(Ball * ball){
        sf::Vector2f center = ball->getCenter();
        sf::Vector2f moveVector = ball->getMoveVector();
        float radius = ball->getRadius();

        if(center.x < radius && moveVector.x < 0){
            ball->updateMoveVector(sf::Vector2f(moveVector.x *(-1),moveVector.y));
        }

        if(center.x >1376 -  radius && moveVector.x > 0){
            ball->updateMoveVector(sf::Vector2f(moveVector.x *(-1),moveVector.y));
        }

        if(center.y < radius && moveVector.y < 0){
            ball->updateMoveVector(sf::Vector2f(moveVector.x ,moveVector.y*(-1)));
        }

  //      its only for tests
        if(center.y > 900 -radius && moveVector.y > 0){
            ball->updateMoveVector(sf::Vector2f(moveVector.x ,moveVector.y*(-1)));
        }

        if(playerBar->getPosition().x < 0){
            playerBar->move(sf::Vector2f{0,playerBar->getPosition().y} - playerBar->getPosition());      
        }

        if(playerBar->getPosition().x > 1376.0f - playerBar->width){
            playerBar->move(sf::Vector2f{1376.0f - playerBar->width,playerBar->getPosition().y} - playerBar->getPosition()); 
            
        }
    }    

    void CollisionEngine::playerBarBounce(Ball *ball){
        sf::Vector2f center = ball->getCenter();
        sf::Vector2f moveVector = ball->getMoveVector();
        sf::Vector2f playerPosition = playerBar->getPosition();
        float radius = ball->getRadius();
        
        if(    center.y + radius > playerPosition.y
            && center.y - radius < playerPosition.y + playerBar->height
            && center.x + radius > playerPosition.x 
            && center.x - radius < playerPosition.x + playerBar->width){
            ball->updateMoveVector(calculateNewVector(ball->getCenter(), playerBar->getMassCenter(),ball->speed));
        }
    }


    bool CollisionEngine::isBallTouchBrick(Ball ball, Brick brick){
        sf::Vector2f ballCenter = ball.getCenter();
        float radius = ball.getRadius();
        sf::Vector2f brickMassCenter = brick.getMassCenter();

        if( abs(ballCenter.x - brickMassCenter.x) < 3*radius
            &&  abs(ballCenter.y - brickMassCenter.y) < 3*radius){
                for(sf::Vector2f point: brick.getCornersList()){
                    if(ball.isPointInside(point)){
                        return true;
                    }
                }
        }

        return false;
    }

    sf::Vector2f CollisionEngine::calculateNewVector(sf::Vector2f firstVector, sf::Vector2f secondVector, float scalar){
        sf::Vector2f newVector = firstVector - secondVector ;
        float newVectorLength = sqrt(newVector.x*newVector.x + newVector.y*newVector.y);
        float speedScalar = newVectorLength/scalar;
        return newVector/speedScalar;

    }
