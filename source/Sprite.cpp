#include <Sprite.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>

namespace gl {

    SpriteRenderer::SpriteRenderer(Shader shader) :
        shader_(shader)
    {
        // configure VAO/VBO
        unsigned int VBO;
        float vertices[] = { 
            // pos      // tex
            -0.5f, 0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.0f, 0.0f, 
        
            -0.5f, 0.5f, 0.0f, 1.0f,
            0.5f, 0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, 1.0f, 0.0f
        };

        glGenVertexArrays(1, &VAO_);
        glGenBuffers(1, &VBO);
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindVertexArray(VAO_);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);  
        glBindVertexArray(0);
    }

    void SpriteRenderer::render(glm::vec2 size, uint32_t position_[2],
                glm::vec2 scale, float rotate) {
        // prepare transformations
        shader_.use();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::scale(model, glm::vec3(size, 1.0f));
        model = glm::scale(model, glm::vec3(scale, 1.0f));
        model = glm::rotate(model, glm::radians(rotate),
            glm::vec3(0.0f, 0.0f, 1.0f));
        // model = glm::translate(model, glm::vec3(position_, 0.0f));  
    
        shader_.setMat4("model", model);
    
        // glActiveTexture(GL_TEXTURE0);
        // texture.Bind();

        glBindVertexArray(this->VAO_);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
    }


    Sprite::Sprite(SpriteRenderer* renderer) :
        size_(0.3,0.2), position_{0,0}, rotate_(0),
        scale_(1,1), renderer_(renderer)
    {}


    void Sprite::moveTo(uint32_t xPos, uint32_t yPos) {
        position_[0] = xPos;
        position_[1] = yPos;
    }
    void Sprite::move(uint32_t xPos, uint32_t yPos) {
        position_[0] += xPos;
        position_[1] += yPos;   
    }

    void Sprite::setRotation(float rotation) {
        rotate_ = rotation;
    }
    void Sprite::rotate(float rotation) {
        rotate_ = fmod(rotate_+rotation, 360);
    }

    void Sprite::setScale(float xScale, float yScale) {
        scale_ = {xScale, yScale};
    }
    void Sprite::scale(float xScale, float yScale) {

    }


    void Sprite::render() {
        renderer_->render(size_, position_, scale_, rotate_);
    }  
    // virtual void update()=0;



}