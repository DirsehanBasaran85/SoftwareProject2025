#pragma once
#include <string>
#include <tuple>
#include <memory>
#include "Components.h"


using ComponentTuple = std::tuple<
	TransformComponent,
	CollisionComponent,
	LifespanComponent
>;

class Entity {
public:



	std::shared_ptr<TransformComponent> transformComponent = nullptr;
	std::shared_ptr<CollisionComponent> collisionComponent = nullptr;
	std::shared_ptr<LifespanComponent> lifespanComponent = nullptr;

	bool isAlive() ;
	size_t getId() ;
	std::string& getTag() ; 
	void Deactivate();
	


private:

	friend class EntityManager;
	bool isActive=true; // alive or dead
	size_t id=0; // identifier
	std::string tag = "default"; // entity type

	Entity(const size_t id, const std::string& tag);
};