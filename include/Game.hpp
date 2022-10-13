#include <Entity.hpp>

namespace gl {

    class Game {

        EntityList entities_;
        
        public:
        
        Game();
        ~Game();

        void loadEntity(Entity* entity);
        void execute();
    };


}