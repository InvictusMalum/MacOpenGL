#include <Game.hpp>

namespace gl {

    

        

    Game::Game(uint32_t fps, uint16_t fieldWidth, uint16_t fieldHeight,
            const char* windowTitle, Window::WindowType windowType) :

        fps_(fps), width_(fieldWidth), height_(fieldHeight),
        window_(new Window(this, windowType, fieldWidth, fieldHeight, windowTitle))
    {}

    Game::~Game() {
        delete window_;
    }

    template<typename T>
    bool Game::loadRenderer(T* renderer) {
        std::type_index index = typeid(renderer);
        if (renderMap_[index]) return false;
        renderMap_[index] = renderer;
        return true;
    }

    template<typename T>
    void* Game::renderer() {
        return renderMap_[typeid(T)];
    }


    void Game::loadEntity(Entity* entity) {
        entities_.appendFront(entity);
    }
    void Game::execute() {
        while (!window_->shouldClose()) {
            entities_.render(window_->windowModel());
            entities_.update(&gameData_);
        }
    }



}