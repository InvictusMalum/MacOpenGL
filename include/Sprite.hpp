#include <Entity.hpp>
#include <shader.hpp>

namespace gl {

    class Sprite : public Entity {

        Shader shader_;
        unsigned int VAO_;

        public:

        Sprite();
        ~Sprite();


        void render();
        // virtual void update()=0;

    };

}