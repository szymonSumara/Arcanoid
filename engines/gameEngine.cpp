#include "gameEngine.hpp"


 void GameEngine::startGame(){
        while( visualisationEngine.windowIsOpen() && balls.size() > 0 && bricks.size() > 0 ){
            
            auto begin =  std::chrono::steady_clock::now();

            

            std::list<MapObject*> objectsToDisplay;

            playerBar.doRutine();
            objectsToDisplay.push_back(&playerBar);

            for(auto ball: balls){
                ball->doRutine(); 
                objectsToDisplay.push_back(ball); 
            }
            collisionEngine.detectAndHandleColisions();

            for(Brick * brick: bricks){ 
                if(!brick->isReadyToRemove){
                    
                    objectsToDisplay.push_back(brick);
                }else{
                    if(rand() % 10  ==  0 ){
                        balls.push_back(new Ball(brick->getMassCenter(),20));
                    }
                }
            }
            
             balls.remove_if(
             [](const Ball * o) { 
                 return o->getCenter().y > 1000; 
             });


             bricks.remove_if(
             [](const Brick * o) { 
                 return o->isReadyToRemove; 
             });
           // bricks->remove_if()
            printf("balls in list %ld \n", balls.size() );
            printf("bricks in list %ld \n", bricks.size() );
            visualisationEngine.visualisationRutine(objectsToDisplay);

            auto end = std::chrono::steady_clock::now();;      
            auto enlapsedTimeInMilisecods = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
            
            if(enlapsedTimeInMilisecods < 16 )
                sf::sleep(sf::milliseconds(16 - enlapsedTimeInMilisecods));
        }
    }