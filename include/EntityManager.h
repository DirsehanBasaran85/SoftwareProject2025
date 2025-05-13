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
	EntityPtr addEntity(const std::string& tag);
	EntityVec& getEntities();
	EntityVec& getEntities(const std::string& tag);
	EntityMap& getEntityMap();
	void removeDeadEntities(EntityVec& entityVec);

private:
	EntityVec entities;
	EntityMap entityMap;
	EntityVec toBeAddedEntities; // exists to avoid iterator invalidation
	size_t totalEntities = 0;

};