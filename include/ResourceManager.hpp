#pragma once

#include "shader.hpp"

#include <map>
#include <typeinfo>
#include <typeindex> 

namespace gl {

    std::map<std::type_index, void*> renderers_;
    std::map<std::string, Shader>    shaders_;
    


}