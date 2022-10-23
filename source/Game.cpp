#include <Game.hpp>

namespace gl {

    

        

    Game::Game(uint32_t fps, uint32_t fieldWidth, uint32_t fieldHeight,
            const char* windowTitle, Window::WindowType windowType) :
        
        fps_(fps), width_(fieldWidth), height_(fieldHeight),
        window_(new Window(windowType, fieldWidth, fieldHeight, windowTitle))
    {}

    Game::~Game() {
        delete window_;
    }


    void Game::loadEntity(Entity* entity) {
        entities_.appendFront(entity);
    }
    void Game::execute() {
        while (!window_->shouldClose()) {
            entities_.update();
            entities_.render();
        }
    }



}