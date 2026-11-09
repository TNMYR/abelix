#include <iostream>
#include <glad/gl.h>
// GLFW (include after glad)
#include <GLFW/glfw3.h>


constexpr float WIDTH=720, HEIGHT=480; 

int main() {
    // -- snip --
    if (!glfwInit()) {
        std::fprintf(stderr, "glfwInit failed\n");
        return -1;
    }
    
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
    if (!window) 
    {
        std::cerr << "Error with window\n";
        return -1;
    }
    glfwMakeContextCurrent(window);

    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0) {
        printf("Failed to initialize OpenGL context\n");
        return -1;
    }

    // Successfully loaded OpenGL
    printf("Loaded OpenGL %d.%d\n", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));

    // -- snip --
}