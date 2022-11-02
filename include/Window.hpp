#pragma once

namespace gl{
    class Window;
    enum class WindowType {
        static_window,
        stretch_window,
        scale_window,
        dynamic_window
    };
}

#include "gl.hpp"
#include "Game.hpp"

#include <map>

namespace gl {

    

    class Window {
        public:

        private:
        GLFWwindow* window_;
        WindowType type_;
        Game* game_;
        uint16_t winWidth_, winHeight_;
        float ratio_;
        glm::mat4 windowModel_; // Transforms point on game field to point on screen

        public:
        Window(Game* game, WindowType type, uint16_t windowWidth = 0,
                    uint16_t windowHeight = 0, const char* title = "",
                    void (*key_callback)(GLFWwindow*,int,int,int,int) = nullptr);

        private:

        void adjustModel(); // Set sceenModel to proper transform

        public:
        

        // Callbacks
        void framebuffer_size_callback(int width, int height);

        glm::mat4* windowModel() {return &windowModel_;}
        
        void setDimensions(int width, int height);
        void processInput();
        void swapBuffers();
        bool shouldClose();
        void setWindowShouldClose(bool state);
    };

    
}