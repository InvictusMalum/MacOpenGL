
#include <ResourceManager.hpp>


namespace gl {



    Texture_base* ResourceManager::loadTexture(Texture_base *texture, std::string name) {
        textures_[name] = texture;
        return texture;
    }
    Texture_base* ResourceManager::texture(std::string name) {
        return textures_[name];
    }

    void ResourceManager::clear() {
        for (auto iter : textures_)
            delete &iter.second;
    }



}