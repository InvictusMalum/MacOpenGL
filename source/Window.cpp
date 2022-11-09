#include <Window.hpp>
#include <stdexcept>
#include <functional>

#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

namespace gl {
    class WindowRegistry {
        
        std::map<GLFWwindow*, Window*>
            windowMap_;
        
        public:
        
        WindowRegistry() {}
        ~WindowRegistry() {}

        bool registerWindow(GLFWwindow* glfwWindow, Window* window);
        void unregisterWindow(GLFWwindow* glfwWindow);
        Window* getWindow(GLFWwindow* window) {return windowMap_[window];}

        private:

        static void framebuffer_size_central_callback
                (GLFWwindow* window, int width, int height);
    
    } g_windowRegistry;

    bool WindowRegistry::registerWindow(GLFWwindow* glfwWindow,
                                        Window* window) {
        if (!glfwWindow || !window ||
                windowMap_[glfwWindow])
            return false;
        glfwSetFramebufferSizeCallback(glfwWindow,
            WindowRegistry::framebuffer_size_central_callback);

        windowMap_[glfwWindow] = window;
        return true;
    }

    void WindowRegistry::unregisterWindow(GLFWwindow* glfwWindow) {
        windowMap_[glfwWindow] = nullptr;
    }

    void WindowRegistry::framebuffer_size_central_callback
            (GLFWwindow* window, int width, int height) {
        g_windowRegistry.windowMap_[window]->
                framebuffer_size_callback(width, height);
    }



    Window::Window(Game* game, WindowType type, uint16_t windowWidth,
            uint16_t windowHeight, const char* title,
            void (*key_callback) (GLFWwindow*,int,int,int,int)) :
        type_(type), game_(game), winWidth_(windowWidth),
        winHeight_(windowHeight)
    {


        window_ = glfwCreateWindow(winWidth_, winHeight_, title, NULL, NULL);
        if (window_ == nullptr)
            throw std::runtime_error("Failed To Create GLFW Window");
        
        // If window mode is static then 
        if (type_ == WindowType::static_window)
            glfwSetWindowSizeLimits(window_, winWidth_, winHeight_,
                                    GLFW_DONT_CARE, GLFW_DONT_CARE);

        // Register window with global registry so this class 
        // recieves callbacks from them.
        g_windowRegistry.registerWindow(window_, this);

        glfwMakeContextCurrent(window_);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD\n";
        }

        if (type == WindowType::static_window)
            glfwSetWindowAttrib(window_, GLFW_RESIZABLE, false);
        
        glViewport(0, 0, winWidth_, winHeight_);

        initializeProjection();
    }

    void Window::initializeProjection() {
        projection_ = glm::mat4(1.0f);
        switch (type_) {
            case WindowType::static_window:
                // Fall through as static_window projection is same as stretch
                // just static can't changes size after the fact

            case WindowType::stretch_window:
                // Translate to range -1 - 1 inclusive
                projection_ = glm::translate(projection_,
                    glm::vec3{-1, 1, 0});
                // Map to range 0 - 2 inclusive
                projection_ = glm::scale(projection_,
                    glm::vec3{
                        2.0f/(game_->fieldWidth()),
                        -2.0f/(game_->fieldHeight()),
                        1.0f});
                break;
            case WindowType::scale_window:
                break;

            case WindowType::dynamic_window:
                break;
                
        }
    }

    void Window::adjustProjection() {
        switch (type_) {
            case WindowType::static_window:
                break; // Maintains current projection regardless of changes in window
                
            case WindowType::stretch_window:
                break; // Maintains current projection regardless of changes in window

            case WindowType::scale_window:
                break;
            case WindowType::dynamic_window:
                break;
                
        }
    }

    // Callback for adjusting view window size
    void Window::framebuffer_size_callback(int width, int height) {
        winWidth_ = width;
        winHeight_ = height;
        glViewport(0, 0, width, height);
        adjustProjection();
    }
    
    void Window::setDimensions(int width, int height) {
        // Manually run callback function to adjust sizing of the view port
        // UNTESTED IF WORKS PROPERLY
        framebuffer_size_callback(width, height);
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