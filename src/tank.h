#pragma once

#include "shader.h"
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Tank {
public:
    const float maxSpeed = 0.5f;
    const float rotationSpeed = 0.1f;

    Tank(glm::vec3 position, float rotation);

    glm::vec3 getPosition() { return position; }
    float getRotation() { return rotation; }

    void update(float deltaTime);
    void draw(Shader& shader);

private:
    glm::vec3 position;
    float rotation;
    glm::vec3 scale;
};