#include "Window.h"

Window::Window(unsigned int width, unsigned int height, const std::string& title)
    : width(width), height(height), title(title)
{

    createWindow();
    ImGui::SFML::Init(window);  // init imgui
}

Window::~Window() {
    ImGui::SFML::Shutdown();  //clean on exit
}

void Window::run() {

    windowLoop();
}

void Window::createWindow() {

    window.create(sf::VideoMode({ width, height }), title,sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
}

void Window::windowLoop() {
    while (isOpen()) {

        while (const std::optional<sf::Event> event = window.pollEvent()) {
            ImGui::SFML::ProcessEvent(window, *event); // feed imgui

            if (event->is<sf::Event::Closed>()) {
                close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart()); // new frame

        // start imgui frame
        ImGui::Begin("FPS");
        ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
        ImGui::End();


        clear();

        // render imgui at the top
        ImGui::SFML::Render(window);

        display();
    }
}