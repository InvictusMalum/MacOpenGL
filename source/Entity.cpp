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

    void EntityLink::breakFromList() {
        if (next_)
            next_->setLast(last_);
        next_ = nullptr;
        if (last_)
            last_->setNext(next_);
        last_ = nullptr;
    }

    bool EntityLink::pushFront(EntityList* list) {
        if (!list) return false;
        breakFromList();
        list->appendFront(this);
    }
    bool EntityLink::pushBack(EntityList* list) {
        if (!list) return false;
        breakFromList();
        list->appendFront(this);
    }

    bool EntityLink::moveForward(size_t n=1) {
        if (!last_ || !n) return !(bool)n;
        EntityLink* link = last_;
        breakFromList();
        size_t i = 1;
        while (i < n) {
            if (!link->last()) break;
            link = link->last(); 
            i++;
        }

        // Insert Link
        if (link->last()) {
            link->last()->setNext(this);
            last_ = link->last();
        } else 
            last_ = nullptr;
        link->setLast(this);
        next_ = link;
        return !(i < n);
    }

    bool EntityLink::moveBacward(size_t n=1) {
        if (!next_ || !n) return !(bool)n;
        EntityLink* link = next_;
        breakFromList();
        size_t i = 1;
        while (i < n) {
            if (!link->next()) break;
            link = link->next(); 
            i++;
        }

        // if (i < n) {

        // }

        // Insert Link
        if (link->next()) {
            link->next()->setNext(this);
            next_ = link->next();
        } else 
            next_ = nullptr;
        link->setNext(this);
        last_ = link;
        return !(i < n);
    }


    EntityList::EntityList() {
        
    }
    EntityList::~EntityList() {

    }

    void EntityList::appendFront(EntityLink* entity) {

    }

    void EntityList::appendBack(EntityLink* entity) {

    }

    void EntityList::display() {

    }
    void EntityList::update() {

    }


}