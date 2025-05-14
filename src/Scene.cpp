#include "Scene.h"
#include <stdexcept>

Scene::Scene(sf::Vector2u size) : scene(size) {

}

Scene::~Scene() {}

const sf::Texture& Scene::getScene() {
    return scene.getTexture();
}

sf::Vector2u Scene::getSize() const {

    return scene.getSize();
}

void Scene::clear() {

    scene.clear();
}

void Scene::draw(const sf::Drawable& drawable) {

    scene.draw(drawable);
}

void Scene::drawLine(const sf::Vector2f& p1, const sf::Vector2f& p2) 
{
    sf::VertexArray line(sf::PrimitiveType::LineStrip, 2);

    line[0].position = sf::Vector2f(p1.x, p1.y);
    line[1].position = sf::Vector2f(p2.x, p2.y);

    this->draw(line);
}

void Scene::display() {

    scene.display();
}
void Scene::update() {
    entityManager.Update();
}

EntityPtr Scene::addEntity(const std::string& tag) {
    auto e = entityManager.addEntity(tag);
    return e;

}

EntityPtr Scene::addEntity(const std::string& tag, sf::Vector2f position) { // initialize an entity with no velocity (local player ?)
    sf::Vector2f velocity = { 0.0f, 0.0f };
    float angle = 0.0f;
    sf::Vector2f scale = { 1.0f, 1.0f };
    auto e = entityManager.addEntity(tag);
    e->addComponent<TransformComponent>(position, velocity, scale, angle); //= std::make_shared<TransformComponent>(position, velocity, angle); // be careful here if its null game crashes, should probably check or make more secure
    e->addComponent<CollisionComponent>(sf::Vector2f(32.0f, 32.0f));
    return e;
}

void Scene::removeEntity(const std::string& tag) {

    auto& entityvec = entityManager.getEntities();
    for (auto e : entityvec)
    {
        if (e->getTag() == tag)
        {
            e->Deactivate();
        }
    }
}

void Scene::setPosition(const std::string& tag, sf::Vector2f position) { // this should only work for local player

    auto& entityvector = entityManager.getEntities();
    for (auto e : entityvector)
    {
        if (e->getTag() == tag)
        {
            e->getComponent<TransformComponent>().position = position;
        }
    }
}

sf::Vector2f Scene::getPosition(const std::string& tag) {
    bool found = 0;
    sf::Vector2f res;
    auto& entityvec = entityManager.getEntities();
    for (auto e : entityvec)
    {
        if (e->getTag() == tag)
        {
            found = true;
            res = e->getComponent<TransformComponent>().position;
        }
    }
    if (found) {
        return res;
    }
    else {
        throw std::runtime_error("Entity '" + tag + "' not found.");
    }
}

const sf::RenderTexture& Scene::getRaw() const {

    return scene;
}

EntityVec& Scene::getEntities() {

    return entityManager.getEntities();
}