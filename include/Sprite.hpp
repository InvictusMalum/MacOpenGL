#include <Entity.hpp>
#include <shader.hpp>

namespace gl {


    class SpriteRenderer {
        Shader shader_;
        unsigned int VAO_;

        public:

        SpriteRenderer(Shader shader);
        ~SpriteRenderer();

        void render(glm::vec2 size_, glm::vec2 position_,
                glm::vec2 scale_, float rotate_);
        
    };

    class Sprite : public Entity {

        SpriteRenderer* renderer_; 

        glm::vec2 position_, scale_;
        float rotate_;
        glm::vec2 size_;

        public:

        Sprite(SpriteRenderer* renderer);
        ~Sprite() {}


        void render();
        // virtual void update()=0;

    };

}