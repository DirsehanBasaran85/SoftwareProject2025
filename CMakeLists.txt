cmake_minimum_required(VERSION 3.10)

# Project Information
project(SoftwareProject2025)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Directories
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(ASSETS_DIR ${PROJECT_SOURCE_DIR}/assets)
set(SFML_DIR ${PROJECT_SOURCE_DIR}/thirdparty/SFML-3.0.0/lib/cmake/SFML)
set(Ogg_DIR ${PROJECT_SOURCE_DIR}/thirdparty/SFML-3.0.0/lib/cmake/Ogg)
set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/thirdparty/imgui)
set(IMGUI_SFML_DIR ${PROJECT_SOURCE_DIR}/thirdparty/imgui-sfml)

# SFML Configuration
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Network System Window)

# ImGui Core
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
)

# ImGui-SFML
set(IMGUI_SFML_SOURCES
    ${IMGUI_SFML_DIR}/imgui-SFML.cpp
)

# Source Files
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Executable
add_executable(${PROJECT_NAME} "src/Main.cpp")

# Add All Sources
target_sources(${PROJECT_NAME} PRIVATE
    ${SOURCE_FILES}
    ${IMGUI_SOURCES}
    ${IMGUI_SFML_SOURCES}
)

# Include Paths
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

# Configuration-specific options (optional)
target_compile_definitions(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:DEBUG_BUILD>
    $<$<CONFIG:Release>:RELEASE_BUILD>
)

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:/MDd /Zi /Od>        # Use Debug CRT, debug info, no optimizations
    $<$<CONFIG:Release>:/MD /O2 /DNDEBUG>  # Use Release CRT, optimizations, no asserts
)

# Post-build: copy assets
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${ASSETS_DIR} $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
