#pragma once

#include "gl.hpp"

namespace gl{
class Window;
}

namespace gl {
    

    class Window {
        public:
        enum WindowType {
            static_window,
            stretch_window,
            scale_window,
            dynamic_window
        };

        private:
        GLFWwindow* window_;
        WindowType type_;
        int winWidth_, winHeight_;
        float ratio_;


        public:
        Window(WindowType type, int windowWidth = 0,
                    int windowHeight = 0, const char* title = "",
                    void (*key_callback)(GLFWwindow*,int,int,int,int) = nullptr);
        
        void setDimensions(int width, int height);
        void processInput();
        void swapBuffers();
        bool shouldClose();
        void setWindowShouldClose(bool state);
    };
}