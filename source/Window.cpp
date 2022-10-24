#include <Window.hpp>
#include <stdexcept>
#include <functional>


namespace gl {

    WindowRegistry g_windowRegistry();

    bool WindowRegistry::registerWindow(GLFWwindow* glfwWindow,
                                        Window* window) {
        if (glfwWindow && window &&
                windowMap_[glfwWindow])
            return false;
        
        windowMap_[glfwWindow] = window;
        return true;
    }

    void WindowRegistry::unregisterWindow(GLFWwindow* glfwWindow) {
        windowMap_[glfwWindow] = nullptr;
    }

    static void framebuffer_size_callback
            (GLFWwindow* window, int width, int height) {
        windowMap_[window].framebufferCallback(width, height)
    }


    Window::Window(WindowType type, int windowWidth,
            int windowHeight, const char* title,
            void (*key_callback) (GLFWwindow*,int,int,int,int)) :
        type_(type), winWidth_(windowWidth), winHeight_(windowHeight)
    {
        window_ = glfwCreateWindow(winWidth_, winHeight_, title, nullptr, nullptr);
        if (window_ == nullptr)
            throw std::runtime_error("Failed To Create GLFW Window");

        // Register window with global registry so this class 
        // recieves callbacks from them.
        g_windowRegistry.registerWindow(window_, this);

        glfwMakeContextCurrent(window_);
        glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);

        if (key_callback)
            glfwSetKeyCallback(window_, key_callback);
        
    }

    // Callback for adjusting view window size
    void Window::framebuffer_size_callback(int width, int height) {
        glViewport(0, 0, width, height);
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