#pragma once

#include <GLFW/glfw3.h>

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
        int width_, height_;
        int winWidth_, winHeight_;
        float ration_;

        void framebuffer_size_callback(GLFWwindow* window, int width, int height);

        public:
        Window(int width, int height, WindowType type, int windowWidth = 0,
                    int windowHeight = 0, const char* title = "",
                    void (*key_callback)(GLFWwindow*,int,int,int,int) = nullptr);
        
        void scale(int width, int height);
        void processInput();
        void swapBuffers();
        bool shouldClose();
    };
}