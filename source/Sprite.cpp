#include <Sprite.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>

#include <iostream>
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

<<<<<<< HEAD
    void SpriteRenderer::render(glm::vec2 size, float position_[2],
=======
    void SpriteRenderer::render(glm::vec2 size, glm::vec2 position_,
>>>>>>> 80c0ebb9d2e6c240c11e86ae35b890c40c8faccc
                glm::vec2 scale, float rotate, const glm::mat4 &projection) {
        // prepare transformations
        shader_.use();

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(position_, 0.0f));
        model = glm::rotate(model, glm::radians(rotate),
            glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(size*scale, 1.0f));
        
        
        shader_.setMat4("model", model);

        shader_.setMat4("projection", projection);
    
        // glActiveTexture(GL_TEXTURE0);
        // texture.Bind();

        glBindVertexArray(this->VAO_);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
    }


    Sprite::Sprite() :
        size_(100,100), position_{0,0}, rotation_(0),
        scale_(1,1), renderer_(nullptr)
    {}

    Sprite::Sprite(Game* game) :
        size_(100,100), position_{0,0}, rotation_(0),
        scale_(1,1), renderer_(game->renderer<SpriteRenderer>())
    {}


    void Sprite::moveTo(float xPos, float yPos) {
        position_[0] = xPos;
        position_[1] = yPos;
    }
    void Sprite::move(float xPos, float yPos) {
        position_[0] += xPos;
        position_[1] += yPos;   
    }

    void Sprite::setRotation(float rotation) {
        rotation_ = rotation;
    }
    void Sprite::rotate(float rotation) {
        rotation_ = fmod(rotation_+rotation, 360);
    }

    void Sprite::setScale(float xScale, float yScale) {
        scale_ = {xScale, yScale};
    }
    void Sprite::scale(float xScale, float yScale) {
        scale_ = {scale_[0]*xScale, scale_[1]*yScale};
    }

    void Sprite::render(const glm::mat4& projection) {
        renderer_->render(size_, position_, scale_, rotation_, projection);
    }  
    // virtual void update()=0;
}