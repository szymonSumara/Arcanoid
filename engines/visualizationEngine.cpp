#include "visualizationEngine.hpp"

 void VisualisationEngine::visualisationRutine(std::list<MapObject*> objectsToDisplay ){
    sf::Event zdarzenie;
    while(  gameWindow.pollEvent( zdarzenie ) )
    {
        if( zdarzenie.type == sf::Event::Closed )
            gameWindow.close();
        
        if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
            gameWindow.close();
        
        if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
            gameWindow.close();
    }

    displayElements(objectsToDisplay);
}

    void VisualisationEngine::displayElements(std::list<MapObject*> objectsToDisplay ){
        gameWindow.clear( sf::Color::Black );
        gameWindow.draw(background);
        
        for(auto objectsToDisplay:objectsToDisplay){
            objectsToDisplay->drawOn(gameWindow);
        }

        gameWindow.display();
    }