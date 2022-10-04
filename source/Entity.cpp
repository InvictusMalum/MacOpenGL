#include <Entity.hpp>

namespace gl {


    EntityLink::EntityLink(Entity* entity) :
        next_(nullptr), last_(nullptr), entity_(entity)
    {}

    EntityLink* EntityLink::setNext(EntityLink* link) {
        EntityLink* tmp = next_;
        next_ = link;
        return tmp;
    }
    EntityLink* EntityLink::setLast(EntityLink* link) {
        EntityLink* tmp = last_;
        last_ = link;
        return tmp;
    }

    void EntityLink::pushFront(EntityLink* list) {
        // Remove node from current list
        // next_->
    }
    void EntityLink::pushBack(EntityLink* list) {

    }

    bool EntityLink::sendForward(size_t n=1) {

    }
    bool EntityLink::sendBacward(size_t n=1) {

    }

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