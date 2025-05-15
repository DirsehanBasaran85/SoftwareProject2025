#include "DebugMenu.h"
#include <iostream>
DebugMenu::DebugMenu() {

}

DebugMenu::~DebugMenu()
{
	ImGui::SFML::Shutdown(); // clean up
}

bool DebugMenu::Init(sf::RenderWindow* _window) {
	window = _window;
    if (!ImGui::SFML::Init(*window))
    {
        return 0;
    }
    else
    {
        ImGui::GetStyle().ScaleAllSizes(1.2f);
        ImGuiIO& io = ImGui::GetIO();
        ImFont* customFont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Calibri.ttf", 15);
        io.FontDefault = customFont;
        ImGui::SFML::UpdateFontTexture();
        return 1;
    }
  
}
// todo add entity logic
void DebugMenu::Update(Scene& scene) {
    ImGui::SFML::Update(*window, deltaClock.restart()); // new imgui frame
    ImGui::Begin("Debug Info");
    ImGui::BeginTabBar("FirstTabBar", ImGuiTabBarFlags_None);
    if (ImGui::BeginTabItem("Stats"))
    {
        ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
        sf::Vector2f pos_apple = scene.em.getFirstEntityPosByTag("apple");
        ImGui::Text("local x: %f local y: %f", pos_apple.x, pos_apple.y);
        ImGui::Checkbox("Show AABB", &showCollisions);
        ImGui::EndTabItem();
    }
    /*  if (ImGui::BeginTabItem("Test"))
      {


          ImGui::Checkbox("Draw Circle", &drawCircle);
          ImGui::SameLine();
          ImGui::Checkbox("Draw Text", &drawText);
          ImGui::SliderFloat("Radius", &circleRadius, 0.0f, 300.f);
          ImGui::SliderInt("Sides", &circleSegments, 3, 64);
          ImGui::ColorEdit3("Color Circle", colors);
          ImGui::InputText("Text", displayString, 255);

          ImGui::SameLine();
          if (ImGui::Button("Reset Circle"))
          {
              circle.setPosition({ 0.0f,0.0f });
          }
          ImGui::EndTabItem();
          circle.setPointCount(circleSegments);
          circle.setRadius(circleRadius);
          circle.setFillColor(sf::Color(std::uint8_t(colors[0] * 255), std::uint8_t(colors[1] * 255), std::uint8_t(colors[2] * 255)));
          if (drawCircle) { scene.draw(circle); }

      }*/
    ImGui::EndTabBar();
    ImGui::End();
}

void DebugMenu::Render() {
	ImGui::SFML::Render(*window);
}

void DebugMenu::ProcessEvent(sf::Event event) {
	ImGui::SFML::ProcessEvent(*window, event);
}