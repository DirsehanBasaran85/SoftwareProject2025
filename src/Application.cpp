#include "Application.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

Application::Application() {
	
    running = true;

	//Code below must be moved to the Window and be taken care of there
	//it is here to showcase the sfml library

        // Create the main window
        sf::RenderWindow window(sf::VideoMode({ 1200, 800 }), "Test");

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
                shutdown();
        }

        // Clear screen
        window.clear();

        // Update the window
        window.display();
    }

}

void Application::shutdown() {

    running = false;

}

bool Application::isRunning() {
	
    return running;

}