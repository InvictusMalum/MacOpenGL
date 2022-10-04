#include <glm/glm.hpp>

namespace gl {

    class Entity {
        EntityLink* link_;

        glm::vec2 pos_;
        float rotation_;
        glm::vec2 scale_;

        public:

        virtual void update()=0;
        virtual void display()=0;
        virtual glm::vec2 hitBox()=0;
        virtual glm::vec2 position() {return pos_;}
        virtual float rotation() {return rotation_;}
        virtual glm::vec2 scale() {return scale_;}

    };

    class EntityLink {
        EntityLink* next_;
        EntityLink* last_;
        Entity* entity_;

        public:
        EntityLink(Entity* entity);
        

        EntityLink* next() {return next_;}
        EntityLink* setNext(EntityLink* link);
        EntityLink* last() {return last_;}
        EntityLink* setLast(EntityLink* link);

        void pushFront(EntityList* list);
        void pushBack(EntityList* list);
        bool sendForward(size_t n=1);
        bool sendBacward(size_t n=1);
    };

    class EntityList {
        EntityLink* front_;
        EntityLink* last_;
        
        public:

        EntityList();
        ~EntityList();

        void appendFront(EntityLink* entity);
        void appendFront(Entity* entity) {
            appendFront(new EntityLink(entity));
        }

        void appendBack(EntityLink* entity);
        void appendBack(Entity* entity) {
            appendBack(new EntityLink(entity));
        }

        void display();
        void update();
    };

}