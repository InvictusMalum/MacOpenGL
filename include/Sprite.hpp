#include <Entity.hpp>
#include <shader.hpp>

namespace gl {


    class SpriteRender {
        Shader shader_;
        
    };

    class Sprite : public Entity {

        Shader shader_;
        unsigned int VAO_;

        glm::vec2 position_, scale_;
        float rotate_;
        glm::vec2 size_;

        public:

        Sprite();
        ~Sprite();


        void render();
        // virtual void update()=0;

    };

}