#pragma once
#include <string>
#include <tuple>
#include <memory>
#include "Component.h"


using ComponentTable = std::tuple<
	TransformComponent,
	CollisionComponent,
	LifespanComponent,
	SpriteComponent
>;

class Entity {
public:

	template <typename T>
	bool hasComponent() { return getComponent<T>().exists; }

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&...mArgs)
	{
		auto& component = getComponent<T>();
		component = T(std::forward<TArgs>(mArgs)...);
		component.exists = true;
		return component;
	}

	template <typename T>
	T& getComponent() { return std::get<T>(components); }

	template <typename T>
	void removeComponent() { getComponent<T>() = T(); }

	bool isAlive() ; 
	size_t getId() ;
	std::string& getTag() ; 
	void Deactivate();
	


private:

	friend class EntityManager;
	bool isActive=true; // alive or dead
	size_t id=0; // identifier
	std::string tag = "default"; // entity type
	ComponentTable components;

	Entity(const size_t id, const std::string& tag);
};