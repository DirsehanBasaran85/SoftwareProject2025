#include <EntityManager.h>
#include <iostream>
EntityManager::EntityManager()
	: totalEntities(0) {}

void EntityManager::Update() {
	for (auto& e : toBeAddedEntities) {
		entities.push_back(e); // update the vector

		entityMap[e->getTag()].push_back(e); // update the map
	}
	toBeAddedEntities.clear(); // clear the queue

	removeDeadEntities(entities);

	for (auto& e : entityMap) {
		removeDeadEntities(e.second);
	}
}

EntityPtr EntityManager::addEntityWithTag(const std::string& tag) {
	EntityPtr entity(new Entity(totalEntities++, tag));
	toBeAddedEntities.push_back(entity);
	return entity;
}


EntityVec& EntityManager::getEntities() {
	return entities;
}

EntityVec& EntityManager::getEntitiesByTag(const std::string& tag) {
	return entityMap[tag];
}


EntityMap& EntityManager::getEntityMap() {
	return entityMap;
}



EntityPtr EntityManager::getEntityByID(const size_t id) {
	auto& entityvec = getEntities();
	for (const auto& e : entityvec) {
		if (e->getId() == id)
			return e;
	}

	std::cout << "Entity id: " << id << " not found" << std::endl;
	return nullptr;
}

sf::Vector2f EntityManager::getEntityPosByID(const size_t id) {
	return getEntityByID(id).get()->getComponent<TransformComponent>().position;
}

void EntityManager::setEntityPosByID(const size_t id, sf::Vector2f pos){
	auto entity = getEntityByID(id);
	entity->getComponent<TransformComponent>().position = pos;

}


void EntityManager::removeDeadEntities(EntityVec& entityVec) {
	auto it = remove_if(entityVec.begin(), entityVec.end(), [](const EntityPtr& e) {return e->isAlive() == false;}); // move dead values to the end and alive ones to the beginning
	entityVec.erase(it, entityVec.end()); // delete the dead entities
}

