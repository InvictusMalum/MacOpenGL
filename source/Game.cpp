#include <Game.hpp>

#include <Sprite.hpp>


#include <iostream>
namespace gl {
    Game::Game(uint32_t fps, uint16_t fieldWidth, uint16_t fieldHeight,
            const char* windowTitle, WindowType windowType) :
        fps_(fps), width_(fieldWidth), height_(fieldHeight), window_(nullptr),
        entities_(new EntityList())
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif

        window_ = new Window(this, windowType, fieldWidth, fieldHeight, windowTitle);


        SpriteRenderer *spriteRenderer = new SpriteRenderer
            (Shader(SpriteRenderer::VERTEX_PATH, SpriteRenderer::FRAMENT_PATH));
        loadRenderer<SpriteRenderer>(spriteRenderer);

    }

    Game::~Game() {
        glfwTerminate();
        if (window_)
            delete window_;
    }


    void Game::loadEntity(Entity* entity) {
        entities_->appendFront(entity);
        std::cout << "LOADING RENDERER\n";
        entity->loadRenderer(this);
    }
    void Game::execute() {
        std::cout << "TEST EXECUTE: " << (bool)entities_ << " : " << (long long)window_ << "\n";
        while (!window_->shouldClose()) {
            std::cout << "TEST1\n";
            std::cout << "TEST EXECUTE: " << (bool)entities_ << " : " << window_->windowModel()[0][1] << "\n";
            entities_->render(window_->windowModel());
            std::cout << "TEST2\n";
            entities_->update(gameData_);
        }
    }



}