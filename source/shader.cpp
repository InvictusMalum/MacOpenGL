#include "shader.hpp"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace gl {

    Shader::Shader(const char* vertexSource, const char* fragmentSource) {
        loadShader(vertexSource, fragmentSource);
    }


    unsigned int Shader::compileVertexShader(const char* vertexSource) {
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        glCompileShader(vertexShader);

        int success;
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cerr << "VERTEX SHADER ERROR: COMPILATION FAILED\n"
                    << infoLog << "\n";
            return 0;
        }
        return vertexShader;
    }

    unsigned int Shader::compileFragmentShader(const char* fragmentSource) {
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
        glCompileShader(fragmentShader);

        int success;
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cerr << "ERROR:SHADER:FRAGMENT: COMPILATION FAILED\n"
                    << infoLog << "\n";
            return 0;
        }
        return fragmentShader;
    }

    bool Shader::loadShader(const char* vertexSource, const char* fragmentSource) {
        unsigned int vertShader = compileVertexShader(vertexSource);
        unsigned int fragShader = compileFragmentShader(fragmentSource);

        shaderProgram_ = glCreateProgram();
        glAttachShader(shaderProgram_, vertShader);
        glAttachShader(shaderProgram_, fragShader);
        glLinkProgram(shaderProgram_);

        int success;
        glGetProgramiv(shaderProgram_, GL_LINK_STATUS, &success);
        if(!success) {
            char infoLog[512];
            glGetProgramInfoLog(shaderProgram_, 512, NULL, infoLog);
            std::cerr << "ERROR:PROGRAM: LINKING FAILED\n"
                    << infoLog << "\n";
        }

        glUseProgram(shaderProgram_);

        glDeleteShader(vertShader);
        glDeleteShader(fragShader);
    }

}