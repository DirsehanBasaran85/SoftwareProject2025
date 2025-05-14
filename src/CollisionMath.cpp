#include "CollisionMath.h"

sf::Vector2f CollisionMath::calculateOverlap(const sf::Vector2f& aPos, const sf::Vector2f& bPos, const sf::Vector2f& aSize, const sf::Vector2f& bSize){
    const sf::Vector2f d = { abs(aPos.x - bPos.x), abs(aPos.y - bPos.y) };
    return { aSize.x / 2 + bSize.x / 2 - d.x, aSize.y / 2 + bSize.y / 2 - d.y };
}

sf::Vector2f CollisionMath::getOverLap(std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b){
    const auto& aPos = a->getComponent<TransformComponent>().position;
    const auto& bPos = b->getComponent<TransformComponent>().position;
    const auto& aSize = a->getComponent<CollisionComponent>().size; // width/height
    const auto& bSize = b->getComponent<CollisionComponent>().size;
    return calculateOverlap(aPos, bPos, aSize, bSize);
}

sf::Vector2f CollisionMath::getPreviouslyOverlap(std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b){
    const auto& aPos = a->getComponent<TransformComponent>().previousPosition;
    const auto& bPos = b->getComponent<TransformComponent>().previousPosition;
    const auto& aSize = a->getComponent<CollisionComponent>().size; // width/height
    const auto& bSize = b->getComponent<CollisionComponent>().size;
    return calculateOverlap(aPos, bPos, aSize, bSize);
}

