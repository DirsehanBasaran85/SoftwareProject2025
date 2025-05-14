#pragma once
#include "ComponentBase.h"

// for position, velocity, angle
class TransformComponent : public Component {
public:
	TransformComponent() = default;
	TransformComponent(sf::Vector2f& pos, sf::Vector2f& vel, sf::Vector2f& sc, float& ang)
		: previousPosition(pos), position(pos), velocity(vel), scale(sc), angle(ang) {
	}

	bool exists = false;
	sf::Vector2f previousPosition = { 0.0f,0.0f };
	sf::Vector2f position = { 0.0f,0.0f };
	sf::Vector2f scale = { 1.0f,1.0f };
	sf::Vector2f velocity = { 0.0f,0.0f };
	float angle = 0.0f;
};

// scoreboard
//class ScoreboardComponent : public Component {
//public:
//	ScoreboardComponent(int score) 
//		: score(score){}
//
//	Component;
//	int score = 0;
//};

class CollisionComponent : public Component { // bounding box
public:
	CollisionComponent() = default;
	CollisionComponent(const sf::Vector2f& s)
		: size(s), halfSize(s.x / 2, s.y / 2) {
	}
	bool exists = false;
	sf::Vector2f size;
	sf::Vector2f halfSize;

};

class LifespanComponent : public Component {
public:
	LifespanComponent() = default;
	LifespanComponent(int lt, int rlt)
		: lifetime(lt), remainingLifetime(rlt) {
	}
	bool exists = false;
	int lifetime;
	int remainingLifetime;
};
