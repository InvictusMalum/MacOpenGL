#pragma once

#include "gl.hpp"

namespace gl{
class SpriteRender;
class Sprite;
}

#include <Entity.hpp>
#include <shader.hpp>

namespace gl {


    class SpriteRenderer {
        Shader shader_;
        unsigned int VAO_;

        public:

        SpriteRenderer(Shader shader);
        ~SpriteRenderer();

        void render(glm::vec2 size, uint16_t position[2],
                glm::vec2 scale, float rotate, glm::mat4 windowModel);
        
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

        void loadGame(Game* game) {game_ = game;}

        void moveTo(uint16_t xPos, uint16_t yPos);
        void move(uint16_t xPos, uint16_t yPos);

        void setRotation(float rotation);
        void rotate(float rotation);

        void setScale(float xScale, float yScale);
        void scale(float xScale, float yScale);

        void render();
        virtual void init() {};
        virtual void update() {};

    };

}