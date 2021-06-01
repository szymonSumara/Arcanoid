#ifndef MAP_OBJECT
#define MAP_OBJECT

#include <SFML/Graphics.hpp>


class MapObject{
   
   
    sf::Sprite sprite;
    sf::Texture texture;
    public:
    int width;
    int height;

    MapObject(int width,int height, std::string spritePath):width(width),height(height),sprite(),texture(){
        texture.loadFromFile(spritePath);
        sprite.setTexture(texture);
        sprite.setScale( 1, 1 );

    }

    void drawOn(sf::RenderWindow & appWindow){
        appWindow.draw(sprite);
    }

    void updateSpraitPosition(sf::Vector2f newPosition){
        
        sprite.move(newPosition);
    }

    virtual void move(sf::Vector2<float> vector) = 0;

    virtual void doRutine(){};

    virtual ~MapObject(){};

};

#endif