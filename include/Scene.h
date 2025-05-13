#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include "AssetManager.h"
#include <EntityManager.h>

//Rendering texture where sprites are drawn to 
//think of it as the game world, where everything has a coordinate based on the game world

class Scene {

public:

    Scene(sf::Vector2u size);
    ~Scene();

    const sf::Texture& getScene() ;
    sf::Vector2u getSize() const;
    void clear();
    void draw(const sf::Drawable& drawable);
    void display();
    const sf::RenderTexture& getRaw() const;


    EntityPtr addEntity(const std::string& tag);
    EntityPtr addEntity(const std::string& tag, sf::Vector2f position);
    void removeEntity(const std::string& tag);

    void setPosition(const std::string& tag, sf::Vector2f position);
    sf::Vector2f getPosition(const std::string& tag) ;

    EntityVec& getEntities();            // non-const
    const EntityVec& getEntities() const;      // const

    void update();

private:

    sf::RenderTexture scene;
    EntityManager entityManager;
    sf::Vector2u size;
};
