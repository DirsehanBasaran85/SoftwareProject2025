#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <unordered_map>
#include <vector>
#include <string>

enum class InputType { Keyboard, MouseButton };

struct InputBinding {
    InputType type;
    union {
        sf::Keyboard::Scancode key;
        sf::Mouse::Button mouseButton;
    };

    bool operator==(const InputBinding& other) const;
};

class InputManager {
public:

    InputManager();

    // Update input state for each frame
    void beginFrame();
    void update(const sf::Event& event);

    // Keyboard
    bool isKeyDown(sf::Keyboard::Scancode key) const;
    bool isKeyPressed(sf::Keyboard::Scancode key) const;
    bool isKeyReleased(sf::Keyboard::Scancode key) const;

    // Mouse buttons
    bool isMouseDown(sf::Mouse::Button button) const;
    bool isMousePressed(sf::Mouse::Button button) const;
    bool isMouseReleased(sf::Mouse::Button button) const;
    sf::Vector2i getMousePosition() const;
    float getScrollDelta() const;

    // Action mappings
    void bindAction(const std::string& actionName, const InputBinding& input);
    void unbindAction(const std::string& actionName); //deletes a action
    void unbindAction(const std::string& actionName, const InputBinding& binding); //deletes a binding from action
    bool isActionDown(const std::string& actionName) const;
    bool isActionPressed(const std::string& actionName) const;
    bool isActionReleased(const std::string& actionName) const;

private:
    // Maps keys and mouse buttons to action states
    std::unordered_map<sf::Keyboard::Scancode, bool> currentKeys;
    std::unordered_map<sf::Keyboard::Scancode, bool> previousKeys;

    std::unordered_map<sf::Mouse::Button, bool> currentMouseButtons;
    std::unordered_map<sf::Mouse::Button, bool> previousMouseButtons;

    sf::Vector2i mousePosition = { 0, 0 };
    float scrollDelta = 0.0f;

    // Action bindings maps action names to multiple input bindings example: jump action is done both with space and mouse left click
    std::unordered_map<std::string, std::vector<InputBinding>> actionBindings;
};