#pragma once
#include "EntityManager.h"
#include <SFML/Graphics.hpp>


class System {
protected:
    EntityManager* entityManager = nullptr;
public:
    void setEntityManager(EntityManager* entityMgr) { entityManager = entityMgr; }
};



class CollisionSystem : System {
public:
    sf::Vector2f calculateOverlap(const sf::Vector2f& aPos, const sf::Vector2f& bPos,
        const sf::Vector2f& aSize, const sf::Vector2f& bSize) {
        float ax1 = aPos.x;
        float ay1 = aPos.y;
        float ax2 = ax1 + aSize.x;
        float ay2 = ay1 + aSize.y;

        float bx1 = bPos.x;
        float by1 = bPos.y;
        float bx2 = bx1 + bSize.x;
        float by2 = by1 + bSize.y;

        float overlapX = std::min(ax2, bx2) - std::max(ax1, bx1);
        float overlapY = std::min(ay2, by2) - std::max(ay1, by1);

        return { overlapX, overlapY }; // Can be negative if not overlapping
    }

    sf::Vector2f getOverLap(std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b) {
        const auto& aPos = a->getComponent<TransformComponent>().position;
        const auto& bPos = b->getComponent<TransformComponent>().position;
        const auto& aSize = a->getComponent<CollisionComponent>().size;
        const auto& bSize = b->getComponent<CollisionComponent>().size;
        return calculateOverlap(aPos, bPos, aSize, bSize);
    }

    sf::Vector2f getPreviouslyOverlap(std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b) {
        const auto& aPos = a->getComponent<TransformComponent>().previousPosition;
        const auto& bPos = b->getComponent<TransformComponent>().previousPosition;
        const auto& aSize = a->getComponent<CollisionComponent>().size;
        const auto& bSize = b->getComponent<CollisionComponent>().size;
        return calculateOverlap(aPos, bPos, aSize, bSize);
    }

    void resolveCollision(std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b) {
        auto& aTransform = a->getComponent<TransformComponent>();
        auto& bTransform = b->getComponent<TransformComponent>();
        const auto& aSize = a->getComponent<CollisionComponent>().size;
        const auto& bSize = b->getComponent<CollisionComponent>().size;

        sf::Vector2f aPos = aTransform.position;
        sf::Vector2f bPos = bTransform.position;

        sf::Vector2f delta = (aPos + aSize * 0.5f) - (bPos + bSize * 0.5f); // Center-to-center
        sf::Vector2f overlap = calculateOverlap(aPos, bPos, aSize, bSize);

        if (overlap.x <= 0.f || overlap.y <= 0.f)
            return;

        if (overlap.x < overlap.y) {
            // Resolve X axis
            if (delta.x > 0)
                aTransform.position.x += overlap.x;
            else
                aTransform.position.x -= overlap.x;
        }
        else {
            // Resolve Y axis
            if (delta.y > 0)
                aTransform.position.y += overlap.y;
            else
                aTransform.position.y -= overlap.y;
        }
    }
};

class LifespanSystem : System {

};