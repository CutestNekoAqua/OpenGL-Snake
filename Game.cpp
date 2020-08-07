//
// Created by valen on 04.08.2020.
//

#include "Game.h"

SpriteRenderer *Renderer;

Game::Game(unsigned int width, unsigned int height)
        : State(GAME_ACTIVE), Width(width), Height(height)
{

}

Game::~Game()
{

}

void Game::Init()
{
    // load shaders
    ResourceManager::LoadShader("sprite.vs", "sprite.frag", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width),
                                      static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
    // load textures
    ResourceManager::LoadTexture("awesomeface.png", true, "face");
    ResourceManager::LoadTexture("berry.png", true, "block");
    Level = new GameLevel();

    // Debug
    Level.Load(this->Width, this->Height);
}

void Game::Update(float dt)
{

}

void Game::ProcessInput(float dt)
{

}

void Game::Render()
{
    /*Renderer->DrawSprite(ResourceManager::GetTexture("face"),
                         glm::vec2(200.0f, 200.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));*/
    if(this->State == GAME_ACTIVE)
    {
        // draw background
        /*Renderer->DrawSprite(ResourceManager::GetTexture("background"),
                             glm::vec2(0.0f, 0.0f), glm::vec2(this->Width, this->Height), 0.0f
        );*/
        // draw level
        Level.Draw(*Renderer);
    }
}

Game::Game() {

}
