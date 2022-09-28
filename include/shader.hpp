
#include <string>

namespace gl {
 
    class Shader {
        unsigned int shaderProgram_;

        public:

        Shader() {}
        Shader(const char* vertexSource, const char* fragmentSource);
        ~Shader();

        private:

        static unsigned int compileVertexShader(const char* vertexSource);
        static unsigned int compileFragmentShader(const char* fragmentSource);

        public:

        bool loadShader(const char* vertexSource, const char* fragmentSource);

        bool successful();

    };

}