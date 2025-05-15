#include <EntityManager.h>

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

EntityPtr EntityManager::addEntityByTag(const std::string& tag) {
	EntityPtr entity(new Entity(totalEntities++, tag));
	toBeAddedEntities.push_back(entity);
	return entity;
}


EntityPtr EntityManager::addInitializedEntityByTag(const std::string& tag, sf::Vector2f position) { // initialize an entity with no velocity (local player ?)
	sf::Vector2f velocity = { 0.0f, 0.0f };
	float angle = 0.0f;
	sf::Vector2f scale = { 1.0f, 1.0f };
	auto e = addEntityByTag(tag);
	e->addComponent<TransformComponent>(position, velocity, scale, angle); //= std::make_shared<TransformComponent>(position, velocity, angle); // be careful here if its null game crashes, should probably check or make more secure
	e->addComponent<CollisionComponent>(sf::Vector2f(32.0f, 32.0f));
	return e;
}

EntityPtr EntityManager::AddComponents(const std::string& tag) { // only exists for testing
	auto e = addEntityByTag(tag);
	TransformComponent t({ 200,200 }, {0.0f,0.0f}, {1.0f,1.0f}, 0.0f);
	CollisionComponent c({32.0f,32.0f});
	AddComponentToEntity(e, t, c); // definition of this is at EntityManager.h
	return e;
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

EntityPtr EntityManager::getFirstEntityByTag(const std::string& tag) {
	auto& entityvec = getEntities();
	for (auto e : entityvec)
	{
		if (e->getTag() == tag)
		{
			return e;
		}
	}

	throw std::runtime_error("Entity '" + tag + "' not found.");

}

EntityPtr EntityManager::getEntityByID(const size_t id) {
	auto& entityvec = getEntities();
	for (auto e : entityvec) {
		if (e->getId() == id) return e;
	}
	throw std::runtime_error("Entity id:" + std::to_string(id) + "not found");
}

sf::Vector2f EntityManager::getFirstEntityPosByTag(const std::string& tag) {
	auto& entityvec = getEntities();
	for (auto e : entityvec)
	{
		if (e->getTag() == tag)
		{
			return (e->getComponent<TransformComponent>().position);
		}
	}

	throw std::runtime_error("Entity '" + tag + "' not found.");

}

void EntityManager::setEntityPosByTag(const std::string& tag, sf::Vector2f position) { // this should only work for local player

	auto& entityvector = getEntities();
	for (auto e : entityvector)
	{
		if (e->getTag() == tag)
		{
			e->getComponent<TransformComponent>().position = position;
		}
	}
}

void EntityManager::removeEntityByTag(const std::string& tag) {

	auto& entityvec = getEntities();
	for (auto e : entityvec)
	{
		if (e->getTag() == tag)
		{
			e->Deactivate();
		}
	}
}

void EntityManager::removeDeadEntities(EntityVec& entityVec) {
	auto it = remove_if(entityVec.begin(), entityVec.end(), [](const EntityPtr& e) {return e->isAlive() == false;}); // move dead values to the end and alive ones to the beginning
	entityVec.erase(it, entityVec.end()); // delete the dead entities
}

