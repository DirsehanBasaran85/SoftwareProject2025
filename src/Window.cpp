#include "Window.h"

Window::Window(unsigned int width, unsigned int height, const std::string& title)
    : width(width), height(height), title(title)
{

    createWindow();
    ImGui::SFML::Init(window); // Initialize ImGui
}

Window::~Window() {
    ImGui::SFML::Shutdown(); // Destroy ImGui
}

void Window::run() { windowLoop();}

void Window::createWindow() {

    window.create(sf::VideoMode({ width, height }), title);
}

void Window::windowLoop() {

    while (isOpen())
    {

        while (const std::optional event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window,*event);
            if (event->is<sf::Event::Closed>())
                close();
        }

        ImGui::SFML::Update(window, deltaClock.restart()); // new frame

        ImGui::Begin("FPS");
        ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
        ImGui::End();

        clear();


        ImGui::SFML::Render(window); // draw ImGui at top
        display();
    }
}