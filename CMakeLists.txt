cmake_minimum_required(VERSION 3.10)

# Project Information
project(SoftwareProject2025)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Include Directories
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(ASSETS_DIR ${PROJECT_SOURCE_DIR}/assets)
set(SFML_DIR ${PROJECT_SOURCE_DIR}/thirdparty/SFML-3.0.0/lib/cmake/SFML)
set(Ogg_DIR ${PROJECT_SOURCE_DIR}/thirdparty/SFML-3.0.0/lib/cmake/Ogg)
set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/thirdparty/imgui)
set(IMGUI_SFML_DIR ${PROJECT_SOURCE_DIR}/thirdparty/imgui-sfml)

# SFML Configuration
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Network System Window)

# ImGui-SFML Configuration
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
)

set(IMGUI_SFML_SOURCES
    ${IMGUI_SFML_DIR}/imgui-SFML.cpp
)

# Source Files
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Define Executable
add_executable(${PROJECT_NAME} "src/Main.cpp")

# Add Source Files
target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${IMGUI_SOURCES} ${IMGUI_SFML_SOURCES})

# Include Directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${INCLUDE_DIR}
    ${IMGUI_DIR}
    ${IMGUI_SFML_DIR}
)

# Link Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    SFML::Graphics
    SFML::Audio
    SFML::Network
    SFML::Window
    SFML::System
)

# Custom Post-Build Command: Copy Assets
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${ASSETS_DIR} $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)


# Link Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    SFML::Graphics
    SFML::Audio
    SFML::Network
    SFML::Window
    SFML::System
)

# Custom Post-Build Command: Copy Assets
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${ASSETS_DIR} $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)
