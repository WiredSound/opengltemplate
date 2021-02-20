#include "window.hpp"

#include <stdexcept>

void Window::create(int width, int height, const char* title) {
	if(!glfwInit()) {
		glfwTerminate();
		throw std::runtime_error("Failed to initialise GLFW");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	handle = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if(handle == nullptr) {
		glfwTerminate();
		throw std::runtime_error("Failed to create GLFW window");
	}

	glfwMakeContextCurrent(handle);
}

GLFWwindow* Window::operator*() {
	return handle;
}

Window::~Window() {
	glfwTerminate();
}
