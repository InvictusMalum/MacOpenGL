#include <Game.hpp>

namespace gl {
    Game::Game(uint32_t fps, uint16_t fieldWidth, uint16_t fieldHeight,
            const char* windowTitle, WindowType windowType) :

        fps_(fps), width_(fieldWidth), height_(fieldHeight),
        window_(new Window(this, windowType, fieldWidth, fieldHeight, windowTitle))
    {}

    Game::~Game() {
        delete window_;
    }

    // template<typename T>
    // bool Game::loadRenderer(T* renderer) {
    //     std::type_index index = typeid(renderer);
    //     if (renderMap_[index]) return false;
    //     renderMap_[index] = renderer;
    //     return true;
    // }

    // template<typename T>
    // T* Game::renderer() {
    //     return (T*)renderMap_[typeid(T)];
    // }

    // // Remove renderer of type T from internal map
    // // Returns pointer if removed
    // // Returns nullptr if renderer of type T doesn't exist
    // template<typename T>
    // T* Game::removeRenderer() {
    //     if (!renderMap_[typeid(T)]) return nullptr;
    //     T* tmpReturn = renderMap_[typeid(T)];
    //     renderMap_.erase(typeid(T));
    //     return tmpReturn;
    // }

    // // Remove renderer from internal map
    // // Returns pointer if removed
    // // Returns nullptr if renderer of type T doesn't exist
    // // or pointer doesn't match provided renderer
    // template<typename T>
    // T* Game::removeRenderer(T* renderer) {
    //     if (!renderer || renderMap_[typeid(T)] != renderer)
    //         return nullptr;
    //     T* tmpReturn = renderMap_[typeid(T)];
    //     renderMap_.erase(typeid(T));
    //     return tmpReturn;
    // }

    // // Removes and deletes renderer of given type
    // // from internal map
    // // Returns true if renderer of type T was delete
    // // false if not found in map
    // template<typename T>
    // bool Game::deleteRenderer() {
    //     T* tmpRenderer = renderMap_[typeid(T)];
    //     if (!tmpRenderer) return nullptr;
    //     delete tmpRenderer;
    //     renderMap_.erase(typeid(T));
    //     return true;
    // }

    // // Removes and deletes renderer of given type
    // // from internal map
    // // Returns true if renderer was delete
    // // false if not found in map
    // template<typename T>
    // bool Game::deleteRenderer(T* renderer) {
    //     T* tmpRenderer = renderMap_[typeid(T)];
    //     if (!tmpRenderer) return nullptr;
    //     delete tmpRenderer;
    //     renderMap_.erase(typeid(T));
    //     return true;
    // }


    void Game::loadEntity(Entity* entity) {
        entities_->appendFront(entity);
    }
    void Game::execute() {
        while (!window_->shouldClose()) {
            entities_->render(window_->windowModel());
            entities_->update(&gameData_);
        }
    }



}