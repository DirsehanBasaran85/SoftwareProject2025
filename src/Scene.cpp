#include "Scene.h"
#include <stdexcept>

Scene::Scene(sf::Vector2u size) : scene(size) {

}

Scene::~Scene() {}

sf::Vector2u Scene::getSize() const {

    return scene.getSize();
}

void Scene::clear() {

    scene.clear();
}

void Scene::draw(const sf::Drawable& drawable) {

    scene.draw(drawable);
}
void Scene::display() {

    scene.display();
}

void Scene::addEntity(const std::string& entityName) {

    entities.emplace(entityName, Entity{ sf::Vector2f(0, 0) });
}

void Scene::addEntity(const std::string& entityName, sf::Vector2f position) {

    entities.emplace(entityName, Entity{ position });
}

void Scene::removeEntity(const std::string& entityName) {

    entities.erase(entityName);
}

void Scene::setPosition(const std::string& entityName, sf::Vector2f position) {

    auto it = entities.find(entityName);
    if (it == entities.end()) {

        throw std::runtime_error("Entity '" + entityName + "' not found.");
    }
    it->second.position = position;
}

sf::Vector2f Scene::getPosition(const std::string& entityName) const {

    auto it = entities.find(entityName);
    if (it == entities.end()) {

        throw std::runtime_error("Entity '" + entityName + "' not found.");
    }
    return it->second.position;
}

const sf::RenderTexture& Scene::getRaw() const {

    return scene;
}

const std::unordered_map<std::string, Scene::Entity>& Scene::getEntities() const {

    return entities;
}
