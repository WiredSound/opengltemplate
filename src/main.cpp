#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <iostream>
#include <stdexcept>

#include "window.hpp"

void load_gl();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main() {
    Window window;

    try {
        window.create(800, 600, "OpenGL Template C++");
        load_gl();
    }
    catch(std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(*window, framebuffer_size_callback);

    while(!glfwWindowShouldClose(*window)) {
        if(glfwGetKey(*window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(*window, true);
        }

        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(*window);
        glfwPollEvents();
    }

    return 0;
}

void load_gl() {
    if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        throw std::runtime_error("Failed to initialise GLAD");
    }
}

void framebuffer_size_callback([[maybe_unused]] GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
