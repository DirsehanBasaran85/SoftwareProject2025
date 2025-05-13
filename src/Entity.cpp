#include "Entity.h"

Entity::Entity(const size_t id, const std::string& tag)
	: isActive(true),id(id),tag(tag){}

bool Entity::isAlive()  {
	return isActive;
}

 size_t Entity::getId()  {
	return id;
}


 std::string& Entity::getTag()	 {
	return tag;
}

void Entity::Deactivate() {
	isActive = false;
}




