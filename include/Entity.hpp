#pragma once

#include "gl.hpp"

namespace gl{
class Entity;
class EntityLink;
class EntityList;
}

#include <Game.hpp>


namespace gl {


    class Entity {
        EntityLink* link_;

        public:

        virtual void init(GameData* gameData) {}
        virtual void update(GameData* gameData) {};
        virtual void render() {};
        // virtual glm::vec2 hitBox()=0;
        // virtual glm::vec2 position() {return pos_;}
        // virtual float rotation() {return rotation_;}
        // virtual glm::vec2 scale() {return scale_;}

    };

    class EntityLink {
        EntityLink* next_;
        EntityLink* last_;
        Entity* entity_;

        public:
        EntityLink(Entity* entity);
        ~EntityLink();

        Entity* entity() {return entity_;}
        
        EntityLink* next() {return next_;}
        EntityLink* setNext(EntityLink* link);
        EntityLink* last() {return last_;}
        EntityLink* setLast(EntityLink* link);

        void breakFromList();

        bool pushFront(EntityList* list);
        bool pushBack(EntityList* list);
        bool moveForward(size_t n=1);
        bool moveBacward(size_t n=1);
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

        void render();
        void update();
    };

}