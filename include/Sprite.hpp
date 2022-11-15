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

        void render(glm::vec2 size, uint16_t position[2],
                glm::vec2 scale, float rotate, const glm::mat4 &windowModel);
        
    };

    class Sprite : public Entity {

        SpriteRenderer* renderer_; 

        uint16_t position_[2];
        glm::vec2 scale_;
        float rotate_;
        glm::vec2 size_;

        public:

        Sprite();
        Sprite(Game* game);
        ~Sprite() {}

        virtual void loadRenderer(Game* game) override {
            renderer_ = game->renderer<SpriteRenderer>();
        }

        void moveTo(uint16_t xPos, uint16_t yPos);
        void move(uint16_t xPos, uint16_t yPos);
        void setX(uint16_t xPos) {position_[0] = xPos;}
        void setY(uint16_t yPos) {position_[1] = yPos;}
        void moveX(uint16_t xPos) {position_[0] += xPos;}
        void moveY(uint16_t yPos) {position_[1] += yPos;}
        uint16_t xPos() {return position_[0];}
        uint16_t yPos() {return position_[1];}


        void setRotation(float rotation);
        void rotate(float rotation);

        void setScale(float xScale, float yScale);
        void scale(float xScale, float yScale);

        virtual void render(const glm::mat4& windowModel) override;
        virtual void update(const gl::GameData& gameData) override {};

    };

}