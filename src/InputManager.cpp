#include "InputManager.h"

InputManager::InputManager() {}

void InputManager::beginFrame() {
    previousKeys = currentKeys;
    previousMouseButtons = currentMouseButtons;
    scrollDelta = 0.0f; // Reset scroll delta each frame
}

// Update Input States
void InputManager::update(const sf::Event& event) {
    if (auto keyPressed = event.getIf<sf::Event::KeyPressed>()) {
        currentKeys[keyPressed->scancode] = true;
    }
    else if (auto keyReleased = event.getIf<sf::Event::KeyReleased>()) {
        currentKeys[keyReleased->scancode] = false;
    }
    else if (auto mousePressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        currentMouseButtons[mousePressed->button] = true;
    }
    else if (auto mouseReleased = event.getIf<sf::Event::MouseButtonReleased>()) {
        currentMouseButtons[mouseReleased->button] = false;
    }
    else if (auto mouseMoved = event.getIf<sf::Event::MouseMoved>()) {
        mousePosition = { mouseMoved->position.x, mouseMoved->position.y };
    }
    else if (auto wheelScrolled = event.getIf<sf::Event::MouseWheelScrolled>()) {
        scrollDelta += wheelScrolled->delta;
    }
}

// Key Input Methods
bool InputManager::isKeyDown(sf::Keyboard::Scancode key) const {
    auto it = currentKeys.find(key);
    return it != currentKeys.end() && it->second;
}

bool InputManager::isKeyPressed(sf::Keyboard::Scancode key) const {
    return isKeyDown(key) && (!previousKeys.contains(key) || !previousKeys.at(key));
}

bool InputManager::isKeyReleased(sf::Keyboard::Scancode key) const {
    return !isKeyDown(key) && previousKeys.contains(key) && previousKeys.at(key);
}

// Mouse Input Methods
bool InputManager::isMouseDown(sf::Mouse::Button button) const {
    auto it = currentMouseButtons.find(button);
    return it != currentMouseButtons.end() && it->second;
}

bool InputManager::isMousePressed(sf::Mouse::Button button) const {
    return isMouseDown(button) && (!previousMouseButtons.contains(button) || !previousMouseButtons.at(button));
}

bool InputManager::isMouseReleased(sf::Mouse::Button button) const {
    return !isMouseDown(button) && previousMouseButtons.contains(button) && previousMouseButtons.at(button);
}

sf::Vector2i InputManager::getMousePosition() const {
    return mousePosition;
}

float InputManager::getScrollDelta() const {
    return scrollDelta;
}

// Action Bindings Methods
void InputManager::bindAction(const std::string& actionName, const InputBinding& input) {
    actionBindings[actionName].push_back(input);
}

void InputManager::unbindAction(const std::string& actionName) {
    actionBindings.erase(actionName);
}

void InputManager::unbindAction(const std::string& actionName, const InputBinding& binding) {
    auto it = actionBindings.find(actionName);
    if (it != actionBindings.end()) {
        auto& bindings = it->second;
        auto removeIt = std::remove(bindings.begin(), bindings.end(), binding);
        if (removeIt != bindings.end()) {
            bindings.erase(removeIt, bindings.end());
        }
    }
}


bool InputManager::isActionDown(const std::string& actionName) const {
    auto it = actionBindings.find(actionName);
    if (it == actionBindings.end()) return false;

    for (const auto& binding : it->second) {
        if (binding.type == InputType::Keyboard && isKeyDown(binding.key)) return true;
        if (binding.type == InputType::MouseButton && isMouseDown(binding.mouseButton)) return true;
    }
    return false;
}

bool InputManager::isActionPressed(const std::string& actionName) const {
    auto it = actionBindings.find(actionName);
    if (it == actionBindings.end()) return false;

    for (const auto& binding : it->second) {
        if (binding.type == InputType::Keyboard && isKeyPressed(binding.key)) return true;
        if (binding.type == InputType::MouseButton && isMousePressed(binding.mouseButton)) return true;
    }
    return false;
}

bool InputManager::isActionReleased(const std::string& actionName) const {
    auto it = actionBindings.find(actionName);
    if (it == actionBindings.end()) return false;

    for (const auto& binding : it->second) {
        if (binding.type == InputType::Keyboard && isKeyReleased(binding.key)) return true;
        if (binding.type == InputType::MouseButton && isMouseReleased(binding.mouseButton)) return true;
    }
    return false;
}

// InputBinding comparison operator
bool InputBinding::operator==(const InputBinding& other) const {
    if (type != other.type) return false;
    if (type == InputType::Keyboard) return key == other.key;
    if (type == InputType::MouseButton) return mouseButton == other.mouseButton;
    return false;
}