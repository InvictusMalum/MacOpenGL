#pragma once

namespace gl{
class SpriteRender;
class Sprite;
}

#include <Entity.hpp>
#include <shader.hpp>

#include <iostream>

#include <deps.h>

namespace gl {
    class SpriteRenderer {
        Shader shader_;
        unsigned int VAO_;

        public:

        static constexpr char* VERTEX_PATH = "shaders/sprite/sprite.vs";
        static constexpr char* FRAGMENT_PATH = "shaders/sprite/sprite.frag";

        SpriteRenderer(Shader shader);
        ~SpriteRenderer();

        void render(glm::vec2 size, glm::vec2 position, glm::vec2 scale,
                float rotate, const glm::mat4 &windowModel, Texture_base* texture);
        
    };

    class Sprite : public Entity {

        SpriteRenderer* renderer_; 
        Texture_base* texture_;
        
        glm::vec2 position_, scale_;
        float rotate_;
        glm::vec2 size_;

        public:

        Sprite();
        Sprite(Game* game);
        ~Sprite() {}

        virtual void loadRenderer(Game* game) override {
            renderer_ = game->renderer<SpriteRenderer>();
        }

        virtual void loadTextures(const GameData &data) override {}
        void setActiveTexture(Texture_base* texture) {
            size_ = {texture->getWidth(), texture->getHeight()};
            texture_ = texture;
        }

        void moveTo(float xPos, float yPos);
        void move(float xPos, float yPos);
        void setX(float xPos) {position_[0] = xPos;}
        void setY(float yPos) {position_[1] = yPos;}
        void moveX(float xPos) {position_[0] += xPos;}
        void moveY(float yPos) {position_[1] += yPos;}
        float xPos() {return position_[0];}
        float yPos() {return position_[1];}


        void setRotation(float rotation);
        void rotate(float rotation);
        float rotation() {return rotate_;}

        void setScale(float xScale, float yScale);
        void scale(float xScale, float yScale);

        virtual void render(const glm::mat4& windowModel) override;
        virtual void update(const gl::GameData& gameData) override {};

    };

}