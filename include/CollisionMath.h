#pragma once

#include "Entity.h"
#include <SFML/Graphics.hpp>

class CollisionMath
{
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

};