#ifndef VISUALISATION_ENGINE
#define VISUALISATION_ENGINE


#include <SFML/Graphics.hpp>
#include "../components/mapObject.hpp"
#include <list>

class VisualisationEngine{
    public:
    sf::RenderWindow gameWindow;
    sf::Sprite background;
    sf::Texture backgroundTexture;

    VisualisationEngine(int windowWidth, int windowHeight):
        gameWindow( sf::VideoMode( windowWidth , windowHeight, 32 ), "Simple Game" ),
        background(),backgroundTexture(){
        backgroundTexture.loadFromFile("background.jpg");
        background.setTexture(backgroundTexture);
        background.setScale( 1, 1 );
    }

    void visualisationRutine(std::list<MapObject*> objectsToDisplay );

    void displayElements(std::list<MapObject*> objectsToDisplay );

    bool windowIsOpen(){
        return gameWindow.isOpen();
    }
};


#endif