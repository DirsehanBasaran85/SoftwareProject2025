#pragma once
#include <SFML/Graphics.hpp>


// for position, velocity, angle
class TransformComponent {
public:
	TransformComponent(sf::Vector2f& pos, sf::Vector2f& vel, float& ang) 
		: position(pos), velocity(vel), angle(ang) {}

	bool exists = false;
	sf::Vector2f position = { 0.0f,0.0f };
	sf::Vector2f velocity = { 0.0f,0.0f };
	float angle = 0.0f;
};

// scoreboard
//class ScoreboardComponent {
//public:
//	ScoreboardComponent(int score) 
//		: score(score){}
//
//	Component;
//	int score = 0;
//};

class CollisionComponent {
public:
	CollisionComponent(float aabbsize,sf::Vector2f aabbposition,sf::Vector2f aabboffset)
		: aabbSize(aabbsize),aabbPosition(aabbposition),aabbOffset(aabboffset){}
	bool exists = false;
	float aabbSize;
	sf::Vector2f aabbPosition;
	sf::Vector2f aabbOffset;

};

class LifespanComponent {
public:
	LifespanComponent(int lt,int rlt) 
		: lifetime(lt), remainingLifetime(rlt){}
	bool exists = false;
	int lifetime;
	int remainingLifetime;
};