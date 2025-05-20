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
        if (!ImGui::SFML::UpdateFontTexture()) {
            return 0; 
        }
        return 1;
    }
  
}
// todo add entity logic
void DebugMenu::Update(EntityManager& em) {
    ImGui::SFML::Update(*window, deltaClock.restart()); // new imgui frame
    ImGui::Begin("Debug Info");
    ImGui::BeginTabBar("FirstTabBar", ImGuiTabBarFlags_None);
    if (ImGui::BeginTabItem("Stats"))
    {
        ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
        sf::Vector2f pos_local = em.getEntityPosByID(0);  
        ImGui::Text("local x: %f local y: %f", pos_local.x, pos_local.y);
        ImGui::Checkbox("Show AABB", &showCollisions);
        ImGui::EndTabItem();
    }
    if (ImGui::BeginTabItem("Entities")) 
    {
        EntityVec entities = em.getEntities();
        
        static ImGuiTableFlags flags = ImGuiTableFlags_BordersOuter | ImGuiTableFlags_NoBordersInBody | ImGuiTableFlags_ScrollY;

        if (ImGui::BeginTable("entity_table", 5, flags, ImVec2(0.0f, ImGui::GetTextLineHeightWithSpacing() * 15), 0.0f))
        {
            ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_DefaultSort | ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableSetupColumn("Tag", ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableSetupColumn("Alive", ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableSetupColumn("Position", ImGuiTableColumnFlags_WidthFixed);
            ImGui::TableSetupColumn("AABB Size", ImGuiTableColumnFlags_WidthStretch);
            ImGui::TableHeadersRow();

            for (const auto& e : entities)
            {
                ImGui::TableNextRow();
                ImGui::TableSetColumnIndex(0);
                ImGui::Text("%zu", e->getId());

                ImGui::TableSetColumnIndex(1);
                ImGui::Text("%s", e->getTag().c_str());

                ImGui::TableSetColumnIndex(2);
                ImGui::Text("%s", e->isAlive() ? "Yes" : "No");

                ImGui::TableSetColumnIndex(3);
                if (e->hasComponent<TransformComponent>())
                {
                    auto& t = e->getComponent<TransformComponent>();
                    ImGui::Text("(%.0f, %.0f)", t.position.x, t.position.y);
                }
                else
                {
                    ImGui::Text("-");
                }

                ImGui::TableSetColumnIndex(4);
                if (e->hasComponent<CollisionComponent>())
                {
                    auto& c = e->getComponent<CollisionComponent>();
                    ImGui::Text("(%.0f, %.0f)", c.size.x,c.size.y);
                }
                else
                {
                    ImGui::Text("-");
                }
            }

            ImGui::EndTable();
        }
        
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

void DebugMenu::ProcessEvent(const sf::Event& event) {
	ImGui::SFML::ProcessEvent(*window, event);
}