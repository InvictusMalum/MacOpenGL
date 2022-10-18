#pragma once

#include <Entity.hpp>


namespace gl {

    

    class Game {
        using Callback = std::function<void()>;
        using Key = std::tuple<int,int,int>;

        template<KEY, NEXT=void>
        class CallbackMap {
            std::map<KEY, NEXT> map_;
            std::vector<Callback> callbacks_;
            void bindCallBack(CallBack callback) {
                callBacks_.pushBack(callBack);
            }
        }

        

        EntityList entities_;
        CallbackMap<int,CallbackMap<int,CallbackMap<int>> keyCallbackMap_;
        
        public:
        
        Game();
        ~Game();

        void bindKey(int scancode, Callback callback);
        void bindKey(int scancode, int action, Callback callback);
        void bindKey(int scancode, int action, int mod, Callback callback);



        void loadEntity(Entity* entity);
        void execute();
    };


}