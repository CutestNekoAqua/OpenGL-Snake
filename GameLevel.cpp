//
// Created by valen on 06.08.2020.
//

#include <GameLevel.h>
#include <resource_manager.h>

void GameLevel::Load(unsigned int levelWidth, unsigned int levelHeight)
{
    // clear old data
    this->dots.clear();
    // load from file
    unsigned int tileCode;
    GameLevel level;
    std::string line;

    // TODO: Make TileAmount Configureable
    unsigned int height = 24;
    unsigned int width  = 32;
    float unit_width    = levelWidth / static_cast<float>(width);
    float unit_height   = levelHeight / height;

    this->berry = GenFood(width, unit_width, height, unit_height);

}

void GameLevel::Draw(SpriteRenderer &renderer)
{
    /*for (GameObject &tile : this->dots) {
        if (!tile.Destroyed)
            tile.Draw(renderer);
    }*/
    this->berry.Draw(renderer);
    //this->player.Draw(renderer);
}

GameObject GameLevel::GenFood(unsigned int width, unsigned int unit_width, unsigned int heigth,
                              unsigned int unit_height) {
    // Setting up the randomizer
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distWidth(1,width);
    std::uniform_int_distribution<> distHeigth(1,heigth);

    // Randomizing
    int posX = distWidth(gen);
    int posY = distHeigth(gen);

    glm::vec2 pos(unit_width * posX, unit_height * posY);
    glm::vec2 size(unit_width, unit_height);
    // Red
    glm::vec3 color = glm::vec3(1.0f, 0.0f, 0.0f);

    return GameObject(pos, size, ResourceManager::GetTexture("block"), color);

}


GameLevel::GameLevel() {

}

GameLevel::GameLevel(GameLevel *pLevel) {

}
