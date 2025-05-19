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

	EntityPtr addEntityWithTag(const std::string& tag);

	template<typename... Components>
	void AddComponentToEntity(EntityPtr entity, Components&&... components) {
		(entity->addComponent<std::decay_t<Components>>(std::forward<Components>(components)), ...);
	}

	EntityVec& getEntities();
	EntityVec& getEntitiesByTag(const std::string& tag);
	EntityMap& getEntityMap();
	EntityPtr getEntityByID(const size_t id);
	sf::Vector2f getEntityPosByID(const size_t id);

	void setEntityPosByID(const size_t id, sf::Vector2f pos);

	void removeDeadEntities(EntityVec& entityVec);


private:
	EntityVec entities;
	EntityMap entityMap;
	EntityVec toBeAddedEntities; // exists to avoid iterator invalidation
	size_t totalEntities = 0;

};