#pragma once

#include "gl.hpp"

namespace gl {
class Game;
class GameData;
}

#include <Window.hpp>
#include <Entity.hpp>


namespace gl {

    struct GameData {
        uint32_t width, height;
        uint32_t fps;
        uint32_t dTime;
    };

    class Game {
        // using Callback = std::function<void()>;
        // using Key = std::tuple<int,int,int>;

        // template<KEY, NEXT=void>
        // class CallbackMap {
        //     std::map<KEY, NEXT> map_;
        //     std::vector<Callback> callbacks_;
        //     void bindCallBack(CallBack callback) {
        //         callBacks_.pushBack(callBack);
        //     }
        // }

        public:

        

        private:

        EntityList entities_;
        Window* window_;
        uint32_t fps_;
        uint16_t width_, height_;
        GameData gameData_;

        // CallbackMap<int,CallbackMap<int,CallbackMap<int>> keyCallbackMap_;
        
        public:
        
        Game(uint32_t fps, uint16_t fieldWidth, uint16_t fieldHeight,
            const char* windowTitle = "", 
            Window::WindowType windowType = Window::static_window);
        ~Game();

        // void bindKey(int scancode, Callback callback);
        // void bindKey(int scancode, int action, Callback callback);
        // void bindKey(int scancode, int action, int mod, Callback callback);

        uint16_t fieldWidth() {return width_;}
        uint16_t fieldHeight() {return height_;}
        GameData* data() {return gameData_;}

        void loadEntity(Entity* entity);
        void execute();
    };


}