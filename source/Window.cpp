#include <Window.hpp>
#include <stdexcept>
#include <functional>


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




    Window::Window(WindowType type, int windowWidth,
            int windowHeight, const char* title,
            void (*key_callback) (GLFWwindow*,int,int,int,int)) :
        type_(type), winWidth_(windowWidth), winHeight_(windowHeight)
    {
        window_ = glfwCreateWindow(winWidth_, winHeight_, title, nullptr, nullptr);
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

        


        // if (key_callback)
        //     glfwSetKeyCallback(window_, key_callback);
        
    }

    void Window::adjustModel() {
        screenModel_ = {};
        switch (type_) {
            case WindowType::static_window:
                break;
            case WindowType::stretch_window:
                break;
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