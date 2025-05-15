#pragma once
#include "EntityManager.h"
#include <SFML/Graphics.hpp>


class System {
protected:
    EntityManager* entityManager = nullptr;
public:
    void setEntityManager(EntityManager* entityMgr) { entityManager = entityMgr; }
};

class GameplaySystem : System {
public:
    EntityPtr addEntity(const std::string& tag);
    EntityPtr addEntity(const std::string& tag, sf::Vector2f position);
    void removeEntity(const std::string& tag);
    void setPosition(const std::string& tag, sf::Vector2f position);
    sf::Vector2f getPosition(const std::string& tag);
    EntityPtr getEntityByName(const std::string& tag);
    EntityVec& getEntities();            // non-const
    const EntityVec& getEntities() const;      // const
    void update();
private:
    EntityManager entityManager;
};

class CollisionSystem : System {
public:
    sf::Vector2f calculateOverlap(const sf::Vector2f& aPos, const sf::Vector2f& bPos, const sf::Vector2f& aSize, const sf::Vector2f& bSize);

    /*
           Overlap if diff > 0, No overlap if diff < 0
           diff = [abs(x1-x2), abs(y1-y2)]
           overlapX = (w1/2) + (w2/2) - diff.x
           overlapY = (h1/2) + (h2/2) - diff.y
           overlap = [overlapX, overlapY]
     */
    sf::Vector2f getOverLap(std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b);

    /*
           Overlap.y > 0
           Movement from left or right side
           if pos.x > prevPos.x - from left
           if pos.x < prevPos.x - from right

     */
    sf::Vector2f getPreviouslyOverlap(std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b);

    //this exists for testing only 
    void resolveCollision(std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b);
};

class LifespanSystem : System {

};