#include <deps.h>

#include <Texture.hpp>

#include <stb/stb_image.h>

namespace gl {

    Texture::Texture()
        : Width(0), Height(0), Internal_Format(GL_RGB), Image_Format(GL_RGB),
        Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR),
        Filter_Max(GL_LINEAR)
    {
        glGenTextures(1, &this->ID);
    }

    Texture::Texture(const char* file, bool alpha)
        : Width(0), Height(0), Internal_Format(GL_RGB), Image_Format(GL_RGB),
        Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR),
        Filter_Max(GL_LINEAR)
    {
        glGenTextures(1, &this->ID);
        generate(file, alpha);
    }

    Texture::~Texture() {
        glDeleteTextures(1, &this->ID);
    }

    void Texture::generate(const char* file, bool alpha)
    {
        int width, height, nrChannels;
        unsigned char* data;

        if (alpha) {
            Internal_Format = GL_RGBA;
            Image_Format = GL_RGBA;
        }
        this->Width = width;
        this->Height = height;

        data = stbi_load(file, &width, &height, &nrChannels, 0);

        // create Texture
        glBindTexture(GL_TEXTURE_2D, this->ID);
        glTexImage2D(GL_TEXTURE_2D, 0, this->Internal_Format, width, height, 0, this->Image_Format, GL_UNSIGNED_BYTE, data);
        // set Texture wrap and filter modes
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Filter_Min);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Filter_Max);
        
        stbi_image_free(data);
        
        // unbind texture
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    void Texture::bind() const
    {
        glBindTexture(GL_TEXTURE_2D, this->ID);
    }

}