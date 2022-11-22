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

<<<<<<< HEAD
        void render(glm::vec2 size, float position[2],
=======
        void render(glm::vec2 size, glm::vec2 position,
>>>>>>> 80c0ebb9d2e6c240c11e86ae35b890c40c8faccc
                glm::vec2 scale, float rotate, const glm::mat4 &windowModel);
        
    };

    class Sprite : public Entity {

        SpriteRenderer* renderer_; 

<<<<<<< HEAD
        float position_[2];
        glm::vec2 scale_;
        float rotation_;
=======
        
        glm::vec2 position_, scale_;
        float rotate_;
>>>>>>> 80c0ebb9d2e6c240c11e86ae35b890c40c8faccc
        glm::vec2 size_;

        public:

        Sprite();
        Sprite(Game* game);
        ~Sprite() {}

        virtual void loadRenderer(Game* game) override {
            renderer_ = game->renderer<SpriteRenderer>();
        }

<<<<<<< HEAD
        float getPosX() {return position_[0];}
        float getPosY() {return position_[1];}
        float getRotation() {return rotation_;}
        float getScaleX() {return scale_[0];}
        float getScaleY() {return scale_[1];}

=======
>>>>>>> 80c0ebb9d2e6c240c11e86ae35b890c40c8faccc
        void moveTo(float xPos, float yPos);
        void move(float xPos, float yPos);
        void setX(float xPos) {position_[0] = xPos;}
        void setY(float yPos) {position_[1] = yPos;}
        void moveX(float xPos) {position_[0] += xPos;}
        void moveY(float yPos) {position_[1] += yPos;}
<<<<<<< HEAD
        
=======
        float xPos() {return position_[0];}
        float yPos() {return position_[1];}


>>>>>>> 80c0ebb9d2e6c240c11e86ae35b890c40c8faccc
        void setRotation(float rotation);
        void rotate(float rotation);

        void setScale(float xScale, float yScale);
        void scale(float xScale, float yScale);

        virtual void render(const glm::mat4& windowModel) override;
        virtual void update(const gl::GameData& gameData) override {};

    };

}