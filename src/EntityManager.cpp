#include <EntityManager.h>

EntityManager::EntityManager() 
	: totalEntities(0){}

void EntityManager::removeDeadEntities(EntityVec& entityVec) {
	auto it = remove_if(entityVec.begin(), entityVec.end(), [](const EntityPtr& e) {return e->isAlive() == false;}); // move dead values to the end and alive ones to the beginning
	entityVec.erase(it, entityVec.end()); // delete the dead entities
}

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

EntityPtr EntityManager::addEntity(const std::string& tag){
	EntityPtr entity(new Entity(totalEntities++,tag));
	toBeAddedEntities.push_back(entity);
	return entity;
}

EntityVec& EntityManager::getEntities() {
	return entities;
}

EntityVec& EntityManager::getEntities(const std::string& tag) {
	return entityMap[tag];
}

EntityMap& EntityManager::getEntityMap() {
	return entityMap;
}