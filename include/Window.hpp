#pragma once

#include "gl.hpp"

namespace gl{
class Window;
}

#include <map>

namespace gl {

    class WindowRegistry {
        using Window::framebuffer_size_callback framebufferCallback;
        
        std::map<GLFWwidow*, Window*>
            windowMap_;
        
        public:
        
        WindowRegistry() {}
        ~WindowRegistry() {}

        protected:

        bool registerWindow(GLFWwindow* glfwWindow, Window* window);
        void unregisterWindow(GLFWwindow* glfwWindow);
        Window* getWindow(GLFWwindow* window) {return windowMap_[window];}

        private:

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    };
    

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

        // Callbacks
        void framebuffer_size_callback(int width, int height)
        
        void setDimensions(int width, int height);
        void processInput();
        void swapBuffers();
        bool shouldClose();
        void setWindowShouldClose(bool state);
    };
}