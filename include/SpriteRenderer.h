//
// Created by valen on 04.08.2020.
//

#ifndef SNAKE_SPRITERENDERER_H
#define SNAKE_SPRITERENDERER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "texture.h"
#include "shader.h"

class SpriteRenderer
{
public:
    SpriteRenderer(Shader &shader);

    SpriteRenderer(Shader shader);

    ~SpriteRenderer();

    void DrawSprite(Texture2D texture, glm::vec2 position,
                    glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f,
                    glm::vec3 color = glm::vec3(1.0f));
private:
    Shader       shader;
    unsigned int quadVAO;

    void initRenderData();
};

#endif //SNAKE_SPRITERENDERER_H
