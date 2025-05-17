#pragma once 
#include "EntityManager.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>


class DebugMenu {
private:

	sf::RenderWindow* window = nullptr;
	sf::Clock deltaClock;
	
public:
	DebugMenu();
	~DebugMenu();

	DebugMenu(const DebugMenu&) = delete; // prevent shallow copies
	DebugMenu& operator=(const DebugMenu&) = delete;

	bool IsMenuActive = true;
	bool showCollisions = true;
	bool Init(sf::RenderWindow* _window);
	void Update(EntityManager& em);
	void Render();
	void ProcessEvent(const sf::Event& event);

};