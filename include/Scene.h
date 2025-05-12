#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include "AssetManager.h"

//Rendering texture where sprites are drawn to 
//think of it as the game world, where everything has a coordinate based on the game world

class Scene {

public:

    Scene(sf::Vector2u size);
    ~Scene();

    sf::Vector2u getSize() const;
    void clear();
    void draw(const sf::Drawable& drawable);
    void display();

    void addEntity(const std::string& entityName);
    void addEntity(const std::string& entityName, sf::Vector2f position);
    void removeEntity(const std::string& entityName);

    void setPosition(const std::string& entityName, sf::Vector2f position);
    sf::Vector2f getPosition(const std::string& entityName) const;

    const sf::RenderTexture& getRaw() const;

    struct Entity {
        sf::Vector2f position;
    };

    const std::unordered_map<std::string, Entity>& getEntities() const;

private:

    sf::RenderTexture scene;
    std::unordered_map<std::string, Entity> entities;
    sf::Vector2u size;
};
