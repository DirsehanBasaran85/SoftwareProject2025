#pragma once

#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>

using EntityPtr = std::shared_ptr<Entity>;
using EntityVec = std::vector<EntityPtr>;
using EntityMap = std::map<std::string, EntityVec>;

class EntityManager {
public:
	EntityManager();
	void Update();
	EntityPtr addEntityByTag(const std::string& tag);
	EntityPtr addInitializedEntityByTag(const std::string& tag, sf::Vector2f position);
	EntityVec& getEntities();
	EntityVec& getEntitiesByTag(const std::string& tag);
	EntityMap& getEntityMap();
	EntityPtr getFirstEntityByTag(const std::string& tag);
	sf::Vector2f getFirstEntityPosByTag(const std::string& tag);
	void setEntityPosByTag(const std::string& tag, sf::Vector2f position);
	void removeEntityByTag(const std::string& tag); // added
	void removeDeadEntities(EntityVec& entityVec);


private:
	EntityVec entities;
	EntityMap entityMap;
	EntityVec toBeAddedEntities; // exists to avoid iterator invalidation
	size_t totalEntities = 0;

};