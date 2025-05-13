#pragma once 
#include "EntityManager.h"
#include "Scene.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics.hpp>


class DebugMenu {
private:

	sf::RenderWindow* window;
	Scene* scene;
	sf::Clock deltaClock;
	
public:
	DebugMenu();
	~DebugMenu();

	DebugMenu(const DebugMenu&) = delete; // prevent shallow copies
	DebugMenu& operator=(const DebugMenu&) = delete;

	bool IsMenuActive = true;
	bool Init(sf::RenderWindow* _window);
	void Update(Scene& scene);
	void Render();
	void ProcessEvent(sf::Event event);

};