#pragma once

#include <GLFW/glfw3.h>

class Window {
public:
    void create(int width, int height, const char* title);
    GLFWwindow* operator*();
    ~Window();

private:
    GLFWwindow* handle;
};
