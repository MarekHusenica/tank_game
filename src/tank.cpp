#include "tank.h"


Tank::Tank(glm::vec3 position, float rotation) {
    this->position = position;
    this->rotation = rotation;
    this->scale = glm::vec3(0.5f, 0.8f, 1.0f);
}

void Tank::draw(Shader& shader) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, scale);

    shader.use();
    shader.setMat4("u_Model", model);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Tank::update(float deltaTime) {
    float vx = cos(glm::radians(rotation)) * maxSpeed * deltaTime;
    float vy = sin(glm::radians(rotation)) * maxSpeed * deltaTime;
    position.x += vx;
    position.y += vy;
}