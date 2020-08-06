//
// Created by valen on 06.08.2020.
//

#ifndef SNAKE_GAMELEVEL_H
#define SNAKE_GAMELEVEL_H

#include <list>
#include <random>

#include "GameObject.h"

class GameLevel {
public:
    GameLevel(GameLevel *pLevel);

    int length;
    int width;
    int height;
    std::list<GameObject> dots;
    GameObject berry;
    GameObject player;
    GameLevel();
    void Draw(SpriteRenderer &renderer);
    void Load(unsigned int width, unsigned int height);
    bool isDead;
    GameObject GenFood(unsigned int width, unsigned int unitwidth, unsigned int heigth, unsigned int unitheight);
};

#endif //SNAKE_GAMELEVEL_H
