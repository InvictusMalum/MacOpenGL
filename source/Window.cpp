#include <Window.hpp>
#include <stdexcept>
#include <functional>


namespace gl {

        // enum WindowType {
        //     static_window,
        //     stretch_window,
        //     scale_window,
        //     dynamic_window
        // };

        // GLFWwindow* window_;
        // WindowType type_;
        // int width, height;
        // int winWidth_, winHeight_;
        // float ratio_


        // Callback for adjusting view window size
        void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        }

        Window::Window(WindowType type, int windowWidth,
                int windowHeight, const char* title,
                void (*key_callback) (GLFWwindow*,int,int,int,int)) :
            type_(type), winWidth_(windowWidth), winHeight_(windowHeight)
        {
            window_ = glfwCreateWindow(winWidth_, winHeight_, title, nullptr, nullptr);
            if (window_ == nullptr)
                throw std::runtime_error("Failed To Create GLFW Window");

            glfwMakeContextCurrent(window_);
            glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);

            if (key_callback)
                glfwSetKeyCallback(window_, key_callback);
            
        }

        
        void Window::setDimensions(int width, int height) {
            // Manually run callback function to adjust sizing of the view port
            // UNTESTED IF WORKS PROPERLY
            framebuffer_size_callback(window_, width, height);
        }
        void Window::swapBuffers() {
            glfwSwapBuffers(window_);
        }
        bool Window::shouldClose() {
            return glfwWindowShouldClose(window_);
        }
        void Window::setWindowShouldClose(bool state) {
            glfwSetWindowShouldClose(window_, state);
        }


}