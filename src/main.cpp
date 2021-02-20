#include <iostream>
#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.hpp"

void load_gl();

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

	std::cout << glfwWindowShouldClose(*window) << std::endl;

	return 0;
}

void load_gl() {
	if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
		throw std::runtime_error("Failed to initialise GLAD");
	}
}
