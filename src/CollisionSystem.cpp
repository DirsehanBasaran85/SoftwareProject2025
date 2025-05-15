#include "../game/Systems.h"

sf::Vector2f CollisionSystem::calculateOverlap(const sf::Vector2f& aPos, const sf::Vector2f& bPos, const sf::Vector2f& aSize, const sf::Vector2f& bSize){
    const sf::Vector2f d = { abs(aPos.x - bPos.x), abs(aPos.y - bPos.y) };
    return { aSize.x / 2 + bSize.x / 2 - d.x, aSize.y / 2 + bSize.y / 2 - d.y };
}

sf::Vector2f CollisionSystem::getOverLap(std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b){
    const auto& aPos = a->getComponent<TransformComponent>().position;
    const auto& bPos = b->getComponent<TransformComponent>().position;
    const auto& aSize = a->getComponent<CollisionComponent>().size; // width/height
    const auto& bSize = b->getComponent<CollisionComponent>().size;
    return calculateOverlap(aPos, bPos, aSize, bSize);
}

sf::Vector2f CollisionSystem::getPreviouslyOverlap(std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b){
    const auto& aPos = a->getComponent<TransformComponent>().previousPosition;
    const auto& bPos = b->getComponent<TransformComponent>().previousPosition;
    const auto& aSize = a->getComponent<CollisionComponent>().size; // width/height
    const auto& bSize = b->getComponent<CollisionComponent>().size;
    return calculateOverlap(aPos, bPos, aSize, bSize);
}

void CollisionSystem::resolveCollision(std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b) {
    auto& aTransform = a->getComponent<TransformComponent>();
    auto& bTransform = b->getComponent<TransformComponent>();
    const auto& aSize = a->getComponent<CollisionComponent>().size;
    const auto& bSize = b->getComponent<CollisionComponent>().size;

    sf::Vector2f delta = aTransform.position - bTransform.position;
    sf::Vector2f overlap = calculateOverlap(aTransform.position, bTransform.position, aSize, bSize);

    // No overlap: do nothing
    if (overlap.x <= 0.f || overlap.y <= 0.f)
        return;

    // Resolve by the smallest axis
    if (overlap.x < overlap.y) {
        // Push on X axis
        if (delta.x > 0)
            aTransform.position.x += overlap.x;
        else
            aTransform.position.x -= overlap.x;
    }
    else {
        // Push on Y axis
        if (delta.y > 0)
            aTransform.position.y += overlap.y;
        else
            aTransform.position.y -= overlap.y;
    }
}
