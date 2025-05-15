#include "../game/Systems.h"

EntityPtr GameplaySystem::addEntity(const std::string& tag) {
    auto e = entityManager.addEntity(tag);
    return e;

}

EntityPtr GameplaySystem::addEntity(const std::string& tag, sf::Vector2f position) { // initialize an entity with no velocity (local player ?)
    sf::Vector2f velocity = { 0.0f, 0.0f };
    float angle = 0.0f;
    sf::Vector2f scale = { 1.0f, 1.0f };
    auto e = entityManager.addEntity(tag);
    e->addComponent<TransformComponent>(position, velocity, scale, angle); //= std::make_shared<TransformComponent>(position, velocity, angle); // be careful here if its null game crashes, should probably check or make more secure
    e->addComponent<CollisionComponent>(sf::Vector2f(32.0f, 32.0f));
    return e;
}

void GameplaySystem::removeEntity(const std::string& tag) {

    auto& entityvec = entityManager.getEntities();
    for (auto e : entityvec)
    {
        if (e->getTag() == tag)
        {
            e->Deactivate();
        }
    }
}

void GameplaySystem::update() {
    entityManager.Update();
}

void GameplaySystem::setPosition(const std::string& tag, sf::Vector2f position) { // this should only work for local player

    auto& entityvector = entityManager.getEntities();
    for (auto e : entityvector)
    {
        if (e->getTag() == tag)
        {
            e->getComponent<TransformComponent>().position = position;
        }
    }
}

sf::Vector2f GameplaySystem::getPosition(const std::string& tag) {
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

EntityPtr GameplaySystem::getEntityByName(const std::string& tag) {
    bool found = 0;
    auto& entityvec = entityManager.getEntities();
    EntityPtr ent;
    for (auto e : entityvec)
    {
        if (e->getTag() == tag)
        {
            found = true;
            ent = e;
        }
    }
    if (found) {
        return ent;
    }
    else {
        throw std::runtime_error("Entity '" + tag + "' not found.");
    }
}

EntityVec& GameplaySystem::getEntities() {

    return entityManager.getEntities();
}