//
// Created by valen on 04.08.2020.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "SpriteRenderer.h"
#include "resource_manager.h"
#include "GameLevel.h"

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

class Game
{
public:
    Game();

// game state
    GameState    State;
    GameLevel    Level;
    bool         Keys[1024];
    unsigned int Width, Height;
    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();
    // initialize game state (load all shaders/textures/levels)
    void Init();
    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
};

#endif //SNAKE_GAME_H
